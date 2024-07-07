#include <stdio.h>
#include <stdlib.h>

struct lfile {
    char name[26];
    int start, siz;
    int blocks[20];
}files[20];

int main() {
    int f[200] = {0}, alloc = 0, nof;

    printf("Enter the number of Files...\n");
    scanf("%d", &nof);

    for (int w = 0; w < nof; w++) {
        printf("Enter the file name...\n");
        scanf("%s", files[alloc].name);

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
            files[alloc].blocks[i] = a;
        }

        if (flag == 1) continue;

        files[alloc].start = st;
        files[alloc].siz = n;
        alloc++;
    }

    printf("\nFile\tStart\tSize\tBlock\n");
    for (int i = 0; i < alloc; i++) {
        printf("%s\t%d\t%d\t", files[i].name, files[i].start, files[i].siz);
        printf("%d", files[i].blocks[0]);
        for (int j = 1; j < files[i].siz; j++) {
            printf(" --> %d", files[i].blocks[j]);
        }
        printf("\n");
    }

    return 0;
}
