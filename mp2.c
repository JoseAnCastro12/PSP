#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
//ABUELO-PADRE-NIETO
void main() {
  pid_t pid, padre_pid, pid2,nieto_pid;  
 
  // Soy el ABUELO
  pid = fork();
  if (pid == 0 )
  {
    pid2 = fork();//creo el proceso 2
    if (pid2 == 0)
    {
     //proceso nieto
    printf("\tSoy el proceso NIETO %d; Mi padre es = %d \n",getpid(), getppid());
    sleep(5);
   
    }
    else
    {
     //proceso padre
     nieto_pid= wait(NULL);
    printf("\tSoy el proceso PADRE %d, Mi padre es: %d.\n", getpid(), getppid());
   
   
    }
    sleep(5);
    }

else //proceso ABUELO
{
padre_pid= wait(NULL); //espera la finalización del proceso hijo
printf("\tSoy el proceso ABUELO: %d, Mi HIJO: %d terminó.\n", getpid(), padre_pid);
}
exit(0);
 

 
}
