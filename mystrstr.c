#include <stdio.h>

#define LOGPRINT(fmt, args...) fprintf(stdout, fmt, ##args)
int mystrlen(char *s) {
    int i;
      for ( i = 0; s[i] != '\0'; i++ );
    return i;
}

int mystrncmp(char *xx, char *cc, size_t tam) {
     while ( tam && *xx && *xx == *cc ) {
         xx++;
         cc++;
         tam--;
     }
     
     if ( tam == 0 ) {
         return 0;
     }else{
         return ( *xx - *cc );
     }
         
}

char * str(char *p, char *s) {
    unsigned char *ptr = NULL;
    
    if ( !p || !s ) {
        return (char *)NULL;
    }
    
   unsigned int size = mystrlen(s);
    
        while ( *p && *s ) {
             if ( mystrncmp(p, s, size ) == 0 ) {
                 ptr = p;
                 break;
              }  
              p++;
        }   
       
     return ptr;
}

int main( int argc, char *argv[] ) {
    const char p[] = "test of my function", c[] = "of";
    
    LOGPRINT("%s", str( (char *)p, (char *)c ) );
    putchar('\n');
    fflush(stdout);
    
    return 0;
}
