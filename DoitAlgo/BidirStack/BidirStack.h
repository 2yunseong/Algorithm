#ifndef __BidirStack
#define __BidirStack

typedef struct {
    int front_ptr;
    int rear_ptr;
    int max;
    int *stk;
    int flag;   //front : 0 rear : 1 
} BidirStack;

int Initialize(BidirStack *s, int n);

void ChangeFlag(BidirStack *s);

int IsFlag(const BidirStack *s);

int IsFull(const BidirStack *s);

int IsEmpty(const BidirStack *s);

int Push(BidirStack *s, int data);

int Pop(BidirStack *s, int *x);

int Peek(const BidirStack *s, int *x);

void Clear(BidirStack *s);

int Capacity(const BidirStack *s);

int Size(const BidirStack *s);

int Search(const BidirStack *s, int x);

void Print(const BidirStack *s);

void Terminate(BidirStack *s);

#endif