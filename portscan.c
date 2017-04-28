#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <string.h>
#include <netdb.h>

#define w printf
#define wf fprintf

#define die(STRING, ERRO) \
 w(STRING); \
 exit(ERRO);

enum { MAX_BUF = 140 };
int main(void) {
    void * retr( struct sockaddr_in *, struct hostent * );
    struct sockaddr_in server;
    
    unsigned char BUF[MAX_BUF];
    struct hostent *h;
    int sockfd, recebe, numb;
    
       w("host: ");
       scanf("%99[^\n]", BUF);
       
      if ( (h = gethostbyname(BUF)) == NULL ) {
          die("erro gethostbyname. \n", -1);
      }
      
    void * (*myfunc) ();
       myfunc = retr;
        (*myfunc) (&server, h) ;
        
     unsigned int count = 0;
     for (count = 21; count < 100; count++ ) 
     {
         
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
     if ( sockfd < 0 ) {
         die("erro socket. \n", -1);
     }
     
     server.sin_port = htons(count);
     
     recebe = connect(sockfd, (struct sockaddr *)&server, sizeof(server));
     if ( recebe == 0 ) {

         wf(stdout, "porta aberta: " \
                " %-5d\n", count);
     } else {
         die("closed... \n", -1);
     }
     close(sockfd);
 }
    return 0;
}

void * retr( struct sockaddr_in *end, struct hostent *host ) 
{
     end->sin_family = host->h_addrtype;
     end->sin_addr = (*(struct in_addr*)host->h_addr);
     memset(&(end->sin_zero), '\0', sizeof(end->sin_zero));
     return (void *)0;
}
