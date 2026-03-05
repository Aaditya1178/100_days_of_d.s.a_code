#include <stdio.h>
#include <stdlib.h>

struct Node {
    int val;
    struct Node* next;
};

struct Node* reverseList(struct Node* head) {
    struct Node *prev = NULL;
    struct Node *curr = head;
    struct Node *next = NULL;

    while(curr != NULL) {
        next = curr->next;   // store next node
        curr->next = prev;   // reverse link
        prev = curr;         // move prev
        curr = next;         // move curr
    }

    return prev; // new head
}

int main() {
    int n, x;
    scanf("%d", &n);

    struct Node *head = NULL, *temp = NULL, *newNode;

    for(int i = 0; i < n; i++) {
        scanf("%d", &x);

        newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->val = x;
        newNode->next = NULL;

        if(head == NULL) {
            head = newNode;
            temp = head;
        } else {
            temp->next = newNode;
            temp = newNode;
        }
    }

    head = reverseList(head);

    temp = head;
    while(temp != NULL) {
        printf("%d ", temp->val);
        temp = temp->next;
    }

    return 0;
}