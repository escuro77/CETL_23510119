#include<stdio.h>
#include<omp.h>

int main(){
    int n;
    printf("Enter the no. threads: ");
    scanf("%d",&n);
    omp_set_num_threads(n);

    printf("Sequential\n");
    double s1=omp_get_wtime();
    for(int i=0;i<n;i++){
        printf("Hello World %d\n",i);
    }
    double e1=omp_get_wtime();

    printf("\nParallel\n");
    double s2=omp_get_wtime();
    #pragma omp parallel
    {
        printf("hello world %d\n",omp_get_thread_num());
    }
    double e2=omp_get_wtime();

    printf("Sequential time %f\nParallel time %f\nSpeedup %f\n",(e1-s1),(e2-s2),(e1-s1)/(e2-s2));

return 0;
}