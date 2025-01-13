#include <stdio.h>
#include <malloc.h>

struct Item
{
    int val;
    struct Item* next;
};

struct Deque
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

struct Deque* new_Deque()
{
    // make new Deque
    
    // initializing
    
    // return Deque 
    
}

int size(struct Deque* dq)
{
    // return Deque size

}

int empty(struct Deque* dq)
{
    // if Deque is empty return 1 else return 0

}

int front(struct Deque* dq)
{
    // return front of Deque 
    
}

void push_front(struct Deque* dq, int val)
{
    // push to Deque 
    
}

int rear(struct Deque* dq)
{

}

void push_rear(struct Deque* dq, int val)
{
    // push to Deque
}

int pop_front(struct Deque* q)
{
    // pop and return the value of Deque
    
}

int pop_rear(struct Deque* q)
{
    // pop and return the value of Deque
    
}

int main()
{
    struct Deque* dq = new_Deque();
    int i,n = 5;
    printf("Push to front\n");
    printf("Size, Pushed item\n");
    for(i=0; i<n; i++)
    {
        push(dq,i*10);
        printf("%4d, %11d\n", size(dq), i*10);
    }
    printf("Push to rear\n");
    printf("Size, Pushed Item\n");
    for(i=n; i>0; i--)
    {
        push(dq,i*10);
        printf("%4d, %11d\n", size(dq), i*10);
    }
    printf("Pop from front\n");
    printf("Size,  Poped item\n");
    while(!empty(dq))
    {
        printf("%4d, %11d\n", size(dq), pop_front(dq));
    }

    return 0;
}