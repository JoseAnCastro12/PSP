#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>

void main() {
    pid_t pid1, pid2, pid3;

    // Crear el primer hijo
    pid1 = fork();

    if (pid1 == 0) {
    if(getpid()%2==0)
    {
    printf("Soy el proceso hijo P2(tio) ... \n");
    printf("\tmi pid es ... %d \n",getpid());
    printf("\tMi padre es ... %d \n",getppid());
    }
    else
    {
    printf("Soy el proceso hijo P2(tio) ... \n");
    printf("\tmi pid es ... %d \n",getpid());
    }
         
    }
    else  
    {
        // Este es el proceso padre

        // Crear el segundo hijo
        pid2 = fork();

        if (pid2 == 0) {
       
            // Este es el segundo hijo
            if(getpid()%2==0)
            {
            printf("\tSoy el proceso hijo P3(padre) ... %d \n", getpid());
    printf("\tMi padre es ... %d \n",getppid());
            }
            else
            {
            printf("\tSoy el proceso hijo P3(padre) ... %d \n", getpid());
            }
   
            // Crear un tercer hijo desde el segundo hijo
            pid3 = fork();

            if (pid3 == 0)
            {
                // Este es el tercer hijo
                if(getpid()%2==0)
                {
                printf("\tSoy el proceso hijo P4(nieto) ... %d \n", getpid());
    printf("\tMi padre es el segundo hijo... %d \n",getppid());
                }
                else
                {
                printf("\tSoy el proceso tercer hijo(nieto) ... %d \n", getpid());
                }
            }
        }
       

        // Esperar a que todos los hijos terminen
        wait(NULL);
    }

    exit(0);
}
