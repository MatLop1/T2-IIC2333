#pragma once
#include "../process/process.h"

struct queue;
typedef struct queue Queue;

struct queue {
    Process* front;
    Process* rear;
    int* size;
    };

Queue* createQueue();

void enqueue(Queue* queue, Process* process);

Process* dequeue(Queue* queue);

Queue* wait_tick_queue(Queue* queue);
