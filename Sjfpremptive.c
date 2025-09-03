#include<stdio.h>

typedef struct process{
	int pid;
	int at,bt,ct,rt,tat,remtime,wt;
}pro;

void sjfpremptive(pro[],int);
int i;
void sjfpremptive(pro p[],int n){
	int timeprogress[100],processtrack[100],j=-1,k=-1;
	float avgwt=0;
	float avgrt=0;
	float avgtat=0;
	int totalwt=0;
	int totaltat=0;
	int totalrt=0;
	int et=0;
	int remainingprocesses=n;
	timeprogress[++j]=0;
	while(remainingprocesses){
	
		int exec=-1;
		int shortestbursttime=9999;
		for(i=0;i<n;i++){
			if(p[i].at<=et && p[i].remtime>0){
				if(p[i].remtime<shortestbursttime){
					shortestbursttime=p[i].remtime;
					exec=i;
					
				}
			}}
			if(exec==-1){
				processtrack[++k]=0;
				et++;
				timeprogress[++j]=et;
				continue;
			}
			if(p[exec].remtime==p[exec].bt){
				p[exec].rt=et-p[exec].at;
			}
			p[exec].remtime--;
			et++;
			processtrack[++k]=p[exec].pid;
			timeprogress[++j]=et;
			
			if(p[exec].remtime==0){
				p[exec].ct=et;
				p[exec].tat=p[exec].ct-p[exec].at;
				p[exec].wt=p[exec].tat-p[exec].bt;
				totaltat+=p[exec].tat;
				totalwt+=p[exec].wt;
				totalrt+=p[exec].rt;
				remainingprocesses--;
			}}
			avgtat=(float)totaltat/n;
			avgrt=(float)totalrt/n;
			avgwt=(float)totalwt/n;
			printf("\n Observation Table \n PID \t AT \t BT \t CT \t TAT \t WT \t RT \n");
			for(i=0;i<n;i++){
				printf("%d \t %d \t %d \t %d \t %d \t %d \t %d\n",p[i].pid,p[i].at,p[i].bt,p[i].ct,p[i].tat,p[i].wt,p[i].rt);
			}
			printf("\n Average TurnAroundTime : %.2f",avgtat);
			printf("\n Average ResponseTime : %.2f",avgrt);
			printf("\n Average WaitingTime : %.2f",avgwt);
			
			printf("\n Gantt Chart \n (PO-->idle time)\n");
			for(i=0;i<=k;i++)
			  printf("|P%d\t",processtrack[i]);
			  printf("\n");
		
	}
	int main(){
		int n;
		printf("\n Enter the number of processes");
		scanf("%d",&n);
		pro p[n];
		for(i=0;i<n;i++)
		{
			printf("\n Process %d \n",i+1);
			printf("\n Enter the at");
			scanf("%d",&p[i].at);
			printf("\n Enter the bt");
			scanf("%d",&p[i].bt);
			p[i].pid=i+1;
			p[i].remtime = p[i].bt;
		}
		sjfpremptive(p,n);
		return 0;
	}
	
