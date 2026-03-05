#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);   // n = arr.size()

    int arr[n];
    long long actualSum = 0;

    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
        actualSum += arr[i];
    }

    long long total = (long long)(n + 1) * (n + 2) / 2;
    long long missing = total - actualSum;

    printf("%lld\n", missing);

    return 0;
}