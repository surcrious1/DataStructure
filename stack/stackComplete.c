#include <stdio.h>
#include <malloc.h>

struct Item
{
    int val;
    struct Item* next;
};

struct Stack
{
    struct Item* top;
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

struct Stack* new_stack()
{
    // make new stack
    struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack));
    // initializing
    stack->size = 0;
    stack->top = NULL;
    // return stack 
    return stack;
}

int size(struct Stack* s)
{
    // return stack size
    return s->size;
}

int empty(struct Stack* s)
{
    // if stack is empty return 1 else return 0
    return s->size == 0;
}

int top(struct Stack* s)
{
    // return top of stack 
    if(empty(s))
    {
        return -1;
    } 
    else
    {
        return s->top->val;
    } 
}

void push(struct Stack* s, int val)
{
    // push to stack 
    if(empty(s))
    {
        s->top = new_item(val);
        s->size++;
    }
    else
    {
        struct Item* tmp = s->top;
        s->top = new_item(val);
        s->top->next = tmp;
        s->size++;
    }
}

int pop(struct Stack* s)
{
    // pop and return the value of stack
    if(empty(s))
    {
        return -1;
    }
    else
    {
        struct Item* tmp = s->top;
        int ret_val = tmp->val;
        s->top = s->top->next;
        free(tmp);
        s->size--;
        return ret_val;
    }
}

int main()
{
    struct Stack* s = new_stack();
    int i,n = 5;
    printf("Size, Pushed item\n");
    for(i=0; i<n; i++)
    {
        push(s,i*10);
        printf("%4d, %11d\n",size(s), top(s));
    }
    printf("Size,  Poped item\n");
    while(!empty(s))
    {
        printf("%4d, %11d\n", size(s), pop(s));
    }

    return 0;
}