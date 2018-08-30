#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

typedef struct note
{
	void (*print_note)(char *, char *);
	char *title;
	char *content;
}note;

void init()
{
	setvbuf(stdin,0,2,0);
	setvbuf(stdout,0,2,0);
	alarm(60);
}

size_t read_bytes(void *mem, size_t n)
{
	size_t length = read(0,mem,n);
	if(*((char *)&mem[length-1]) == '\n') *(((char *)&mem[--length])) = 0;
	return length;
}

int read_num(void *mem, size_t n)
{
	read_bytes(mem,n);
	return atoi(mem);
}

void print_note(char *title, char *content)
{
	puts(title);
	puts(content);
}

unsigned int index;
note *notes[16];

void create_note()
{
	int n;
	char buffer[16];
	if(index < 16)
	{
		note *p = (note *)malloc(sizeof(note));
		if(!p) exit(0);
		notes[index++] = p;
		p->print_note = print_note;
		p->title = (char *)malloc(16);
		if(!(p->title)) exit(0);
		printf("Title: ");
		read_bytes(p->title,16);
		printf("Size: ");
		n = read_num(buffer,16);
		p->content = (char *)malloc(n);
		if(!(p->content)) exit(0);
		printf("Content: ");
		read_bytes(p->content,n);
		puts("Success!");
	}
	else puts("You can't create notes anymore!");
}

void view_note()
{
	int choice;
	char buffer[16];
	do
	{
		printf("Index of the note: ");
		choice = read_num(buffer,16)-1;
	}while(choice < 0 || choice > index-1);
	if(notes[choice])
	{
		note *p = notes[choice];
		p->print_note(p->title,p->content);
	}
	else puts("Note wasn't found.");
}

void delete_note()
{
	int choice;
	char buffer[16];
	do
	{
		printf("Index of the note: ");
		choice = read_num(buffer,16)-1;
	}while(choice < 0 || choice > index-1);
	if(notes[choice])
	{
		note *p = notes[choice];
		free(p->title);
		free(p->content);
		free(p);
		puts("Note deleted!");
	}
	else puts("Note wasn't found.");
}

void menu()
{
	puts("Bee note");
	puts("========");
	puts("1. Create note");
	puts("2. View note");
	puts("3. Delete note");
	puts("4. Exit");
}

int main()
{
	int choice;
	char buffer[16];
	init();
	printf("Your user ID is: %llu\n",stdin);
	do
	{
		menu();
		do
		{
			printf(">> ");
			choice = read_num(buffer,16);
		}while(choice < 1 || choice > 4);
		if(choice == 1) create_note();
		else if(choice == 2) view_note();
		else if(choice == 3) delete_note();
		else if(choice == 4) break;
		else puts("What are you inputting ?");
	}while(choice != 4);
	return 0;
}
