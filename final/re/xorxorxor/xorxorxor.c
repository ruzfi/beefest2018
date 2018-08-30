#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct data{
	char password[25];
	char namafile[20];
}data[100];
char text1[25] = {"abcdefghjklmnopqrstuvwxy"};
char text2[25] = {"can you see me in hereee"};
char text3[25] = {"H3LL0_W0RLD"};
int index3 = 0;

void xor(){
	int i = 2;

	int arc = strlen(text1);
	int arx = strlen(text3);
	for(int k = 0 ; k < arc ; k++){
		text1[k] = text1[k]^i;
		text2[k] = text2[k]^i;
	}
	for(int x = 0 ; x < arx ; x++){
		text3[x] = text3[x]^i;
	}
}
void writefile(){
	xor();
	FILE *write = fopen("nano.txt","w");
	fprintf(write, "ini adalah petunjuk kunci ini dienkripsi\n");
	fprintf(write, "%s\n", text1);
	fprintf(write, "%s\n", text2);
	fprintf(write, "%s", text3);
	fclose(write);
}
void buka(){
	for(int i = 0 ; i < strlen(text1) ; i++){
		text1[i] = text1[i] ^ 2;
		text2[i] = text2[i] ^ 2;
	}
	for(int i = 0 ; i < strlen(text3); i++){
		text3[i] = text3[i]^2;
	}
}
void readfile(){
	FILE *read = fopen("nano.txt","r");
	if(read == NULL){
		printf("gak ada bang coba jalanin dulu");
	}
	else{
		while(!feof(read)){
			fscanf(read,"%s",data[index3].password);
			index3++;
		}
	}
	fclose(read);
}
void printIsifile(){
	for(int i = 0 ; i < index3 ; i++){
		printf("%s", data[i].password);
	}
}
int main(){
	writefile();
	readfile();
//	printIsifile();
	char password[25];
	buka();
	int argx = strlen(password);
	printf("Masukkan Password : ");scanf("%[^\n]",password);
	if(strcmp(text3, password) == 0){
		printf("here is your flag = BeeFest{%s}\n",text3); 
	}
	else{
		printf("Try again");
	}

	getchar();
	return 0;
}
