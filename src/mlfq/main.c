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

//Módulos de la tarea pasada
// Para debuguear
#include "debug/debug.h"

// Módulos de esta tarea
#include "../black_box/scheduler.h"
#include "../process/process.h"
#include "../queue/queue.h"
#include "../file_manager/manager.h"

void free_up_queue(Queue* queue) {
  int queue_size = queue->size;  // FIXME!!!

  for (int i = 0; i < queue_size; ++i) {
    just_wait();
    dprint_txt_char_x2("Sacando de la cola un proceso");
    Process* process = dequeue_normal(queue);
    dprint_txt_char_x2("Salió de la cola!!");

    if(process){
      char* name2 = process->name;
      dprint_txt(); dprint_char_x("Proceso: "); dprint_char_x2(name2); dprint_line();

      dprint_txt_char_x2("Lierando MEM");
      free(process);
      dprint_txt_char_x2("Liberada!!"); dprint_line();
    }
  }

  free(queue);
}


int main(int argc, char const *argv[]) {
  //Creo las colas
  Queue* not_started_yet = createQueue();
  Queue* running_queue = createQueue();
  Queue* finished_queue = createQueue();
  Queue* queue_p2 = createQueue();
  Queue* queue_p1 = createQueue();
  Queue* queue_p0 = createQueue();

  /*Lectura del input*/
  char *file_name = (char *)argv[1];
  InputFile *input_file = read_file(file_name);

  const int *q_value = (int *)argv[3];

	/*Mostramos el archivo de input en consola*/
	printf("Nombre archivo: %s\n", file_name);
	printf("Cantidad de procesos: %d\n", input_file->len);
	printf("Procesos:\n");

  int not_started_yet_size = 0;
  int running_queue_size = 0;
  int finished_queue_size = 0;
  int queue_p2_size = 0;
  int queue_p1_size = 0;
  int queue_p0_size = 0;

	for (int i = 0; i < input_file->len; ++i)	{
		for (int j = 0; j < 7; ++j)	{


			printf("F%iC%i: %s", i + 1, j + 1,input_file->lines[i][j]);
		}

    // Separo las variables con las características del proceso
    char* name = input_file->lines[i][0];
    int pid = atoi(input_file->lines[i][1]);
    int t_start = atoi(input_file->lines[i][2]);
    int n_cycles = atoi(input_file->lines[i][3]);
    int wait_cycles = atoi(input_file->lines[i][4]);
    int wait_delay = atoi(input_file->lines[i][5]);
    int s = atoi(input_file->lines[i][6]);

    dprint_line();
    dprint_txt_char_x("        Datos del proceso");
    dprint_txt(); dprint_char_x("Nombre:        "); dprint_char_x2(name);     dprint_line();
    dprint_txt(); dprint_char_x("PID:           "); dprint_int(pid);         dprint_line();
    dprint_txt(); dprint_char_x("Inicio:        "); dprint_int(t_start);     dprint_line();
    dprint_txt(); dprint_char_x("Nro de ciclos: "); dprint_int(n_cycles);    dprint_line();
    dprint_txt(); dprint_char_x("Ciclos espera: "); dprint_int(wait_cycles); dprint_line();
    dprint_txt(); dprint_char_x("Tiempo espera: "); dprint_int(wait_delay);  dprint_line();
    dprint_txt(); dprint_char_x("S:             "); dprint_int(s);           dprint_line();

    //Instancio un proceso
    just_wait_longer();
    dprint_txt_char_x2("Vnot_started_yetoy a crear un proceso");
    Process* process = createProcess(name, pid, t_start, n_cycles, wait_cycles, wait_delay, s);
    dprint_txt_char_x2("Proceso creado!!");

    //Lo agrego a la cola
    dprint_txt_char_x("Metiendo a la cola");
    enqueue(not_started_yet, process);
    dprint_txt_char_x("Está en la cola");
    dprint_line();
    just_wait_longer();

    not_started_yet_size = not_started_yet->size;  // FIXME!!!
    dprint_txt(); dprint_char_x("Largo de cola: "); dprint_int(not_started_yet_size); dprint_line(); dprint_line();
	}

  // Main loop
  while (not_started_yet_size +
         running_queue_size +
         queue_p2_size +
         queue_p1_size +
         queue_p0_size > 0) {
    dprint_line(); dprint_txt_char_x("     - - - - - - - ");
    dprint_txt_char_x2("Procesos sin terminar:");
    dprint_txt(); dprint_char_x("not_started_yet: "); dprint_int(not_started_yet_size); dprint_line();
    dprint_txt(); dprint_char_x("running_queue: "); dprint_int(running_queue_size); dprint_line();
    dprint_txt(); dprint_char_x("queue_p2: "); dprint_int(queue_p2_size); dprint_line();
    dprint_txt(); dprint_char_x("queue_p1: "); dprint_int(queue_p1_size); dprint_line();
    dprint_txt(); dprint_char_x("queue_p0: "); dprint_int(queue_p0_size); dprint_line();
    dprint_line(); dprint_txt_char_x("     - - - - - - - ");

    just_wait();
    dprint_line(); dprint_txt_char_x("- TICK -");dprint_line();
    wait_just_a_bit();
    tick(q_value, not_started_yet, running_queue, finished_queue, queue_p2, queue_p1, queue_p0);

    not_started_yet_size = not_started_yet->size;  // FIXME!!!
    running_queue_size = running_queue->size;  // FIXME!!!
    queue_p2_size = queue_p2->size;  // FIXME!!!
    queue_p1_size = queue_p1->size;  // FIXME!!!
    queue_p0_size = queue_p0->size;  // FIXME!!!
    //break;
  }

  // TODO: Guardar en un archivo los resultados
  //*file_name = (char *)argv[2];
  //OutputFile *output_file = save_file(file_name, data);

  // OPTIMIZE: No debería tener que limpiar todas las colas, pero mejor estar
  //  seguros.
  free_up_queue(not_started_yet);
  free_up_queue(running_queue);
  free_up_queue(finished_queue);
  free_up_queue(queue_p2);
  free_up_queue(queue_p1);
  free_up_queue(queue_p0);

  input_file_destroy(input_file);
}
