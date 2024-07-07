#include<stdio.h>

int accessoptimal(int r[],int n, int i,int a){
    int count=0;
    for(int j=i+1;j<n;j++){
        count++;
        if(r[j]==a)
        return count;
    }
    return count+1;
}
int main(){
    int n,f,r[100],m[100],x,count=0,i,flag,pf=0,j,index;
    printf("enter no . proceess\n");
    scanf("%d",&n);
    printf("enter proceess\n");
    for(i=0;i<n;i++)
    
    scanf("%d",&r[i]);
    printf("enter no . frames\n");
    scanf("%d",&f);
    for(i=0;i<f;i++)
     m[i]=-1;
    for(i=0;i<n;i++){
       flag=0;
         printf("page %d",r[i]);
       for(j=0;j<f;j++){
        if(m[j]==r[i]){
            printf("page hit");
            flag=1;
            break;
        }
       }
        if(flag==0){
            pf++;
            if(count==f)
            {
                int max=-1;
                for(j=0;j<f;j++){
                  x=accessoptimal(r,n,i,m[j]);
                  if(x>max);{
                    max=x;
                    index=j;
                  }
                }
                m[index]=r[i];
            }
            else{
                m[count++]=r[i];
            }
          
            for(j=0;j<f;j++){
                if(m[j]!=-1){
                    printf(" %d",m[j]);

                }
                else{
                    printf(" -");
                }
            }
             printf("  pf %d",pf);
        }
       printf("\n");
        }
    printf("pf=%d",pf);
    }
    
