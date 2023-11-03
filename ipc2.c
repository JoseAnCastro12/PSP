#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main()
{
    int numeros[] = {25, 18, 67};
    int fd[2];
    char buffer[30];
    int suma = 0;
    pid_t pid;

    pipe(fd);

    pid = fork();

    if (pid == 0)
    {
        close(fd[1]);
        for (int i = 0; i < 3; i++)
        {
            read(fd[0], buffer, 30);
            int num = atoi(buffer); // Convierte el valor leído a entero
            printf("Numero leido en el proceso hijo: %d\n",num);
            suma += num;
        }
        printf("Suma en el proceso hijo: %d\n", suma);
    }
    else
    {
        close(fd[0]);
        for (int i = 0; i < 3; i++)
        {
            char buffer2[30];
            snprintf(buffer2, 30, "%d", numeros[i]); // Convierte el número a cadena
            write(fd[1], buffer2, 30);
        }
        wait(NULL);
    }

    exit(0);
}

