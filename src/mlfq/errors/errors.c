// T02 IIC2333
// Matías López    y    Luis González
// Nro. 17210674        Nro. 16625439

//Para printear
#include <stdio.h>

//Importar archivo
#include "errors.h"


char output_symbol[] = " |> ";

void missing_argument() {
  printf("%sERROR: Falta a lo menos un argumento\n", output_symbol);
}

void unexpected_argument() {
  printf("%sERROR: Hay a lo menos un argumento más de los esperados\n", output_symbol);
}

void file_not_found(char *file_path) {
  printf("%sERROR: El archivo %s no existe\n", output_symbol, file_path);
}