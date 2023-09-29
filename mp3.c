#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>

void main(){
pid_t pid, pid2, padre_pid, pid_hijo,pid_hijo3;

pid = fork();

if (pid == 0 )
  {        
    printf("Soy el proceso hijo P2 ... \n");
    printf("\tmi pid es ... %d \n",getpid());
    printf("\tMi padre es ... %d \n",getppid());
    printf("Voy a dormir 10 segundos ... \n");  
    sleep(10);
   
  }
  else    //Nos encontramos en Proceso padre
  {
   pid_hijo = wait(NULL);
   pid2=fork();
   if(pid2 == 0)
   {
   
    printf("Estoy despierto");
    printf("\tSoy el proceso hijo P3 ... %d \n", getpid());
    printf("\tMi padre es ... %d \n",getppid());
    sleep(5);
   }
   else{
   pid_hijo3 = wait(NULL); //espera la finalización del proceso hijo
   
   printf("Soy el proceso padre\n");
   printf("\t mi pid es: %d \n",getpid());
   printf("\t elpid de mi proceso hijo P2 es: %d \n", pid_hijo);
   printf("\t elpid de mi proceso hijo P3 es: %d \n", pid_hijo3);
           
  }
  }
exit(0);
}
