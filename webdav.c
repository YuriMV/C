/* coded by: vold greetz synt4x3r */
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

void cpstring(char *dest, const char *str) {
    int i = 0;
       while(str[i] != '\0') {
           dest[i] = str[i];
           i++;
       }
       dest[i] = '\0';
}

void strct(comp *elemen) {
    cpstring(elemen->b, "PUT");
    cpstring(elemen->x, "Host:");
    cpstring((*elemen).cont, "Content-Length:");
    cpstring((*elemen).connec, "Connection: close");
}

void erro(const char *str, int erro) {
    printf("%s", str);
    exit(erro);
}
void erroargc(const char *s, char *arg) {
    printf("%s%s", arg, s);
    exit(EXIT_FAILURE);
}


void content(char *str, FILE *p) {
    rewind(p);
    fgets(str, MAX_READ_SIZE, p);
}

int main(int argc, char **argv) {
    
       if (argc < 3) {
           fprintf(stderr, "Erro\nuso: ");
           erroargc(" site.com arquivo.txt /diretorio\n", argv[0]);
       }
       
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
        erro("erro gethostbyname. \n", -1);
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
              fprintf(stdout, ": %s%s%s\n", argv[1], argv[3],argv[2]);
    fclose(fileptr);
    return 0;
}
