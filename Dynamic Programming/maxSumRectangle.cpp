#include<bits/stdc++.h>
#define ROW 4
#define COL 5
using namespace std;


int kadane(int *arr,int n){
    int current_sum=0;
    int best_sum=0;
    for(int i=0;i<n;i++){
            //we add the current element to the current_sum
        current_sum=current_sum+arr[i];
    //here we check the value of best_sum at that instant
    //if it kess than the current sum we just update our best sum
    if(best_sum<current_sum)
        best_sum=current_sum;
    //if the current sum has negative value we just make it zero
    //as we dont want the baggage to continue further
    if(current_sum<0)
        current_sum=0;
    }
    return best_sum;
}

void findMaxSum(int M[][COL])
{
    // Variables to store the final output
    int maxSum = INT_MIN, finalLeft=0, finalRight=0, finalTop=0, finalBottom=0;

    int left=0, right=0, i=0;
    int temp[ROW], sum=INT_MIN, start=0, finish=0;

    // Set the left column
    for (left = 0; left < COL; ++left)
    {
        // Initialize all elements of temp as 0
        memset(temp, 0, sizeof(temp));

        // Set the right column for the left column set by outer loop
        for (right = left; right < COL; ++right)
        {
           // Calculate sum between current left and right for every row 'i'
            for (i = 0; i < ROW; ++i)
                temp[i] += M[i][right];

            // Find the maximum sum subarray in temp[]. The kadane()
            // function also sets values of start and finish.  So 'sum' is
            // sum of rectangle between (start, left) and (finish, right)
            //  which is the maximum sum with boundary columns strictly as
            //  left and right.
            sum = kadane(temp,ROW);

            // Compare sum with maximum sum so far. If sum is more, then
            // update maxSum and other output values
            if (sum > maxSum)
            {
                maxSum = sum;
                finalLeft = left;
                finalRight = right;
                finalTop = start;
                finalBottom = finish;
            }
        }
    }

    // Print final values
    printf("(Top, Left) (%d, %d)\n", finalTop, finalLeft);
    printf("(Bottom, Right) (%d, %d)\n", finalBottom, finalRight);
    printf("Max sum is: %d\n", maxSum);
}

int main()
{
    int M[ROW][COL] = {{1, 2, -1, -4, -20},
                       {-8, -3, 4, 2, 1},
                       {3, 8, 10, 1, 3},
                       {-4, -1, 1, 7, -6}
                      };

    findMaxSum(M);

    return 0;
}
