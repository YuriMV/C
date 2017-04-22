#include <stdio.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <stdlib.h>
#include <netdb.h>
#include <string.h>

#define PORTA 80
#define say printf
#define wf fprintf

#define die(STR) \
  say(STR); \
   exit(-1)

void * copystring( char *str , char *str2) {
	int i;
	  for ( i = 0; str2[i] != '\0' ; i++) {
	  	str[i] = str2[i];
	  }
	  str[i] = '\0';
}

void * _NULCHAR ( void *ponteiro, unsigned int valor, unsigned int TAM ) {
	
	   unsigned char *_ponteiro = (unsigned char *)ponteiro;
	   
	 while ( TAM > 0 ) {
	 	*_ponteiro = valor;
	 	_ponteiro++;
	 	TAM--;
	 }
	
	 return ( void *)_ponteiro;
}

int tamanhostring(char *string )
{
    int i;
     for (i=0;string[i] != '\0';i++);
     return i;
}

enum { SIZE = 30000 };
int main(int argc, char **argv) {
	const char bing[] = "www.bing.com";
	
	char *request [] = {
	  "HTTP/1.1", 
	  "Connection: close", 
	  "User-Agent: Mozilla/5.0 (Windows NT 6.1) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/57.0.2987.133 Safari/537.36"
	};
	
    unsigned char mbuff[SIZE], get[SIZE], BUF[SIZE], *resposta = NULL;
    resposta = (unsigned char *) realloc(resposta, (sizeof ( unsigned char ) * (SIZE*2) ));
	
	_NULCHAR(get, '\0', SIZE);
	_NULCHAR(mbuff, '\0', SIZE);
	_NULCHAR(BUF, '\0', SIZE);
	
	int sockfd, recebe;
	unsigned long int tamanho = 0, flag = 1;
	
    struct sockaddr_in server, addr;
    struct hostent *h;
   
    sprintf(mbuff, "GET /search?q=%s %s\r\n%s\r\nHost: %s\r\n%s\r\n\r\n", argv[1], request[0], request[2], bing, request[1]);
    
    copystring(BUF, mbuff);  
    _NULCHAR(mbuff, '\0', sizeof mbuff);
     
     sockfd = socket(AF_INET,SOCK_STREAM,0);
	if (sockfd < 0) {
	  die("erro socket. \n");
	}
	
	h = gethostbyname(bing);
     if ( h == NULL ) 
     { 
       die("erro gethostbyname. \n");	
       }
    
    server.sin_family = h->h_addrtype; 
    server.sin_port = htons(PORTA);
    server.sin_addr = (*(struct in_addr *)h->h_addr);
	
	
    if ( connect( sockfd, (struct sockaddr *)&server, sizeof(server)) < 0) {
          die("erro connect. \n");
     } 
          
         if ( send(sockfd, BUF, tamanhostring(BUF), 0) < 0) {
               die("erro send. \n");
          }
          
          unsigned char *str = NULL;

            while (flag) {
                recebe = recv(sockfd, get, (sizeof (char) * (SIZE*2)), 0);
                
                  if ( recebe == 0 || recebe < 0 ) {
                      flag = 0;
                  } else {
                      if (( resposta = (unsigned char *)realloc(resposta, tamanho + ( sizeof (char) * (SIZE*2)) )) != NULL) {
                          memcpy( &resposta[tamanho], get, recebe );
                          tamanho += recebe;
                      }
                  }
            }
               resposta[tamanho] = '\0';
               str = resposta;
               char domain[SIZE];
               _NULCHAR(domain, '\0', sizeof (char) *SIZE);
               
              unsigned int a = 0;
               
                while ( 1 )  {
                    str = strstr(str, "://");
                    str += strlen("://");
                    
                     if (!str) {
                         say("nao tem mais URLs. \n");
                         break;
                     }
                    
                     for (a = 0; str[a] != '\0'; a++) {
                         
                          if ( sscanf(&str[a], "%[a-zA-Z..][^/]", &domain[a])) {
                           break;   
                          }
                          
                     }
                     
                    printf("%s\n",domain);
                }
               
	return 0;
}
