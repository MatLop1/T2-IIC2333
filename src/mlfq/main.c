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

// Traigo módulos que venían
#include "../process/process.h"
#include "../queue/queue.h"
#include "../file_manager/manager.h"

//Módulos de la tarea pasada
// Para debuguear
#include "debug/debug.h"

// Módulos de esta tarea
#include "../black_box/scheduler.h"
#include "../queue/queue.h"
#include "../queue/queue.h"


int main(int argc, char const *argv[]) {

	/*Lectura del input*/

  Queue* not_started_yet = createQueue();
  Queue* running_queue = createQueue();
  Queue* finished_queue = createQueue();
  Queue* queue_p2 = createQueue();
  Queue* queue_p1 = createQueue();
  Queue* queue_p0 = createQueue();

	char *file_name = (char *)argv[1];
	InputFile *input_file = read_file(file_name);

	/*Mostramos el archivo de input en consola*/
	printf("Nombre archivo: %s\n", file_name);
	printf("Cantidad de procesos: %d\n", input_file->len);
	printf("Procesos:\n");

	for (int i = 0; i < input_file->len; ++i)	{
		for (int j = 0; j < 7; ++j)	{


			printf("F%iC%i: %s ", i + 1, j + 1,input_file->lines[i][j]);
		}

    char* name = input_file->lines[i][0];
    int pid = atoi(input_file->lines[i][1]);
    int t_start = atoi(input_file->lines[i][2]);
    int n_cycles = atoi(input_file->lines[i][3]);
    int wait_cycles = atoi(input_file->lines[i][4]);
    int wait_delay = atoi(input_file->lines[i][5]);
    int s = atoi(input_file->lines[i][6]);

    dprint_line();
    dprint_txt_char_x("Datos del proceso");
    dprint_txt(); dprint_char_x("Nombre:        "); dprint_char_x(name);     dprint_line();
    dprint_txt(); dprint_char_x("PID:           "); dprint_int(pid);         dprint_line();
    dprint_txt(); dprint_char_x("Inicio:        "); dprint_int(t_start);     dprint_line();
    dprint_txt(); dprint_char_x("Nro de ciclos: "); dprint_int(n_cycles);    dprint_line();
    dprint_txt(); dprint_char_x("Ciclos espera: "); dprint_int(wait_cycles); dprint_line();
    dprint_txt(); dprint_char_x("Tiempo espera: "); dprint_int(wait_delay);  dprint_line();
    dprint_txt(); dprint_char_x("S:             "); dprint_int(s);           dprint_line();

    dprint_line(); dprint_char_x("\nVoy a crear un proceso");
    Process* process = createProcess(name, pid, t_start, n_cycles, wait_cycles, wait_delay, s);
    dprint_char_x("\nProceso creado !!");

    dprint_line(); dprint_char_x("\nMetiendo a la cola"); dprint_line();
    enqueue(not_started_yet, process);
    dprint_char_x("\nEstá en la cola"); dprint_line();
		printf("\n");
	}

  for (int i = 0; i < input_file->len; ++i) {
    dprint_txt(); dprint_char_x("Sacando de la cola un proceso"); dprint_line();
    Process* process = dequeue_normal(not_started_yet);
    if(process){
      char* name2 = process->name;
      printf("\nProceso: %s\n", name2);
      dprint_txt(); dprint_char_x("Proceso: "); dprint_char_x(name2); dprint_line();
      dprint_txt(); dprint_char_x("Lierando MEM"); dprint_line();
      free(process);
    }
  }

  free(not_started_yet);
  free(running_queue);
  free(finished_queue);
  free(queue_p2);
  free(queue_p1);
  free(queue_p0);

  input_file_destroy(input_file);
}
