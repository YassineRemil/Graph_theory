#include<stdio.h>
#include<stdlib.h>
#define MAX 30
int G[MAX][MAX],n;
typedef struct edge
{
    int u,v,w;
}edge;
typedef struct edgelist
{
    edge data[MAX];
    int n;
}edgelist;
edgelist elist;
edgelist spanlist;
void kruskal();
int find(int belongs[],int vertexno);
void union1(int belongs[],int c1,int c2);
void sort();
void print();
int main()
{
int i,j,total_cost;
printf("Entrer le nombre des sommets:\n");
scanf("%d",&n);
printf("Entrer la matrice:\n");
for(i=0;i<n;i++)
  for(j=0;j<n;j++){
    printf("M[%d][%d]=",i+1,j+1);
    scanf("%d",&G[i][j]);}
kruskal();
print();
return 0;
}
void kruskal()
{ int belongs[MAX],i,j,cno1,cno2;
  elist.n=0;
    for(i=1;i<n;i++)
		for(j=0;j<i;j++)
		{
			if(G[i][j]!=0)
			{
				elist.data[elist.n].u=i;
				elist.data[elist.n].v=j;
				elist.data[elist.n].w=G[i][j];
				elist.n++;
			}
		}
  sort();
	for(i=0;i<n;i++)
		belongs[i]=i;
	spanlist.n=0;
	for(i=0;i<elist.n;i++)
	{
		cno1=find(belongs,elist.data[i].u);
		cno2=find(belongs,elist.data[i].v);
     if(cno1!=cno2)
		{
			spanlist.data[spanlist.n]=elist.data[i];
			spanlist.n=spanlist.n+1;
			union1(belongs,cno1,cno2);
		}
	}
}

int find(int belongs[],int vertexno)
{
	return(belongs[vertexno]);
}

void union1(int belongs[],int c1,int c2)
{
	int i;

	for(i=0;i<n;i++)
		if(belongs[i]==c2)
			belongs[i]=c1;
}

void sort()
{
	int i,j;
	edge temp;

	for(i=1;i<elist.n;i++)
		for(j=0;j<elist.n-1;j++)
			if(elist.data[j].w>elist.data[j+1].w)
			{
				temp=elist.data[j];
				elist.data[j]=elist.data[j+1];
				elist.data[j+1]=temp;
			}
}
void print()
{
	int i,cout=0;
	printf("*** resultat ***");
	for(i=0;i<spanlist.n;i++)
	{
		printf("\n%d-----%d\t\t%d",spanlist.data[i].u+1,spanlist.data[i].v+1,spanlist.data[i].w);
		cout+=spanlist.data[i].w;
	}

	printf("\n\nle cout total de l'arbre partiel obtenu est=%d",cout);
}
