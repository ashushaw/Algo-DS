#include<bits/stdc++.h>

using namespace std;
    int checkRotation(int arr[] ,int n){

        //int max=arr[n-1];
       for(int i=n-2;i>=0;i--){
        if(arr[i-1]>arr[i])
            return i;

       }
       return 0;
    }

int main(){
    int t=0;
    cin>>t;
    while(t--){
	int n=0;
	//cout<<"Enter the array size";
	cin>>n;
	//cout<<"enter the array\n";
	int arr[n];

	for(int i=0;i<n;i++)
		cin>>arr[i];

	cout<<checkRotation(arr,n)<<"\n";
	cout<<"\n";
}
}


