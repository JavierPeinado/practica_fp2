#include <stdlib.h>
#include <stdio.h>
#include "errors_fp2.h"
#include "funcions.h"
int leer_archivo(FILE *archivo, int *vertices, xarxa_t *x)
{
    int result = fscanf(archivo, "*Vertices %d", vertices);
    int error = ERR_NONE;
    if (result == 1)
    {
        printf("El numero de vertices es: %d\n", *vertices);
    }
    else
    {
        printf("No se pudo leer el numero de vertices\n");
        error = ERR_IO_READ;
    }
    x->matriz = (int *) malloc(*vertices * sizeof(int));
    for (int i = 0; i < *vertices; i++)
    {
        x->matriz[i] = calloc(*vertices,sizeof(int));
    }
    

    return error;
}