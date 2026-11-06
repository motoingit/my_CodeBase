#include <stdio.h>

#define MAX 100

typedef struct {
    int data[MAX];
    int front;
    int rear;
    int size;
} Queue;

// Initialize queue
void initQueue(Queue *q) {
    q->front = 0;
    q->rear = -1;
    q->size = 0;
}

// Check if empty
int isEmpty(Queue *q) {
    return q->size == 0;
}

// Check if full
int isFull(Queue *q) {
    return q->size == MAX;
}

// Add process to queue
void enqueue(Queue *q, int process) {
    if (isFull(q)) {
        return;
    }

    q->rear = (q->rear + 1) % MAX;
    q->data[q->rear] = process;
    q->size++;
}

// Remove process from queue
int dequeue(Queue *q) {
    if (isEmpty(q)) {
        return -1;
    }

    int process = q->data[q->front];

    q->front = (q->front + 1) % MAX;
    q->size--;

    return process;
}
