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

#include "black_magic.h"

//Colas:
#include "../queue/queue.h"
//#include "../queue/queue_1.h"
//#include "../queue/queue_2.h"
//#include "../queue/queue_3.h"


// Obtiene el quantum del proceso en base a la fórmula del enunciado
int get_quantum(int q_value, int priority) {  //
  int quantum_val;

  quantum_val = q_value * priority;

  return quantum_val;
}

void run_fifo(int q, int priority, Queue queue1, Queue queue2, Queue queue3) {
  int quantum = get_quantum(q, priority)
  //TODO: guardar quantum restante en "algún" lugar

  // TODO: Asignar el tipo de variable al proceso
  if (priority == 2) {
    Process *process = queue1.pop(0);

  } else {
    Process *process = queue2.pop(0);
  }

  process.do_stuff()


}

// Hace pasar un ciclo.
// Retorna falso si no hay más programas en la cola
//FIXME: Si pasa que el CPU no tiene nada que hacer, pero dsps van
// a llegar programas, entonces va a marcar como que terminó.
bool tick(int q, Queue queue1, Queue queue2, Queue queue3) {
  load_programs()

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

  return true;
}
