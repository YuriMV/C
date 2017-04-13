/* código de teste... 
alocando memória pra estrutura, zerando, apontando membros para a primeira posição da memória ( apontando para NULL pq não estou usando os membros da estrutura naquela linha )
alocando memória para membros, copiando string "teste" para membro 1 (mem1), copiando bloco de memória (copiando teste) para membro 2 (mem2) com memcpy()
pegando tamanho da struct e do ponteiro multiplicado pela macro SIZE
e pegando tamanho de ambas normal.
by: vold */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int strsize( char *mem) {
    int i = 0;
      while ( mem[i] != '\0' ) {
          i++;
      }
     return i;
}

void _setNULL(char *str, int value, int size) {
    int i;
      for (i = 0; i<size; i++ ) {
          str[i] = value;
      }
}

char * cpstring(char *dest, const char *src) {
    int i = 0;
      while (src[i] != '\0' ) {
          dest[i] = src[i];
          i++;
      }
    dest[i] = '\0';
    return dest;
}

typedef struct {
   unsigned char *mem1;
   unsigned char *mem2;
} inst_t;

inst_t *fsptr;

static unsigned const int SIZE = 240;
#define echo printf

#define die(STR, ERRO) \
 do { \
  echo("%s", STR); \
   exit(ERRO); \
 } while (0) 
   
main() {
    fsptr = malloc(SIZE*sizeof(inst_t));
    
    _setNULL( (char *)fsptr, (char)'\0', (int)sizeof(inst_t) *SIZE);
    fsptr->mem1 == NULL;
    fsptr->mem2 == NULL;
    
     if ( (fsptr->mem2 = (unsigned char *)calloc(SIZE, sizeof(inst_t)) ) && (fsptr->mem1 = (unsigned char *)calloc(SIZE, sizeof(inst_t)) ) == NULL) 
         die("erro ao alocar memoria. \n", -1);
    
    echo("%s\n", cpstring( (char *)fsptr->mem2, "teste"));
    
    memcpy( (unsigned char *)fsptr->mem1, (unsigned char *)fsptr->mem2, strsize( (char *)fsptr->mem2)+1 );
    echo("%s\n", fsptr->mem1);
    
    echo("%d\n%d\n", (int)sizeof( (unsigned char *)fsptr->mem1), (int)sizeof( (unsigned char *)fsptr->mem2));
    
    echo("%d\n", (int)sizeof(inst_t) *SIZE);
    echo("%d\n", (int)sizeof( (char *)fsptr)  *SIZE);
    
    echo("%d\n", (int)sizeof(inst_t));
    echo("%d\n", (int)sizeof( (char *)fsptr));
    
  free(fsptr);
}
