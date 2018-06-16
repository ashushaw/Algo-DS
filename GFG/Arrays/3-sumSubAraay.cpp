#include<bits/stdc++.h>
using namespace std;
int maxSumSubArray(int arr[], int size , int sum){

	int curr_sum = arr[0];

    //int k=sum;
    int start=0;
	for(int i=0 ; i < size ;i++){

        while (curr_sum > sum && start < i-1)
        {
            curr_sum = curr_sum - arr[start];
            start++;
        }

        // If curr_sum becomes equal to sum, then return true
        if (curr_sum == sum)
        {
            printf ("Sum found between indexes %d and %d", start, i-1);
            return 1;
        }

        // Add this element to curr_sum
        if (i < n)
          curr_sum = curr_sum + arr[i];
    }
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
