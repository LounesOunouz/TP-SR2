#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <signal.h>
#include <wait.h>
void handler(int sig)
{
    printf("SIGINT recu par %d\n", getpid());
}
int main(int argc, char **argv)
{
    struct sigaction sa;
    sa.sa_handler = handler;
    sa.sa_flags = 0;
    sigemptyset(&sa.sa_mask);
    sigaction(SIGINT, &sa, NULL);

    pid_t pid;
    switch (pid = fork())
    {
    case -1:
        perror("echec du fork");
        exit(2);
    case 0:
        while (1)
        {
            time_t t = time(NULL);
            printf("Mon numero est  %d, il est  %s", getpid(), ctime(&t));
            sleep(1);
        }
        exit(0);
        // default:
    }
    printf("Je suis le pere <<%d>>\n", getpid());
    int status;
    int x = 0;
    do
    {
        x = wait(&status);
    } while (x == -1);

    return 0;
}