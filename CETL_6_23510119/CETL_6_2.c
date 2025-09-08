#include<stdio.h>
#include<omp.h>

static double a[100000000];
static double b[100000000];
int main(){
    int n=1000000;
    double dot=0.0,dot2=0.0;
    double s1,s2,e1,e2;

    for(int i=0;i<n;i++){
            a[i]=i*0.37;
            b[i]=i*0.1;
    }

    s1=omp_get_wtime();
    for(int i=0;i<n;i++){
        dot+=a[i]*b[i];
    }
    e1=omp_get_wtime();

    s2=omp_get_wtime();
    #pragma omp parallel for reduction(+:dot2)
    for(int i=0;i<n;i++){
        dot2+=a[i]*b[i];
    }
    e2=omp_get_wtime();
    printf("Dot product\nBy serial: %f\nBy parallel:%f\n",dot,dot2);
    printf("Speedup %f\n",(e1-s1)/(e2-s2));

    return 0;
}
