#include<bits/stdc++.h>
#define ll long long
#define mod 1000000007

using namespace std;
//ll dp[1001][101];

ll gcd(ll a,ll b)
{
    while(b!=0)
    {
        ll r=b;
        b=a%b;
        a=r;
    }
    return a;
}

void vanyaGCD(int *arr,int n){

  for(int i=1;i<n+1;i++)
            dp[arr[i-1]][i]=1;

    for(int i=2;i<n+1;i++){
            //iis the current elemnt which we access
        for(int j=1;j<i;j++){
            //j starts from the first element goes until i , finding the gcd for all no 1 to 101 via the k loop
            if(arr[j-1]>arr[i-1]){
            //if we have the elemnt previous to i greater than it we skip as then gcd will not be 1
                continue;
            }
            //finding the gcd for all no's in array for each value from 1 to 100
            for(int k=1;k<101;k++){
                    if(dp[k][j]>=1)
                    {
                        ll s=gcd(k,arr[i-1]);
                        dp[s][i]=(dp[s][i]+dp[k][j])%mod;
                    }

            }

        }
    }

        ll ans =0;
        // we only need the gcd value of 1
       for(int i=1;i<n+1;i++)
            ans=(ans+dp[1][i])%mod;

 cout<<ans<<"\n";
}

int main(){

int n=0;
cin>>n;

int *arr = new int[n];
for(int i=0;i<n;i++)
    cin>>arr[i];

vanyaGCD(arr,n);

return 0;
}
