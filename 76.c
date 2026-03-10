#include <stdio.h>

#define MAX 100000

int* maxSlidingWindow(int nums[], int n, int k, int* returnSize)
{
    static int result[MAX];
    int dq[MAX]; 
    int front = 0, rear = -1;

    *returnSize = n - k + 1;
    int idx = 0;

    for(int i = 0; i < n; i++)
    {
        // Remove indices outside window
        if(front <= rear && dq[front] <= i - k)
            front++;

        // Remove smaller elements from rear
        while(front <= rear && nums[dq[rear]] < nums[i])
            rear--;

        dq[++rear] = i;

        // Window start hone ke baad max store karo
        if(i >= k - 1)
            result[idx++] = nums[dq[front]];
    }

    return result;
}

int main()
{
    int nums[] = {1,3,-1,-3,5,3,6,7};
    int k = 3;
    int n = sizeof(nums)/sizeof(nums[0]);

    int returnSize;

    int* res = maxSlidingWindow(nums, n, k, &returnSize);

    for(int i = 0; i < returnSize; i++)
        printf("%d ", res[i]);

    return 0;
}