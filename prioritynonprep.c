#include<stdio.h>
#include<stdlib.h>

typedef struct process{
	int id,at,ct,bt,wt,tat,iscompl,priority;
}pro;
int i,j;
pro p[15];
void main(){
	int total_tat=0,total_wt=0,n,idletime=0;
	float avg_tat=0,avg_wt=0;
	printf("\n Enter the number pf processes");
	scanf("%d",&n);
	printf("\n AT BT p\n");
	for(i=0;i<n;i++){
		scanf("%d %d %d",&p[i].at,&p[i].bt,&p[i].priority);
		p[i].id=(i+1);
	}
	int minindex,minpriority,curtime=0,completed=0;
	printf("\n Gantt chart");
	while(completed!=n){
		minindex=-1;
		minpriority=9999;
		for(i=0;i<n;i++){
			if(p[i].at<=curtime && p[i].iscompl==0){
				if(p[i].priority<minpriority||p[i].priority==minpriority && p[i].at<p[minindex].at){
					minindex=i;
					minpriority=p[i].priority;
				}
			}
		}
		if(minindex==-1){
			curtime++;
			idletime++;
		}else{
			if(idletime>0){
				printf("|Idle till %d",idletime);
			}
			idletime=0;
			curtime+=p[minindex].bt;
			p[minindex].ct=curtime;
			p[minindex].tat=p[minindex].ct-	p[minindex].at;
				p[minindex].wt=p[minindex].tat-	p[minindex].bt;
			total_tat+=p[minindex].tat;
			total_wt+=p[minindex].wt;
			completed++;
			p[minindex].iscompl=1;
			printf("|P%d (%d) %d",p[minindex].id,p[minindex].bt,p[minindex].ct);
		}}
		printf("\n");
	avg_wt=(float)total_wt/n;
	avg_tat=(float)total_tat/n;
	printf("\n PID \t AT \t BT \t CT \t TAT \t WT \t P \n");
	for(i=0;i<n;i++){
		printf("%d \t %d \t %d \t %d \t %d \t %d \t %d \n",p[i].id,p[i].at,p[i].bt,p[i].ct,p[i].tat,p[i].wt,p[i].priority);
	}
	printf("\n Average tat=%.2f \n Average wt=%.2f \n",avg_tat,avg_wt);
		}
	

