#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "errors_fp2.h"
#include "funcions.h"
void liberar_memoria(xarxa_t *x)
{
    if (x->matriz != NULL) // Librerar espacio
    {
        for (int i = 0; i < x->vertices; i++)
        {
            free(x->matriz[i]);
        }
        free(x->matriz);
        x->matriz = NULL;
    }
    x->vertices = 0;
}int leer_archivo(FILE *archivo, xarxa_t *x)
{
    int error = ERR_NONE;
    char buffer[100];
    int a, b;
    int i;

    /* 1. Leer cabecera */
    if (error == ERR_NONE)
    {
        if (fscanf(archivo, "%s", buffer) != 1)
        {
            error = ERR_IO_READ;
        }
    }

    if (error == ERR_NONE)
    {
        if (fscanf(archivo, "%d", &x->vertices) != 1)
        {
            error = ERR_IO_READ;
        }
    }

    /* 2. Reservar matriz */
    if (error == ERR_NONE)
    {
        x->matriz = (int **)malloc(x->vertices * sizeof(int *));
        if (x->matriz == NULL)
        {
            error = ERR_MEM_ALLOC;
        }
    }

    if (error == ERR_NONE)
    {
        for (i = 0; i < x->vertices && error == ERR_NONE; i++)
        {
            x->matriz[i] = (int *)calloc(x->vertices, sizeof(int));

            if (x->matriz[i] == NULL)
            {
                error = ERR_MEM_ALLOC;
            }
        }
    }

    /* 3. Buscar *Edges */
    if (error == ERR_NONE)
    {
        while (fscanf(archivo, "%s", buffer) == 1 && strcmp(buffer, "*Edges") != 0)
        {
            /* saltar */
        }
    }

    /* 4. Leer conexiones */
    if (error == ERR_NONE)
    {
        while (fscanf(archivo, "%d %d", &a, &b) == 2)
        {
            x->matriz[a - 1][b - 1] = 1;
            x->matriz[b - 1][a - 1] = 1;
        }
    }
    for (int i = 0; i < x->vertices; i++){
        for (int j = 0; j < x->vertices; j++)
        {
            printf("%d ", x->matriz[i][j]);
        }
        printf("\n");
        
    }

    

    return error;
}