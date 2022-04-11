#include "queue.h"
 
Queue* createQueue()
{
    Queue* queue = (Queue*)malloc(sizeof(Queue));
    queue->size = 0
    queue->front = NULL;
    queue->rear = NULL;
    return queue;
}

void enqueue(Queue* queue, char[32] name, int pid, int start_time, int cycles, int wait, int waiting_delay, int s)
{
    Process* tmp = createProcess(name, pid, start_time, cycles, wait, waiting_delay, s);
    if(!queue->front){
        queue->rear->next = tmp;
        queue->rear = tmp;
    } else {
        queue->front = tmp;
        queue->rear = tmp;
    }
    queue->size++;
}

Process* dequeue(Queue* queue)
{
    Process* tmp = queue->front;
    queue->front = queue->front->next;
    queue->size--;
    return tmp;
}
