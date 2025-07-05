#include<stdio.h>
#include<stdlib.h>

typedef struct process{
	int id,at,bt,ct,tat,wt,flag;
}pro;
pro p[15];
int i,j;
void swap(pro *a,pro *b){
	pro temp=*a;
	*a=*b;
	*b=temp;
	return;
}

void sort(int n){
	for(i=0;i<n-1;i++){
		for(j=0;j<n-i-1;j++){
			if(p[j].at>p[j+1].at){
				swap(&p[j],&p[j+1]);
			}
		}
	}
}

void main(){
	int n,total_tat=0,total_wt=0,tempbt[15],quantum;
	float avg_wt=0,avg_tat=0;
	printf("\n Enter the number of processes");
	scanf("%d",&n);
	printf("\n Enter arrival time n burst time\n");
	printf("AT BT \n");
	for(i=0;i<n;i++){
		p[i].id=(i+1);
		scanf("%d %d",&p[i].at,&p[i].bt);
		tempbt[i]=p[i].bt;
		p[i].flag=0;
	}
	printf("\n Enter the time quantum");
	scanf("%d",&quantum);
	sort(n);
	int completed=0,curindex,curtime=p[0].at,*waitqueue,front=0,rear=0;
	waitqueue=(int *)malloc(n*sizeof(int));
	waitqueue[rear]=0;
	p[0].flag=1;
	while(completed!=n){
		curindex=waitqueue[front];
		front=(front+1)%n;
		if(p[curindex].bt>quantum){
			p[curindex].bt-=quantum;
			curtime+=quantum;
			printf("|P%d (%d) %d",p[curindex].id,quantum,curtime);
		}
		else{
			curtime+=p[curindex].bt;
				printf("|P%d (%d) %d",p[curindex].id,quantum,curtime);
				p[curindex].bt=0;
				p[curindex].ct=curtime;
				p[curindex].tat=p[curindex].ct-p[curindex].at;
				total_tat+=	p[curindex].tat;
				p[curindex].wt=p[curindex].tat-tempbt[p[curindex].id-1];
					total_wt+=	p[curindex].wt;
				}
				for(i=0;i<n && p[i].at<=curtime;i++){
					if(i==curindex||p[i].flag==1||p[i].bt==0)
					  continue;
					  rear=(rear+1)%n;
					  p[i].flag=1;
					  waitqueue[rear]=i;
				}
		       if(p[curindex].bt>0){
		       	rear=(rear+1)%n;
		       	waitqueue[rear]=curindex;
			   }
			   else{
			   	completed++;
			   }		}
			   
			   printf("\n");
	avg_wt=(float)total_wt/n;
	avg_tat=(float)total_tat/n;
	printf("\n PID \t AT \t BT \t CT \t TAT \t WT \t \n");
	for(i=0;i<n;i++){
		printf("%d \t %d \t %d \t %d \t %d \t %d  \n",p[i].id,p[i].at,tempbt[i],p[i].ct,p[i].tat,p[i].wt);
	}
	printf("\n Average tat=%.2f \n Average wt=%.2f \n",avg_tat,avg_wt);
		}
		
	
