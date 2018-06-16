#include<bits/stdc++.h>

using namespace std;

int length(char input[]) {
    int len = 0;
    for(int i = 0; input[i] != '\0'; i++) {
            len++; }
    return len;
}

void reverse(char input[],int i , int j ){
char temp;
    while(start<end){
         temp = input[i];
        input[i] = input[j] ;
        input[j] = temp;
        i++;
        j--;
    }
}

void wordReverse(input str[]){

    int start =0; end= =;
    for(int i=0;i<str[i]='\0';i++){
        if(str[i]=='\0'){
            end = i-1;
            reverse(str,start,end);
            start=i+1;
        }

    }

    end= i-1;
    reverse(str,start,end);
}

int main(){

     char s[] = "i like this program very much";
     char s[20];
     getline()
 char *temp = s;
 wordReverse(s);
  printf("%s", s);

  getchar();
  return 0;

return 0;
}

