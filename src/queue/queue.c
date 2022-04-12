// T02 IIC2333
// Matías López  y  Luis González
// Nro. 17210674    Nro. 16625439

#include <stdlib.h>
#include "queue.h"

Queue* createQueue() {
  Queue* queue = malloc(sizeof(Queue));
  queue->size = 0;
  queue->front = NULL;
  queue->rear = NULL;
  return queue;
}

// Agrega un elemento a la cola
void enqueue(Queue* queue, Process* process) {
  Process* tmp = process;

  if (queue->front) {
    queue->rear->next = tmp;
    queue->rear = tmp;

  } else {
    queue->front = tmp;
    queue->rear = tmp;
  }

  queue->size++;
}

// Saca de la cola un proceso que cumple con FIFO
Process* dequeue_fifo(Queue* queue) {
  dprint_txt_char_x("Entro a la función");
  
  dprint_txt_char_x("tmp# = queue[0]");
  Process* tmp1 = queue->front;
  Process* tmp2 = queue->front;
  
  dprint_txt_char_x("Mientras que...");
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

Process* dequeue_normal(Queue* queue) {
  Process* tmp1 = queue->front;
  
  if (tmp1) {
    queue->front = tmp1->next;
    queue->size = queue->size - 1;
    dprint_line(); dprint_txt(); dprint_char_x("Largo de cola: "); dprint_int(queue->size); dprint_line(); dprint_line();

  } else {
    dprint_line(); dprint_txt_char_x("Cola se quedó vacia"); dprint_line();
  }
  
  return tmp1; 
}

// Saca de la cola un proceso que cumple con SFJ, si hay varios es en FIFO
Process* dequeue_sfj(Queue* queue) {
  Process* sfj = queue->front;

  while (sfj && sfj->state==2){
    sfj = sfj->next;
  }

  Process* tmp1 = sfj;
  Process* tmp3 = sfj;
  Process* tmp4 = sfj;

  while (tmp4 && sfj) {
    if (tmp4->pid == tmp3->pid) {
      tmp4 = tmp4->next;

    } else {
      if (tmp4->remaining_cycles < sfj->remaining_cycles && tmp4->state==1) {
        tmp1 = tmp3;
        sfj = tmp4;
      }

      tmp3 = tmp3->next;
      tmp4 = tmp4->next;
    }
  }
  if (sfj) {
    tmp1->next = sfj->next;
    queue->size--;
  }

  return sfj;
}

// genera un tick a todos los elementos de la cola
void wait_tick_queue(Queue* queue) {
  Process* process = queue->front;
  while(process){
    proc_tick(process);
    process = process->next;
  }

  return;
}

// Une queue2 al final de la queue1
void join_queue(Queue* queue1, Queue* queue2){
  if(queue1->rear){
    queue1->rear->next = queue2->front;
  } else {
    queue1->front = queue2->front;
    queue1->rear = queue2->rear;
  }
}

// ingresa todos los procesos que ya completaron su tiempo de envejecimiento en la cola N°2 o N°3 (queue2) a la cola N°1 (queue1)
void join_queue_reset(Queue* queue1, Queue* queue2){
  Queue* new_queue = createQueue();
  Process* tmp1 = queue2->front;
  Process* tmp2 = queue2->front;
  while(tmp2){
    if (tmp1->pid == tmp2->pid){
      if(tmp2->cycles_until_queue_reset == 0){
        tmp2->cycles_until_queue_reset = tmp2->s;
        enqueue(new_queue, tmp2);
        queue2->front = queue2->front->next;
        tmp1 = queue2->front;
        tmp2 = queue2->front;
      } else {
        tmp2 = tmp2->next;
      }
    } else {
      if(tmp2->cycles_until_queue_reset == 0){
        tmp2->cycles_until_queue_reset = tmp2->s;
        enqueue(new_queue, tmp2);
        tmp1->next = tmp2->next;
        tmp2 = tmp2->next;
      } else {
        tmp1 = tmp1->next;
        tmp2 = tmp2->next;
      }
    }
  }

  join_queue(queue1, new_queue);
  free(new_queue);
}

// ingresa todos los procesos que ya completaron su tiempo para iniciar en la cola AUX (queue2) a la cola N°1 (queue1)
void join_queue_start(Queue* queue1, Queue* queue2){
  Queue* new_queue = createQueue();
  Process* tmp1 = queue2->front;
  Process* tmp2 = queue2->front;
  while(tmp2){
    if (tmp1->pid == tmp2->pid){
      if(tmp2->cycles_until_start == 0){
        enqueue(new_queue, tmp2);
        queue2->front = queue2->front->next;
        tmp1 = queue2->front;
        tmp2 = queue2->front;
      } else {
        tmp2 = tmp2->next;
      }
    } else {
      if(tmp2->cycles_until_start == 0){
        enqueue(new_queue, tmp2);
        tmp1->next = tmp2->next;
        tmp2 = tmp2->next;
      } else {
        tmp1 = tmp1->next;
        tmp2 = tmp2->next;
      }
    }
  }

  join_queue(queue1, new_queue);
  free(new_queue);
}
