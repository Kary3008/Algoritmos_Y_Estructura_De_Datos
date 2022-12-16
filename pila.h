#define MAXSIZE 5
#define true 1
#define false 0

typedef struct stack
{
    int top; 
    elemento S[MAXSIZE];
} stack;

void create(stack *S);
int is_full(stack S);
int is_empty(stack S);

elemento pop(stack *S);
void push(stack *S, elemento e);
void show(stack S);


