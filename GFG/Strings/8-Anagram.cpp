#include<bits/stdc++.h>

using namespace std;

bool anagram(char str1[],char str2[]){

    int n1= strlen(str1);
    int n2= strlen(str2);
    if(n1!=n2)
        return false;
    sort(str1,str1+n1);
    sort(str2,str2+n2);

    for(int i=0;i<n1;i++){
        if(str1[i]!=str2[i])
            return false;
    }
    return true;
}

int main(){

   //  char s[] = "i like this program very much";
    char str1[20];
    char str2[20];

// char *temp = s;

    cin>>str1;
    cin>>str2;
    if(anagram(str1,str2))
        cout<<"YES";
    else
        cout<<"NO";
    //cout<<s;
  getchar();
  return 0;

return 0;
}




