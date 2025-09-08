#include <stdio.h>
#include <omp.h>

int main() {
    int n;
    printf("enter array size:");
    scanf("%d",&n);
    int a[n][n],b[n][n],e[n][n],c[n][n],d[n][n];
    int j,k=0;

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            a[i][j]=i+j;
            b[i][j]=i-j;
            c[i][j]=0;
            d[i][j]=0;
        }
    }
    double s1=omp_get_wtime();
    for(int i=0;i<n;i++)
        for(j=0;j<n;j++)
            for(k=0;k<n;k++)
                e[i][j]+=a[i][k] * b[k][j];
    
    double e1=omp_get_wtime();
    printf("Normal time: %f\n",e1-s1);

    double s2=omp_get_wtime();
    #pragma omp parallel for schedule(static) private(j,k)
    for(int i=0;i<n;i++)
        for(j=0;j<n;j++)
            for(k=0;k<n;k++)
                c[i][j]+=a[i][k] * b[k][j];
    double e2=omp_get_wtime();
    printf("Static schedule time: %f\n",e2-s2);

    double s3=omp_get_wtime();
    #pragma omp parallel for schedule(dynamic) private(j,k)
    for(int i=0;i<n;i++)
        for(j=0;j<n;j++)
            for(k=0;k<n;k++)
                c[i][j]+=a[i][k] * b[k][j];

    double e3=omp_get_wtime();
    printf("Dynamic schedule time: %f\n",e3-s3);

    return 0;
}
