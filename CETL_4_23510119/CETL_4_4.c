#include <stdio.h>
#include <omp.h>

int main() {
    int sum=0;
    int p_sum=0;
    #pragma omp for lastprivate(sum)
    for(int i=1;i<=20;i++){
            p_sum+=i;
    }

    sum=p_sum;
    
    printf("Total sum = %d\n",sum);
    return 0;
}
