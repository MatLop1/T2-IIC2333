// T02 IIC2333
// Matías López    y    Luis González
// Nro. 17210674        Nro. 16625439

#pragma once

#include <stdlib.h>
#include <stdbool.h>

struct process;
typedef struct process Process;

struct process {
  char* name;
  int pid;
  int start_time;
  int cycles;
  int wait;
  int waiting_delay;
  int s;

  int priority;
  int state;

  int cycles_until_start;
  int remaining_cycles;
  int remaining_wait_time;
  int active_cycles_until_wait;
  int cycles_until_queue_reset;

  int remaining_quantum;

  int times_chosen;
  int times_interrupted;
  int turnaround_time;
  int response_time;
  int waiting_time;

  Process* next;
};

Process* createProcess(char* name, int pid, int start_time, int cycles, int wait, int waiting_delay, int s);
Process* proc_tick(Process* process);
Process* set_priority(Process* process, int priority);
Process* start_first_time(Process* process);

Process* sigcont(Process* process);
Process* sigstop(Process* process);
Process* sigstart(Process* process);
