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

// Hace pasar un ciclo.
// Retorna falso si no hay más programas en la cola
//FIXME: Potencial bug: Si pasa
bool tick(Queue queue1, Queue queue2, Queue queue3) {
  load_programs()

  if (queue1.size > 0) {
    run_fifo(queue1);

  } else if (queue2.size > 0) {
    run_fifo(queue2);

  } else if (queue3.size > 0) {
    run_sjf(queue3);

  } else {
    return false;
  }
  //  TODO: Marcar cuál es el que está corriendo

  return true;
}

while procesos.existen()
checkeo_listas()
0x#### <-- lista#.pop()

checkear_nueva_lista(0x####)
lista[#+1].push() --> 0x####

calculo_tiempo_exec

for tick in t_exec_l#=10:
lista1.procesar_tick()
lista2.procesar_tick()
lista3.procesar_tick()

lista3.pop() <inlcuye sort>