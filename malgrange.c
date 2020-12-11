#include<stdio.h>
#include<stdlib.h>
int main()
{
int malgrange(){
int n,i,j,M[50][50],col[50],lin[50],node[n],taille,k,*somm;
somm=&node[0];
printf("entrer le nombre des sommets!\n");
scanf("%d",&n);
taille=n;
somm=malloc(n*sizeof(int));
for(i=0;i<n;i++)
{
    node[i]=i;
}

printf("la matrice booleenne!\n");
printf("entrer 0 ou 1\n");
for(i=0;i<n;i++)
{
 for(j=0;j<n;j++)
    {
        printf("MB[X_%d][X_%d]=",i,j);
        scanf("%d",&M[i][j]);

    }
}

void suppression(int position,int taille)
{

 for (i = position; i <taille-1; i++)
  node[i] = node[i+1];
 /*printf("Aprés la suppression,le tableau = ");
 for (i = 0; i <taille-1; i++)
    printf("%d\t", node[i]);*/
}
while(taille>0)
{
//for(k=node[0];k<n;k++)
{
 k=node[0];
 for(i=k;i<n;i++)
 {
 col[0]=0;
 lin[0]=0;
 for(j=0;j<n;j++)
 {
    if(M[k][j]==1)
        col[j]=1;
 }
 for(i=k;i<n;i++)
 {
    if(M[i][k]==1)
        lin[i]=1;
 }

 }
 for(i=0;i<n;i++)
 { if (col[i]==1)
  {for (j=0;j<n;j++)
   {if (M[i][j]==1) col[j]+=1;}
  }
 }
for(i=0;i<n;i++)
 { if (lin[i]==1)
  {for (j=0;j<n;j++)
   {if (M[j][i]==1) lin[i]+=1;}
  }
 }
 /* for(j=0;j<n;j++)
 {
    printf("%d\t",col[j]);
 }
 printf("\n");
 for(i=0;i<n;i++)
 {
    printf("%d\t",lin[i]);
 }
 printf("\n");*/
 printf("les composantes fortement connexes sont:");
 printf("{X_%d}\n",k);
 suppression(0,taille);
 taille-=1;
 for(i=k+1;i<n;i++)
 {
    if(col[i]!=0 && lin[i]!=0)
     {
         for(j=0;j<taille;j++)
         {
          if(j==i){
                   printf("{X_%d}\n",i);
                   suppression(i,taille);
                  }    
         }
     
     }
 }

}
}
}
malgrange();
return 0;
}


