#include <stdio.h>

int main() {
    int n, i, j, k, b[20], sb[20], t[20], x, c[20][20], allocated[100] = {0};
    
    printf("Enter no.of files: ");
    scanf("%d", &n);
    
    for (i = 0; i < n; i++) {
        printf("Enter no. of blocks occupied by file%d: ", i + 1);
        scanf("%d", &b[i]);
        printf("Enter the starting block of file%d: ", i + 1);
        scanf("%d", &sb[i]);
        
        // Check if blocks are available
        int isAvailable = 1;
        for (j = 0; j < b[i]; j++) {
            if (allocated[sb[i] + j] == 1) {
                isAvailable = 0;
                break;
            }
        }
        
        if (isAvailable) {
            // Allocate blocks if available
            t[i] = sb[i];
            for (j = 0; j < b[i]; j++) {
                c[i][j] = sb[i]++;
                allocated[c[i][j]] = 1;
            }
            printf("File%d allocated successfully.\n", i + 1);
        } else {
            // If not available, set length to 0 and print an error message
            b[i] = 0;
            printf("File%d could not be allocated due to block availability.\n", i + 1);
        }
    }
    
    printf("Filename\tStart block\tLength\n");
    for (i = 0; i < n; i++) {
        if (b[i] > 0) {
            printf("%d\t\t%d\t\t%d\n", i + 1, t[i], b[i]);
        }
    }
    
    printf("Enter file name (number): ");
    scanf("%d", &x);
    
    if (x <= n && b[x - 1] > 0) {
        printf("File name is: %d\n", x);
        printf("Length is: %d\n", b[x - 1]);
        printf("Blocks occupied: ");
        for (i = 0; i < b[x - 1]; i++) {
            printf("%4d", c[x - 1][i]);
        }
        printf("\n");
    } else {
        printf("File %d not found or not allocated successfully.\n", x);
    }
    
    return 0;
}

