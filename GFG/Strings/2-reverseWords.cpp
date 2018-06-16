#include<bits/stdc++.h>

using namespace std;

void reverse(char* begin , char* end){
char temp;
    while(begin<end){
         temp = *begin;
        *begin++ = *end ;
        *end-- = temp;
        //begin++;
        //end--;
    }
}

void wordReverse(char *s){

    char *word_begin = s;
    char *temp =s;

    while(*temp){
            temp++;
        if(*temp=='\0')
            reverse(word_begin,temp-1);

        else if(*temp==' '){
            reverse(word_begin,temp-1);
            word_begin = temp+1;
        }
    }

    reverse(s,temp-1);
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
