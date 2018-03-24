#include<bits/stdc++.h>
using namespace std;

//recursive solution
int min_cost(int **input,int si,int sj,int ei,int ej){

    if(si==ei && sj==ej)
        return input[ei][ej];
    if(si>ei||sj>ej)
        return INT_MAX;

    int option1=min_cost(input,si+1,sj,ei,ej);
    int option2=min_cost(input,si,sj+1,ei,ej);
    int option3=min_cost(input,si+1,sj+1,ei,ej);
    return input[si][sj]+min(option1,min(option2,option3));
}

//dynamic approach
int min_costDynamic(int **input,int si,int sj,int ei,int ej,int **output){

    if(si==ei && sj==ej)
        return input[ei][ej];
    if(si>ei||sj>ej)
        return INT_MAX;

     if(output[si][sj]>-1)
            return input[si][sj];
    int option1=min_cost(input,si+1,sj,ei,ej);
    int option2=min_cost(input,si,sj+1,ei,ej);
    int option3=min_cost(input,si+1,sj+1,ei,ej);
    output[si][sj]=input[si][sj]+min(option1,min(option2,option3));
    return input[si][sj]+min(option1,min(option2,option3));
}

//iterative way
// m and n are the rows and columns of the input array
int min_costIterative(int **input,int m ,int n){

    int **dp=new int*[m];
    for(int i=0;i<m;i++)
        dp[i]=new int[n];
    //here we start from the bottom to fill the dp array
    //which has the cost at each step
    //at dp[0][0] the ans is presnt
    //thus at last position the dp array will have same entry as the input array

    dp[m-1][n-1]=input[m-1][n-1];

    //last row of the dp array will have values starting from the bottom
    //each value is the sum of the previous one below it so we add the values
    // as we keep moving upwards
    for(int i=m-2;i>=0;i--){
        dp[i][n-1]=dp[i+1][n-1]+input[i][n-1];
    }

    //simalrly for the last row also
    for(int i=n-2;i>=0;i--){
        dp[m-1][i]=dp[m-1][i+1]+input[m-1][i];
    }

    for(int i=m-2;i>=0;i--){
        for(int j=n-2;j>=0;j--){
            dp[i][j]=input[i][j]+min(dp[i+1][j+1],min(dp[i][j+1],dp[i+1][j]));
    }
    }
return dp[0][0];
}



int main() {
	int ** input = new int*[3];
	input[0] = new int[3];
	input[1] = new int[3];
	input[2] = new int[3];
	input[0][0] = 4;
	input[0][1] = 3;
	input[0][2] = 2;
	input[1][0] = 1;
	input[1][1] = 8;
	input[1][2] = 3;
	input[2][0] = 1;
	input[2][1] = 1;
	input[2][2] = 8;

	cout << min_cost(input, 0,0,2,2) << endl;
	cout << min_costIterative(input,3,3) << endl;
	delete [] input[0];
	delete [] input[1];
	delete [] input[2];
	delete [] input;
}
