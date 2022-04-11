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

int get_quantum(int q_value, int priority) {  //
  int quantum_val;

  quantum_val = q_value * priority;

  return quantum_val;
}


