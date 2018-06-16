#include<bits/stdc++.h>

using namespace std;

int preProcess(){



}


char highestOccurChar(char str[]){
    int freq[256]={0};
   int index[256]={-1};

   for(int i=0;i!='\0';i++){
        int j = str[i];
        freq[j]++;
        if(index[j]==-1)
            index[j]=i;
   }

   int max_occuring_idx=0;
   for(int i=0;i<256;i++){
        if(freq[i]>freq[max_occuring_idx]){
            max_occuring_idx=i;
   }
   else if(freq[i]==freq[max_occuring_idx]){
        if(index[i]<index[max_occuring_idx]){
            max_occuring_idx=i;
        }
   }
   }
return (char)max_occuring_idx;
}

int main(){

   //  char s[] = "i like this program very much";
    char s[20];

// char *temp = s;

    cin>>s;
    cout<<s;
    cout<<highestOccurChar(s);
  getchar();
  return 0;

return 0;
}


