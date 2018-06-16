#include<bits/stdc++.h>

using namespace std;

int my_strstr(string s , string x){

    int n = s.length();
    int i=0 , j=0;
    while(i!=n){

    int start =0,end=0;
    while(i!=n && j!=x.length() && s.at(i)==x.at(j)){
            start=i;
            j++;
            i++;
    }
    if(j==x.length())
        return i;
    i++;

    }
    return -1;
}

int main(){

   char str1[20];
    char str2[20];

// char *temp = s;

    cin>>str1;
    cin>>str2;

    cout<<my_strstr(str1,str2);
  getchar();
return 0;
}







