#include<stdio.h>
#include<omp.h>

int main(){
    int n;
    int k;
    int a[n];
    printf("size of array and scalar:\n ");
    scanf("%d%d",&n,&k);
    
    for(int i=0;i<n;i++) a[i]=2*i;

    double s1=omp_get_wtime();
    #pragma omp parallel for schedule(dynamic)
       for(int i=0;i<n;i++){
        a[i]+=k;
       }
    double e1=omp_get_wtime();

    printf("\ndynamic time = %f\n",(e1-s1));
    return 0;
}


