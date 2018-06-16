#include<bits/stdc++.h>

using namespace std;
    int pythgoreantriplets(int arr[] ,int n){

        for(int i=0;i<n;i++)
            arr[i]=arr[i]*arr[i];

            sort(arr,arr+n);
       for(int i=n-1;i>=2;i++){
            int l=0;
            int r= i-1;
            while(l<r){
                if(arr[l]+arr[r]==arr[i])
                    return true;
                else if(arr[l]+arr[r]>arr[i])
                    r--;

                else if(arr[l]+arr[r]<arr[i])
                    l++;

            }
       }

       return false;
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

	cout<<pythgoreantriplets(arr,n)<<"\n";
	cout<<"\n";
}
}


