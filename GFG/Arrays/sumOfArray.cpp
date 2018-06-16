#include<bits/stdc++.h>

using namespace std;
    void arraySum(int arr1[] ,int m,int arr2[] ,int n){
        int size=0;
        if(m>n)
            size =m;
        else
            size=n;
        int arr3[size+1];
        int k = size-1;
        int sum=0;
        int temp=0;
        int i=0,j=0;
        for(i=0,j=0;i<m,j<n;i++,j++)
            {


            sum=temp+(arr1[m-i-1]+arr2[n-j-1]);
			arr3[k]=sum%10;
			temp=sum/10;
			k--;
    }
        while(i<m){

			sum=temp+arr1[m-i-1];
			arr3[k]=sum%10;
			temp=arr1[m-i-1]/10;
			k--;
			i++;
		}

		while(j<n){
			sum=temp+arr2[n-j-1];
			arr3[k]=sum%10;
			temp=arr2[n-j-1]/10;
			k--;
			j++;
		}

        for(int l=0;l<size;l++)
            cout<<arr3[l];

    }

int main(){
    int t=0;
    //cin>>t;
    //while(t--){
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

	arraySum(arr1,m,arr2,n);
	cout<<"\n";
//}
}




