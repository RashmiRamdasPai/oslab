#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include<semaphore.h>

sem_t empty;
sem_t full;
pthread_mutex_t mutex;
int buffer[3];
int in=0;
int out=0;
int i,j;
void *producer(void *pro){
	for(i=0;i<3;i++){
	
	 int item=rand()%100;
	sem_wait(&empty);
	pthread_mutex_lock(&mutex);
	buffer[in]=item;
	printf("\n Procucer %d inserted item %d into %d",  *((int *)pro),buffer[in],in);
	in=(in+1)%3;
	pthread_mutex_unlock(&mutex);
	sem_post(&full);
}}

void *consumer(void *cno){
	for(i=0;i<3;i++){
		sem_wait(&full);
		pthread_mutex_lock(&mutex);
		int item=buffer[out];
		printf("\n Consumer %d  removed item %d from %d",  *((int *)cno),item,out);
		out=(out+1)%3;
		pthread_mutex_unlock(&mutex);
		sem_post(&empty);
	}
}

int main(){
	pthread_t pro[3],con[3];
	pthread_mutex_init(&mutex,NULL);
	sem_init(&empty,0,3);
	sem_init(&full,0,0);
	int a[3]={1,2,3};
	for(i=0;i<3;i++)
	   pthread_create(&pro[i],NULL,(void *)producer,(void *)&a[i]);
	for(i=0;i<3;i++)
	     pthread_create(&con[i],NULL,(void *)consumer,(void *)&a[i]);
	for(i=0;i<3;i++)
	  pthread_join(pro[i],NULL);
	for(i=0;i<3;i++)
	   pthread_join(con[i],NULL);
	   pthread_mutex_destroy(&mutex);
	   sem_destroy(&full);
	   sem_destroy(&empty);
	   return 0;
}
