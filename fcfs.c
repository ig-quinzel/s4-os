#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
struct process{
    char name[10];
    int bt,at,ct;
}temp,p[10];

int main(){
    int i,j,wt[10],tt[10],n;
    float avgwt=0,avgtt=0;
    printf("enter the number of processes\n");
    scanf("%d",&n);
    for (i = 0; i < n; i++)
    {
       printf("enter name at bt for %d\n",i+1);
       scanf("%s %d %d",&p[i].name,&p[i].at,&p[i].bt);
    }
    for(i=0;i<n;i++){
        for(j=0;j<n-i-1;j++){
            if(p[j].at>p[j+1].at){
             temp=p[j];
             p[j]=p[j+1];
             p[j+1]=temp;
            }
        }
    }
    printf("pro  at   bt  ct  tt   wt\n");
    p[0].ct=p[0].bt;
    for(i=1;i<n;i++){
    p[i].ct=p[i-1].ct+p[i].bt;
    }
    for(i=0;i<n;i++){
        printf("p%s   %d   %d  %d   %d   %d\n",p[i].name,p[i].at,p[i].bt,p[i].ct,p[i].ct-p[i].at,p[i].ct-p[i].at-p[i].bt);
         avgtt+=p[i].ct-p[i].at;
        avgwt+=p[i].ct-p[i].at-p[i].bt;
    }
    printf("%f\n",avgtt/n);
    printf("%f\n",avgwt/n);
    printf("\n----------------------------------------------------\n");
    for(i=0;i<n;i++){
        printf("%s    |",p[i].name);
    }
    printf("\n----------------------------------------------------\n");
    printf("%d    ",p[0].ct);
    for(i=0;i<n;i++){
        printf("%d    ",p[i].ct);
    }
}
