// T02 IIC2333
// Matías López    y    Luis González
// Nro. 17210674        Nro. 16625439

// Compilar sólo una vez
#pragma once

// Constante
#define DEBUG_MODE 1

// Funciones
void dprint_line();
void dprint_txt();

void dprint_str();
void dprint_txt_str();

void dprint_char_xx(char **input);
void dprint_char_x(char *input);
void dprint_txt_char_xx(char **input);
void dprint_txt_char_x(char *input);

void dprint_pid(pid_t process_id);
void dprint_txt_pid(pid_t process_id);

void dprint_int(int input);
void dprint_txt_int(int input);

void dprint_float(float input);
void dprint_txt_float(float input);
