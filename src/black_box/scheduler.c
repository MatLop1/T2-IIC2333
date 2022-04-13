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



int do_tick(const int* q,
         Queue* not_started_yet,
         Queue* running_queue,
         Queue* finished_queue,
         Queue* queue_p2,
         Queue* queue_p1,
         Queue* queue_p0) {
  // - Sumo uno a la cuenta de ticks
  tick_count ++;

  // 02- Reviso a cual le toca entrar en ese momento
  // 03- Saco a los que entran
  // 04- Los pongo en la cola de esperando
  // 05- Reviso si hay algún proceso en "corriendo"
  // 06- Si hay algún proceso corriendo, lo hago correr.
  // 07- Si no hay proceso corriendo reviso la cola P2
  // 08- Si no hay ninguno corriendo en P2, reviso en la cola P1
  // 09- Si no hay ninguno corriendo en P1, reviso en la cola P0
  //






  return tick_count;

}

