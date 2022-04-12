// T02 IIC2333
// Matías López    y    Luis González
// Nro. 17210674        Nro. 16625439

//Para printear
#include <stdio.h>
//Para booleanos
#include <stdbool.h>
//Para poder hacer fork
#include <unistd.h>

//Importar archivo
#include "debug.h"


// Printea "\n"
void dprint_line() {
  if (DEBUG_MODE) {
    printf("\n");
  }
  return;
}

// Printea "DEBUG: "
void dprint_txt() {
  if (DEBUG_MODE) {
    char *start_color = "\033[33;3;1m";
    char *end_color = "\033[0m";
    printf("%sDEBUG: %s", start_color, end_color);
  }

  return;
}
// Printea "**input"
void dprint_char_xx(char **input) {
  if (DEBUG_MODE) {
    char *start_color = "\033[36;3;1m";
    char *end_color = "\033[0m";
    printf("%s%s%s", start_color, *input, end_color);
  }

  return;
}

// Printea "*input"
void dprint_char_x(char *input) {
  if (DEBUG_MODE) {
    char *start_color = "\033[36;3;1m";
    char *end_color = "\033[0m";
    printf("%s%s%s", start_color, input, end_color);
  }

  return;
}

// Printea "DEBUG: **input\n"
void dprint_txt_char_xx(char **input) {
  if (DEBUG_MODE) {
    char *start_color = "\033[36;3;1m";
    char *end_color = "\033[0m";
    printf("%sDEBUG: %s%s\n", start_color, *input, end_color);
  }

  return;
}

// Printea "DEBUG: *input\n"
void dprint_txt_char_x(char *input) {
  if (DEBUG_MODE) {
    char *start_color = "\033[36;3;1m";
    char *end_color = "\033[0m";
    printf("%sDEBUG: %s%s\n", start_color, input, end_color);
  }

  return;
}

// Printea "pid"
void dprint_pid(pid_t process_id) {
  if (DEBUG_MODE) {
    char *start_color = "\033[36;3;1m";
    char *end_color = "\033[0m";
    printf("%s%d%s", start_color, process_id, end_color);
  }

  return;
}

// Printea "DEBUG: pid\n"
void dprint_txt_pid(pid_t process_id) {
  if (DEBUG_MODE) {
    char *start_color = "\033[36;3;1m";
    char *end_color = "\033[0m";
    printf("%sDEBUG: %d%s\n", start_color, process_id, end_color);
  }

  return;
}

// Printea "input"
void dprint_int(int input) {
  if (DEBUG_MODE) {
    char *start_color = "\033[36;3;1m";
    char *end_color = "\033[0m";
    printf("%s%i%s", start_color, input, end_color);
  }

  return;
}

// Printea "DEBUG: input\n"
void dprint_txt_int(int input) {
  if (DEBUG_MODE) {
    char *start_color = "\033[36;3;1m";
    char *end_color = "\033[0m";
    printf("%sDEBUG: %i%s\n", start_color, input, end_color);
  }

  return;
}

// Printea "input"
void dprint_float(float input) {
  if (DEBUG_MODE) {
    char *start_color = "\033[36;3;1m";
    char *end_color = "\033[0m";
    printf("%s%f%s", start_color, input, end_color);
  }

  return;
}

// Printea "DEBUG: input\n"
void dprint_txt_float(float input) {
  if (DEBUG_MODE) {
    char *start_color = "\033[36;3;1m";
    char *end_color = "\033[0m";
    printf("%sDEBUG: %f%s\n", start_color, input, end_color);
  }

  return;
}
