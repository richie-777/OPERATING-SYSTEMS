#include<stdio.h>
int main()
 {
   int x,n,p[10],pp[10],pt[10],w[10],t[10],i;
   float awt,atat;
   printf("Enter the number of process : ");
   scanf("%d",&n);
   printf("\n Enter process : time priorities \n");
   for(i=0;i<n;i++)
    {
      printf("\nP%d : ",i+1);
      scanf("%d\t%d",&pt[i],&pp[i]);
      p[i]=i+1;
    }
  for(i=0;i<n-1;i++)
   {
     for(int j=i+1;j<n;j++)
     {
       if(pp[i]<pp[j])
       {
         x=pp[i];
         pp[i]=pp[j];
         pp[j]=x;
         x=pt[i];
         pt[i]=pt[j];
         pt[j]=x;
         x=p[i];
         p[i]=p[j];
         p[j]=x;
      }
   }
}
w[0]=0;
awt=0;
t[0]=pt[0];
atat=t[0];
for(i=1;i<n;i++)
 {
   w[i]=t[i-1];
   awt+=w[i];
   t[i]=w[i]+pt[i];
   atat+=t[i];
 }
printf("\n\n Process \t Burst Time \t Wait Time \t Turn Around Time   Priority \n");
for(i=0;i<n;i++)
  printf("\n %d \t\t %d  \t\t %d \t\t %d \t\t %d \n",p[i],pt[i],w[i],t[i],pp[i]);
awt/=n;
atat/=n;
printf("\n Average Wait Time : %.2f \n",awt);
printf("\n Average Turn Around Time : %.2f \n",atat);
return 0;
}
