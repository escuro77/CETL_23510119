#include<stdio.h>
#include<omp.h>

int main(){
    long c=0;
    int n=100000;

    #pragma omp parallel for
    for(int i=0;i<n;i++){
        c++;
    }
    printf("Without synchronization %ld\n",c);

    c=0;

    #pragma omp parallel for
    for(int i=0;i<n;i++){
        #pragma omp critical
        c++;
    }
    printf("With synchronization %ld\n",c);

    return 0;

}