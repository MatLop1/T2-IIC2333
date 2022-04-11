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

void enqueue(Queue* queue,
             char name,
             int pid,
             int start_time,
             int cycles,
             int wait,
             int waiting_delay,
             int s);

Process* dequeue(Queue* queue);
