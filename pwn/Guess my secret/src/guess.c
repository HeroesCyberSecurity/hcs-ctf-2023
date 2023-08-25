#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FLAGSIZE_MAX 64
#define SECRETSIZE_MAX 32

void win(){
    char flag[FLAGSIZE_MAX];

    FILE *fd = fopen("flag.txt", "r");
    if (fd == NULL){
    printf("%s%s", 
            "flag.txt not found, please create a flag.txt\n",
            "if this happened on remote server please contact admin");
    exit(1);
    }
    fgets(flag, FLAGSIZE_MAX, fd);

    printf("\nCongrats! here's your reward: \n");
    printf(flag);
}

void setup(){
    setvbuf(stdout, NULL, _IONBF, 0);
    setvbuf(stdin, NULL, _IONBF, 0);
    setvbuf(stderr, NULL, _IONBF, 0);
}

void vuln(){
    char buffer[40];
    char secret[SECRETSIZE_MAX];
    FILE *fd;
    size_t n;
    
    fd = fopen("secret.txt", "r");
    if (fd == NULL){
    printf("%s%s", 
            "flag.txt not found, please create a flag.txt\n",
            "if this happened on remote server please contact admin");
    exit(1);
    }
    fgets(secret, SECRETSIZE_MAX, fd);
    n = strlen(secret);
    if ( n && secret[n-1] == '\n' ) secret[n-1] = '\0';

    printf("Hej! Here's a simple challenge\n\n");
    printf("I will hold a \033[1;36msecret\033[1;0m\n");
    printf("Your task is to guess my \033[1;36msecret\033[1;0m\n");
    printf("simple right?\n\n");
    
    printf("are you ready? \033[1;36m(yes/no):\033[1;0m ");
    fgets(buffer, 40, stdin);

    // removing newline, conflict when compares
    n = strlen(buffer);
    if ( n && buffer[n-1] == '\n' ) buffer[n-1] = '\0';
    if(strcmp(buffer, "yes") != 0){
        printf(buffer);
        printf("? okay then..");
        exit(1);
    }

    printf("\ngreat! so what's my secret?\n");
    printf("\033[1;36msecret: \033[1;0m");
    fgets(buffer, SECRETSIZE_MAX, stdin);
 
    n = strlen(buffer);
    if ( n && buffer[n-1] == '\n' ) buffer[n-1] = '\0';
    if(strcmp(buffer, secret) == 0){
        win();
    } else {
        printf("welp, goodluck next time!");
    }
}

int main(){
    setup();
    vuln();
    return 0;
}