#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Node {
    int data;
    struct Node* next;
};

bool isPalindrome(struct Node* head) {
    int arr[100000];
    int i = 0;

    struct Node* temp = head;

    // Store values in array
    while (temp != NULL) {
        arr[i++] = temp->data;
        temp = temp->next;
    }

    // Check palindrome
    int start = 0, end = i - 1;
    while (start < end) {
        if (arr[start] != arr[end])
            return false;
        start++;
        end--;
    }

    return true;
}

int main() {
    int n, x;
    struct Node *head = NULL, *temp = NULL, *newNode;

    scanf("%d", &n);

    for(int i = 0; i < n; i++) {
        scanf("%d", &x);

        newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->data = x;
        newNode->next = NULL;

        if(head == NULL) {
            head = newNode;
            temp = head;
        } else {
            temp->next = newNode;
            temp = newNode;
        }
    }

    if(isPalindrome(head))
        printf("true");
    else
        printf("false");

    return 0;
}