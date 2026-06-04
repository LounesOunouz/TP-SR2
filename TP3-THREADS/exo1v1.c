#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <wait.h>
int main(int argc, char **argv)
{
    printf("DÉBUT DU PROGRAMME\n");
    if (argc != 3)
    {
        fprintf(stderr, "USAGE : Pas assez d'arguments \n");
        exit(1);
    }
    int NA = atoi(argv[1]);
    int NF = atoi(argv[2]);
    pid_t pid;
    for (int i = 0; i < NA; i++)
    {
        switch (pid = fork())
        {
        case -1:
            perror("echec du fork \n");
            exit(2);
        case 0:
            for (int k = 0; k < NF; k++)
            {
                // int delaii = rand();
                int delaii = 1;
                printf("Activité rang %d, identifiant = %d (delai = %d)\n", i, getpid(), delaii);
                // usleep(delaii);
                sleep(1);
            }
            exit(i);
        }
    }
    int status;
    int x = 0;

    // while (x != -1)
    for (int j = 0; j < NA; j++)
    {
        x = wait(&status);
        printf("valeur retourné par le fils %d = %d\n", x, WEXITSTATUS(status));
    }
    return 0;
}