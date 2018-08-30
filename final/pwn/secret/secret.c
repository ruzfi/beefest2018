#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#define BUF_LEN 64
char buffer[BUF_LEN];

void init()
{
	setvbuf(stdin,0,2,0);
	setvbuf(stdout,0,2,0);
	alarm(60);
}

int main() {
    int secret;
    char rahasia[20] = "Rahasia";
    init();
    srand(time(NULL));
    secret = rand();
    printf("Input sesuatu: ");
    fgets(buffer, BUF_LEN, stdin);
    printf(buffer);
    int not_secret;
    puts("Tebak rahasia dalam hexadecimal!");
    printf("Rahasia: ");
    scanf("%x", &not_secret);
    if(secret == not_secret){
        puts("Selamat!");
        system("cat ./flag");   
    }else{
        puts("Coba lagi!");
    }
    return 0;
}
