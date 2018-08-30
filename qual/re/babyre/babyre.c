#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
void print(int angka){
	for(int i = 0 ; i < angka ; i++){
		usleep(10000);
	}
}
int main(){
	for(int i = 0 ; i < 10000000 ; i++){
		print(20);
		printf("Sabardong \n Halo reverse aku dong\n");
		printf("coba cek rahasianya\n");
	}
	printf("BeeFest{basic_reverse_bisa_");
	printf("gak_liat_sampe_sini_!}\n");
	getchar();
	return 0;
}
