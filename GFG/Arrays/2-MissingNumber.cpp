#include<bits/stdc++.h>

using namespace std;

int missingNumbers(int arr[] , int n){

    int X1 =arr[0],X2=1;
    for(int i=1;i<n;i++)
        X1^=arr[i];

    for(int i=2;i<=n+1;i++)
        X2^=i;

    return X1^X2;
}

int main(){


    int t=0;
    cin>>t;
    while(t--){

    int n;
    cin>>n;

    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    cout<<missingNumbers(arr , n);
    cout<<"\n";

}
return 0;
}
