#include <stdlib.h> 
#include <sys/types.h> 
#include <unistd.h>
#include <stdio.h>
int main() 
{  
	if(fork()) {
		printf("Parent process going to sleep %d\n",getpid());
		sleep(60); 
	}
	else {
		printf("Child process which is about to terminate and become zombie, PID- %d Parent PID- %d\n",getpid(),getppid());
		exit(0);
	} 
	return 0; 
} 

