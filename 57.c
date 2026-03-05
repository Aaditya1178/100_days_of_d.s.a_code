#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

int main() {
    int n, k, x;

    scanf("%d", &n);

    struct Node *head = NULL, *temp = NULL, *newNode;

    // Create linked list
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

    scanf("%d", &k);

    if(head == NULL || k == 0) {
        temp = head;
    } else {
        // Find length and last node
        int length = 1;
        struct Node* tail = head;

        while(tail->next != NULL) {
            tail = tail->next;
            length++;
        }

        k = k % length;

        if(k != 0) {
            // Make circular
            tail->next = head;

            int steps = length - k;
            struct Node* curr = head;

            for(int i = 1; i < steps; i++) {
                curr = curr->next;
            }

            head = curr->next;
            curr->next = NULL;
        }
    }

    // Print rotated list
    temp = head;
    while(temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }

    return 0;
}