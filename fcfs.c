#include<stdio.h>

typedef struct process{
	int id,at,bt,ct,tat,wt,rt;
}pro;
int i,j;
void main(){
	int n;
	printf("\n Enter the number of processes");
	scanf("%d",&n);
	pro p[n];
	printf("\n Enter the at and bt");
	for(i=0;i<n;i++){
		printf("%d Process ",i+1);
		scanf("%d %d",&p[i].at,&p[i].bt);
		p[i].id=i+1;
		printf("\n");
	}
	for(i=0;i<n-1;i++){
		for(j=0;j<n-i-1;j++){
			if(p[j].at>p[j+1].at){
				pro temp=p[j];
				p[j]=p[j+1];
				p[j+1]=temp;
			}
		}
	}
	int curtime=0;
	int totaltat=0,totalwt=0,totalrt=0;
	float avgtat=0,avgrt=0,avgwt=0;
	for(i=0;i<n;i++ ){
		if(p[i].at>curtime) //we have to take care of the idle time
		curtime=curtime+(p[i].at-curtime);
		int temp=curtime;
		p[i].rt=curtime-p[i].at;
		curtime+=p[i].bt;
		p[i].ct=curtime;
		p[i].tat=p[i].ct-p[i].at;
		p[i].wt=p[i].tat-p[i].bt;
		printf("|(%d)P%d(%d)",temp,p[i].id,curtime);
		totaltat+=p[i].tat;
		totalwt+=p[i].wt;
		totalrt+=p[i].rt;
	}
	printf("\n");
	 printf("\n PID \t AT \t BT \t CT \t TAT \t WT \t P \n");
	for(i=0;i<n;i++){
		printf("%d \t %d \t %d \t %d \t %d \t %d \t %d \n",p[i].id,p[i].at,p[i].bt,p[i].ct,p[i].tat,p[i].wt,p[i].rt);
	}
	avgwt=(float)totalwt/n;
	avgtat=(float)totaltat/n;
	avgrt=(float)totalrt/n;
	printf("\n Average tat=%.2f \n Average wt=%.2f \n Average rt=%.2f \n",avgtat,avgwt,avgrt);
}
   
	
