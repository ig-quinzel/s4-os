#include<stdio.h>
#include<stdlib.h>

void firstfit(int p_size[],int n,int m_size[],int m){
    int i,j,flag,psize[100],msize[100];
    for(i=0;i<n;i++){
        psize[i]=p_size[i];
    }
    for(j=0;j<m;j++){
        msize[j]=m_size[j];
    }
    for(i=0;i<n;i++)
    {
        flag=0;
        for(j=0;j<m;j++){
            if(msize[j]>=psize[i]){
                printf("process %d allocated memory %d\n",psize[i],msize[j]);
                msize[j]=msize[j]-psize[i];
                printf("remaining space=%d\n",msize[j]);
                flag=1;
                break;
            }
            
        }
        if(flag==0)
        printf("memory not allocated\n");
    }
}

void worstfit(int p_size[],int n,int m_size[],int m){
    int i,j,flag,loc,max,psize[100],msize[100];
    for(i=0;i<n;i++){
        psize[i]=p_size[i];
    }
    for(j=0;j<m;j++){
        msize[j]=m_size[j];
    }
    for(i=0;i<n;i++)
    {
        max=msize[0];
        loc=0;
        for(j=0;j<m;j++){
            if(msize[j]>max){
                max=msize[j];
                loc=j;
            }
        }
            if(max>=psize[i]){
                printf("process %d allocated memory %d\n",psize[i],msize[loc]);
                msize[loc]=msize[loc]-psize[i];
                printf("remaining space=%d\n",msize[loc]);
            }
            else{
                printf("memory not allocated\n");
            }
        
    }
}

void bestfit(int p_size[],int n,int m_size[],int m){
    int i,j,flag,loc,max,psize[100],msize[100];
    for(i=0;i<n;i++){
        psize[i]=p_size[i];
    }
    for(j=0;j<m;j++){
        msize[j]=m_size[j];
    }
    for(i=0;i<n;i++)
    {
        loc=-1;
        for(j=0;j<m;j++){
        if(msize[j]>=psize[i])
        {
            if(loc==-1 || msize[loc]>msize[j])
                loc=j;
         
        }
        
    }
    if(loc!=-1){
      printf("process %d allocated memory %d\n",psize[i],msize[loc]);
                msize[loc]=msize[loc]-psize[i];
                printf("remaining space=%d\n",msize[loc]);
           
    }
     else{
                printf("memory not allocated\n");
            }
}
}

int main(){
    int n,m,p_size[10],m_size[10];
    printf("enter memory blocks size\n");
    scanf("%d",&m);
    printf("enter memory blocks \n");
    for(int j=0;j<m;j++)
    scanf("%d",&m_size[j]);
     printf("enter process blocks size\n");
    scanf("%d",&n);
     printf("enter process blocks \n");
     for(int i=0;i<n;i++)
    scanf("%d",&p_size[i]);

    firstfit(p_size,n,m_size,m);
    worstfit(p_size,n,m_size,m);
    bestfit(p_size,n,m_size,m);
}
