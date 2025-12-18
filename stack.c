#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

struct Stack {
    int *array;
    int capacity;
    int top;
};

struct Stack* createStack(int cap) {
    struct Stack* newStack = (struct Stack*)malloc(sizeof(struct Stack));

    if (!newStack) return NULL;

    newStack -> array = (int*)malloc(sizeof(int) * cap);
    newStack -> capacity = cap;
    newStack -> top = -1;
    
    return newStack;
}

int isEmpty(struct Stack* stack) {
    return stack -> top == -1;
}

int isFull(struct Stack* stack) {
    return stack -> top == stack -> capacity - 1;
}

int size(struct Stack* stack) {
    return stack -> top + 1;
}

void push(struct Stack* stack, int val) {
    if (isFull(stack)) {
        printf("Stack is full\n");
        return;
    }

    stack -> array[++stack -> top] = val;
}

int pop(struct Stack* stack) {
    if (isEmpty(stack)) {
        printf("The stack is empty.\n");
        return INT_MIN;
    }

    return stack -> array[stack -> top--];
}

int top(struct Stack* stack) {
    if (isEmpty(stack)) {
        return INT_MIN;
    }

    return stack -> array[stack -> top];
}

void deleteStack(struct Stack* stack) {
    if (stack) {
        if (stack -> array) {
            free(stack -> array);
        }
        free(stack);
    }
}

int main() {
    int i = 0, cap = 5;

    struct Stack* myStk = createStack(cap);

    for (int i = 0; i < 2 * cap; i++) {
        push(myStk, i);
    }

    printf("Top element is %i\n", top(myStk));
    printf("Size of stack is %i\n", size(myStk));

    for (int i = 0; i < 3; i++) {
        printf("The poppped element is %i\n", pop(myStk));
    }

    printf("Now the size of stack is %i\n", size(myStk));
}