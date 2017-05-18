#include <stdio.h>
int size ( char *string ) 
{
	int i;
	 for ( i = 0; string[i] != '\0'; i++);
	return i;
}

unsigned char * mstr( char *nee, char *hay) 
 {
 	char *ptr = NULL;
 	  int i, len = size(hay), b = 0, j = 0;
 	  
 	   while ( *nee && *hay ) {
 	   	     if (*nee == *hay) {
 	   	         break;	   
			 }
 	   	    nee++;
		}
 	  
 	   for ( j = 0; nee[j] != '\0'; j++) {
 	   	  for ( b = 0; hay[b] != '\0'; b++) {
 	   	  	     if ( nee[j] == hay[b] ) {
 	   	  	     	     ptr = &nee[j];
					   }
					break;
			  }
		}
		
 	 return (unsigned char *)ptr;
 }
 
int main( int argc, char *argv[] ) {
	const char p[] = "minha string aqui!!!", hay[] = "minha";
	
	printf("output = %s\n", mstr( (char *)p, (char *)hay) );
	return 0;
}
