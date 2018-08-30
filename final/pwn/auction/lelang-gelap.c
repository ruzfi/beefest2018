#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void auction ()
{
    int player = 0;
    int input = 0;
    int computer = 0;
    int temp = 0;
    int x = 0;
    puts ("Pelelangan dimulai!!!");
    puts ("Oiya, satu lagi, tawaran jangan dibawah 1000 ya :)");
    while (x < 5)
    {
        printf ("Masukan tawaran: ");
        fflush (stdout);
        scanf ("%d", &input);
        if (input < 1000)
        {
            puts ("Kan, dah dibilang jangan. Keluar deh -_-");
            exit (0);
        }
        else
        {
            srand (time (NULL));
            temp = input - (rand() % (10+1 - 1));
            if (x < 1)
            {
                computer = temp-1;
            }
            else
            {
                if (computer >= input)
                {
                    computer = temp;
                }
            }
            printf ("Lawan anda menawar %d\n", computer);
            x++;
            player++;
        }
    }
    player += input;
    if (player >= computer)
    {
        puts ("Yah, sayang, lawan anda lebih imba :(");
        exit (0);
    }
    else
    {
        puts ("Wah, anda kotor sekali!");
        puts ("Anda layak untuk mendapatkan barang keramat ini ;)");
        system ("/bin/cat flag");
        exit (0);
    }
}

int main (void)
{
    puts ("Selamat datang di Pelelangan Pasar Gelap!");
    puts ("Dalam ronde ini, kami akan menjual:");
    puts ("");
    puts (" _____ _           ______ _       ___  _____ ");
    puts ("|_   _| |          |  ___| |     / _ \\|  __ \\");
    puts ("  | | | |__   ___  | |_  | |    / /_\\ \\ |  \\/");
    puts ("  | | | '_ \\ / _ \\ |  _| | |    |  _  | | __ ");
    puts ("  | | | | | |  __/ | |   | |____| | | | |_\\ \\");
    puts ("  \\_/ |_| |_|\\___| \\_|   \\_____/\\_| |_/\\____/");
    puts ("");
    puts ("");
    puts ("");
    puts ("Pelelangan akan dilaksanakan dalam 5 babak, dimana anda harus menawar.");
    puts ("Tetapi tidak seperti pelelangan lainnya, untuk memenangkan barang ini anda harus");
    puts ("menjadi penawar TERENDAH :)");
    puts ("Perlu diingat bahwa anda tidak dapat memasukkan angka negatif");
    puts ("karena hal itu merupakan kecurangan :)");
    puts ("");
    puts ("");
    puts ("");
    auction ();

}
