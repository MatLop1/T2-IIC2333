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


// Dice si quedan tareas pendientes en la lista.
int remaining_tasks() {
  //  https://www.tutorialspoint.com/cprogramming/c_arrays.htm
  int i;
  int **remaining_per_queue[3];
  Queue **queues = {queue_1, queue_2, queue_3};

  for ( i=0; i<3; i++ ) {
    if ( queues[i].size > 0 )
  }

  return 0;
}

  if (queue1.length == 0) || (queue1.length == 0)
}


void tick() {


  return;
};

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