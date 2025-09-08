#include<stdio.h>
#include<omp.h>

int main(){
    int n=500;
    int a[n][n],b[n][n],c[n][n],d[n][n];
    double s1,s2,e1,e2;

    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++){
            a[i][j]=i+j;
            b[i][j]=i-j;
            c[i][j]=0;
            d[i][j]=0;
        }

    s1=omp_get_wtime();
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            int sum=0;
            for(int k=0;k<n;k++)
                sum += a[i][k]*b[k][j];
            c[i][j]=sum;
        }
    }
    e1=omp_get_wtime();

    s2=omp_get_wtime();
    #pragma omp parallel for collapse(2)
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            int sum=0;
            for(int k=0;k<n;k++)
                sum += a[i][k]*b[k][j];
            d[i][j]=sum;
        }
    }
    e2=omp_get_wtime();
    printf("Speedup %f\n",(e1-s1)/(e2-s2));

    return 0;
}
