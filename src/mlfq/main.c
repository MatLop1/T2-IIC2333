// T02 IIC2333
// Matías López    y    Luis González
// Nro. ########        Nro. 16625439

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

// Traigo módulos que venían
#include "../process/process.h"
#include "../queue/queue.h"
#include "../file_manager/manager.h"

//Módulos de la tarea pasada
// Para debuguear
# include "debug/debug.h"
// Mensajes de error
# include "errors/errors.h"


int main(int argc, char const *argv[]) {

	/*Lectura del input*/
	char *file_name = (char *)argv[1];
	InputFile *input_file = read_file(file_name);

	/*Mostramos el archivo de input en consola*/
	printf("Nombre archivo: %s\n", file_name);
	printf("Cantidad de procesos: %d\n", input_file->len);
	printf("Procesos:\n");

	for (int i = 0; i < input_file->len; ++i)	{
		for (int j = 0; j < 7; ++j)	{
			printf("%s ", input_file->lines[i][j]);
		}

		printf("\n");
	}

	input_file_destroy(input_file);
}