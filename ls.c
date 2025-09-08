#include<stdio.h>
#include<stdlib.h>
#include<dirent.h>
#include<sys/types.h>

void main(int argc,char *argv[]){
	DIR *dp;
	struct dirent *dirp;
	if(argc<2){
		printf("\n You are not passing the directory");
		exit(1);
	}
	dp=opendir(argv[1]);
	if(dp==NULL){
	
	 printf("\n Cannot open it");
	 exit(1);
}
    dirp=readdir(dp);
    while(dirp!=NULL)
     printf("%s\n",dirp->d_name);
     closedir(dp);
	}
