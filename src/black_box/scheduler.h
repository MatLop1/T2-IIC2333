// T02 IIC2333
// Matías López    y    Luis González
// Nro. ########        Nro. 16625439

// Compilar sólo una vez
#pragma once

//Colas:
#include "../queue/queue.h"
//Procesos
#include "../process/process.h"

// Funciones
int get_queue_quantum(int q_value, int priority);
void make_tick_happen(Queue* not_started_yet, Queue* running, Queue* finished,
                      Queue* queue1, Queue* queue2, Queue* queue3)

bool tick(int q, Queue queue1, Queue queue2, Queue queue3);


