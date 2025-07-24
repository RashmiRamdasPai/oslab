#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
 int i,j;
void *sum(void * arg);
void *mul(void * arg);
int sm=0,pro=1;
void *sum(void *arg){
	int n=atoi(arg);
	for(i=0;i<=n;i++)
	  sm=sm+i;
}
void *mul(void * arg){
	int n=atoi(arg);
	for(i=2;i<=n;i++)
	  pro=pro*i;
}

void main(int argc,char *argv[]){
	pthread_t T1,T2;
	pthread_attr_t attr;
	pthread_attr_init(&attr);
	pthread_create(&T1,&attr,sum,argv[1]);
	pthread_create(&T2,&attr,mul,argv[1]);
	pthread_join(T1,NULL);
	pthread_join(T2,NULL);
	printf("\n Inside main thread \n");
	printf("Sum %d",sm);
	printf("pro %d",pro);
	
}
