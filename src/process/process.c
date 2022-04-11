#include "process.h"

Process* createProcess(char[32] name, int pid, int start_time, int cycles, int wait, int waiting_delay, int s)
{
  struct Process* process = (Process*)malloc(sizeof(Process));
  process->name = name;
  process->pid = pid;
  process->start_time = start_time;
  process->cycles = cycles;
  process->wait = wait;
  process->waiting_delay = waiting_delay;
  process->s = s;

  process->priority = 0;
  process->state = 0;

  process->times_chosen = 0;
  process->times_interrupted = 0;
  process->turnaround_time = 0;
  process->response_time = 0;
  process->waiting_time = 0;
  return process;
}
