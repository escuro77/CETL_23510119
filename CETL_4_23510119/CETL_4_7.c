#include<stdio.h>
#include<omp.h>

int main(){
    long long n;
    printf("Enter size");
    scanf("%lld",&n);

    int a[n];
    long long total_sum=0;
    for(int i=0;i<n;i++){
        a[i]=1;
    }

    double s1=omp_get_wtime();
    #pragma omp parallel for
    for(int i=0;i<n;i++){
        total_sum+=a[i];
    }
    double e1=omp_get_wtime();

    printf("Unsynchronized\nSum = %lld Time = %f\n",total_sum,e1-s1);

    total_sum=0;
    double s2=omp_get_wtime();
    #pragma omp parallel for
    for(int i=0;i<n;i++){
        #pragma omp atomic
        total_sum+=a[i];
    }
    double e2=omp_get_wtime();
    printf("Synchronized\nSum = %lld Time = %f\n",total_sum,e2-s2);
    printf("Comparison Time = %f\n",(e2-s2)/(e1-s1));

    return 0;
}

