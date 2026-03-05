#include <stdio.h>

void reverseString(char* s, int sSize) {
    int left = 0, right = sSize - 1;

    while (left < right) {
        char temp = s[left];
        s[left] = s[right];
        s[right] = temp;
        left++;
        right--;
    }
}

int main() {
    int n;
    scanf("%d", &n);

    char s[n];
    for (int i = 0; i < n; i++) {
        scanf(" %c", &s[i]);  // space before %c to skip whitespace
    }

    reverseString(s, n);

    for (int i = 0; i < n; i++) {
        printf("%c ", s[i]);
    }

    return 0;
}