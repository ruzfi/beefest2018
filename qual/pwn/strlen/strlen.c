#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

/* Kodingan ini tidak perlu dibaca */
void init()
{
    setvbuf(stdin,0,2,0);
    setvbuf(stdout,0,2,0);
    alarm(60);
}
/* =============================== */

int buggy_check (char *string)
{
    int x = 0;
    while (string [x] != '\n')
    {
        x++;
    }
    return x;
}

int main (void)
{
    char var [64];

    puts ("Kata orang, fungsi strlen() tidak very secure.");
    puts ("Sebagai seorang h4ck3r, anda harus dapat melihat sesuatu dari segala sisi.");
    puts ("Dapatkah anda memasukkan input yang panjangnya melebihi batasan strlen()?");
    puts ("Jika anda bisa memasukkan lebih dari 32 karakter,");
    puts ("saya akan memberikan anda flag-nya :)");
    printf ("> ");
    fflush (stdout);
    fgets (var, 64, stdin);
    if (strlen (var) > 32)
    {
        puts ("Coba lebih kreatif lagi ;)");
        exit (0);
    }
    else
    {
        if (buggy_check (var) <= 32)
        {
            puts ("Yah, anda ga niat ya :(");
            exit (0);
        }
        else
        {
            puts ("Nah, bisa kan :D");
            system ("/bin/cat flag");
            exit (0);
        }
    }
}
