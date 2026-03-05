#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX 10000

int stack[MAX];
int top = -1;

void push(int x) {
    stack[++top] = x;
}

int pop() {
    return stack[top--];
}

int main() {
    int n;
    scanf("%d", &n);

    char token[20];

    for (int i = 0; i < n; i++) {
        scanf("%s", token);

        if (strcmp(token, "+") == 0 ||
            strcmp(token, "-") == 0 ||
            strcmp(token, "*") == 0 ||
            strcmp(token, "/") == 0) {

            int b = pop();
            int a = pop();
            int res;

            if (strcmp(token, "+") == 0) res = a + b;
            else if (strcmp(token, "-") == 0) res = a - b;
            else if (strcmp(token, "*") == 0) res = a * b;
            else res = a / b;

            push(res);
        }
        else {
            push(atoi(token));
        }
    }

    printf("%d\n", pop());

    return 0;
}