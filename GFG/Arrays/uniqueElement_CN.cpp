#include<bits/stdc++.h>

using namespace std;
    int uniqueElem(int arr[] ,int n){
        int uniqElem=0;

        for(int i=0;i<n;i++){
                uniqElem^=arr[i];
        }
            cout<<uniqElem;
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

	uniqueElem(arr,n);
	cout<<"\n";
//}
}




