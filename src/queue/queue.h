// T02 IIC2333
// Matías López    y    Luis González
// Nro. 17210674        Nro. 16625439

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
             Process* process);

Process* dequeue(Queue* queue);

Queue* wait_tick_queue(Queue* queue);

Queue* extract_queue_reset(Queue* queue);

void join_queue_reset(Queue* queue1, Queue* queue2);

void kill_queue(Queue* queue);