#include <stdio.h>
#include <stdlib.h>

// $ gcc shialabof.c -o shialabof -fno-stack-protector -z execstack -no-pie -m32

int main(){
    volatile int var = 1337;
	char buf[32];
	printf("Enter your name: ");
	gets(buf);
	printf("Hello, %s\n", buf);
	printf("var = %d\n", var);
	if(var != 1337){
		system("/bin/cat flag.txt");
	} else{
		printf("Can't change the variable? JUST, DO IT! DON'T LET YOUR DREAMS BE DREAMS.\n");
	}
}
