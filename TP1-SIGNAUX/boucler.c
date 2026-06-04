#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
int main(int argc, char **argv)
{
    printf("Bonjour\n");
    if (argc != 3)
    {
        fprintf(stderr, "Usage : Nombre d'arguments \n");
        exit(1);
    }
    time_t t = time(NULL);
    int NBS = atoi(argv[1]);
    int NBF = atoi(argv[2]);
    for (int i = 0; i < NBF; i++)
    {
        printf("Mon numero est  %d, il est  %s", getpid(), ctime(&t));
        sleep(NBS);
    }
    return 0;
}