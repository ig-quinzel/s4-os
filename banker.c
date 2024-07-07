#include <stdio.h>
#include <stdlib.h>

int main() {
    int i, j, k, n, r;
    int max[100][100], alloc[100][100], need[100][100], finished[100] = {0}, avail[100], flag = 1, cl = 0;

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    printf("Enter the number of resources: ");
    scanf("%d", &r);

    printf("Enter the allocation matrix:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < r; j++) {
            scanf("%d", &alloc[i][j]);
        }
    }

    printf("Enter the max matrix:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < r; j++) {
            scanf("%d", &max[i][j]);
        }
    }

    printf("Enter the available resources: ");
    for (j = 0; j < r; j++) {
        scanf("%d", &avail[j]);
    }

    for (i = 0; i < n; i++) {
        for (j = 0; j < r; j++) {
            need[i][j] = max[i][j] - alloc[i][j];
        }
    }

    printf("Process\t\tAlloc\t\tMax\t\tNeed\t\tAvail\n");
    for (i = 0; i < n; i++) {
        printf("P%d\t\t", i + 1);
        for (j = 0; j < r; j++) {
            printf("%d ", alloc[i][j]);
        }
        printf("\t");
        for (j = 0; j < r; j++) {
            printf("%d ", max[i][j]);
        }
        printf("\t");
        for (j = 0; j < r; j++) {
            printf("%d ", need[i][j]);
        }
        if (i == 0) {
            printf("\t");
            for (j = 0; j < r; j++) {
                printf("%d ", avail[j]);
            }
        }
        printf("\n");
    }

    while (flag) {
        flag = 0;
        for (i = 0; i < n; i++) {
            int c = 0;
            for (j = 0; j < r; j++) {
                if (finished[i] == 0 && need[i][j] <= avail[j]) {
                    c++;
                    if (c == r) {
                        for (k = 0; k < r; k++) {
                            avail[k] += alloc[i][k];
                        }
                        finished[i] = 1;
                        flag = 1;
                        printf("P%d -> ", i + 1);
                    }
                }
            }
        }
    }

    for (i = 0; i < n; i++) {
        if (finished[i] == 1) {
            cl++;
        } else {
            printf("P%d -> ", i + 1);
        }
    }

    if (cl == n) {
        printf("System is safe\n");
    } else {
        printf("System is not safe\n");
    }

    return 0;
}


