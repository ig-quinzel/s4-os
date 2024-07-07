#include <stdio.h>

// Function to find the least recently used page
int accessrecent(int r[], int i, int a) {
    int count = 0;
    for (int j = i; j >= 0; j--) {
        count++;
        if (r[j] == a)
            return count;
    }
    return count;
}

int main() {
    int n, f, r[100], m[100], x, count = 0, i, flag, pf = 0, j, index;
    int lru[100][100];  // To store LRU page history for printing
    
    printf("Enter number of processes: ");
    scanf("%d", &n);
    
    printf("Enter processes: ");
    for (i = 0; i < n; i++) {
        scanf("%d", &r[i]);
    }
    
    printf("Enter number of frames: ");
    scanf("%d", &f);
    
    for (i = 0; i < f; i++) {
        m[i] = -1;
    }
    
    for (i = 0; i < n; i++) {
        flag = 0;
        
        for (j = 0; j < f; j++) {
            if (m[j] == r[i]) {
                flag = 1;
                break;
            }
        }
        
        if (flag == 0) {
            pf++;
            if (count == f) {
                int max = -1;
                for (j = 0; j < f; j++) {
                    x = accessrecent(r, i, m[j]);
                    if (x > max) {
                        max = x;
                        index = j;
                    }
                }
                m[index] = r[i];
            } else {
                m[count++] = r[i];
            }
        }
        
        for (j = 0; j < f; j++) {
            lru[j][i] = m[j];
        }
    }

    printf("Page reference string:\n");
    for (i = 0; i < n; i++) {
        printf("%d ", r[i]);
    }
    for (i = 0; i < f; i++) {
        for (j = 0; j < n; j++) {
            if (lru[i][j] != -1) {
                printf("%d ", lru[i][j]);
            } else {
                printf("- ");
            }
        }
        printf("\n");
    }
    
    printf("\nTotal number of page faults using LRU is %d\n", pf);
    return 0;
}
