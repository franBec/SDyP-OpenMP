#include <stdio.h>
#include <stdlib.h>
#include <omp.h>


int main(int argc, char const *argv[]){
	int mean_array[]={15, 7, 5, 13},aSize=4;
	double mean = 0;
    #pragma omp parallel num_threads(4)
    {
      #pragma omp for reduction(+:mean)
      for (int i=0; i<aSize; i++) {
         mean += mean_array[i];
      }
    }
    mean /= aSize;
    printf("Hola %d Media %f\n", omp_get_thread_num(),mean);
	return 0;
}
 