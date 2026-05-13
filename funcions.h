#ifndef FUNCIONS_H
#define FUNCIONS_H
#include <stdio.h>
#include <stdlib.h>
typedef struct
{
    int vertices;
    int **matriz;
}xarxa_t;
int leer_archivo(FILE *archivo,xarxa_t *x);
#endif
