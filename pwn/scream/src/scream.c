#include <stdio.h>
#include <stdlib.h>
#include <signal.h>

#define FLAGSIZE_MAX 64

void give_flag(){
  char flag[FLAGSIZE_MAX];
  FILE *fd;

  fd = fopen("flag.txt", "r");
  if (fd == NULL){
    printf("%s%s", 
          "flag.txt not found, please create a flag.txt\n",
          "if this happened on remote server please contact admin");
    exit(1);
  }
  fgets(flag, 64, fd);

  printf("%s%s%s",
  "\nTch. fine, fine, here, go and have it!\n",
  flag,
  "\nnow give me a favour and be quiet will ya?\n");
}

void sigsegv_handler(int sig){
  give_flag();
  fflush(stdout);
  exit(1);
}

void setup(){
	setvbuf(stdout, NULL, _IONBF, 0);
	setvbuf(stdin, NULL, _IONBF, 0);
	setvbuf(stderr, NULL, _IONBF, 0);

  signal(SIGSEGV, sigsegv_handler); // Set up signal handler
}

void vuln(){
  char buffer[0x100];
  gets(buffer);
}

int main(){
  setup();

  printf("%s%s%s%s",
        "Look its midnight over here,\n",
        "can you please be quiet and dont make loud noises?\n",
        "appreciate it. thanks.\n\n",
        "Input: ");
  fflush(stdout);

  vuln();
  printf("\nzzzzzzzzz.......");

  return 0;
}