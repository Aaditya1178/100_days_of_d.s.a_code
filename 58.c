#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* newNode(int val) {
    struct ListNode* node = (struct ListNode*)malloc(sizeof(struct ListNode));
    node->val = val;
    node->next = NULL;
    return node;
}

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    struct ListNode dummy;
    struct ListNode* temp = &dummy;
    dummy.next = NULL;

    int carry = 0;

    while (l1 != NULL || l2 != NULL || carry) {
        int sum = carry;

        if (l1 != NULL) {
            sum += l1->val;
            l1 = l1->next;
        }

        if (l2 != NULL) {
            sum += l2->val;
            l2 = l2->next;
        }

        carry = sum / 10;
        temp->next = newNode(sum % 10);
        temp = temp->next;
    }

    return dummy.next;
}

void printList(struct ListNode* head) {
    while (head != NULL) {
        printf("%d ", head->val);
        head = head->next;
    }
}

int main() {
    // Example: [2,4,3]
    struct ListNode* l1 = newNode(2);
    l1->next = newNode(4);
    l1->next->next = newNode(3);

    // Example: [5,6,4]
    struct ListNode* l2 = newNode(5);
    l2->next = newNode(6);
    l2->next->next = newNode(4);

    struct ListNode* result = addTwoNumbers(l1, l2);

    printList(result);

    return 0;
}