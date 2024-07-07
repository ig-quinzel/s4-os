#include<stdio.h>
int main(){
    int n,f,r[100],m[100],count=0,i,flag,pf=0,j;
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
		printf("page %d",r[i]);
		flag=0;
       for(j=0;j<f;j++){
        if(m[j]==r[i]){
            flag=1;
			printf("page hit");
            break;
        }
       }
        if(flag==0){
            m[count]=r[i];
            count=(count+1)%f;
            pf++;
            for(j=0;j<f;j++){
                if(m[j]!=-1){
                    printf(" %d",m[j]);

                }
                else{
                    printf(" -");
                }
            }
            printf("pf %d",pf);
        }
       printf("\n");
    }
    printf("pf=%d",pf);

}
