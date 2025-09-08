#include <stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<unistd.h>

int main() {
    pid_t parent_pid,child_pid,my_pid;
    child_pid=fork();
    if(child_pid<0)
    {
        printf("\n Fork failed");
        exit(0);
    }
    if(child_pid==0){
        printf("[CHILD]This is the child process\n");
        my_pid=getpid();
        parent_pid=getppid();
        printf("[CHILD]my pid is %d \n",my_pid);
        printf("[CHILD]my parent's pid is %d \n",parent_pid);
        printf("[CHILD]Exiting");
        exit(0);
        
    }
    else{
       printf("[PARENT]This is the parent process\n");
        my_pid=getpid();
        parent_pid=getppid();
        printf("[PARENT]my pid is %d \n",my_pid);
        printf("[PARENT]my parent's pid is %d \n",parent_pid);
        printf("[PARENT]Sleeping for 10 seconds");
        sleep(10);
        printf("[PARENT] Child pid=%d has ended but still it has an entry in the process table,It is a zombie process",child_pid);
    }
      return 0;    }
