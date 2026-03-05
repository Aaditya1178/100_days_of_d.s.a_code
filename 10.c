#include <stdio.h>

void merge(int nums1[], int m, int nums2[], int n) {
    int i = m - 1;        // Last element in nums1
    int j = n - 1;        // Last element in nums2
    int k = m + n - 1;    // Last index of nums1

    // Merge from the end
    while (i >= 0 && j >= 0) {
        if (nums1[i] > nums2[j]) {
            nums1[k] = nums1[i];
            i--;
        } else {
            nums1[k] = nums2[j];
            j--;
        }
        k--;
    }

    // Copy remaining elements of nums2 (if any)
    while (j >= 0) {
        nums1[k] = nums2[j];
        j--;
        k--;
    }
}

int main() {
    int m, n;
    scanf("%d %d", &m, &n);

    int nums1[m + n];
    int nums2[n];

    for (int i = 0; i < m + n; i++) {
        scanf("%d", &nums1[i]);
    }

    for (int i = 0; i < n; i++) {
        scanf("%d", &nums2[i]);
    }

    merge(nums1, m, nums2, n);

    // Print merged array
    for (int i = 0; i < m + n; i++) {
        printf("%d ", nums1[i]);
    }

    return 0;
}