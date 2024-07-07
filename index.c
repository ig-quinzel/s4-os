#include <stdio.h>
#include <stdlib.h>

int main() {
    int f[200] = {0}, allocated = 0, nof,fil[100][100],index[100];

    printf("Enter the number of Files...\n");
    scanf("%d", &nof);

    for (int w = 0; w < nof; w++) {
    
        int st;
        printf("Enter the starting block...\n");
        scanf("%d", &st);

        if (f[st] == 1) {
            printf("Block is already Allocated!\n");
            continue;
        }
        f[st] = 1;

        int n;
        printf("Enter the number of blocks...\n");
        scanf("%d", &n);
        printf("Enter Block Numbers...\n");
        int flag = 0;
        for (int i = 0; i < n; i++) {
            int a;
            scanf("%d", &a);

            if (f[a] == 1) {
                printf("The block %d is already allocated!\n", a);
                flag = 1;
                break;
            }
            f[a] = 1;
            index[i]= a;
        }

        if (flag == 1) continue;

        printf("allocated\n");
             fil[allocated][0]=w+1;
             fil[allocated][1]=st;
             fil[allocated][2]=n;
             allocated++;
    }

    printf("file   start  size   \n");
    for(int i=0;i<allocated;i++){
        printf("%d   %d    %d   \n",fil[i][0], fil[i][1],fil[i][2]);
    }
    
}
