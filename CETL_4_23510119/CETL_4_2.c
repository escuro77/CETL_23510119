#include<stdio.h>
#include<omp.h>

int main(){
    int n;
    printf("Enter no. of threads: ");
    scanf("%d",&n);
    omp_set_num_threads(n);

    long sum=0;

    #pragma omp parallel reduction(+:sum)
    {
        int t=omp_get_thread_num();
        printf("Thread:%d Square:%d\n",t,t*t);
        sum+=t*t;
    }

    printf("\nSum = %ld\n",sum);
    return 0;
}