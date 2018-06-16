#include<bits/stdc++.h>
#define ll long long
#define mod 1000000007

using namespace std;

int dp[101][101][2];


//This is working correctly
void iterativeBitCount(int n,int k){

//the kth bit is for the start bit i.e 0 or 1
    for (int j = 0; j <= k; j++)
            for (int k = 0; k < 2; k++)
              dp[1][j][k] = 0;
          dp[1][0][0] = 1; dp[1][0][1] = 1;

        for (int i = 2; i <= n; i++)
        for (int j = 0; j <= k; j++)
          for (int k = 0; k < 2; k++) {
            if (k == 0)
              dp[i][j][k] = dp[i-1][j][0] + dp[i-1][j][1];
            else
              dp[i][j][k] = dp[i-1][j][0];

            if (j > 0 && k == 1)
              dp[i][j][k] += dp[i-1][j-1][1];
          }

    cout <<" " << (dp[n][k][0] + dp[n][k][1])<< "\n";
}
int adjacentBitcount(int n,int k,int start){

    for(int i=0;i<=n;i++){
        for(int j=0;j<=n;j++){
            for(int k=0;k<2;k++){
                 dp[i][j][k]=-1;
            }
        }
    }

    if(k<0)
        return 0;
    if(n<1){
        if(k==1)
            return 1;
        else
            return 0;
    }

    if(dp[n][k][start]>-1)
        return dp[n][k][start];
    if(start==0){
        dp[n][k][start]+=adjacentBitcount(n-1,k,0);
        dp[n][k][start]+=adjacentBitcount(n-1,k,1);
    }

    if(start==1){
        dp[n][k][start]+=adjacentBitcount(n-1,k,0);
        dp[n][k][start]+=adjacentBitcount(n-1,k-1,1);
    }

    return  dp[n][k][start];
}

int cal( int pos, int total, int prev )
{
	if( total < 0 ) return 0;
	if( pos < 0 ){
		if( total == 0 ) return 1;
		return 0;
	}
	int &ret = dp[ pos ][ total ][ prev ];
	if( ret != -1 ) return ret;
	ret = 0;
	if( prev == 1 ){
		ret += cal(pos - 1, total - 1, 1 );
		ret += cal(pos - 1, total, 0 );
	}
	else
	{
		ret += cal(pos - 1, total, 1 );
		ret += cal(pos - 1, total, 0 );
	}
	return ret;
}

int main(){

    int n , k;
    cin>>n;
    cin>>k;
    cout<<"\n"<<adjacentBitcount(n-2,k,0)+adjacentBitcount(n-2,k,1);
    cout<<"\n"<<cal(n-2,k,0)+cal(n-2,k,1);
    cout<<"\n";
    cout<<"\n";
    iterativeBitCount(n,k);
return 0;
}
