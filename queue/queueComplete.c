#include <stdio.h>
#include <malloc.h>

struct Item
{
    int val;
    struct Item* next;
};

struct Queue
{
    struct Item* front;
    struct Item* rear;
    int size;
};

struct Item* new_item(int val)
{
    // make new item
    struct Item* item = (struct Item*)malloc(sizeof(struct Item)); 
    // initializing
    item -> val = val;
    item -> next = NULL;
    //return item
    return item;
}

struct Queue* new_Queue()
{
    // make new Queue
    struct Queue* queue = (struct Queue*)malloc(sizeof(struct Queue));
    // initializing
    queue->size = 0;
    queue->front = NULL;
    queue->rear = NULL;
    // return Queue 
    return queue;
}

int size(struct Queue* q)
{
    // return Queue size
    return q->size;
}

int empty(struct Queue* q)
{
    // if Queue is empty return 1 else return 0
    return q->size == 0;
}

int front(struct Queue* q)
{
    // return top of Queue 
    if(empty(q))
    {
        return -1;
    } 
    else
    {
        return q->front->val;
    } 
}

void push(struct Queue* q, int val)
{
    // push to Queue 
    if(empty(q))
    {
        q->front = new_item(val);
        q->rear = q->front;
        q->size++;
    }
    else
    {
        q->rear->next = new_item(val);
        q->rear = q->rear->next;
        q->size++;
    }
}

int pop(struct Queue* q)
{
    // pop and return the value of Queue
    if(empty(q))
    {
        return -1;
    }
    else
    {
        int ret_val = q->front->val;
        struct Item* tmp = q->front;
        q->front = q->front->next; 
        q->size--;
        free(tmp);
        return ret_val;
    }
}

int main()
{
    struct Queue* q = new_Queue();
    int i,n = 5;
    printf("Size, Pushed item\n");
    for(i=0; i<n; i++)
    {
        push(q,i*10);
        printf("%4d, %11d\n", size(q), i*10);
    }
    printf("Size,  Poped item\n");
    while(!empty(q))
    {
        printf("%4d, %11d\n", size(q), pop(q));
    }

    return 0;
}