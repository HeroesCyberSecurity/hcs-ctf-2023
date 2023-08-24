#include <stdio.h>
#include <stdlib.h>
#include <signal.h>

#define FLAGSIZE_MAX 64

void sigsegv_handler(int sig){
    /*
        some code, no need to worry about this
    */
}

void win(){
    /*
        your win function,
        but it never gets called in a normal routine,
        can you alter the program execution flow?
    */
}

void setup(){
    /*
        some code, no need to worry about this
    */
}

void vuln(){
    char buffer[40];
    int random = rand() % 640;

    printf("I just made a simple random number generator, surely its random enough right?\n");
    printf("\nlets see if you can defeat my random number generator...\n");
    printf("what's my random number: ");

    fgets(buffer, 24, stdin);

    if(atoi(buffer) != random){
        printf("\nwelp, seems like random enough");
        exit(1);
    }

    printf("\nn-nani??? how did you know that???\n");
    printf("well I'm still not going to give you the flag that easily though\n");
    printf("\nlet's see if you can alter the program execution flow :)\n");
    printf("your payload: ");

    fgets(buffer, 64, stdin);
}

int main(){
    setup();
    vuln();

    /*
        some code, no need to worry about this
    */
    return 0;
}