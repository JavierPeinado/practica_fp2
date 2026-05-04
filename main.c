#include <stdio.h>
#include <stdlib.h>
#include "errors_fp2.h"
#include "funcions.h"

int main(int argc, char *argv[])
{
    int error = ERR_NONE;

    xarxa_t x;
    x.n = 0;

    x.matriz = NULL;
    FILE *archivo = NULL;
    if (argc != 2)
    {
        fprintf(stderr, "Error:El correcto uso de la temrinal seria asi : ./main.exe <nom_fitxer_xarxa>\n");

        error = ERR_CMD_ARGS;
    }
    else
    {
        // Abrir fichero .net con los nodos
        archivo = fopen(argv[1], "r");
        if (archivo == NULL)
        {
            fprintf(stderr, "Error al abrir archivo\n");
            error = ERR_IO_OPEN;
        }
        else
        {
            error = leer_archivo(archivo, &x.n, &x);
        }
        // Cerrar archivo y liberar espacio
        if (archivo != NULL)
        {
            fclose(archivo);
            archivo = NULL;
        }
        if (x.matriz != NULL) // Librerar espacio
        {
            for (int i = 0; i < x.n; i++)
            {
                free(x.matriz[i]);
            }
            free(x.matriz);
            x.matriz = NULL;
        }
    }

    return error;
}
