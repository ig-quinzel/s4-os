#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct process {
    char name[10];
    int bt, at, ct, wt, tt;
} temp, p[10], b[10];

int main() {
    int i, j, n;
    float avgwt = 0, avgtt = 0;

    // Getting the number of processes
    printf("Enter the number of processes: ");
    scanf("%d", &n);

    // Getting process details
    for (i = 0; i < n; i++) {
        printf("Enter name, arrival time and burst time for process %d: ", i + 1);
        scanf("%s %d %d", p[i].name, &p[i].at, &p[i].bt);
    }

    // Sorting processes by arrival time
    for (i = 0; i < n; i++) {
        for (j = i + 1; j < n; j++) {
            if (p[i].at > p[j].at) {
                temp = p[i];
                p[i] = p[j];
                p[j] = temp;
            }
        }
    }

    // Copying the first process to the buffer
    b[0] = p[0];

    // Sorting remaining processes by burst time
    for (i = 1; i < n; i++) {
        for (j = i + 1; j < n; j++) {
            if (p[i].bt > p[j].bt) {
                temp = p[i];
                p[i] = p[j];
                p[j] = temp;
            }
        }
    }

    // Calculating completion time for each process
    b[0].ct = b[0].at + b[0].bt;
    b[0].tt = b[0].ct - b[0].at;
    b[0].wt = b[0].tt - b[0].bt;
    avgtt += b[0].tt;
    avgwt += b[0].wt;
     p[1].ct = b[0].ct + p[1].bt;
        p[1].tt = p[1].ct - p[1].at;
        p[1].wt = p[1].tt - p[1].bt;
        avgtt += p[1].tt;
    avgwt += p[1].wt;
    
    for (i = 2; i < n; i++) {
    
            p[i].ct = p[i - 1].ct + p[i].bt;
        p[i].tt = p[i].ct - p[i].at;
        p[i].wt = p[i].tt - p[i].bt;
        avgtt += p[i].tt;
        avgwt += p[i].wt;
    }

    // Printing the results
    printf("Process   AT   BT   CT   TT   WT\n");
    printf("%s        %d    %d    %d    %d    %d\n", b[0].name, b[0].at, b[0].bt, b[0].ct, b[0].tt, b[0].wt);
    for (i = 1; i < n; i++) {
        printf("%s        %d    %d    %d    %d    %d\n", p[i].name, p[i].at, p[i].bt, p[i].ct, p[i].tt, p[i].wt);
    }

    // Printing average turn-around time and waiting time
    printf("Average Turnaround Time: %.2f\n", avgtt / n);
    printf("Average Waiting Time: %.2f\n", avgwt / n);

    // Printing Gantt chart
    printf("\nGantt Chart\n");
    printf("----------------------------------------------------\n");
    printf("%s    |", b[0].name);
    for (i = 1; i < n; i++) {
        printf("%s    |", p[i].name);
    }
    printf("\n----------------------------------------------------\n");
    printf("%d     ", b[0].at);
    printf("%d     ", b[0].ct);
    for (i = 1; i < n; i++) {
        printf("%d     ", p[i].ct);
    }
    printf("\n");

    return 0;
}
