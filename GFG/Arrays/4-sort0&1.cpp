

sort01(int arr,int n){

int left=0,right=n-1;

while(left<right){
    while(arr[left]==0 && left<right)
        left++;

    while(arr[right]==1 && left<right)
        right--;

    if(left<right){
        arr[left]=0;
        arr[right]=1;
        left++;
        right--;
    }

}
