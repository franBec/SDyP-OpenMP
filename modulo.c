#include <stdio.h>
#include <stdlib.h>
#include <omp.h>
#include <math.h>

int main(int argc, char const *argv[]){
	int vector[]={15, 7, 5, 13};
	int i, suma=0,size=4;
	float resultado=0;
	#pragma omp parallel num_threads(4)
	{
		#pragma omp for reduction(+:suma)
		for(i = 0; i < size; ++i){
			suma += pow(vector[i],2);
		}
		#pragma omp barrier
		if (omp_get_thread_num()==0){
			resultado = sqrt(suma);
		}
	}
	printf("Resultado: %f\n",resultado);
	return 0;
}