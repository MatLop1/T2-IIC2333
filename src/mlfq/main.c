// T02 IIC2333
// Matías López    y    Luis González
// Nro. 17210674        Nro. 16625439

#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

// Para debuguear
#include "debug/debug.h"

// Módulos de esta tarea
#include "../black_box/scheduler.c"
#include "../process/process.h"
#include "../queue/queue.h"
#include "../file_manager/manager.h"

int main(int argc, char const *argv[]) {

  // create scheduler
  Scheduler*  = createScheduler();

  // read Input
  char *file_name = (char *)argv[1];
  InputFile *input_file = read_file(file_name);
  
  // get quantum value
  int q_value = atoi(argv[3]);

  // Create all process
	for (int i = 0; i < input_file->len; ++i)	{
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

    // create process
    Process* process = createProcess(name, pid, t_start, n_cycles, wait_cycles, wait_delay, s);

    // add process for first time in scheduler
    add_process(scheduler, process);
	}

  // Main loop
  while (run_scheduler(scheduler)) {
    dprint_line(); dprint_txt_char_x("- TICK -"); dprint_line();   
    tick(scheduler, q_value);
  }

  //free memory
  destroy_scheduler(scheduler);
  input_file_destroy(input_file);
}
