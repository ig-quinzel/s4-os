#include <stdio.h>
#include <stdlib.h>

struct process {
    char name[10];
    int bt, at, ct,st, rt;
} p[10];

int main() {
    int wt = 0, tt = 0, time = 0, tq, count, remain, flag = 0, n;
    printf("Enter the number of processes: ");
    scanf("%d", &n);
    remain = n;

    for (int i = 0; i < n; i++) {
        printf("Enter process name, arrival time, and burst time for process %d: ", i + 1);
        scanf("%s %d %d", p[i].name, &p[i].at, &p[i].bt);
        p[i].rt = p[i].bt;
    }

    printf("Enter time quantum: ");
    scanf("%d", &tq);

    printf("Process  AT  BT  CT  TT  WT\n");

    for (count = 0, time = 0; remain != 0; ) {
        if (p[count].rt <= tq && p[count].rt > 0) {
            time += p[count].rt;
            p[count].st=p[count].rt;
            p[count].rt = 0;
            flag = 1;
        } else if (p[count].rt > 0) {
            p[count].rt -= tq;
            p[count].st=p[count].rt;
            time += tq;
        }
        
        if (p[count].rt == 0 && flag == 1) {
            remain--;
            int turnaround_time = time - p[count].at;
            int waiting_time = turnaround_time - p[count].bt;
            printf("%s\t%d\t%d\t%d\t%d\t%d\n", p[count].name, p[count].at, p[count].bt, time, turnaround_time, waiting_time);
            wt += waiting_time;
            tt += turnaround_time;
            flag = 0;
        }

        if (count == n - 1)
            count = 0;
        else if (p[count + 1].at <= time)
            count++;
        else
            count = 0;
    }

    printf("Average waiting time = %.2f\n", (float)wt / n);
    printf("Average turnaround time = %.2f\n", (float)tt / n);
     printf("\n----------------------------------------------------\n");
    for(int i=0;i<n;i++){
        printf("%s    |",p[i].name);
    }
    printf("\n----------------------------------------------------\n");
    printf("%d    ",p[0].st);
    for(int i=0;i<n;i++){
        printf("%d    ",p[i].st);
    }

    return 0;
}
