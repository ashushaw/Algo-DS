#include<bits/stdc++.h>

using namespace std;
    int equilibriumIndex(int arr[] ,int n){

    int sum=0;

        for(int i=0;i<n;i++)
            sum+=arr[i];


        int sum_start=0,sum_end=0;

			for(int i=0;i<n;i++){
				if(sum_start==sum-sum_start-arr[i])
					return i;
				sum_start=sum_start+arr[i];

			}
         return -1;
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

	cout<<equilibriumIndex(arr,n)<<"\n";
	cout<<"\n";
}
}

