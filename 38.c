#include <stdio.h>

int maxSubarraySumCircular(int nums[], int n) {
    int total = 0;

    int max_sum = nums[0], cur_max = 0;
    int min_sum = nums[0], cur_min = 0;

    for(int i = 0; i < n; i++) {
        total += nums[i];

        // Kadane for maximum subarray
        cur_max = (cur_max + nums[i] > nums[i]) ? cur_max + nums[i] : nums[i];
        max_sum = (max_sum > cur_max) ? max_sum : cur_max;

        // Kadane for minimum subarray
        cur_min = (cur_min + nums[i] < nums[i]) ? cur_min + nums[i] : nums[i];
        min_sum = (min_sum < cur_min) ? min_sum : cur_min;
    }

    // If all elements are negative
    if(max_sum < 0)
        return max_sum;

    int circular = total - min_sum;

    return (max_sum > circular) ? max_sum : circular;
}

int main() {
    int nums[] = {5, -3, 5};
    int n = sizeof(nums) / sizeof(nums[0]);

    int result = maxSubarraySumCircular(nums, n);
    printf("Maximum Circular Subarray Sum: %d\n", result);

    return 0;
}