#include<bits/stdc++.h>

using namespace std;

//n is final sum of money we want
//Recursive Approach
int coin_change(int n , int *denominations,int numD){
    if(n==0)
        return 1;

    if(n<0)
        return 0;

    if(numD==0)
        return 0;
    //in this case we include the denomination
    int first_change=coin_change(n-denominations[0],denominations,numD);
    //in this case we donot include include the denomination thus access the array denominations+1 and the numD also will decrease.
    int second_change=coin_change(n,denominations+1,numD-1);

    return first_change+second_change;
}
//Here we see for Dynamic Approach we need to store n and numD as they are getting repeated
//thus we use a 2d-Array to store n and numD
int coin_change(int n , int *denominations,int numD,int **output){
    if(n==0)
        return 1;

    if(n<0)
        return 0;

    if(numD==0)
        return 0;

     //we check if already a value for that iteration we just return the value from the 2-D array
     // by default the 2-D array will have -ve values
     if(output[n][numD]>-1)
            return output[n][numD];

    //in this case we include the denomination
    int first_change=coin_change(n-denominations[0],denominations,numD);
    //in this case we donot include include the denomination thus access the array denominations+1 and the numD also will decrease.
    int second_change=coin_change(n,denominations+1,numD-1);

    //here we store the ans we are getting in the 2-D array
    output[n][numD]=first_change+second_change;
    return first_change+second_change;
}

int main(){

    int d[2]={1,2};
//Declaration of the 2-D output array
/*
    int **output= new int*[value+1];
for(int i = 0; i < value+1; ++i)
      output[i] = new int[numDenominations+1];

  for(int i = 0; i < value+1; ++i){
    for(int j = 0; j < numDenominations+1; ++j){
          output[i][j]=-1;
*/
    cout<<coin_change(4,d,2,output);
return 0;
}
