/* coded by: vold e synt4x3r */
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <string.h>
#include <netdb.h>

enum {PORTA=80};
enum {MAX=2000};
enum {MAX_READ_SIZE=200};

typedef struct {
    char b[MAX];
    char x[MAX];
    char cont[MAX];
    char connec[MAX];
}comp;

void strct(comp *elemen) {
    strcpy(elemen->b, "PUT");
    strcpy(elemen->x, "Host:");
    strcpy((*elemen).cont, "Content-Length:");
    strcpy((*elemen).connec, "Connection: close");
}

void erro(char *str, int erro) {
    printf("%s", str);
    exit(erro);
}

void content(char *str, FILE *p) {
    rewind(p);
    fgets(str, MAX_READ_SIZE, p);
}

int main(int argc, char **argv) {
    char BUFF[MAX], read[MAX], get[MAX];
    comp p2;
    strct(&p2);
    
    int sockfd, size, recebe;
    struct sockaddr_in server, addr;
    struct hostent *h;
    
    memset(BUFF, '\0', sizeof(char) *MAX);
    
    FILE *fileptr;
    fileptr = fopen(argv[2], "r+");
     if (!fileptr) {
         erro("erro file. \n", -1);
     }
     
    content(read, fileptr);
    size = strlen(read);

    sprintf(BUFF, "%s %s%s HTTP/1.1\r\n%s %i\r\n%s %s\r\n%s\r\n\r\n%s\r\n\r\n\r\n", p2.b, argv[3], argv[2], p2.cont, size, p2.x, argv[1], p2.connec, read);

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
     if (sockfd < 0) {
         erro("erro socket. \n", -1);
     }
     
    h = gethostbyname(argv[1]);
    if (!h) {
        erro("erro gethostbyname.\n", -1);
    }
    
    server.sin_family = h->h_addrtype;
    server.sin_port = htons(PORTA);
    server.sin_addr = (*(struct in_addr *)h->h_addr);
    
     if( connect(sockfd, (struct sockaddr *)&server, sizeof(server)) < 0) {
         erro("erro connect. \n", -1);
     }
       if(send (sockfd, BUFF, strlen(BUFF), 0) < 0) {
           erro("erro send. \n", -1);
       } 
       else {
           printf("[+]Sucesso\n");
       }
      
         while ( recebe=recv(sockfd, get, MAX, 0)) {
             get[recebe] = '\0';
             printf("%s\n", get);
         }
             
    return 0;
}
