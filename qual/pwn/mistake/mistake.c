#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

/* Kodingan ini tidak perlu dibaca */
#define flush while(getchar()!=10);
void init()
{
    setvbuf(stdin,0,2,0);
    setvbuf(stdout,0,2,0);
    alarm(60); 
}
/* =============================== */

int main()
{
    init();
	int a,b,c;
	printf("Ikuti aturannya dan menangkan hadiahnya!\n");
	printf("Masukkan angka pertama : ");
	scanf("%d",&a); /* Setelah scan angka, buang newline */ flush;
	printf("Masukkan angka kedua : ");
	scanf("%d",&b); flush;
	if(c=a*b+a-b<=0)
	{
		system("cat ./flag ");
	}
	else
	{
		printf("Kurang beruntung\n");
	}
}
