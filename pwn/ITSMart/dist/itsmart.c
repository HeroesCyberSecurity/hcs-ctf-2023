#include <stdio.h>
#include <stdlib.h>
#include <signal.h>

#define FLAGSIZE_MAX 64

void win(){
  /*
    you win function, no need to worry about the code
  */
}

void setup(){
	setvbuf(stdout, NULL, _IONBF, 0);
	setvbuf(stdin, NULL, _IONBF, 0);
	setvbuf(stderr, NULL, _IONBF, 0);
}

void menu(){
  puts("mau beli apa gan?");
  puts("(1) ayank Rp.99");
  puts("(2) circle kampus Rp.1");
  puts("(3) IPK 4.0 Rp.666");
}

int main(){
  setup();
  int uang = 1337;
  long c = 0;
  long n = 0;

  puts("selamat datang di ITS Mart!!!\n");
  while(1){
    if(uang <= 0 || uang > 1337){
      puts("loh kok gini ya rek?");
    }

    printf("uang: Rp.%d\n", uang);
    menu();
    scanf("%d", &c);

    switch(c){
      case 1:
        puts("mau beli berapa?");
        scanf("%d", &n);
        uang -= n * 99;
        puts("berhasil membeli ayank <3\n");
        break;
      case 2:
        puts("mau beli berapa?");
        scanf("%d", &n);
        uang -= n * 1;
        puts("berhasil membeli circle kampus\n");
        break;
      case 3:
        puts("mau beli berapa?");
        scanf("%d", &n);
        uang -= n * 666;
        puts("berhasil membeli IPK 4.0\n");
        break;
      case 69:
        if(uang <= 999999999){
          puts("mau flag? harus kaya dlu broh\n");
        } else{
          win();
          exit(1);
        }
        break;
      default:
        puts("klo milih yang benar rek\n");
    }

    c = 0;
    n = 0;
  }

  return 0;
}