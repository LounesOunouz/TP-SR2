#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <signal.h>
void handler(int sig)
{
    printf("SIGUSR1 recu par %d\n", getpid());
}
int main(int argc, char **argv)
{
    struct sigaction sa;
    sa.sa_handler = handler;
    sa.sa_flags = 0;
    sigemptyset(&sa.sa_mask);
    sigaction(SIGUSR1, &sa, NULL);

    time_t t = time(NULL);

    while (1)
    {
        printf("Mon numero est  %d, il est  %s", getpid(), ctime(&t));
        sleep(1);
    }
    return 0;
}