#pragma once
#include "process.h"

struct queue;
typedef struct queue Queue;

struct queue {
    Process* front;
    Process* rear;
    int* size;
};

Queue* createQueue(unsigned capacity);

void enqueue(struct Queue* queue);

int dequeue(struct Queue* queue);
