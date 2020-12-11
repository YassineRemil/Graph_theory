//FONCTION ORDINALE
#include<stdio.h>
#include<stdlib.h>
int main()
{
int n,i,j,G[20][20],k=0,taille,somm[20],a,b,p;
void ord(int G[20][20])
{
void suppression(int position,int taille)
 {
 for (i = position; i <taille-1; i++)
  somm[i] =somm[i+1];
 }
for(j=0;j<n;j++)
{
 G[n][j]=0;
 for(i=0;i<n;i++)
{
     G[n][j]+=G[i][j];
}}
for(j=0;j<n;j++){
 if(G[n][j]==0)
{
 for(i=0;i<taille;i++)
 {
 if(j==somm[i])
 {
             printf("X_%d ",j);
             for(a=0;a<n;a++)
             {
                 G[j][a]=0;}
             for(b=0;b<taille;b++)
             {
                 if(somm[b]==j)
                  {p=b;
                  break;}}
             suppression(p,taille);
             taille-=1;
         }
         }
         }
         }
}
printf("Entrer le nombre des sommets:\n");
scanf("%d",&n);
taille=n;
for(i=0;i<n;i++)
{
    somm[i]=i;
}
printf("Entrer la matrice booleenne du graphe sans circuit:\n");
for(i=0;i<n;i++)
  for(j=0;j<n;j++){
    do{
    printf("M[%d][%d]=",i,j);
    scanf("%d",&G[i][j]);}
    while(G[i][j]!=0 && G[i][j]!=1);
    }
while(taille>0)
{
printf("N_%d={",k);
ord(G);
printf("}\n");
k++;}
return 0;}
