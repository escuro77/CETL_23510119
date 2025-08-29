#include<stdio.h>
#include<omp.h>

int main(){
    int n;
    printf("enter size of array:");
    scanf("%d",&n);
    int a[n];

    printf("using nowait\n");

    #pragma omp parallel
    {
        #pragma omp for nowait
        for(int i=0;i<n;i++){
            a[i]=i;
        }

        #pragma omp for
        for(int i=0;i<n;i++){
            printf("%d ",a[i]);
        }
    }

    printf("\nremoving nowait\n");

    #pragma omp parallel
    {
        #pragma omp for
        for(int i=0;i<n;i++){
            a[i]=i;
        }

        #pragma omp for
        for(int i=0;i<n;i++){
            printf("%d ",a[i]);
        }
    }
}
