#include<bits/stdc++.h>

using namespace std;

void removeDupl(char str[]){

    int n= strlen(str);

    sort(str,str+n);

    int pos=0;
    for(int i=0;i<n;i++){
        if(str[i]!=str[i+1]){
            str[pos++] = str[i];
        }
    }

    str[pos]='\0';


}

int main(){

   //  char s[] = "i like this program very much";
    char str[20];
    //char str2[20];

// char *temp = s;

    cin>>str;
   // cin>>str2;
   removeDupl(str);
   cout<<str;
    //cout<<s;
  getchar();
  return 0;

return 0;
}




