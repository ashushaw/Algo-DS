#include<bits/stdc++.h>

using namespace std;
void sort012(int arr[] ,int n){

        int lo = 0;
        int hi = n- 1;
        int mid = 0,temp=0;
        while (mid <= hi)
        {
            switch (arr[mid])
            {
            case 0:
            {
                temp   =  arr[lo];
                arr[lo]  = arr[mid];
                arr[mid] = temp;
                lo++;
                mid++;
                break;
            }
            case 1:
                mid++;
                break;
            case 2:
            {
                temp = arr[mid];
                arr[mid] = arr[hi];
                arr[hi] = temp;
                hi--;
                break;
            }
            }
        }

        for(int i=0;i<n;i++)
            cout<<arr[i]<<" ";
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

	sort012(arr,n);
	cout<<"\n";
}
}
