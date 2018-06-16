#include<bits/stdc++.h>

using namespace std;

void rvereseArray(char arr[], int start, int end)
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
void rightRotate(char arr[], int d)
{
     int n = strlen(arr);
    rvereseArray(arr, 0, n-1);
    rvereseArray(arr, 0, d-1);
    rvereseArray(arr, d, n-1);

}

/*NOTE in left Rotate we first reverse the parts and then reverse the complete array */
void leftRotate(char arr[], int d)
{
    int n = strlen(arr);
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

    char s[20];

    cin.get(s,20);

    int d=0;
    cout<<"\n";
    cin>>d;
    rightRotate(s,d);
   // printArray(arr,n);
    cout<<s;
return 0;
}
