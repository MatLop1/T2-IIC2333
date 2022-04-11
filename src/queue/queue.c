// T02 IIC2333
// Matías López    y    Luis González
// Nro. 17210674        Nro. 16625439

#include <stdlib.h>
#include "queue.h"

Queue* createQueue() {
    Queue* queue = malloc(sizeof(Queue));
    queue->size = 0;
    queue->front = NULL;
    queue->rear = NULL;
    return queue;
}

void enqueue(Queue* queue, Process* process) {
    Process* tmp = process;
    if (!queue->front){
        queue->rear->next = tmp;
        queue->rear = tmp;

    } else {
        queue->front = tmp;
        queue->rear = tmp;
    }

    queue->size++;
}

Process* dequeue_fifo(Queue* queue) {
    Process* tmp1 = queue->front;
    Process* tmp2 = queue->front;

    while (tmp2 && tmp2->state==2) {
        if (tmp1->pid == tmp2->pid) {
            tmp2 = tmp2->next;

        } else {
            tmp1 = tmp1->next;
            tmp2 = tmp2->next;
        }
    }

    if (tmp2) {
        tmp1->next = tmp2->next;
        queue->size--;
    }

    return tmp2;
}

Process* dequeue_sfj(Queue* queue) {
    Process* sfj = queue->front;
    
    while (sfj && sfj->state==2){
        sfj = sfj->next;
    }
    
    Process* tmp1 = sfj;
    Process* tmp2 = sfj;
    Process* tmp3 = sfj;
    Process* tmp4 = sfj;

    while (tmp4 && sfj) {
        if (tmp4->pid == tmp3->pid) {
            tmp4 = tmp4->next;

        } else {
            if (tmp4->remaining_cycles < sfj->remaining_cycles && tmp4->state==1) {
                tmp1 = tmp3;
                tmp2 = tmp4;
                sfj = tmp4;
            }

            tmp3 = tmp3->next;
            tmp4 = tmp4->next;
        }
    }

    if (sfj) {
        tmp1->next = tmp2->next;
        queue->size--;
    }

    return sfj;
}

Queue* wait_tick_queue(Queue* queue) {
  // TODO:
  //  for process in queue:
  //      proc_tick(process)
  return queue;
}

Process* pop(Queue* queue, int pos) {
  // 0 por defecto --> Saca el primero
  // TODO
  return process;
}

void push(Queue* queue, int pos) {
  // -1 por defecto --> Lo pone al final
  // TODO
}




