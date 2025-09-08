#include<stdio.h>
#include<omp.h>

int main(){
    int n;
    printf("Size of series ");
    scanf("%d",&n);

    #pragma omp parallel
    {
        int t=omp_get_thread_num();
        if(t%2==0) printf("Thread %d: 2\n",t);
        else printf("Thread %d: 4\n",t);
    }
    return 0;
}