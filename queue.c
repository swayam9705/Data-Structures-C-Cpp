#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

struct Queue {
    int *arr;
    int capacity;
    int front;
    int rear;
    int back;
    int size;
};

struct Queue* createQueue(int cap) {
    struct Queue* q = (struct Queue*)malloc(sizeof(struct Queue));
    if (!q) return NULL;

    q -> arr = (int*)malloc(sizeof(int) * cap);
    q -> capacity = cap;
    q -> front = -1;
    q -> rear = -1;
    q -> size = 0;
    
    return q;
}


int size(struct Queue* q) {
    return q -> size;
}

int isEmpty(struct Queue* q) {
    return q -> size == 0;
}

int isFull(struct Queue* q) {
    return q -> size == q -> capacity;
}

int frontElement(struct Queue* q) {
    if (isEmpty(q)) return INT_MIN;

    return q -> arr[q -> front];
}

int rearElement(struct Queue* q) {
    if (isEmpty(q)) return INT_MIN;

    return q -> arr[q -> rear];
}

void enQueue(struct Queue* q, int val) {
    if (isFull(q)) {
        printf("The queue is full.\n");
        return;
    }

    q -> rear = (q -> rear + 1) % q -> capacity;
    q -> arr[q -> rear] = val;

    if (q -> front == -1) {
        q -> front = q -> rear;
    }
    q -> size++;
}

int deque(struct Queue* q) {
    if (isEmpty(q)) {
        printf("The queue is empty.\n");
        return INT_MIN;
    }

    int val = q -> arr[q -> front];

    if (q -> front == q -> rear) {
        q -> front = -1;
        q -> rear = -1;
    }
    else {
        q -> front = (q -> front + 1) % q -> capacity;
    }
    q -> size--;

    return val;
}

void deleteQueue(struct Queue* q) {
    if (q) {
        if (q -> arr) {
            free(q -> arr);
        }
        free(q);
    }
}

int main() {

    struct Queue* q = createQueue(5);
    enQueue(q, 5);
    enQueue(q, 9);
    enQueue(q, 10);
    printf("The dequeud value is %i\n", deque(q));
    printf("The size of queue is %i\n", size(q));

    return 0;
}