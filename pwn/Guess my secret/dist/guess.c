#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FLAGSIZE_MAX 64
#define SECRETSIZE_MAX 32

void win(){
    /*
        your win function, no need to worry about this
    */
}

void setup(){
    /*
        some code, no need to worry about this
    */
}

void vuln(){
    char buffer[40];
    char secret[SECRETSIZE_MAX];
    FILE *fd;
    size_t n;
    
    /*
        some code to load the secret, no need to worry about this
    */

    /*
        some code, no need to worry about this
    */
    
    printf("are you ready? \033[1;36m(yes/no):\033[1;0m ");
    fgets(buffer, 40, stdin);

    /*
        some code, no need to worry about this
    */
    if(strcmp(buffer, "yes") != 0){
        printf(buffer);
        printf("? okay then..");
        exit(1);
    }

    printf("\ngreat! so what's my secret?\n");
    printf("\033[1;36msecret: \033[1;0m");
    fgets(buffer, SECRETSIZE_MAX, stdin);
 
    /*
        some code, no need to worry about this
    */
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