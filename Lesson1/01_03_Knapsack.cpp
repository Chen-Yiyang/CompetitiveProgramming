/*
Knapsack problem using DP
by Yiyang, 12/02/18
*/

#include <bits/stdc++.h>
using namespace std;

int itemValues[1000], itemWeights[100], maxValue[1000][1000];	// global variables

int main(){
	
	int i,j;
	int tmpValue,tmpWeight,takeCurrentOne;
	int itemsNum,maxVolume;
	
	cin>>itemsNum>>maxVolume;
	
	memset(itemValues,0,sizeof(itemValues));		// set default value = 0 (thou global variables by default = 0)
	memset(itemWeights,0,sizeof(itemWeights));
	memset(maxValue,0,sizeof(maxValue));
	
	for (i=1;i<=itemsNum;i++){
		
		cin>>tmpValue>>tmpWeight;
	    itemValues[i] = tmpValue;
	    itemWeights[i] = tmpWeight;	
	}

	// DP process

	for (i=1;i<=itemsNum;i++){
	    for (j=1;j<=maxVolume;j++){
			
			if (itemWeights[i] <= j){
	            takeCurrentOne = maxValue[i-1][j-itemWeights[i]] + itemValues[i];
	        }
			else{
				takeCurrentOne = 0;
			}
			
			if (takeCurrentOne > maxValue[i-1][j-1]){
				maxValue[i][j] = takeCurrentOne;
			}
			else{
				maxValue[i][j] = maxValue[i-1][j-1];
			}
		}
	}
	
	cout<<"The maximum total value is "<<maxValue[itemsNum][maxVolume];
	return 0;
}

