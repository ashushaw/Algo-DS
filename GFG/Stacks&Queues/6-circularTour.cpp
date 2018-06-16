#include<bits/stdc++.h>

using namespace std;

struct petrolPump
{
  int petrol;
  int distance;
};


int printTour(struct petrolPump arr[], int n){


    int start=0;
    int end=1;
    int curr_petrol=0;
    int total_petrol =0;
    while(start!=end){
        curr_petrol = arr[start].petrol - arr[end].distance;

        if(curr_petrol+total_petrol >=0){
            total_petrol+=curr_petrol;
            start=(start+1)%n;
        }
        else{
            total_petrol=0;
            start=(start+1)%n;
            //end denotes the starting index as we keep incrementing start
            end=start;
        }
    }

    return end;
}


int main(){


    int t=0;
    //cin>>t;
    //while(t--){

    int n;
    cin>>n;

    petrolPump P1[n];
    for(int i=0;i<n;i++){
        cin>>P1[i].petrol;
        cin>>P1[i].distance;
    }

    cout<<printTour(P1,n);
    cout<<"\n";

//}
return 0;
}
