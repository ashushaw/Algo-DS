#include<bits/stdc++.h>

using namespace std;

void rvereseArray(int arr[], int start, int end)
{
    while (start < end)
    {
        int temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;
        start++;
        end--;
    }
}


/*NOTE in right Rotate we first reverse complete array and then reverse the parts*/
void rightRotate(int arr[], int d, int n)
{
    rvereseArray(arr, 0, n-1);
    rvereseArray(arr, 0, d-1);
    rvereseArray(arr, d, n-1);

}

/*NOTE in left Rotate we first reverse the parts and then reverse the complete array */
void leftRotate(int arr[], int d, int n)
{
    rvereseArray(arr, 0, n-1);
    rvereseArray(arr, 0, d-1);
    rvereseArray(arr, d, n-1);

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

    int d=0;
    cout<<"\n";
    cin>>d;
    leftRotate(arr,d,n);
    printArray(arr,n);

return 0;
}
