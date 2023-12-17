import os
import matplotlib.pyplot as plt
import pandas as pd

distribution = pd.read_csv('/Users/mymacbookair/Desktop/ftms_dsa_final/draw/goalsDistribution.csv')



x = distribution['x']
y = distribution['y']


plt.plot(x,y,label='Goals Distribution')
plt.xlabel('Gameweek')
plt.ylabel('Goals')
plt.title('Goal Distribution Curve Plot')
plt.xticks(range(1, 39),rotation = 45)
plt.yticks(range(0, 10))
plt.legend()

plt.savefig('../draw/plotOfScoringDistribution.png')
print("success")
