#include <stdio.h>

#define MAX 30000

typedef struct {
    int stack[MAX];
    int minStack[MAX];
    int top;
} MinStack;

void init(MinStack *s) {
    s->top = -1;
}

void push(MinStack *s, int val) {
    s->top++;
    s->stack[s->top] = val;

    if (s->top == 0)
        s->minStack[s->top] = val;
    else {
        if (val < s->minStack[s->top - 1])
            s->minStack[s->top] = val;
        else
            s->minStack[s->top] = s->minStack[s->top - 1];
    }
}

void pop(MinStack *s) {
    if (s->top >= 0)
        s->top--;
}

int top(MinStack *s) {
    return s->stack[s->top];
}

int getMin(MinStack *s) {
    return s->minStack[s->top];
}

int main() {
    MinStack s;
    init(&s);

    push(&s, -2);
    push(&s, 0);
    push(&s, -3);

    printf("%d\n", getMin(&s)); // -3

    pop(&s);

    printf("%d\n", top(&s));    // 0
    printf("%d\n", getMin(&s)); // -2

    return 0;
}