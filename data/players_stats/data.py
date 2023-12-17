import pandas as pd
import numpy as np

# Read the CSV file
df = pd.read_csv('Player19-20-2.csv')

# Initialize an empty list to hold gameweek DataFrames
gameweek_dfs = []

# Generate gameweek data for each player
for _, row in df.iterrows():
    player_data = row.copy()
    for i in range(1, 39):
        # Check if the player played in the gameweek
        played = np.random.choice([0, 1])
        if played == 1:
            minutes_played = np.random.randint(0, 90)
            distance_covered = np.random.uniform(0.1, 1.5) * minutes_played  # Example range for distance
            
            # Create a dictionary for player's gameweek data
            gameweek_data = {
                'PLAYER': player_data[0],
                'TEAM': player_data[1],
                'GP': 0,  # Set GP to 0 initially
                'GS': 0,
                'MIN': 0,
                'G': 0,
                'ASST': 0,
                'Pos': player_data[7],
                'numberYellowCard': 0,
                'numberRedCard': 0,
                'distance': 0,
                'substituted': 0,  # New field 'substituted' set to 0
                'Gameweek': i
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
                'substituted': 0,  # New field 'substituted' set to 0
                'Gameweek': i
            }

        # Append the player's gameweek data to the list
        gameweek_dfs.append(gameweek_data)

# Convert the list of dictionaries to a DataFrame
gameweek_df = pd.DataFrame(gameweek_dfs)

# Ensure that each team has exactly 11 starters for each game
for team in gameweek_df['TEAM'].unique():
    for i in range(1, 39):
        team_gameweek_data = gameweek_df[(gameweek_df['TEAM'] == team) & (gameweek_df['Gameweek'] == i)]
        starters = team_gameweek_data.sample(n=11)
        gameweek_df.loc[starters.index, 'GS'] = 1
        gameweek_df.loc[~gameweek_df.index.isin(starters.index), 'GS'] = 0

# Set certain columns to 0 for all rows
columns_to_zero = ['GP', 'GS', 'G', 'ASST', 'MIN', 'numberYellowCard', 'numberRedCard', 'distance']
gameweek_df[columns_to_zero] = 0

# Write each gameweek's data to a separate Excel file
for i in range(1, 39):
    gameweek_data = gameweek_df[gameweek_df['Gameweek'] == i]
    gameweek_data.to_excel(f'gameweek_{i}.xlsx', index=False)
