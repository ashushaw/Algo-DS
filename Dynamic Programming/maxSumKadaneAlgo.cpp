#include<bits/stdc++.h>

using namespace std;

int maxSum(int *arr,int n){
    int current_sum=0;
    int best_sum=0;
    for(int i=0;i<n;i++){
            //we add the current element to the current_sum
        current_sum=current_sum+arr[i];
    //here we check the value of best_sum at that instant
    //if it kess than the current sum we just update our best sum
    if(best_sum<current_sum)
        best_sum=current_sum;
    //if the current sum has negative value we just make it zero
    //as we dont want the baggage to continue further
    if(current_sum<0)
        current_sum=0;
    }
    return best_sum;
}

int main(){

    int n ;
    cin>>n;
    cout<<"Enter the array";

    int *arr=new int[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cout<<maxSum(arr,n);

}
