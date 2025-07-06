#include<stdio.h>
#include<stdlib.h>

typedef struct process{
	int id,at,bt,ct,wt,tat,rt,finishid;
}Process;
int i,j;
void sjfnp(Process[],int);
void main(){
	int i,j;
	int n,tempbt[15],total_wt=0,total_tat=0;
	float avg_wt=0,avg_tat=0;
	printf("\n Enter the number of processes");
	scanf("%d",&n);
	Process p[n];
	printf("\n Enter the arrival time,burst time and priority");
	printf("\n AT BT \n");
	for(i=0;i<n;i++){
		p[i].id=i+1;
		scanf("%d %d",&p[i].at,&p[i].bt);
		p[i].finishid=0;
		
	}
	sjfnp(p,n);
	return;
}
void sjfnp(Process p[],int n){
  int total_wt=0,total_tat=0,elapsedtime=0,total_rt=0;
	float avg_wt=0,avg_tat=0,avg_rt=0;
	int exec;
	int remainingprocess=n;
	while(remainingprocess){
		exec=-1;
		int shortestbursttime=9999;
		
		for(i=0;i<n;i++){
			if(p[i].at<=elapsedtime && !p[i].finishid){
				if(p[i].bt<shortestbursttime){
					exec=i;
					shortestbursttime=p[i].bt;
				}
			}
		}
		if(exec==-1){
			printf("|(%d)***(%d)",elapsedtime,elapsedtime+1);
			elapsedtime++;
		}else{
			int temp=elapsedtime;
			p[exec].rt=elapsedtime-p[exec].at;
			elapsedtime+=p[exec].bt;
			p[exec].finishid=1;
			p[exec].ct=elapsedtime;
			remainingprocess--;
			p[exec].tat=p[exec].ct-	p[exec].at;
			p[exec].wt=	p[exec].tat-	p[exec].bt;
			total_tat+=p[exec].tat;
			total_wt+=p[exec].wt;
			total_rt+=p[exec].rt;
			printf("|(%d)P %d(%d)",temp,p[exec].id,elapsedtime);
		}
	}
	printf("\n PID \t AT \t BT \t CT \t TAT \t WT \t P \n");
	for(i=0;i<n;i++){
		printf("%d \t %d \t %d \t %d \t %d \t %d \t %d \n",p[i].id,p[i].at,p[i].bt,p[i].ct,p[i].tat,p[i].wt,p[i].rt);
	}
	avg_wt=(float)total_wt/n;
	avg_tat=(float)total_tat/n;
	printf("\n Average tat=%.2f \n Average wt=%.2f \n",avg_tat,avg_wt);
}
	
