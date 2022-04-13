// T02 IIC2333
// Matías López    y    Luis González
// Nro. 17210674        Nro. 16625439

#pragma once

#include "../queue/queue.h"
#include "../process/process.h"

struct scheduler;
typedef struct scheduler Scheduler;

struct scheduler {
  Queue* not_started_yet;
  Queue* running_queue;
  Queue* finished_queue;
  Queue* queue_p2;
  Queue* queue_p1;
  Queue* queue_p0;

  int quantum;
};

Scheduler* createScheduler();

void add_process(Scheduler* scheduler, Process* process);

int run_scheduler(Scheduler* scheduler);

void tick(Scheduler* scheduler,
          int q_value);

void destroy_scheduler(Scheduler* scheduler);
