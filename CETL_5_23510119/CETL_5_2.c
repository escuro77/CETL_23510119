#include<stdio.h>
#include<omp.h>

int main(){
    long c=0;
    int n=1000000;
    int a[n];

    int t;
    printf("Enter no.of threads: ");
    scanf("%d",&t);
    omp_set_num_threads(t);

    for(int i=0;i<n;i++){
       a[i]=i;
    }

    double s=omp_get_wtime();
    #pragma omp parallel for
    for(int i=0;i<n;i++){
        #pragma omp atomic
        c=c+a[i];
    }
    double e=omp_get_wtime();
    printf("With Atomic:\nSum = %ld\nTime = %f\n",c,e-s);

    c=0;

    double s2=omp_get_wtime();
    #pragma omp parallel for
    for(int i=0;i<n;i++){
        #pragma omp critical
        c=c+a[i];
    }
    double e2=omp_get_wtime();
    printf("\nWith Critical:\nSum = %ld\nTime = %f\n",c,e2-s2);

    return 0;

}


