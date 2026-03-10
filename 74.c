#include <stdio.h>
#include <stdlib.h>

#define MAX 20000

typedef struct {
    int heap[MAX];
    int size;
    int k;
} KthLargest;

void swap(int *a, int *b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

void heapifyUp(KthLargest *obj, int i)
{
    while(i > 0)
    {
        int parent = (i - 1) / 2;

        if(obj->heap[parent] > obj->heap[i])
        {
            swap(&obj->heap[parent], &obj->heap[i]);
            i = parent;
        }
        else
            break;
    }
}

void heapifyDown(KthLargest *obj, int i)
{
    while(1)
    {
        int left = 2*i + 1;
        int right = 2*i + 2;
        int smallest = i;

        if(left < obj->size && obj->heap[left] < obj->heap[smallest])
            smallest = left;

        if(right < obj->size && obj->heap[right] < obj->heap[smallest])
            smallest = right;

        if(smallest != i)
        {
            swap(&obj->heap[i], &obj->heap[smallest]);
            i = smallest;
        }
        else
            break;
    }
}

void insertHeap(KthLargest *obj, int val)
{
    obj->heap[obj->size] = val;
    obj->size++;

    heapifyUp(obj, obj->size - 1);
}

void removeMin(KthLargest *obj)
{
    obj->heap[0] = obj->heap[obj->size - 1];
    obj->size--;

    heapifyDown(obj, 0);
}

KthLargest* KthLargestCreate(int k, int* nums, int numsSize)
{
    KthLargest* obj = (KthLargest*)malloc(sizeof(KthLargest));

    obj->size = 0;
    obj->k = k;

    for(int i = 0; i < numsSize; i++)
    {
        insertHeap(obj, nums[i]);

        if(obj->size > k)
            removeMin(obj);
    }

    return obj;
}

int add(KthLargest* obj, int val)
{
    insertHeap(obj, val);

    if(obj->size > obj->k)
        removeMin(obj);

    return obj->heap[0];  // kth largest
}

int main()
{
    int nums[] = {4,5,8,2};
    int k = 3;

    KthLargest* obj = KthLargestCreate(k, nums, 4);

    printf("%d\n", add(obj,3));
    printf("%d\n", add(obj,5));
    printf("%d\n", add(obj,10));
    printf("%d\n", add(obj,9));
    printf("%d\n", add(obj,4));

    return 0;
}