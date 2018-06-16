#include<bits/stdc++.h>

using namespace std;

int longestString(string str){

    int num=0;
    int j=0;
    int sign = 1;
     if(str=="")
        return num;

    //handling -ve numbers
    char firstchar = str.at(0);
    if(firstchar == '-'){
            sign=-1;
        for(int i=1;i<str.length();i++){
            if (!isdigit(str[i]))
                return -1;
            num = num*10 + str.at(i)-'0';
        }
    }

    else{
    for(int i=0;i<str.length();i++){
        if (!isdigit(str[i]))
                return -1;
        num = num*10 + str.at(i)-'0';

        }
    }
    return num*sign;
}

int main(){

   //  char s[] = "i like this program very much";
    string str=" ";
    //char str2[20];

// char *temp = s;

    cin>>str;
   // cin>>str2;
   cout<<longestString(str);
   //cout<<str;
    //cout<<s;
  getchar();
  return 0;

return 0;
}






