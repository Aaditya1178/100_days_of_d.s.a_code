#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

int main() {
    int n, x;
    struct Node *head = NULL, *temp = NULL, *newNode = NULL;

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

    // Make it circular
    if(temp != NULL)
        temp->next = head;

    // Traversal of circular linked list
    if(head != NULL) {
        struct Node *ptr = head;
        do {
            printf("%d ", ptr->data);
            ptr = ptr->next;
        } while(ptr != head);
    }

    return 0;
}