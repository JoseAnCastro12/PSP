#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h> 

void main(){

     int fd[2]; 
     char buffer[30];
     pid_t pid;
    
     // Creamos el pipe
     pipe(fd); 
     
     //Se crea un proceso hijo
     pid = fork();

     if (pid==0)
     
     {
                close(fd[1]); // Cierra el descriptor de escritura
                printf("Soy el proceso hijo con PID %d",getpid());
                read(fd[0],buffer, 30);
                write(fd[1], "Hola padre", 10); 
                printf("%s \n", buffer);
     }
     
     else
     
     {
                close(fd[0]); // Cierra el descriptor de lectura
                write(fd[1],"\t Fecha/Hora 8:56:12, 25/10/23\n",30);  
                wait(NULL);
     }
     
        
}
