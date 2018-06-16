#include<bits/stdc++.h>

using namespace std;

int preProcess(){



}


void highestOccurChar(char str[]){

    char output[20];
    char currentChar = str[0];
    int nextIndex=1;
    int count=1;
   for(int i=1;str[i]!='\0';i++){

    if(str[i]==currentChar)
    {


        count++;}

    else{
        if(count>1){
            str[nextIndex++]=char(count+48);
        }
        currentChar=str[i];
        str[nextIndex++]=str[i];
        count=1;
    }
}
    if(count>1)
        str[nextIndex++]=char(count+48);
    str[nextIndex]='\0';
}

int main(){

   //  char s[] = "i like this program very much";
    char s[20];

// char *temp = s;

    cin>>s;
    cout<<s<<"\n";
    highestOccurChar(s);
    cout<<s;
  getchar();
  return 0;

return 0;
}



