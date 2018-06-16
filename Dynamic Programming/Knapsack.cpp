#include<bits/stdc++.h>

using namespace std;

int knapsack(int* weights, int* values, int n, int maxWeight){

int** dp = new int*[n+1];
	for(int i=0;i<=n;i++){
		dp[i] = new int[maxWeight+1];
	}

	for(int i=0;i<=maxWeight;i++){
		dp[0][i] = 0;
	}
	for(int i=0;i<=n;i++){
		dp[i][0] = 0;
	}

for(int i=0;i<n;i++){
    for(int w=0;w<maxWeight;w++){
        dp[i][w]=dp[i-1][w];
        if(dp[i][w]<=maxWeight){
            dp[i][w]=max(dp[i][w],values[i-1] +dp[i-1][w-weights[i-1]]);
        }
    }
}

int ans = dp[n][maxWeight];
	//delete dp array

  for (int i =0; i <=  n; i++) {
		delete [] dp[i];
	}
	delete [] dp;

	return ans;
}



int main(){

    int val[] = {60, 100, 120};
    int wt[] = {10, 20, 30};
    int  W = 50;
    int n = sizeof(val)/sizeof(val[0]);
    cout<<knapsack(wt,val,n,W);
    return 0;
return 0;
}
