#include <stdio.h>

void reverse(int arr[], int start, int end) {
    while (start < end) {
        int temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;
        start++;
        end--;
    }
}

int main() {
    int n, k;
    scanf("%d", &n);

    int nums[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &nums[i]);
    }

    scanf("%d", &k);

    k = k % n;   // handle k > n

    // Step 1: reverse whole array
    reverse(nums, 0, n - 1);

    // Step 2: reverse first k elements
    reverse(nums, 0, k - 1);

    // Step 3: reverse remaining elements
    reverse(nums, k, n - 1);

    // Print result
    for (int i = 0; i < n; i++) {
        printf("%d ", nums[i]);
    }

    return 0;
}