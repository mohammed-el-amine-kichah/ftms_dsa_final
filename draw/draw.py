import matplotlib.pyplot as plt
import pandas as pd

with open('/Users/mymacbookair/Desktop/ftms_dsa_final/draw/goalDistribution.csv', 'r') as file:
    player = file.readline().strip()

distribution = pd.read_csv('/Users/mymacbookair/Desktop/ftms_dsa_final/draw/goalDistribution.csv',skiprows=1)

x = distribution['GameweekNumber']
y = distribution['Goals']

plt.plot(x,y,label='Goals Distribution')
plt.xlabel('Gameweek')
plt.ylabel('Goals')
plt.title('Goal Distribution Curve of '+player)
plt.xticks(range(1, 39),rotation = 45)
plt.yticks(range(0, 10))
plt.legend()
plt.savefig('../draw/plotOfScoringDistribution.png')
plt.show()

