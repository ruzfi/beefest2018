#include <stdio.h>

// gcc hexamethics.c -o hexamethics -no-pie

long int calculate(){
	long v1,v2,v3,v4,v5;

	v1 = 0xbeefe518;
	v2 = 0xdeadf00d;
	v3 = 0x10c4115e;
	v4 = 0x0ff1c1a1;

	v1 *= v4;
	v1 /= v3;
	v2 %= v3;
	v1 -= v2;

	return v1;
}

int main(void){

	long int a1 = calculate();
	long int a2;

	printf("Selamat datang di IndoJuni, passwordnya apa?: ");scanf("%lX",&a2);fflush(stdin);
	a2 == a1 ?  printf("Selamat berbelanja :D\nflag: BeeFest{%lX}\n",a2): printf("Salah :^(\n)");
	getchar();
	return 0;

}
