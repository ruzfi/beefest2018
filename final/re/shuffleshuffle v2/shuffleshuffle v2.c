#include<stdio.h>
#include<string.h>

/*gcc -m32 -std=c89 -O0 -o soal_rev0 soal_rev0_v1.c*/
/*gcc 7.3.0*/
/*tHe_fLa9_i5:reVers1nG_f0r_fuN_4nd_PrOfiT*/

int HAH[40] = {28, 32, 3, 16, 10, 7, 5, 1, 37, 27, 39, 8, 18, 38, 36, 26, 25, 14, 0, 17, 4, 11, 12, 24, 15, 33, 6, 20, 2, 9, 22, 31, 23, 13, 29, 19, 30, 35, 34, 21};
char * WEW = "\x41\x4b\x38\x6c\x25\x1c\x41\x3e\x43\x74\x32\x3f\x1f\x44\x4a\x52\x4e\x54\x6d\x58\x62\x22\x5f\x5d\x4e\x37\x3d\x3f\x5c\x53\x4a\x62\x12\x57\x39\x4d\x25\x58\x31\x5c";
int HEH[40] = {3, 31, 26, 15, 33, 38, 14, 30, 12, 28, 22, 9, 8, 36, 40, 23, 21, 19, 24, 4, 27, 7, 2, 17, 20, 5, 37, 18, 32, 34, 1, 35, 10, 11, 29, 16, 6, 39, 25, 13};

int main(){
	char input[41];
	int l = strlen(WEW);
	char huehue[5];
	
	int j = l % 10;
	int i = l / 10;

	huehue[0] = '%';
	huehue[1] = '0' + i;
	huehue[2] = '0' + j;
	huehue[3] = 's';
	huehue[4] = '\0';

	puts("FLAG???");
	scanf(huehue, input);

	int ii;
	int jj;
	for(ii=0, jj=l-1; ii<l, jj>=0; ii++, jj--){
		if(input[HAH[ii]] - HEH[jj] != WEW[ii]){
			printf("WRONG FLAG!\n");
			return 0;
		}
	}

	printf("CORRECT!\n");
}
