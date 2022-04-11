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


// Obtiene el quantum del proceso en base a la fórmula del enunciado
int get_queue_quantum(int q_value, int priority) {
  int quantum_val;

  quantum_val = q_value * priority;

  return quantum_val;
}

void make_tick_happen(Queue* queue1, Queue* queue2, Queue* queue3) {
  wait_tick_queue(queue1);
  wait_tick_queue(queue2);
  wait_tick_queue(queue3);

  return;
}

void run_fifo(int q, int priority,
              Queue* running, Queue* finished,
              Queue* queue1, Queue* queue2, Queue* queue3) {
  // Necesito saber si hay un proceso corriendo
  // y cuánto le queda
  // TODO: hacer variable global o equiv
  int global_remaining_quantum;

  // Si hay un proceso corriendo, lo obtengo
  if (global_process_is_running)

  if (quantum == 0) {
    quantum = get_quantum(q, priority);
  }

  //TODO: guardar quantum restante en "algún" lugar
  quantum = quantum - 1;

  //TODO: Asignar el tipo de variable al proceso
  if (priority == 2) {
    Process *process = pop(queue1, 0);

  } else {
    Process *process = pop(queue2, 0);
  }

  // Opera un tick en el struct de proceso.
  // Debe restar 1 a s, 1 a w y 1 a los ciclos restantes
  // Debe restarle 1 a los restantes para el prox wait
  proc_tick(*process);
  // Opera un tick en el struct de cola.
  // Debe restar 1 a todos los w y 1 a todos los s
  count_tick(queue1, queue2, queue3);

  // TODO: Revisar que funcione bien al integrar el código
  if (process.is_finished == true) {
    // TODO:push a lista de procesos terminados. Crear lista.
    finished.push(*process);

  } else if (process.s <= 0) {
    process.reset_s();
    process.priority = 2;
    queue1.push(*process, -1);

  } else if (priority == 2){
    process.priority = 1;
    queue2.push(*process, -1);

  } else if (priority == 1) {
    process.priority = 0;
    queue3.push(*process, 0);
  }

  return;
}


void run_sjf() {
  //Si no está corriendo lo reordena.
  if ( ! queue3[0].is_running ) {
    queue3.sort();
  }

  // Opera un tick en el struct de proceso.
  // Debe restar 1 a s, 1 a w y 1 a los ciclos restantes
  // Debe restarle 1 a los restantes para el prox wait
  process.do_stuff();
  // Opera un tick en el struct de cola.
  // Debe restar 1 a todos los w y 1 a todos los s
  wait_tick(queue1, queue2, queue3);

  // TODO: Revisar que funcione bien al integrar el código
  if (process.is_finished == true) {
    // TODO:push a lista de procesos terminados. Crear lista.
    finished.push(*process);

  } else if (process.s <= 0) {
    process.reset_s();

    process.set_ready();
    process.unset_running();

    process.priority = 2;
    queue1.push(*process, -1);

  } else if (priority == 1) {
    process.priority = 0;
    queue3.push(*process, 0);
  }

  return;
}


// Hace pasar un ciclo.
// Retorna falso si no hay más programas en la cola
//FIXME: Si pasa que el CPU no tiene nada que hacer, pero dsps van
// a llegar programas, entonces va a marcar como que terminó.
bool tick(int q, Queue queue1, Queue queue2, Queue queue3) {
  load_programs();

  // TODO: Variable común??
  // TODO: guardar cuenta de ciclos en "algún" lugar
  ciclos ++

  if (queue1.size > 0) {
    run_fifo(int q, 2, queue1, queue2, queue3);

  } else if (queue2.size > 0) {
    run_fifo(int q, 1, queue1, queue2, queue3);

  } else if (queue3.size > 0) {
    run_sjf(queue1, queue2, queue3);

  } else {
    return false;
  }
  //  TODO: Marcar cuál es el que está corriendo

  // TODO: actualizar lista de prioridades en funciónd de S
  //  ... Por las que vuelven a la cola 1
  upd_priority_s(queue3);
  upd_priority_s(queue2);

    return true;
}
