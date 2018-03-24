#include <bits/stdc++.h>
using namespace std;

int magicGrid(int **input,int m,int n){


    int **dp=new int*[m];
    for(int i=0;i<m;i++)
        dp[i]=new int[n];
    //here we start from the bottom to fill the dp array
    //which has the cost at each step
    //at dp[0][0] the ans is presnt
    //thus at last position the dp array will have same entry as the input array

    dp[m-1][n-1]=input[m-1][n-1];

    //NOTE: This problem is just opposite of the MinCOst Problem
    //last row of the dp array will have values starting from the bottom
    //each value be subtracted from the previous as we need to start with the min health in the starting
    for(int i=m-2;i>=0;i--){
        dp[i][n-1]=dp[i+1][n-1]-input[i][n-1];
    }

    //simalrly for the last row also
    for(int i=n-2;i>=0;i--){
        dp[m-1][i]=dp[m-1][i+1]-input[m-1][i];
    }

    for(int i=m-2;i>=0;i--){
        for(int j=n-2;j>=0;j--){
            dp[i][j]=min(dp[i][j+1],dp[i+1][j])-input[i][j];
            //So this condition is imortant to take care
            //if the value gets negative we make it 1 as we donot want value to be zero
            if(dp[i][j]<=0)
               dp[i][j]=1;
    }
    }
return dp[0][0];
}

int main() {
   int t;
   scanf("%d",&t);
   while(t--)
   {
      int r,c;
      scanf("%d%d",&r,&c);
      int **a=new int*[r];
    for(int i=0;i<r;i++)
        a[i]=new int[c];
      for(int i=0;i<r;++i)
         for(int j=0;j<c;++j)
    scanf("%d",&a[i][j]);

     cout<<magicGrid(a,r,c)<<"\n";
   }

  return 0;
}
