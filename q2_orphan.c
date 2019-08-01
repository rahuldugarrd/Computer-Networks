#include<stdio.h> 
#include <sys/types.h> 
#include <unistd.h> 
#include <stdlib.h>
int main() 
{ 
    if (fork()) {
        sleep(1);
        printf("In parent process with pid %d\n",getpid());
        sleep(1);
        exit(0);
    }
    else { 
        printf("Child process[%d] with parent[%d]\n",getpid(),getppid());
        sleep(3);
        printf("Child process[%d]\'s parent after becoming an orphan-%d\n",getpid(),getppid());
    } 
    return 0; 
} 
