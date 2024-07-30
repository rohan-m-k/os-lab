#include <stdio.h>

struct times {
    int p, at, bt, wt, tat, rt;
};

void sortart(struct times a[], int pr) {
    int i, j;
    struct times temp;
    
    for(i = 0; i < pr; i++) {
        for(j = i + 1; j < pr; j++) {
            if(a[i].at > a[j].at) {
                temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
    }
    return;
}

int main() {
    int i, pr, time, remain, flag = 0, ts;
    struct times a[100];
    float avgwt = 0, avgtat = 0;
    
    printf("Enter number of processes: ");
    scanf("%d", &pr);
    
    remain = pr;
    
    for(i = 0; i < pr; i++) {
        printf("Enter arrival time and burst time for process %d: ", i + 1);
        scanf("%d %d", &a[i].at, &a[i].bt);
        a[i].p = i;
        a[i].rt = a[i].bt;
    }
    
    sortart(a, pr);
    
    printf("Enter time slice: ");
    scanf("%d", &ts);
    
    printf("GANTT CHART\n");
    printf("0");
    
    for(time = 0, i = 0; remain != 0;) {
        if(a[i].rt <= ts && a[i].rt > 0) {
            time = time + a[i].rt;
            printf("-->[p%d]<--%d", a[i].p + 1, time);
            a[i].rt = 0;
            flag = 1;
        } else if(a[i].rt > 0) {
            a[i].rt = a[i].rt - ts;
            time = time + ts;
            printf("-->[p%d]<--%d", a[i].p + 1, time);
        }
        
        if(a[i].rt == 0 && flag == 1) {
            remain--;
            a[i].tat = time - a[i].at;
            a[i].wt = time - a[i].at - a[i].bt;
            avgwt = avgwt + time - a[i].at - a[i].bt;
            avgtat = avgtat + time - a[i].at;
            flag = 0;
        }
        
        if(i == pr - 1)
            i = 0;
        else if(a[i + 1].at <= time)
            i++;
        else
            i = 0;
    }
    
    printf("\nPR\tAT\tBT\tTAT\tTWT\n");
    for(i = 0; i < pr; i++) {
        printf("%d\t%d\t%d\t%d\t%d\n", a[i].p + 1, a[i].at, a[i].bt, a[i].tat, a[i].wt);
    }
    
    avgwt = avgwt / pr;
    avgtat = avgtat / pr;
    
    printf("Average waiting time: %f\n", avgwt);
    printf("Average turnaround time: %f\n", avgtat);
    
    return 0;
}
