#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define MAX 10000

char stack[MAX];
int top = -1;

void push(char c) {
    stack[++top] = c;
}

char pop() {
    if (top == -1)
        return '#';
    return stack[top--];
}

bool isValid(char *s) {
    int n = strlen(s);

    for (int i = 0; i < n; i++) {
        char c = s[i];

        if (c == '(' || c == '{' || c == '[') {
            push(c);
        }
        else {
            char t = pop();

            if ((c == ')' && t != '(') ||
                (c == '}' && t != '{') ||
                (c == ']' && t != '[')) {
                return false;
            }
        }
    }

    return top == -1;
}

int main() {
    char s[10000];

    scanf("%s", s);

    if (isValid(s))
        printf("true\n");
    else
        printf("false\n");

    return 0;
}