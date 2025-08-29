#include<stdio.h>
#include<omp.h>

int main(){
    int n;
    printf("enter n: ");
    scanf("%d",&n);

    long long fact0=1;
    double s0=omp_get_wtime();
    for(int i=1;i<=n;i++){
        #pragma omp atomic
        fact0=fact0*i;
    }
    double e0=omp_get_wtime();
    printf("Factorial using sequential %lld\nTime %f\n",fact0,e0-s0);

    long long fact=1;
    double s1=omp_get_wtime();
    #pragma omp parallel for shared(fact)
    for(int i=1;i<=n;i++){
        #pragma omp atomic
        fact=fact*i;
    }
    double e1=omp_get_wtime();
    printf("Factorial using shared %lld\nTime %f\n",fact,e1-s1);

    long long fact2=1;
    double s2=omp_get_wtime();

    #pragma omp parallel for reduction(*:fact2)
    for(int i=1;i<=n;i++){
        fact2=fact2*i;
    }
    double e2=omp_get_wtime();
    printf("Factorial using reduction %lld\nTime %f\n",fact2,e2-s2);
    printf("Speedup by shared = %f\nSpeedup by reduction = %f\n ",(e0-s0)/(e1-s1),(e0-s0)/(e2-s2));

}