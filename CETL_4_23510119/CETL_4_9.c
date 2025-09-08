#include<stdio.h>
#include<omp.h>
#include<stdlib.h>

int main(){
    long long n=1000000;
    long long inside=0;

    #pragma omp parallel
    {
        unsigned int seed=omp_get_thread_num();
        long long count=0;

        #pragma omp for
        for(long long i=0;i<n;i++){
            double x=(double)rand_r(&seed)/RAND_MAX;
            double y=(double)rand_r(&seed)/RAND_MAX;
            if(x*x+y*y<=1.0) count++;
        }

        #pragma omp atomic
        inside+=count;
    }

    double pi =4.0*inside/n;
    printf("Estimated Pi = %f\n",pi);
    return 0;
}
