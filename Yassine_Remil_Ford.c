#include<stdio.h>
#include<conio.h>
#include<math.h>
Bellman_Ford(int k, int* A, int* B, int n){
    int i,j;
    for(i=0;i<n;i++){
        *(B+(k+1)*n+i)=*(B+k*n+i);
        for(j=0;j<n;j++){
            if(*(B+(k+1)*n+i)>*(B+k*n+j)+*(A+*(B+j)*n+*(B+i)))
                *(B+(k+1)*n+i)=*(B+k*n+j)+*(A+*(B+j)*n+*(B+i));
        }
    }
    if(k<n)
        Bellman_Ford(k+1,A,B,n);
}
int main(){
    int n,i,j,k,a;
    printf("Entrer le nombre des sommets:");
    scanf("%d",&n);
    int A[n][n],B[n+2][n];
    printf("Si il n'y a pas des boucles entrer 0\n");
    printf("Si il n'y a pas un arc entre 2 sommets different entrer 99(infini)");
    printf("\nEntrer la matrice:\n");
    for(i=0;i<n;i++){
        printf("\n");
        for(j=0;j<n;j++){
            printf("M[%d][%d]=",i+1,j+1);
            scanf("%d",&A[i][j]);
        }
    }
    printf("\n*****La Matrice*****:\n");
    for(i=0;i<n;i++){
        printf("\n");
        for(j=0;j<n;j++){
            printf("\t%d",A[i][j]);
        }
    }
    printf("\nMarquer le sommet de depart:");
    scanf("%d",&a);


    B[0][0]=a-1;
    B[1][0]=0;
    for(j=1;j<n;j++){
        if(j>a-1)
            B[0][j]=j;
        else
            B[0][j]=j-1;
    }
    for(j=1;j<n;j++)
        B[1][j]=99;

    Bellman_Ford(1,A,B,n);

    printf("\nles iterations sont:");
    for(i=0;i<n+2;i++){
        printf("\n\n");
        for(j=0;j<n;j++){
            printf("\t%d",B[i][j]);
        }
        if(i==1)
            printf("\t#initialization.");
        else if(i!=0)
            printf("\t#iteration no. %d",i-1);
    }
    for(i=0;i<n;i++){
        if(B[n+1][i]!=B[n][i]){
            printf("\n WARNING --<Erreur>--!!!: Il y a un arc negatif dans ce graphe. Corrigez-le et executez à nouveau.");
            return 0;
        }
    }
    printf("\nla reponse est:\n");
    printf("n(x_%d)=0",a);
    for(i=1;i<n;i++)
        printf("\nn(x_%d) = %d",B[0][i]+1,B[n+1][i]);
}
