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
// Mensajes de error
#include "errors/errors.h"

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

    char *name = input_file->lines[i][0];
    int pid = atoi(input_file->lines[i][1]);
    int t_start = atoi(input_file->lines[i][2]);
    int n_cycles = atoi(input_file->lines[i][3]);
    int wait_cycles = atoi(input_file->lines[i][4]);
    int wait_delay = atoi(input_file->lines[i][5]);
    int s = atoi(input_file->lines[i][6]);

    printf("\n");
    dprint1("Nombre: ");
    dprint3(*name);
    printf("PID: %i\n", pid);
    printf("T: %i\n", pid);
    printf("PID: %i\n", pid);
    printf("PID: %i\n", pid);
    printf("PID: %i\n", pid);
    printf("\n");

    Process* process = createProcess(*name, pid, t_start, n_cycles, wait_cycles, wait_delay, s);


		printf("\n");
	}

	input_file_destroy(input_file);

  free(not_started_yet);
  free(running_queue);
  free(finished_queue);
  free(queue_p2);
  free(queue_p1);
  free(queue_p0);

  // TODO:
  //  - Agregar procesos a la cola por iniciar
  //  .
  //  - while (len(cola_p2) + len(cola_p1) + len(cola_p0) > 0) {
  //        tick(cola_null, cola_sin_comenzar, cola finalizado, cola_p2, cola_p1, cola_p0)
  //    }
}
