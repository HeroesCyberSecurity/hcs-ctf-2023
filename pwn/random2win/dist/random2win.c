#include <stdio.h>
#include <stdlib.h>
#include <signal.h>

#define FLAGSIZE_MAX 64

void win(){
    /*
        your win function
    */
}

void setup(){
    /*
        some code, no need to worry about this
    */
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