#include<bits/stdc++.h>
using namespace std;
int maxSumSubArray(int arr[], int size){

	int max_sum_so_far = INT_MIN;
	int max_sum_ending = 0;

	for(int i=0 ; i < size ;i++){

		max_sum_ending=max_sum_ending+arr[i];

		if(max_sum_so_far<max_sum_ending)
			max_sum_so_far=max_sum_ending;

		if(max_sum_ending<0)
			max_sum_ending=0;
	}

	return max_sum_so_far;
}


int main(){


	int n=0;
	cout<<"Enter the array size";
	cin>>n;
	cout<<"enter the array\n";
	int arr[n];

	for(int i=0;i<n;i++)
		cin>>arr[i];
	cout<<"Max Sum is "<<maxSumSubArray(arr,n);
}
