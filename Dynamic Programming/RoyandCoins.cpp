#include<bits/stdc++.h>

using namespace std;



int main(){

    int n;
    cin>>n;
    int *start_arr = new int[n+1];
    int *end_arr = new int[n+1];
    int m;
    cin>>m;
    int l , r;
    for(int i=1;i<=m;i++){
        cin>>l;
        cin>>r;
        start_arr[l]+=1;
        end_arr[r]+=1;
    }
    cout<<"Hello";
    int *dp = new int[n+1];
    end_arr[0]=0;
    dp[0]=0;
    for(int i=1;i<=n;i++){
        dp[i]=start_arr[i]-end_arr[i-1];
    }
cout<<"NextHello";
    int *exactlyFilled = new int[n+1];

    for(int i=0;i<=n;i++)
            exactlyFilled[i]=0;

    for(int i=0;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(dp[j]==i){
                exactlyFilled[i]++;
            }
        }
    }
cout<<"NexttoNexthello";

cout<<"\nexact Filled array\n";

for(int i=0;i<=n;i++)
    cout<<exactlyFilled[i]<<"\n";

    int *atleastFilled= new int[n+1];
    atleastFilled[n-1]=exactlyFilled[n-1];
    for(int i=n-2;i>=0;i--){
        atleastFilled[i]=atleastFilled[i+1]+exactlyFilled[i];
    }
cout<<"\nAtleast Filled array\n";

for(int i=0;i<n;i++)
    cout<<atleastFilled[i]<<"\n";
    int q=0;
    cin>>q;
    int x=0;
    for(int i=0;i<q;i++){
        cin>>x;
        cout<<"ANS is "<<atleastFilled[x]<<"\n";
    }
    return 0;
}
