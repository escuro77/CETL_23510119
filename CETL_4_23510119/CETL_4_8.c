#include<stdio.h>
#include<omp.h>

int main(){
    long n=1000000;
    int a[n];
    long long sum=0;

    for(int i=0;i<n;i++){
        a[i]=i;
    }

    double s1=omp_get_wtime();
    for(int i=0;i<n;i++){
        sum+=a[i];
    }
    double e1=omp_get_wtime();
    
    printf("Sequential\nSum = %lld Time = %f\n",sum,e1-s1);
    sum=0;

    double s2=omp_get_wtime();
    #pragma omp parallel for reduction(+:sum)
    for(int i=0;i<n;i++){
        sum+=a[i];
    }
    double e2=omp_get_wtime();
    printf("Parallel\nSum = %lld Time = %f\n",sum,e2-s2);
    printf("Speedup = %f\n",(e1-s1)/(e2-s2));

}