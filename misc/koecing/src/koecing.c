#include <stdio.h>
#include <stdlib.h>

void setup(){
	setvbuf(stdout, NULL, _IONBF, 0);
	setvbuf(stdin, NULL, _IONBF, 0);
	setvbuf(stderr, NULL, _IONBF, 0);
}

int main(){
   setup();

   puts("Meow Meow Meow?\n");
   system("/bin/cat flag.txt");
   return 0;
}