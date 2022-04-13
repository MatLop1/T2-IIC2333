// T02 IIC2333
// Matías López    y    Luis González
// Nro. 17210674        Nro. 16625439

//Para printear
// FILE, fopen, fclose, etc.
#include <stdio.h>
//Para comparar strings
#include <string.h>
//Para booleanos
#include <stdbool.h>
//Uso de memoria/heap
// malloc, calloc, free, etc
#include <stdlib.h>
//Para concatenar strings
#include <string.h>
//Para poder hacer fork
#include <unistd.h>

//A sí mismo
#include "scheduler.h"


int tick_count = 0;


void make_tick_happen(Queue* not_started_yet,
                      Queue* running_queue,
                      Queue* queue_p2,
                      Queue* queue_p1,
                      Queue* queue_p0) {
  wait_tick_queue(not_started_yet);
  wait_tick_queue(running_queue);
  wait_tick_queue(queue_p2);
  wait_tick_queue(queue_p1);
  wait_tick_queue(queue_p0);

  return;
}



int tick(const int* q,
         Queue* not_started_yet,
         Queue* running_queue,
         Queue* finished_queue,
         Queue* queue_p2,
         Queue* queue_p1,
         Queue* queue_p0) {
  // 01- Sumo uno a la cuenta de ticks
  dprint_txt_char_x("Nuevo tick");
  tick_count ++;

  // 02- Reviso a cuál le toca entrar en ese momento
  Process* new_proc;
  bool check_again = true;

  dprint_txt_char_x("Reviso si hay que agregar procesos a la cola");
  if (not_started_yet->size > 0) {
    dprint_txt_char_x("Hay procesos pendientes");
    while (check_again) {
      new_proc = dequeue_normal(not_started_yet);

      if (new_proc->start_time <= tick_count) {
        dprint_txt_char_x("Agregando un proceso a la cola de prioridad 2");
        start_first_time(new_proc);
        enqueue(queue_p2, new_proc);

      } else {
        dprint_txt_char_x("No hay procesos que agregar en este momento");
        enqueue(not_started_yet, new_proc);
        check_again = false;
      }
    }
  }

  Process* current_proc;

  // 05- Reviso si hay algún proceso en "corriendo"
  if ( running_queue->size ) {
    current_proc = dequeue_normal(running_queue);
  } else if ( queue_p2->size ) {
    // 07- Si no hay proceso corriendo reviso la cola P2
    current_proc = dequeue_normal(queue_p2);
  } else if ( queue_p1->size ) {
    current_proc = dequeue_normal(queue_p1);
  } else {
    current_proc = dequeue_normal(queue_p0);
  }

  // 06- Hago pasar un ciclo.
  proc_tick(current_proc);
  make_tick_happen(not_started_yet,
                   running_queue,
                   queue_p2,
                   queue_p1,
                   queue_p0);




    // 08- Si no hay ninguno corriendo en P2, reviso en la cola P1
    // 09- Si no hay ninguno corriendo en P1, reviso en la cola P0




    return tick_count;


}

