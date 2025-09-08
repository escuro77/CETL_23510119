#include<stdio.h>
#include<omp.h>

int main(){
    int n;
    printf("Enter no. of threads:");
    scanf("%d",&n);
    omp_set_num_threads(n);

    int aryabhatta=10;

    #pragma omp parallel firstprivate(aryabhatta)
    {
        int result=omp_get_thread_num()*aryabhatta;
        printf("Thread id: %d Multiplication: %d\n",omp_get_thread_num(),result);
    }
    return 0;
}

