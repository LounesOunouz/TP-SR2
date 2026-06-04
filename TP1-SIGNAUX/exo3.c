#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <signal.h>
char *NBF;
char *NBS;
void handler(int sig)
{
    printf("SIGINT recu par %d\n", getpid());
    execlp("./boucler", "boucler", NBS, NBF, NULL);
}
int main(int argc, char **argv)
{
    if (argc != 3)
    {
        fprintf(stderr, "Usage: PAs assez d'arguments\n");
        exit(2);
    }
    NBS = argv[1];
    NBF = argv[2];
    struct sigaction sa;
    sa.sa_handler = handler;
    sa.sa_flags = 0;
    sigemptyset(&sa.sa_mask);
    sigaction(SIGINT, &sa, NULL);

    time_t t = time(NULL);

    while (1)
    {
        printf("<<<<<<<Mon numero est  %d, il est  %s", getpid(), ctime(&t));
        sleep(1);
    }
    // printf("je suis au programme de départ\n");
    return 0;
}