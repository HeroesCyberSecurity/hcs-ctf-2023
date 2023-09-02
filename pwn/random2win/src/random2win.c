#include <stdio.h>
#include <stdlib.h>
#include <signal.h>

#define FLAGSIZE_MAX 64

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
}

void vuln(){
    int guess;
    int random = rand() % 640;

    printf("I just made a simple random number generator, surely its random enough right?\n");
    printf("\nlets see if you can defeat my random number generator...\n");
    printf("what's my random number: ");

    scanf("%d", &guess);

    if(guess != random){
        printf("\nwelp, seems like random enough");
        exit(1);
    } else{
        win();
    }
}

int main(){
    setup();
    vuln();
    return 0;
}