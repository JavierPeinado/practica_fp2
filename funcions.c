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
    x->matriz = (int **)malloc(*vertices * sizeof(int));
    for (int i = 0; i < *vertices; i++)
    {
        x->matriz[i] = calloc(*vertices, sizeof(int));
    }
    char buffer[50];
    fscanf(archivo, "%s", buffer); // leer "*Edges"

    int a, b;
    while (fscanf(archivo, "%d %d", &a, &b) == 2)
    {
        x->matriz[a - 1][b - 1] = 1;
        x->matriz[b - 1][a - 1] = 1;
    }
    for (int i = 1; i < x->n; i++)
    {
        for (int j = 1; j < x->n; j++)
        {
            printf("%d ", x->matriz[i][j]);
        }
        printf("\n");
    }

    return error;
}