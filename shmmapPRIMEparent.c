#include<stdio.h>
#include<string.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<sys/shm.h>
#include<sys/mman.h>
#include<sys/ipc.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<unistd.h>
#include<stdlib.h>
#define SIZE 4096
int main(int argc,char *argv[]){
        pid_t childpid;
        int shmid,i,j;

        void *ptr;
        if(argc>2){
                sscanf(argv[1],"%d",&i);
                sscanf(argv[2],"%d",&j);
                if(i<2){
                        printf("\n Error input %d\n",i);
                        return 0;
                }}
        else{
                printf("\n Minimum no of arguments is not passed");
                exit(0);
        }
        childpid=fork();
        if(childpid==0)
                execlp("./prime","prime",argv[1],argv[2],NULL);
        else{
                wait(NULL);
                shmid=shm_open("VSS",O_RDONLY,0666);
                ptr=mmap(0,SIZE,PROT_READ,MAP_SHARED,shmid,0);
                printf("%s",(char *)ptr);
                shm_unlink("VSS");
        }
        return 0;
}
