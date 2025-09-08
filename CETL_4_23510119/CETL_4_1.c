#include<stdio.h>
#include<omp.h>

int main(){
    char *family[]={"Dad","Mum","Sister","Brother"};

    double s=omp_get_wtime();
    for(int i=0;i<4;i++){
        printf("%s , i: %d\n",family[i],i);
    }
    double e=omp_get_wtime();

    double s0=omp_get_wtime();
    #pragma omp parallel for
    for(int i=0;i<4;i++){
        printf("%s , Thread id: %d\n",family[i],omp_get_thread_num());
    }
    double e0=omp_get_wtime();

    printf("\nSpeedup = %f",(e-s)/(e0-s0));
    return 0;
}