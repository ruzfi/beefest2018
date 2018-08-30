#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/ptrace.h>

#define A(c) (char) (((int) (c)) ^ 108)

//char passwd[8] = { A('t'), A('e'), A('s'), A('t'), A('c'), A('b') };
char passwd[8] = { A('6'), A('p'), A('4'), A('i'), A('9'), A('2'),};

void detect_gdb(void) __attribute__((constructor));

void detect_gdb(void)
{
  
  FILE *fd = fopen("/tmp", "r");
  if (fileno(fd) > 5)
    {
      printf("I'm sorry GDB! You are not allowed!\n");
      exit(1);
    }
  fclose(fd);

  if (ptrace(PTRACE_TRACEME, 0, 1, 0) < 0) {
    printf("Tracing is not allowed... Bye\n");
    exit(1);
  }

}

void xor(char *p)
{
  int i;

  for (i = 0; i < 6; i++)
    {
      p[i] ^= 108;
    }
}

int compare(char *input, char *passwd)
{
  while (*input == *passwd)
    {
      if (*input == '\0' || *passwd == '\0' )
	break;

      input++;
      passwd++;
    }
  if (*input == '\0' && *passwd == '\0')
    return 0;
  else
    return -1;
}

int main() {

  char input[8];
  
  fputs("Please tell me my password: ", stdout);

  fgets(input, sizeof input -1, stdin);

  xor(input);

  if (compare(input, passwd) == 0)
    fputs("The password is correct!\nFormat Flag : BeeFest{*password*}\n", stdout);
  else
    fputs("That's not it! Try again.\n", stdout);

  return 0;

}
