#include<bits/stdc++.h>

using namespace std;
    int reverseArray(int arr[] ,int n){
        int temp=0;

        for(int i=n-1;i>=(n-1)/2;i--){
                temp=arr[i];
            arr[i]=arr[n-1-i];
            arr[i]=temp;
        }
            //arr[n-1]=temp;

        for(int i=0;i<n-1;i++)
            cout<<arr[n];
    }

int main(){
    int t=0;
    //cin>>t;
    //while(t--){
	int n=0;
	//cout<<"Enter the array size";
	cin>>n;
	//cout<<"enter the array\n";
	int arr[n];

	for(int i=0;i<n;i++)
		cin>>arr[i];

	reverseArray(arr,n);
	cout<<"\n";
//}
}



