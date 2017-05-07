#include <stdio.h>

unsigned int len(char *p) {
    int i;
      for ( i = 0; p[i] != '\0'; i++);
    return ( unsigned int)i;
}

unsigned char * mystr(char *needle, char *haystack) {
    unsigned char *ptr = NULL;
    unsigned int tamhay = len(haystack), i = 0, b = 0;

        while ( *needle && *haystack ) {
              if( *needle == *haystack ) {
                 break;
              }
            needle++;
        }
        
        
         for ( i = 0; i < tamhay; i++) {
             for ( b = 0; haystack[b] != '\0'; b++) 
                 if (needle[i] == *haystack) {
                     ptr = &needle[i];
                     break;
                 }
         }
         
       return ptr;
}

enum {MAX = 100};
int main(void) {
    char p[MAX] = "my string here!!!", b[MAX] = "string";
    printf("%s\n", mystr(p, b) );
    return 0;
}
