#include<stdio.h>
#include<stdlib.h>
#include<omp.h>

int main(){
    int n;
    printf("Enter size: ");
    scanf("%d",&n);
    
    int *a=(int*)malloc(n*sizeof(int));
    int *b=(int*)malloc(n*sizeof(int));
    int *c=(int*)malloc(n*sizeof(int));
    int *d=(int*)malloc(n*sizeof(int));

    for(int i=0;i<n;i++){
        a[i]=i;
        b[i]=7*i;
    }

    double starts=omp_get_wtime();
    for(int i=0;i<n;i++){
        c[i]=a[i]+b[i];
    }
    double ends=omp_get_wtime();

    double startp = omp_get_wtime();
    #pragma omp parallel for
    for(int i=0;i<n;i++){
        d[i]=a[i]+b[i];
    }

    double endp=omp_get_wtime();

    double speedup=(ends-starts)/(endp-startp);
    printf("Sequential time = %f\n",ends-starts);
    printf("Parallel time = %f\n",endp-startp);
    printf("Speedup = %f\n",speedup);

    free(a); free(b); free(c); free(d);
    return 0;
}


