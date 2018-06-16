#include<bits/stdc++.h>

using namespace std;


int lcsI(char* s1,char* s2){


    int m = strlen(s1);
	int n = strlen(s2);
	int **dp= new int*[m+1];
    for(int i=0;i<m+1;i++)
    dp[i]= new int[n+1];

    //Now we fill the first row and the column of the dp array
    for(int i=0;i<m+1;i++)
        dp[i][n]=0;
    for(int i=0;i<n+1;i++)
        dp[m][i]=0;

    for(int i=1;i<m+1;i++){
        for(int j=1;j<n+1;j++){
                //Note we are comparing the ith and jth characters from the end
                //i.e we remove the m-i and n-j characters
            if(s1[m-i]==s2[n-j])
                dp[i][j]=1+dp[i-1][j-1];
            else
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
        }
    }
    int ans = dp[m][n];
    return ans;
}


int lcsHelper(string s1 , string s2 , int m ,int n,int **dp){

    if(m==0||n==0)
        return 0;

    if(dp[m][n]>-1)
        return dp[m][n];
    int ans=0;
    if(s1.at(0)==s2.at(0)){
        ans=1+lcsHelper(s1.substr(1,m),s2.substr(1,n),m-1,n-1,dp);
    }
    else{
        int option1 = lcsHelper(s1.substr(1,m),s2,m-1,n,dp)	;
        int option2 = lcsHelper(s1,s2.substr(1,n),m,n-1,dp)	;
        ans=max(option1,option2);
    }
    dp[m][n]=ans;

    return ans;

}

int lcs(string s1,string s2){


	int m = s1.length();
	int n= s2.length();
	int **dp= new int*[m+1];

   for(int i=0;i<m+1;i++){
		dp[i]= new int[n+1];
	for(int j=0;j<n+1;j++){
		dp[i][j]=-1;
	}
}
int ans= lcsHelper(s1,s2,m,n,dp);
return ans;

}
int main(){

string s1,s2;

cin>>s1;
cin>>s2;
cout<<"\n"<<lcs(s1,s2);

//cout<<"\n"<<lcsI(s1,s2);
}



