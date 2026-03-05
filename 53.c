#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node* createList(int n) {
    struct Node *head = NULL, *temp = NULL, *newNode;
    int x;

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

    return head;
}

int getLength(struct Node *head) {
    int len = 0;
    while(head != NULL) {
        len++;
        head = head->next;
    }
    return len;
}

int findIntersection(struct Node *head1, struct Node *head2) {
    int len1 = getLength(head1);
    int len2 = getLength(head2);

    int diff;
    struct Node *p1 = head1;
    struct Node *p2 = head2;

    if(len1 > len2) {
        diff = len1 - len2;
        for(int i = 0; i < diff; i++)
            p1 = p1->next;
    } else {
        diff = len2 - len1;
        for(int i = 0; i < diff; i++)
            p2 = p2->next;
    }

    while(p1 != NULL && p2 != NULL) {
        if(p1->data == p2->data)
            return p1->data;

        p1 = p1->next;
        p2 = p2->next;
    }

    return -1;
}

int main() {
    int n, m;

    scanf("%d", &n);
    struct Node *head1 = createList(n);

    scanf("%d", &m);
    struct Node *head2 = createList(m);

    int result = findIntersection(head1, head2);

    if(result == -1)
        printf("No Intersection");
    else
        printf("%d", result);

    return 0;
}