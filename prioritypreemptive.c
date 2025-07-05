include<stdio.h>
#include<stdlib.h>

typedef struct process{
	int id,at,bt,ct,wt,priority,tat;
}pro;

void main(){
	int i,j;
	int n,tempbt[15],total_wt=0,total_tat=0;
	float avg_wt=0,avg_tat=0;
	printf("\n Enter the number of processes");
	scanf("%d",&n);
	pro p[n];
	printf("\n Enter the arrival time,burst time and priority");
	printf("\n AT BT P\n");
	for(i=0;i<n;i++){
		p[i].id=i+1;
		scanf("%d %d %d",&p[i].at,&p[i].bt,&p[i].priority);
		tempbt[i]=p[i].bt;
	}
	int minindex,minpriority,completed=0,curtime=0;
	
	while(completed!=n){
		minindex = -1;
		minpriority=9999;
		for( i=0;i<n;i++){
		   if(p[i].at<=curtime && p[i].bt>0){
		   	if(p[i].priority<minpriority||p[i].priority==minpriority && p[i].at<=p[minindex].at){
		   		minpriority=p[i].priority;
		   		minindex=i;
			   }
		   }
		}
		curtime++;
		if(minindex!=-1){
			p[minindex].bt--;
			printf("|P %d(1)%d",p[minindex].id,curtime);
			if(p[minindex].bt==0){
				p[minindex].ct=curtime;
				p[minindex].tat=p[minindex].ct-p[minindex].at;
				p[minindex].wt=p[minindex].tat-tempbt[minindex];
				total_tat+=p[minindex].tat;
				total_wt+=p[minindex].wt;
				completed++;
			}
		}
		
	}
	printf("\n");
	avg_wt=(float)total_wt/n;
	avg_tat=(float)total_tat/n;
	printf("\n PID \t AT \t BT \t CT \t TAT \t WT \t P \n");
	for(i=0;i<n;i++){
		printf("%d \t %d \t %d \t %d \t %d \t %d \t %d \n",p[i].id,p[i].at,p[i].bt,p[i].ct,p[i].tat,p[i].wt,p[i].priority);
	}
	printf("\n Average tat=%.2f \n Average wt=%.2f \n",avg_tat,avg_wt);
	
}
