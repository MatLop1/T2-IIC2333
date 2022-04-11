#pragma once

struct process;
typedef struct process Process;

struct process {
  char name;
  int pid;
  int start_time;
  int cycles;
  int wait;
  int waiting_delay;
  int s;

  int priority;
  int state;

  int times_chosen;
  int times_interrupted;
  int turnaround_time;
  int response_time;
  int waiting_time;

  Process* next;
};
 
Process* createProcess(char name, int pid, int start_time, int cycles, int wait, int waiting_delay, int s);
Process* proc_tick(Process* process);
