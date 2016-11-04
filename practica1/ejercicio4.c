/**************************************************/
/* Programa: ejercicio4       Fecha:              */
/* Autores:                                       */
/*                                                */
/* Programa que Comprueba SelectSort              */
/*                                                */
/* Entrada: Linea de comandos                     */
/* -tamanio: numero elementos permutacion         */
/* Salida: 0: OK, -1: ERR                         */
/**************************************************/
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include "permutaciones.h"
#include "ordenacion.h"

int main(int argc, char** argv)
{
  int tamano, i, j, ret;
  int* perm = NULL;

  srand(time(NULL));

  if (argc != 3) {
    fprintf(stderr, "Error en los parametros de entrada:\n\n");
    fprintf(stderr, "%s -tamanio <int>\n", argv[0]);
    fprintf(stderr, "Donde:\n");
    fprintf(stderr, " -tamanio : numero elementos permutacion.\n");
    return 0;
  }
  printf("Practica numero 1, apartado 4\n");
  printf("Realizada por: Vuestros nombres\n");
  printf("Grupo: Vuestro grupo\n");

  /* comprueba la linea de comandos */
  for(i = 1; i < argc; i++) {
    if (strcmp(argv[i], "-tamanio") == 0) {
      tamano = atoi(argv[++i]);
    } else {
      fprintf(stderr, "Parametro %s es incorrecto\n", argv[i]);
    }
  }

  perm = genera_perm(tamano);

  if (perm == NULL) { /* error */
    printf("Error: No hay memoria\n");
    exit(-1);
  }

  ret = InsertSort(perm, 0, tamano-1);


  if (ret == ERR) {
    printf("Error: Error en InsertSort\n");
    free(perm);
    exit(-1);
  }


  for(j = 0; j < tamano; j++) {
    printf("%d \t", perm[j]);
  }
  printf("\n");

/*Imprimimos por pantalla el número de veces que se ejecuta la operación básica*/

  printf("Número de veces que se ejecuta la OB: %d\n", ret);

  free(perm);

  return 0;
}

