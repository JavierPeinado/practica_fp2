#ifndef FUNCIONS_H
#define FUNCIONS_H
#include <stdio.h>
#include <stdlib.h>
typedef struct
{
    int n;
    int **matriz;
}xarxa_t;
int leer_archivo(FILE *archivo,int *vertices, xarxa_t *x);
#endif
