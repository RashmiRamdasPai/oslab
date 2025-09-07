#include<stdio.h>
#include<stdlib.h>

typedef struct process{
	int id,ct,at,tat,wt,bt,rt,finishid;
}pro;
int i;
void main(){
	int totaltat=0,totalwt=0,totalrt=0;
	int n;
	int remaningprocess;
	printf("\n Enter the number of process");
	scanf("%d",&n);
	int remainingprocess=n;
	float avgtat=0,avgwt=0,avgrt=0;
	pro p[n];
	printf("\n Enter at,bt: ");
	for(i=0;i<n;i++){
		printf("\n Process:%d ",i+1);
		scanf("%d %d",&p[i].at,&p[i].bt);
		p[i].id=i+1;
		p[i].finishid=0;
   }
   int curtime=0;
   int completed=0;
   while(remainingprocess)
   {
   	int exec=-1;
   	int minbursttime=9999;
   	for(i=0;i<n;i++){
   		if(p[i].at<=curtime && p[i].finishid==0){
   			if(p[i].bt<minbursttime){
   				minbursttime=p[i].bt;
   				exec=i;
			   }
		   }
	   }
	   if(exec==-1){
	   	printf("(%d)***(%d)",curtime,curtime+1);
	   	curtime++;
	   }
	   else{
	   	int temp=curtime;
	   	p[exec].rt=curtime-p[exec].at;
	   	curtime+=p[exec].bt;
	   	p[exec].finishid=1;
	   	p[exec].ct=curtime;
	   	p[exec].tat=p[exec].ct-p[exec].at;
	   	p[exec].wt=p[exec].tat-p[exec].bt;
	   	totaltat+=p[exec].tat;
	   	totalwt+=p[exec].wt;
	   	totalrt+=p[exec].rt;
	   	printf("|(%d)P %d (%d)",temp,p[exec].id,curtime);
	   	remainingprocess--;
	   }}
	   printf("\n PID \t AT \t BT \t CT \t TAT \t WT \t P \n");
	for(i=0;i<n;i++){
		printf("%d \t %d \t %d \t %d \t %d \t %d \t %d \n",p[i].id,p[i].at,p[i].bt,p[i].ct,p[i].tat,p[i].wt,p[i].rt);
	}
	avgwt=(float)totalwt/n;
	avgtat=(float)totaltat/n;
	avgrt=(float)totalrt/n;
	printf("\n Average tat=%.2f \n Average wt=%.2f \n Average rt=%.2f \n",avgtat,avgwt,avgrt);
}
   
