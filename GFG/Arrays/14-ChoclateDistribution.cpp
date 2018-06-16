
#include<bits/stdc++.h>

using namespace std;
    int choclateDistbn(int arr[] ,int n,int m){

    sort(arr,arr+n);

    int temp[m];
    int diff_min=INT_MAX;
    int diff=0;
    int start=0;
    int finish=n-1;
    for(int i=0;i<n;i++){
        diff=arr[i+m-1]-arr[i];
        if(diff<diff_min){
            diff_min=diff;
            start=i;
            finish=i+m-1;
        }

    }


    int result = arr[finish]-arr[start];
    return result;
    }

int main(){
    int t=0;
    cin>>t;
    while(t--){
	int n=0,m=0;
	//cout<<"Enter the array size";
	cin>>n;

	//cout<<"enter the array\n";
	int arr[n];

	for(int i=0;i<n;i++)
		cin>>arr[i];
    cin>>m;
	cout<<choclateDistbn(arr,n,m)<<"\n";
	cout<<"\n";
}
}


