// T02 IIC2333
// Matías López    y    Luis González
// Nro. 17210674        Nro. 16625439

#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include "scheduler.h"

struct scheduler;
typedef struct scheduler Scheduler;

Scheduler* createScheduler() {
  Scheduler* scheduler = malloc(sizeof(Scheduler));
  
  scheduler->not_started_yet = createQueue();
  scheduler->running_queue = createQueue();
  scheduler->finished_queue = createQueue();
  scheduler->queue_p2 = createQueue();
  scheduler->queue_p1 = createQueue();
  scheduler->queue_p0 = createQueue();
  
  scheduler->quantum = 0;
};

// add process to scheduler
void add_process(Scheduler* scheduler, Process* process){
  enqueue(scheduler->not_started_yet, process);
}

// check if there are pending processes
int run_scheduler(Scheduler* scheduler){
  return scheduler->not_started_yet->size +
         scheduler->running_queue->size +
         scheduler->queue_p2->size +
         scheduler->queue_p1->size +
         scheduler->queue_p0->size;
}

void finish_cpu_process(Scheduler* scheduler){
  Process* process = dequeue_normal(scheduler->running_queue);
  if (process && process->remaining_cycles == 0){
    enqueue(scheduler->finished_queue, process);
  } else if (process->priority == 2){
    process->priority = 1;
    enqueue(scheduler->queue_p1, process);
  } else if (process->priority == 1) {
    process->priority = 0;
    enqueue(scheduler->queue_p0, process);
  }
}

void add_next_process_cpu(Scheduler* scheduler, int q_value){
  Process* process;
  process = dequeue_fifo(scheduler->queue_p2);
  if(process){
    enqueue(scheduler->running_queue, process);
    scheduler->quantum = q_value*2;
  } else {
    process = dequeue_fifo(scheduler->queue_p1);
    if(process){
      enqueue(scheduler->running_queue, process);
      scheduler->quantum = q_value*1;
    } else {
      process = dequeue_sfj(scheduler->queue_p0);
      if(process){
        enqueue(scheduler->running_queue, process);
        scheduler->quantum = process->remaining_cycles;
      }
    }
  }
}

void start_first_time(Scheduler* scheduler){
  join_queue_start(scheduler->queue_p2, scheduler->not_started_yet);
}

void restart_agging(Scheduler* scheduler){
  join_queue_reset(scheduler->queue_p2, scheduler->queue_p1);
  join_queue_reset(scheduler->queue_p2, scheduler->queue_p0);
}

// Retorna falso si no hay más programas en la cola
void tick(Scheduler* scheduler, int q_value) {
  start_first_time(scheduler);
  restart_agging(scheduler);
  if(scheduler->quantum == 0){ 
    finish_cpu_process(scheduler);
    add_next_process_cpu(scheduler);
  } else {

  }
}

void free_queue(Queue* queue) {
  int queue_size = queue->size;
  for (int i = 0; i < queue_size; ++i) {
    Process* process = dequeue_normal(queue);
    if(process){
      free(process);
    }
  }
  free(queue);
}

void destroy_scheduler(Scheduler* scheduler){
  free_queue(scheduler->not_started_yet);
  free_queue(scheduler->running_queue);
  free_queue(scheduler->finished_queue);
  free_queue(scheduler->queue_p2);
  free_queue(scheduler->queue_p1);
  free_queue(scheduler->queue_p0);
}
