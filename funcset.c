#include <stdio.h>

/* função p/ atribuir um char no vetor inteiro
by: vold */

enum{MAX=100};

void _set(char *str, char value, int size) {
    int ind; 
      for (ind=0; ind<size; ind++) {
          str[ind] = (int )value;
      }
}

main() {
    const char c[MAX] = "teste";
    printf("size: %lu\nAntes do _set: %s\n", sizeof(c), c);
    
    _set((char *)c, 'A', sizeof(c));
    
    printf("\nDepois do _set: %s\n", c);
    
    //Zerando
    
    _set((char *)c, '\0', sizeof c);
    
    printf("\nZerado\nConteudo: %s\n", c);
}
