#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

int main(int argc, char const *argv[]){
 	int vector[]={15, 7, 5, 13},i,j,tamano=4;
 	double varianza=0,media=0;
 	//asumo que se cargo anteriormente el vector
 	#pragma omp parallel num_threads(tamano)
 	{
		#pragma omp for reduction(+:media)
		for (i=0; i < tamano; ++i){
			media+=vector[i];
		}
		if (omp_get_thread_num()==0){
			media/=tamano;
		}
	}
	#pragma omp parallel num_threads(tamano)
 	{
		#pragma omp for reduction(+:varianza)
		for (j=0; j < tamano; ++j){
			varianza+=((vector[j]-media)*(vector[j]-media));
		}
		if (omp_get_thread_num()==0){
			varianza/=(tamano-1);
		}
	}
	printf("varianza %f media %f\n",varianza,media);
 	return 0;
}