import pandas as pd
import numpy as np

# Read the CSV file
df = pd.read_csv('Player19-20-2.csv')

# Initialize an empty list to hold gameweek DataFrames
gameweek_dfs = []

# Extract unique team names from the dataset
unique_teams = df['TEAM'].unique()

# Initialize team goals counter with keys for all unique teams
team_goals_counter = {team: 0 for team in unique_teams}

# Initialize goalkeeper count
goalkeeper_count = 0

# Generate gameweek data for each player
for _, row in df.iterrows():
    player_data = row.copy()
    for i in range(1, 39):
        # Check if the player played in the gameweek
        played = np.random.choice([0, 1], p=[0.3, 0.7])  # Probability of playing
        if played == 1:
            # Define maximum substitution count and initialize substitution list
            max_subs = np.random.choice([0, 1, 2, 3, 4, 5])  # Random number of substitutions (0 to 5)
            substitutions = []

            # Generate random number of substitutions (0 to max_subs)
            num_subs = np.random.randint(0, max_subs + 1)

            # Generate playing time for starters and substitutes
            playing_time = np.random.choice([90, 60])  # For starters

            if num_subs > 0:
                sub_times = np.random.choice([30, max(90 - playing_time, 0)], size=num_subs, replace=True)
                substitutions.extend(sub_times)

                # Adjust the playing time for starters based on substitutions
                playing_time -= sum(substitutions)

            # Update the goalkeeper count
            if player_data['Pos'] == 'Goalkeeper' and player_data['GS'] == 1:
                goalkeeper_count += 1

            # Create a dictionary for player's gameweek data
            goals_scored = np.random.randint(0, 8)  # Random number of goals (0 to 7)
            team_goals_counter[player_data['TEAM']] += goals_scored

            gameweek_data = {
                'PLAYER': player_data['PLAYER'],
                'TEAM': player_data['TEAM'],
                'GP': 1,  # Set GP to 1 as the player played
                'GS': 1 if i == 1 and player_data['Pos'] == 'Goalkeeper' and goalkeeper_count == 1 else 0,  # Ensure only 1 goalkeeper starts in the first gameweek
                'MIN': playing_time,
                'G': min(goals_scored, 7),  # Cap goals at 7
                'ASST': np.random.randint(0, 6),  # Random number of assists (0 to 5)
                'Pos': player_data['Pos'],
                'numberYellowCard': min(np.random.choice([0, 1, 2]), 2),  # Cap yellow cards at 2
                'numberRedCard': 1 if player_data['numberYellowCard'] == 2 else player_data['numberRedCard'],
                'distance': round(np.random.uniform(0.1, 1.5) * playing_time / 90, 3),  # Ensure max distance of 12
                'Gameweek': i
            }

            # Adjust goals to respect the limit of total goals by a team
            total_team_goals = team_goals_counter[player_data['TEAM']]
            if total_team_goals > 15:
                excess_goals = total_team_goals - 15
                gameweek_data['G'] -= excess_goals
                team_goals_counter[player_data['TEAM']] -= excess_goals

            # Append the player's gameweek data to the list
            gameweek_dfs.append(gameweek_data)
        else:
            # If the player didn't play, set all attributes to 0
            gameweek_data = {
                'PLAYER': player_data['PLAYER'],
                'TEAM': player_data['TEAM'],
                'GP': 0,
                'GS': 0,
                'MIN': 0,
                'G': 0,
                'ASST': 0,
                'Pos': player_data['Pos'],
                'numberYellowCard': 0,
                'numberRedCard': 0,
                'distance': 0,
                'Gameweek': i
            }

            # Append the player's gameweek data to the list
            gameweek_dfs.append(gameweek_data)

# Convert the list of dictionaries to a DataFrame
gameweek_df = pd.DataFrame(gameweek_dfs)

# Write each gameweek's data to a separate CSV file
for i in range(1, 39):
    gameweek_data = gameweek_df[gameweek_df['Gameweek'] == i]
    gameweek_data.to_csv(f'gameweek_{i}.csv', index=False)
