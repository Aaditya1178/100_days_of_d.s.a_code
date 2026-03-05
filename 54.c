#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Node {
    int data;
    struct Node* next;
};

bool removeLoop(struct Node* head) {
    struct Node *slow = head, *fast = head;

    // Detect cycle
    while(fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;

        if(slow == fast) {
            // Cycle detected
            slow = head;

            // Find start of loop
            if(slow == fast) {
                while(fast->next != slow)
                    fast = fast->next;
            } else {
                while(slow->next != fast->next) {
                    slow = slow->next;
                    fast = fast->next;
                }
            }

            // Break the loop
            fast->next = NULL;
            return true;
        }
    }

    return false; // No cycle
}