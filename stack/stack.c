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

    // initializing

    //return item

}

struct Stack* new_stack()
{
    // make new stack

    // initializing

    // return stack 

}

int size(struct Stack* s)
{
    // return stack size

}

int empty(struct Stack* s)
{
    // if stack is empty return 1 else return 0

}

int top(struct Stack* s)
{
    // return top of stack 
    
}

void push(struct Stack* s, int val)
{
    // push to stack 
    
}

int pop(struct Stack* s)
{
    // pop and return the value of stack
    
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