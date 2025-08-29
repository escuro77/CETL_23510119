#include<stdio.h>
#include<omp.h>

int main(){
    int n=20;

    printf("With ordered:\n");
    #pragma omp parallel for ordered
    for(int i=1;i<=n;i++){
        #pragma omp ordered
        printf("%d ",i);
    }

    printf("\nWithout ordered:\n");
    #pragma omp parallel for
    for(int i=1;i<=n;i++){
        printf("%d ",i);
    }

    return 0;
}