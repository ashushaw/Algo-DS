#include<bits/stdc++.h>

using namespace std;

int main(){

    int dp[1001];
    //filling the dp array with pre-computed values

    dp[0]=0;
    dp[1]=1;
    dp[2]=2;
    dp[3]=3;
    dp[4]=1;

    for(int i=5;i<1001;i++){

        dp[i]=i;
        //going through all perfect square and reducing the value of i accordingly
        for(int j=1;j<=i;j++){
                //temp is the prefect square less than i
                int temp=j*j;
                //if we have the perfect square greater than i we just skip
            if(temp>i)
                continue;
                //we find min depending upon the current value and i-temp
                //i-temp is the value of the land after removing a square land
        dp[i]=min(dp[i],1+dp[i-temp]);
        }
    }
//finally dp has complete pre computed array till 1001 i.e the max input
    int t, n;
    scanf("%d", &t);
    while(t-->0)
    {
        scanf("%d", &n);
        printf("%d\n", dp[n]);
    }


return 0;
}
