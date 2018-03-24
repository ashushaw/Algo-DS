#include<bits/stdc++.h>

using namespace std;

int dp[1000003];
int a[1000003];
char c[1000004];
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

int t;
cin>>t;
while(t--){
    		cin>>c;
			int n=strlen(c);
			int cnt=0,x,maxi;
    		for(int i=0;i<n;i++){
        			if(c[i]=='R'){
            				a[i]=-1;
            				cnt++;
       	 			}
        			else a[i]=1;
    		}

    		cout<<maxSum(a,n)+cnt;


}
    return 0;
}
