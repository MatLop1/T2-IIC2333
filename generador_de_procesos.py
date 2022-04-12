#!/usr/bin/python3.9

from random import randrange, randint, shuffle

N_PROCESOS = 3

# -----

max_procs = 2048
N_PROCESOS = min(N_PROCESOS, max_procs)
pids = [i for i in range(max_procs)]
shuffle(pids)

procesos = list()

for n in range(N_PROCESOS):
    nombre = "PROCESS" + str(n + 1).rjust(4, '0')
    pid = pids.pop(0)
    inicio = 0 if len(procesos) < 3 else randint(0, 10 * len(procesos))
    ciclos = randint(50, 500)
    wait = randint(30, 200)
    wait_delay = randint(10, 10 * (len(procesos) + 1) + 1)
    s = randint(10, 120)

    procesos.append(f"{nombre} {pid} {inicio} {ciclos} {wait} {wait_delay} {s}\n")

with open('example.txt', 'w') as file:
    file.write(str(N_PROCESOS) + '\n')

    for proc in procesos:
        file.write(proc)
