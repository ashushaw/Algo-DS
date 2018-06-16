#include<bits/stdc++.h>

using namespace std;

class PetrolPump{

     public:
    int petrol;
    int distance;
    int avail;


    bool visit;
    PetrolPump(){
    petrol=0;
    distance = 0;
    avail =0;
    visit = false;
}
    int petrolAvailable();
};



int PetrolPump:: petrolAvailable(){

    avail = petrol - distance;
    return avail;
}

int circularTour( PetrolPump P1[] ,int n){

    int initial_avail =0;
    int start =0;

    int list[n];
    int k=0;
    for(int i=0;i<n;i++)
         P1[i].petrolAvailable();
    int end=0;
    while(start!=end)

        if(!P1[i].visit && P1[i].avail+initial_avail>=0){
            start=(start+1)%n;
            initial_avail = P1[i].avail+initial_avail;
            P1[i].visit = true;
        }
        else{
            initial_avail=0;
            start=(start+1)%n;
            //we start set end back to start i.e we are using a circular queue
            start=end;
        }

    }
    return start;
}



int main(){


    int t=0;
    //cin>>t;
    //while(t--){

    int n;
    cin>>n;

    PetrolPump P1[n];
    for(int i=0;i<n;i++){
        cin>>P1[i].petrol;
        cin>>P1[i].distance;
    }

    cout<<circularTour(P1,n);
    cout<<"\n";

//}
return 0;
}
