#include <stdio.h>
#include <stdlib.h>
#include <signal.h>

#define FLAGSIZE_MAX 64

void sigsegv_handler(int sig){
  printf("welp, feel free to try again");
  fflush(stdout);
  exit(1);
}

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

    printf("\nNoice, nih flagnya: \n");
    printf(flag);
    exit(0);
}

void setup(){
    setvbuf(stdout, NULL, _IONBF, 0);
    setvbuf(stdin, NULL, _IONBF, 0);
    setvbuf(stderr, NULL, _IONBF, 0);
    signal(SIGSEGV, sigsegv_handler); // Set up signal handler
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

    printf("welp, feel free to try again!");
    return 0;
}