#include<bits/stdc++.h>

using namespace std;

int main(){

    int input[1001];
    int num=0;
    int n=0;
    cin>>n;
    int k=0;
    cin>>k;
    int x=0;
     cin>>x;

     for(int i=0;i<1001;i++){
            input[i]=0;
    }

    for(int i=0;i<n;i++){
            cin>>num;
            input[num]++;
    }
    //sort(input,input+n);

/*
     for(int i=0;i<1001;i++){
            cout<<input[i]<<"\n";
    }
*/
    int ans[1001];
    int count=0;

    for(int j=0;j<k;j++){
        sort(begin(input),end(input));
        cout<<"hello";
            for(int i=0;i<1025;i++){
                    if(i%2==0){

                        int y = input[i]^x;
                        cout<<"y is "<<y<<"\n";
                        input[y]+=i;
                        //count=input[i]/2;
                        //cout<<"\ncount\t"<<count;
                    }
                //else
                  //  count =(input[i]/2)+1;
                    //int y = input[i]^x;
                    //cout<<"\ny\t"<<y;
                    //input[y]+=count;
            }
    }

    for(int i=0;i<1025;i++){
        cout<<"\n"<<input[i];
    }
     int min, max;
  min = max = input[0];

   for (int i = 0; i < 1001; ++i) {
    if (min > input[i]) {
      min = input[i];
    }

    if (max < input[i]) {
      max = input[i];
    }
  }

  cout << max << " " << min << endl;
  return 0;

}
