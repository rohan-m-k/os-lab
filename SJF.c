#include<stdlib.h>
#include<stdio.h>
typedef struct process
{
	int pid ;
	int at,cbt,tat,wt,st,ct;
}process;
int main()
{
	process p[20],t;
	int  n,i,j;
	float sumtat=0,sumtwt=0,avgtat=0,avgtwt=0;
	printf("enter the no. of process :\n");
	scanf("%d",&n);
	for(i=0;i<0;i++)
	{
		p[i].tat=0;
		p[i].wt=0;
        p[i].ct=0;
	}
	for(i=0;i<n;i++)
	{
		printf("enter process id ,arrival time and cpu birst time of process %d\n",i+1);
		scanf("%d %d %d",&p[i].pid,&p[i].at,&p[i].cbt);
		
	}
	for(i=0;i<n-1;i++)
	{
		for(j=0;j<n-1;j++)
		{
			if(p[i].at>p[j+1].at)
			{
				t=p[j];
				p[j]=p[j+1];
				p[j+1]=t;
			}
		}
	}
	for(i=1;i<n-1;i++)
	{
		for(j=1;j<n-1;j++)
		{
			if(p[j].cbt>p[j+1].cbt)
			{
				t=p[j];
				p[j]=p[j+1];
				p[j+1]=t;
			}
		}
	}
	p[0].st=p[0].at;
	for(i=0;i<n;i++)
	{
		p[i].at=p[i].ct+p[i].st+p[i].cbt;
		p[i].tat=p[i].ct-p[i].at;
		p[i].wt=p[i].tat-p[i].cbt;
		p[i+1].st=p[i].ct;
		sumtat=sumtat+p[i].tat;
		sumtwt=sumtwt+p[i].wt;
	}
	avgtat=sumtat/n;
	avgtwt=sumtwt/n;
	printf("pid\tAT\tcpuAT\tTAT\tWT\tST\tCT");
	for(i=0;i<n;i++)
	{
		printf("%d\t%d\t%d\t%d\t%d\t%d\t%d\n",p[i].pid,p[i].at,p[i].cbt,p[i].tat,p[i].wt,p[i].st,p[i].ct);
	}
	printf("average TAT=%f\n",avgtat);
	printf("average wt=%f\n",avgtwt);
	return 0;
}
		
	

		

