#include <stdio.h>

void moveZeroes(int nums[], int n) {
    int k = 0;  // position for next non-zero

    // Move non-zero elements forward
    for (int i = 0; i < n; i++) {
        if (nums[i] != 0) {
            if (i != k) {
                nums[k] = nums[i];
            }
            k++;
        }
    }

    // Fill remaining positions with 0
    while (k < n) {
        nums[k] = 0;
        k++;
    }
}

int main() {
    int n;
    scanf("%d", &n);

    int nums[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &nums[i]);
    }

    moveZeroes(nums, n);

    for (int i = 0; i < n; i++) {
        printf("%d ", nums[i]);
    }

    return 0;
}