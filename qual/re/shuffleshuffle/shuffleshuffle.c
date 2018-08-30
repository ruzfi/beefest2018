#include<stdio.h>
#include<string.h>

/*gcc -m32 -fno-stack-protector -no-pie -std=c89 -O0 -o soal_rev1 soal_rev1.c*/
/*gcc 7.3.0*/
/*r3verS1ng_i5_FuN_aNd_ez*/

int WAT[23] = {14, 5, 20, 1, 21, 15, 0, 11, 4, 9, 10, 12, 18, 3, 6, 17, 16, 7, 22, 8, 19, 13, 2};
char * WKWK = "uS_3eNr5r_i_Ne1a_nzgdFv";

int main(){
	char input[24];
	
	printf("FLAG???\n");
	scanf("%23s", input);

	int ii;
	int jj;
	for(ii=0; ii<23; ii++){
		if(input[WAT[ii]]  != WKWK[ii]){
			printf("WRONG FLAG!\n");
			return 0;
		}
	}

	printf("CORRECT!\n");
}
