#include<bits/stdc++.h>

using namespace std;


void waveSort(int arr[] ,int n){
   /*
    we are making this sort of wave
    \    /\    /\    /
     \  /  \  /  \  /
      \/    \/    \/
    Thus we want even position elements to be less than there right and greater to the element in left
    //we will go only to the even positions*/

    for(int i=0;i<n;i=i+2){
        //checking for the left element
        if( i>0 && arr[i-1]>arr[i])
            swap(arr[i],arr[i-1]);
        //checking the right elemnt
        if(i<=n-2 && arr[i+1]>arr[i])
            swap(arr[i],arr[i+1]);
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

    waveSort(arr,n);
    printArray(arr,n);


return 0;
}

