#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

// Node structure for stack
typedef struct Node {
    int data;
    struct Node* next;
} Node;

Node* top = NULL;

// Push operation
void push(int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = top;
    top = newNode;
}

// Pop operation
int pop() {
    if (top == NULL) {
        printf("Stack Underflow\n");
        exit(1);
    }

    Node* temp = top;
    int value = temp->data;
    top = top->next;
    free(temp);

    return value;
}

// Evaluate postfix expression
int evaluatePostfix(char exp[]) {
    int i = 0;

    while (exp[i] != '\0') {

        // Skip spaces
        if (exp[i] == ' ') {
            i++;
            continue;
        }

        // If operand (digit)
        if (isdigit(exp[i])) {
            int num = 0;

            while (isdigit(exp[i])) {
                num = num * 10 + (exp[i] - '0');
                i++;
            }

            push(num);
            continue;
        }

        // If operator
        int val1 = pop();
        int val2 = pop();

        switch (exp[i]) {
            case '+':
                push(val2 + val1);
                break;
            case '-':
                push(val2 - val1);
                break;
            case '*':
                push(val2 * val1);
                break;
            case '/':
                push(val2 / val1);
                break;
        }

        i++;
    }

    return pop();
}

int main() {
    char expression[100];

    printf("Enter Postfix Expression:\n");
    fgets(expression, sizeof(expression), stdin);

    int result = evaluatePostfix(expression);

    printf("Result = %d\n", result);

    return 0;
}