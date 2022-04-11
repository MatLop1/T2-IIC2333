// T01 IIC2333
// Matías López    y    Luis González
// Nro. ########        Nro. 16625439

//Para printear
#include <stdio.h>
//Para booleanos
#include <stdbool.h>
//Para poder hacer fork
#include <unistd.h>

//Importar archivo
#include "debug.h"

//bool DEBUG_MODE = true;

/*
hello: Este comando crea un nuevo proceso, distinto al de la
shell que imprime en la consola el string 'Hello World!'.
*/
void dprint2(char **input) {
  if (DEBUG_MODE) {
    char *start_color = "\033[34;3;1m";
    char *end_color = "\033[0m";
    printf("%sDEBUG: %s%s\n", start_color, *input, end_color);
  }
  return;
}

void dprint3(char *input) {
  if (DEBUG_MODE) {
    char *start_color = "\033[31;3;1m";
    char *end_color = "\033[0m";
    printf("%sDEBUG: %s%s\n", start_color, input, end_color);
  }

  return;
}

void dprint1(char *input) {
  if (DEBUG_MODE) {
    char *start_color = "\033[36;3;1m";
    char *end_color = "\033[0m";
    printf("%sDEBUG: %s%s\n", start_color, input, end_color);
  }

  return;
}

void dprint_pid(pid_t process_id) {
  if (DEBUG_MODE) {
    char *start_color = "\033[35;3;1m";
    char *end_color = "\033[0m";
    printf("%sDEBUG: %d%s\n", start_color, process_id, end_color);
  }
  return;
}

void dprint_int(int input) {
  if (DEBUG_MODE) {
    char *start_color = "\033[37;3;1m";
    char *end_color = "\033[0m";
    printf("%sDEBUG: %i%s\n", start_color, input, end_color);
  }
  return;
}

void dprint_float(float input) {
  if (DEBUG_MODE) {
    char *start_color = "\033[38;3;1m";
    char *end_color = "\033[0m";
    printf("%sDEBUG: %f%s\n", start_color, input, end_color);
  }
  return;
}