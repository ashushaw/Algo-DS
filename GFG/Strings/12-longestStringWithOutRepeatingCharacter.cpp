#include<bits/stdc++.h>

using namespace std;

int longestString(char str[]){

    int *visited = (int *)malloc(sizeof(int)*256);
    for(int i=0;i<256;i++)
        visited[i]=-1;
    int prev_idx=0;
    int curr_len = 1;
    int max_len=1;
    visited[str[0]]=0;

    for(int i=1;i<strlen(str);i++){
        prev_idx = visited[str[i]];

        if(prev_idx == -1 || i-curr_len > prev_idx)
            curr_len++;

        else{

            if(curr_len>max_len)
                max_len=curr_len;
            curr_len=i-prev_idx;
        }
        visited[str[i]] = i;
    }

     if (curr_len > max_len)
        max_len = curr_len;


    return max_len;
}

int main(){

   //  char s[] = "i like this program very much";
    char str[20];
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





