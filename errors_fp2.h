#ifndef ERRORS_FP2_H
#define ERRORS_FP2_H

/* 0: cap error */
#define ERR_NONE               0

/* 10-19: errors d'arguments */
#define ERR_CMD_ARGS          10   /* arguments de línia de comandes incorrectes */
#define ERR_ARGS              11   /* paràmetres de funció incorrectes */
#define ERR_ARG_VALUE         12   /* valor d'argument incorrecte */
#define ERR_ARG_FORMAT        13   /* format d'argument incorrecte */
#define ERR_NULL_POINTER      14   /* punter NULL no esperat */

/* 20-29: errors de fitxer / entrada-sortida */
#define ERR_IO_OPEN         20   /* error en obrir un fitxer */
#define ERR_IO_READ         21   /* error en llegir un fitxer */
#define ERR_IO_WRITE        22   /* error en escriure en un fitxer */
#define ERR_IO_CLOSE        23   /* error en tancar un fitxer */
#define ERR_IO_FORMAT       24   /* format de fitxer incorrecte o inesperat */
#define ERR_IO_SEEK         25   /* error en posicionar-se dins del fitxer */
#define ERR_IO_EOF          26   /* error: s'ha acabat el fitxer abans d'hora*/

/* 30-39: errors de memòria dinàmica */
#define ERR_MEM_ALLOC         30   /* error en reservar memòria */
#define ERR_MEM_REALLOC       31   /* error en redimensionar memòria */

/* 40-49: errors de dades */
#define ERR_DATA              40   /* dades incorrectes */
#define ERR_DATA_RANGE        41   /* dada fora de rang */
#define ERR_DATA_INVALID      42   /* dada invàlida */
#define ERR_EMPTY             43   /* estructura o fitxer buit */
#define ERR_NOT_FOUND         44   /* element no trobat */


/* Si crees una nova categoria, posa codis en rang 50, 60 ... etc*/
/* 90-99: errors genèrics */
#define ERR_UNKNOWN           99   /* error desconegut */

#endif