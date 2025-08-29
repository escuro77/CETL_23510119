#include<stdio.h>
#include<omp.h>

int main(){
    int t;
    printf("Enter no.of threads: ");
    scanf("%d",&t);
    omp_set_num_threads(t);

    int a[t];

    #pragma omp parallel num_threads(t)
    {
    int n=omp_get_thread_num();
        a[n]=n*n;
    
    #pragma omp barrier

    #pragma omp master
    {
        printf("Result:\n");
        for(int i=0;i<t;i++){
            printf("%d ",a[i]);
        }
    }
    
    }

    return 0;

}


