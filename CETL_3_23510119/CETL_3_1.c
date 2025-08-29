#include<stdio.h>
#include<omp.h>

int main(){
    int n;
    printf("Enter the no. threads: ");
    scanf("%d",&n);
    omp_set_num_threads(n);

    printf("sequential\n");
    double s0=omp_get_wtime();
    for(int i=0;i<n;i++)
    {
        printf("Hello World %d\n",i);
    }
    double e0=omp_get_wtime();

    printf("\n#pragma omp parallel\n");
    double s1=omp_get_wtime();
    #pragma omp parallel
    {
        printf("Hello World %d\n",omp_get_thread_num());
    }
    double e1=omp_get_wtime();
    double s2=omp_get_wtime();
    printf("\n#pragma omp parallel\n");
    #pragma omp parallel for
    for(int i=0;i<n;i++){
         printf("Hello World %d\n",omp_get_thread_num());
    }
    double e2=omp_get_wtime();

    printf("\nsequential time = %f\n",(e0-s0));
    printf("parallel time = %f\n",(e1-s1));
    printf("parallel for time = %f\n",(e2-s2));
    printf("Speedup:\nparallel = %f\nparallel for = %f\n",(e0-s0)/(e1-s1),(e0-s0)/(e2-s2));
    return 0;
}

