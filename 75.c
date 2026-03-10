#include <stdio.h>
#define MAX 100

int deque[MAX];
int front = -1;
int rear = -1;

int empty()
{
    return (front == -1);
}

int size()
{
    if(front == -1)
        return 0;
    return rear - front + 1;
}

void push_front(int value)
{
    if(front == -1)
    {
        front = rear = 0;
        deque[front] = value;
    }
    else if(front > 0)
    {
        front--;
        deque[front] = value;
    }
    else
    {
        printf("Deque Overflow\n");
    }
}

void push_back(int value)
{
    if(front == -1)
    {
        front = rear = 0;
        deque[rear] = value;
    }
    else if(rear < MAX-1)
    {
        rear++;
        deque[rear] = value;
    }
    else
    {
        printf("Deque Overflow\n");
    }
}

void pop_front()
{
    if(empty())
    {
        printf("Deque Underflow\n");
        return;
    }

    printf("Removed: %d\n", deque[front]);

    if(front == rear)
        front = rear = -1;
    else
        front++;
}

void pop_back()
{
    if(empty())
    {
        printf("Deque Underflow\n");
        return;
    }

    printf("Removed: %d\n", deque[rear]);

    if(front == rear)
        front = rear = -1;
    else
        rear--;
}

void getFront()
{
    if(empty())
        printf("Deque Empty\n");
    else
        printf("Front: %d\n", deque[front]);
}

void getBack()
{
    if(empty())
        printf("Deque Empty\n");
    else
        printf("Back: %d\n", deque[rear]);
}

void clear()
{
    front = rear = -1;
}

void display()
{
    if(empty())
    {
        printf("Deque Empty\n");
        return;
    }

    for(int i = front; i <= rear; i++)
        printf("%d ", deque[i]);
    printf("\n");
}

int main()
{
    push_back(10);
    push_back(20);
    push_front(5);

    display();

    getFront();
    getBack();

    pop_front();
    pop_back();

    display();

    printf("Size: %d\n", size());

    return 0;
}