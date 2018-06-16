#include<bits/stdc++.h>

using namespace std;


void zigZag(int arr[] ,int n){
   /*
    we are making this sort of wave
         b
        /\    /\    /\
       /  \  /  \  /  \
      /    \/    \/    \
      a     c

      we want a < b > c
    Thus we want even position elements to be less than there right and greater to the element in left
    //we will go only to the even positions*/
    bool flag = true; //at true we want arr[i]<arr[i+1]

    for(int i=0;i<n-1;i++){

        if(flag){
            if(arr[i]>arr[i+1])
                swap(arr[i],arr[i+1]);
        }
        else{ //this when flag is false
            // at flag false we have the condition arr[i]>arr[i+1]
            if(arr[i+1]>arr[i])
                swap(arr[i],arr[i+1]);
        }
        /*we toggle he flag so that we have zig zag pattern*/
        flag=!flag;
    }
}
void printArray(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    cout << arr[i] << " ";
}

int main(){
int n;
cin>>n;
    int arr[n];

    for(int i=0;i<n;i++)
        cin>>arr[i];

    zigZag(arr,n);
    printArray(arr,n);


return 0;
}

