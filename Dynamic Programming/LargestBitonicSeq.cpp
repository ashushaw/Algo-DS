#include <bits/stdc++.h>
using namespace std;

int largestBitonic(int* input,int n){

	int * outputlis = new int[n];
	for (int i = 0; i < n; i++)
      		outputlis[i] = 1;

     //Here we find the LIS from the starting point
	for(int i=1;i<n;i++){

		for(int j=0;j<i;j++){
			if(input[i]>input[j] && outputlis[j]+1>outputlis[i]){
				outputlis[j]=outputlis[j]+1;
			}
		}
	}

    int * outputlds = new int[n];
	for (int i = 0; i < n; i++)
      		outputlds[i] = 1;
    // Here we starting finding the lis from back side of the array i.e ultimately a decreasing seq
    for(int i=n-2;i>0;i--){

		for(int j=n-1;j>i;j--){
			if(input[i]>input[j] && outputlds[j]+1>outputlds[i]){
				outputlds[j]=outputlds[j]+1;
			}
		}
	}


	int max = outputlis[0] + outputlds[0] - 1;
   for (int i = 1; i < n; i++)
     if (outputlis[i] + outputlds[i] - 1 > max)
         max = outputlis[i] + outputlds[i] - 1;
   return max;
}
