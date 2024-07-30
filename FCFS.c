#include<stdio.h>
#include<stdlib.h>

int main() {
    int i, n, at[10], bt[10], st[10], ct[10], tat[10], wt[10];
    float sum_tat = 0, sum_wt = 0;

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    printf("Enter the arrival time and burst time of each process:\n");
    for(i = 0; i < n; i++) {
        printf("Process %d: ", i + 1);
        scanf("%d %d", &at[i], &bt[i]);
    }

    // Calculating completion time, turnaround time, and waiting time
    for(i = 0; i < n; i++) {
        if(i == 0)
            st[0] = 0;
        else {
            if(at[i] < ct[i - 1])
                st[i] = ct[i - 1];
            else
                st[i] = at[i];
        }
        ct[i] = st[i] + bt[i];
        tat[i] = ct[i] - at[i];
        wt[i] = tat[i] - bt[i];
    }

    // Calculating average turnaround time and average waiting time
    for(i = 0; i < n; i++) {
        sum_tat += tat[i];
        sum_wt += wt[i];
    }

    // Displaying the results
    printf("\nProcess\tAT\tBT\tST\tCT\tTAT\tWT\n");
    for(i = 0; i < n; i++) {
        printf("P%d\t%d\t%d\t%d\t%d\t%d\t%d\n", i + 1, at[i], bt[i], st[i], ct[i], tat[i], wt[i]);
    }
    printf("\nAverage Turnaround Time: %.2f\n", (sum_tat) / n);
    printf("Average Waiting Time: %.2f\n", (sum_wt) / n);

    return 0;
}
