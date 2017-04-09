#include <stdio.h>

enum {MAX=20};

typedef struct {
    char c[MAX];
}Addrstruct;

void cpstring(char *dest, const char *str) {
    int i = 0;
       while(str[i] != '\0') {
           dest[i] = str[i];
           i++;
       }
       dest[i] = '\0';
}

void forstruct(Addrstruct *p) {
    cpstring((*p).c, "teste");  
}


int size(const char *s) {
    int i = 0;
      while(*s != '\0') {
          ++s;
          ++i;
      }
    return i;
}

main() {
    Addrstruct ptrs;
    forstruct(&ptrs);
    printf("size: %d\n", size(ptrs.c));
    
}
