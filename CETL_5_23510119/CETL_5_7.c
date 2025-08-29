#include<stdio.h>
#include<omp.h>

int main(){
    int n=1000000;
    long long sum=0;
    long long sum1=0;

    double s0=omp_get_wtime();
    for(int i=0;i<=n;i++){
        sum1+=(long long)i*i;
    }
    double e0=omp_get_wtime();
    printf("Sum of squares: %lld\nTime required: %f\n",sum1,e0-s0);
    double s=omp_get_wtime();
    #pragma omp parallel for reduction(+:sum)
    for(int i=0;i<=n;i++){
        sum+=(long long)i*i;
    }
    double e= omp_get_wtime();
    printf("\nSum of squares: %lld\nTime required: %f\n",sum,e-s);
    printf("Speedup: %f\n",(e0-s0)/(e-s));

    return 0;
}