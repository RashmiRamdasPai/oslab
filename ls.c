#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<string.h>
#include<dirent.h>
int main(int argc,char *argv[]){
        if(argc<2){
                printf("\n No enough arguments");
                exit(0);
        }
        DIR *dp;
        struct dirent *dirp;
        dp=opendir(argv[1]);
        if(dp==NULL){
                printf("\n Error");
                exit(0);
        }

        while((dirp=readdir(dp))!=NULL)
                printf("%s\n",dirp->d_name);
                closedir(dp);}
