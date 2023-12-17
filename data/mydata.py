import pandas as pd
import numpy as np

# Read the CSV file
df = pd.read_csv('Player19-20-2.csv')

# Initialize an empty list to hold gameweek DataFrames
gameweek_dfs = []

# Define probabilities
prob_red_card = [0.99, 0.01]  # Red cards are rare
prob_yellow_card_DF = [0.7, 0.25, 0.05]  # DFs get more yellow cards
prob_yellow_card_other = [0.6, 0.35, 0.05]  # Other positions get fewer yellow cards

# Generate gameweek data for each player
for _, row in df.iterrows():
    player_data = row.copy()
    for i in range(1, 39):
        # Check if the player played in the gameweek
        played = np.random.choice([0, 1])
        substituted = 0  # Flag to track if the player was substituted
        minutes_played = 0

        if played == 1:
            if np.random.choice([0, 1]):  # If the player starts
                if np.random.choice([0, 1]):  # Check if the player gets substituted
                    substituted = 1
                    minutes_played = np.random.choice([60, 90])  # 60 minutes if substituted, 90 if not
                else:
                    minutes_played = 90
            else:  # If the player gets substituted
                substituted = 1
                minutes_played = np.random.choice([30, 60])  # Minutes for substitutes: 30 or 60

            # Cap the number of substitutions to a maximum of 5
            if substituted == 1:
                substitutions = len(gameweek_dfs) - np.sum([1 for data in gameweek_dfs[::-1] if data['PLAYER'] == player_data[0] and data['Gameweek'] == i])
                if substitutions >= 5:
                    played = 0
                    substituted = 0
                    minutes_played = 0

            # Calculate distance covered based on minutes played and player position
            distance_covered = 0
            if player_data[7] == 'GK':
                distance_covered = np.random.uniform(0.1, 6) * minutes_played / 90  # GKs cover less distance
            elif player_data[7] == 'DF':
                distance_covered = np.random.uniform(6, 10) * minutes_played / 90  # DFs cover more distance
            else:
                distance_covered = np.random.uniform(10, 12) * minutes_played / 90  # Other positions cover average distance

            # Create a dictionary for player's gameweek data
            gameweek_data = {
                'PLAYER': player_data[0],
                'TEAM': player_data[1],
                'GP': 1,  # Set GP to 1 as the player played
                'GS': 1 if minutes_played == 90 else 0,  # Set GS to 1 if the player started
                'MIN': minutes_played,
                'G': 0,  # Initially set goals to 0
                'ASST': 0,  # Initially set assists to 0
                'Pos': player_data[7],
                'numberYellowCard': np.random.choice([0, 1, 2], p=prob_yellow_card_DF if player_data[7] == 'DF' else prob_yellow_card_other),
                'numberRedCard': np.random.choice([0, 1], p=prob_red_card),
                'distance': distance_covered,  # Store distance as a float without formatting
                'Gameweek': i,
                'gotsubstituted': substituted  # Flag if the player got substituted
            }
        else:
            # If the player didn't play, set all attributes to 0
            gameweek_data = {
                'PLAYER': player_data[0],
                'TEAM': player_data[1],
                'GP': 0,
                'GS': 0,
                'MIN': 0,
                'G': 0,
                'ASST': 0,
                'Pos': player_data[7],
                'numberYellowCard': 0,
                'numberRedCard': 0,
                'distance': 0,
                'Gameweek': i,
                'gotsubstituted': 0
            }

        # Append the player's gameweek data to the list
        gameweek_dfs.append(gameweek_data)

# Convert the list of dictionaries to a DataFrame
gameweek_df = pd.DataFrame(gameweek_dfs)

# Ensure that each team has exactly 11 starters for each game
for i in range(1, 39):
    teams = gameweek_df[gameweek_df['Gameweek'] == i]['TEAM'].unique()
    for team in teams:
        team_gameweek_data = gameweek_df[(gameweek_df['TEAM'] == team) & (gameweek_df['Gameweek'] == i) & (gameweek_df['GP'] == 1)]
        num_players = len(team_gameweek_data)
        if num_players >= 11:
            starters_indices = team_gameweek_data.sample(n=11, replace=False).index
        else:
            starters_indices = team_gameweek_data.index
        gameweek_df.loc[starters_indices, 'GS'] = 1

# Ensure goals match assists within a team for each gameweek
for i in range(1, 39):
    for team in gameweek_df[gameweek_df['Gameweek'] == i]['TEAM'].unique():
        team_gameweek_data = gameweek_df[(gameweek_df['TEAM'] == team) & (gameweek_df['Gameweek'] == i) & (gameweek_df['GP'] == 1)]
        total_goals = team_gameweek_data['G'].sum()
        max_assists = min(total_goals, 3)  # Max assists are capped to the total goals of the team or 3, whichever is smaller
        team_gameweek_data.loc[team_gameweek_data['ASST'] > max_assists, 'ASST'] = max_assists

# Write each gameweek's data to a separate CSV file with distance formatted to 3 decimal places
for i in range(1, 39):
    gameweek_data = gameweek_df[gameweek_df['Gameweek'] == i].copy()  # Make a copy of the data to avoid warnings
    gameweek_data['distance'] = gameweek_data['distance'].apply(lambda x: "{:.3f}".format(float(x)))
    gameweek_data.to_csv(f'gameweek_{i}.csv', index=False)
