#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<fcntl.h>
#include<unistd.h>
#include<sys/stat.h>
#define BUFFERSIZE 30

int main(){
	int fd=open("C:/Users/RASHMI R PAI/myfile.txt",O_RDWR);
	int n;
	if(fd==-1){
		printf("\n Unable to open the file");
		exit(0);
	}
	printf("\n File descriptor is %d ",fd);
	char buffer[BUFFERSIZE];
	printf("\n Reading first 10 characters from file");
	n=read(fd,buffer,10);
	write(1,buffer,n);
	printf("\n Skipping 5 characters from the current position");
	lseek(fd,5,SEEK_CUR);
	read(fd,buffer,10);
	write(1,buffer,n);
	printf("\n Going 10 characters before the current position");
	lseek(fd,-10,SEEK_CUR);
	n=read(fd,buffer,10);
	write(1,buffer,n);
	printf("\n Going 5th last character in the file");
	lseek(fd,-5,SEEK_END);
	n=read(fd,buffer,5);
	write(1,buffer,n);
	printf("\n Going to the 3rd character in the file");
	lseek(fd,3,SEEK_SET);
	n=read(fd,buffer,5);
	write(1,buffer,n);
	return 0;
}
