#include <stdio.h>
#include <stdlib.h>

typedef struct Stack
{
    int key;
    char *name;
    int index;
} Stack;

void StartIndex(Stack *stack)
{
    stack->index = 0;
}

void InsertStack(Stack **stack, int *size, int key, char *name)
{
    Stack *temp = *stack;
    int i = temp->index;

    if (i >= *size)
    {
        *size += 1;
        temp = realloc(temp, sizeof(Stack) * (*size));
        *stack = temp;
    }

    temp[i].key = key;
    temp[i].name = name;
    temp->index++;
}
void RemoveStack(Stack *stack,int *size)
{
    if (stack->index > 0)
    {
        stack->index--;
        size-=1;
    }
}

void PrintStack(Stack *stack)
{
    int i = stack->index - 1;
    for (; i >= 0; i--)
    {
        printf("%d - %s\n", stack[i].key, stack[i].name);
    }
}

int main()
{
    Stack *stack = malloc(sizeof(Stack));
    int size = 1;

    StartIndex(stack);
    InsertStack(&stack, &size, 143, "diogo");
    InsertStack(&stack, &size, 265, "guilherme");
    InsertStack(&stack, &size, 690, "rodrigo");
    PrintStack(stack);
    RemoveStack(stack,&size);
    printf("\n\n");
    PrintStack(stack);

    free(stack);
    return 0;
}
