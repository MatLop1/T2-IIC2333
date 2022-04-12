// T02 IIC2333
// Matías López    y    Luis González
// Nro. 17210674        Nro. 16625439

// Compilar sólo una vez
#pragma once

//Colas:
#include "../queue/queue.h"
//Procesos
#include "../process/process.h"

// Funciones
int get_queue_quantum(int q_value, int priority);
void make_tick_happen(
    Queue* not_started_yet, Queue* running_queue, Queue* finished_queue,
    Queue* queue_p2, Queue* queue_p1, Queue* queue_p0);
void run_fifo(
    int q, int priority,
    Queue* not_started_yet, Queue* running_queue, Queue* finished_queue,
    Queue* queue_p2, Queue* queue_p1, Queue* queue_p0);
void run_sjf(
    int q, int priority,
    Queue* not_started_yet, Queue* running_queue, Queue* finished_queue,
    Queue* queue_p2, Queue* queue_p1, Queue* queue_p0);
void tick(int* q,
          Queue* not_started_yet,
          Queue* running_queue,
          Queue* finished_queue,
          Queue* queue_p2,
          Queue* queue_p1,
          Queue* queue_p0);


