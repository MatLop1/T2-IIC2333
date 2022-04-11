// T02 IIC2333
// Matías López    y    Luis González
// Nro. 17210674        Nro. 16625439

#include "process.h"

Process* createProcess(char name, int pid, int start_time, int cycles, int wait, int waiting_delay, int s) {
  Process* process = malloc (sizeof(Process));
  process->name = name;
  process->pid = pid;
  process->start_time = start_time;
  process->cycles = cycles;
  process->wait = wait;
  process->waiting_delay = waiting_delay;
  process->s = s;

  process->cycles_until_start = start_time;
  // -1: None
  // 0: Cola 3
  // 1: Cola 2
  // 2: Cola 1
  process->priority = -1;
  // -1: None
  // 0: Running
  // 1: Ready
  // 2: Wait
  // 3: Finished
  process->state = -1;
  process->remaining_cycles = cycles;
  process->remaining_wait_time = waiting_delay;
  process->active_cycles_until_wait = wait;
  process->cycles_until_queue_reset = s;
  process->remaining_quantum = 0;

  process->times_chosen = 0;
  process->times_interrupted = 0;
  process->turnaround_time = 0;
  process->response_time = 0;
  process->waiting_time = 0;
  
  process->next = NULL;
  
  return process;
}

Process* end_process(Process* process) {
  process->state = 3;
  process->remaining_cycles = 0;
  process->remaining_wait_time = -1;
  process->active_cycles_until_wait = -1;
  process->cycles_until_queue_reset = -1;
  return process;
}

Process* proc_tick(Process* process) {
  // TODO: Sumar valores al resumen
  if (process->state == 0) {  // Running
    process->remaining_cycles -= 1;
    process->active_cycles_until_wait -= 1;

  } else if (process->state == 2) {  // Waiting
    process->remaining_wait_time -= 1;

  } else if (process->state == -1) { // None
    process->cycles_until_start -= 1;
  }

  process->cycles_until_queue_reset -= 1;

  if (process->remaining_cycles == 0) {
    end_process(process);

  } else {
    if (process->state != -1) {
      process->cycles_until_queue_reset -= 1;

    } else {
      process->cycles_until_start -= 1;
    }
  }

  // TODO: Revisar se falta algún otro tipo de procesamiento

  return process;
}

Process* set_priority(Process* process, int priority) {
  return process;
}

Process* start_first_time(Process* process) {
  process->state = 1;
  set_priority(process, 2);
  return process;
}

Process* sigcont(Process* process) {
  // TODO:
  //  process.state = 0
  //  ¿?
  return process;
}

Process* sigstop(Process* process, bool is_waiting) {
  // TODO:
  //  process.times_interrupted ++
  //  process.state = 2 if (is_waiting) else 1
  //  ¿?
  return process;
}
