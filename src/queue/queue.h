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
             char name,
             int pid,
             int start_time,
             int cycles,
             int wait,
             int waiting_delay,
             int s);

Process* dequeue(Queue* queue);

Queue* wait_tick_queue(Queue* queue);
Process* pop(Queue* queue, int pos);
void push(Queue* queue, int pos);
