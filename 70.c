#include <stdio.h>
#include <stdbool.h>

#define MAX 100

// Stack structure
typedef struct {
    int arr[MAX];
    int top;
} Stack;

// Initialize stack
void init(Stack *s) {
    s->top = -1;
}

bool isEmpty(Stack *s) {
    return s->top == -1;
}

void pushStack(Stack *s, int x) {
    s->arr[++(s->top)] = x;
}

int popStack(Stack *s) {
    return s->arr[(s->top)--];
}

int peekStack(Stack *s) {
    return s->arr[s->top];
}

// Queue using two stacks
typedef struct {
    Stack s1;
    Stack s2;
} MyQueue;

void initQueue(MyQueue *q) {
    init(&q->s1);
    init(&q->s2);
}

// Push element to back
void push(MyQueue *q, int x) {
    pushStack(&q->s1, x);
}

// Transfer elements if needed
void transfer(MyQueue *q) {
    if (isEmpty(&q->s2)) {
        while (!isEmpty(&q->s1)) {
            pushStack(&q->s2, popStack(&q->s1));
        }
    }
}

// Pop front element
int pop(MyQueue *q) {
    transfer(q);
    return popStack(&q->s2);
}

// Peek front element
int peek(MyQueue *q) {
    transfer(q);
    return peekStack(&q->s2);
}

// Check if queue empty
bool empty(MyQueue *q) {
    return isEmpty(&q->s1) && isEmpty(&q->s2);
}

int main() {
    MyQueue q;
    initQueue(&q);

    push(&q, 1);
    push(&q, 2);

    printf("%d\n", peek(&q));   // 1
    printf("%d\n", pop(&q));    // 1
    printf("%s\n", empty(&q) ? "true" : "false"); // false

    return 0;
}