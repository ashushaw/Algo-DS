#include<bits/stdc++.h>

using namespace std;

int main(){

int t=0;
cin>>t;
while(t--){
bool change =true;

int cost[10];

    for(int i=0;i<10;i++){
        cin>>cost[i];
    }

    while(change){
            change=false;
        for(int a=0;a<10;a++){
            for(int b=0;b<10;b++){
                int c = (a+b)%10;
                if(cost[c]>cost[a]+cost[b]){
                    cost[c]=cost[a]+cost[b];
                    change = true;
                }

                }
            }
        }




    int s=0,ans=0;
    cin>>s;
    while(s!=0){
        s=s%10;
        ans+=cost[s];
        s=s/10;
    }

    cout<<ans<<"\n";
}
    return 0;
}
