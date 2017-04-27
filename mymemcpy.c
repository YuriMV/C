/* my memcpy function ;) 
by: vold  */
#include <stdio.h>

#define wf fprintf
enum { TAM = 40 };
int main(void) {
    
    void * mmemcpy(void *, const void *, size_t);
    void * (*mymem)();
    
    char destin[TAM], source[] = "teste funcao";
    mymem = mmemcpy;
    
    (*mymem) (destin, source, 12);
    #ifdef DEBUG
    wf( stdout, "output = %-5s\n", destin );
    #endif
    
    (*mymem) (destin, source, 10);
    wf ( stdout, "output = %-5s\n", destin );
    return 0;
}

void * mmemcpy(void *s, const void *src, size_t num) {
    unsigned char *Ptr = NULL;
    Ptr = (unsigned char *)s;
    
    unsigned const char *source = NULL;
    source = (unsigned const char *)src;
    
    unsigned int count;
     for (count = 0; count<num;count++ ) {
         Ptr[count] = source[count];
     }
     Ptr[count] = '\0';
       return ( void *) 0;
}
