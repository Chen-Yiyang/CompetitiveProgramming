# Knapsack problem using DP
# by Yiyang, 12/02/18

import numpy as np

# main
itemsNum = int(input("Enter the number of items: "))
maxVolume = int(input("Enter the maximum volume of the knapsack: "))

# initialisation of value, weight, and f 
itemValues = np.zeros((itemsNum+1), dtype=np.int)                       # start with index 1
itemWeights = np.zeros((itemsNum+1), dtype=np.int)
maxValue = np.zeros((itemsNum+1,maxVolume+1), dtype=np.int)

for i in range(itemsNum):
    tmpValue = int(input())
    tmpWeight = int(input())
    itemValues[i+1] = tmpValue
    itemWeights[i+1] = tmpWeight

# DP
for i in range(1, itemsNum+1):
    for j in range(1, maxVolume+1):
        if itemWeights[i] <= j:
            takeCurrentOne = maxValue[i-1][j-itemWeights[i]] + itemValues[i]
        else:
            takeCurrentOne = 0
        
        if takeCurrentOne > maxValue[i-1][j-1]:
            maxValue[i][j] = takeCurrentOne
        else:
            maxValue[i][j] = maxValue[i-1][j-1]

print("The maximum total value is", maxValue[i][j])
    
