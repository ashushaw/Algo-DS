#include<bits/stdc++.h>

using namespace std;
int arrayIntersection(int arr1[] ,int m,int arr2[] ,int n){

       sort(arr1,arr1+m);
       sort(arr2,arr2+m);
       int i=0,j=0;

       if(n>m)
            n=m;

       while(j!=n){

        if(arr1[i]==arr2[j]){
            cout<<arr1[i]<<" ";
            i++;
            j++;
        }
        if(arr1[i]>arr2[j])
            j++;

       if(arr1[i]<arr2[j])
            i++;
    }
}

int main(){
    int t=0;
    cin>>t;
    while(t--){
    int m=0;
    cin>>m;
	//cout<<"enter the array\n";
	int arr1[m];

	for(int i=0;i<m;i++)
		cin>>arr1[i];
	int n=0;
	//cout<<"Enter the array size";
	cin>>n;
	//cout<<"enter the array\n";
	int arr2[n];

	for(int i=0;i<n;i++)
		cin>>arr2[i];

	cout<<arrayIntersection(arr1,m,arr2,n)<<"\n";
	cout<<"\n";
}
}


