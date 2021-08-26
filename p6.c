#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

int main(int argc, char const *argv[]){
	int vector[]={3,4,8,8,7},tamano=5,min,i;
	min=vector[0];
	#pragma omp parallel num_threads(4)
	{
		#pragma omp for
		for (i = 1; i < tamano; ++i)
		{
			if(min>vector[i]){
				min=vector[i];
			}
		}
		#pragma omp for
		for (i = 0; i < tamano; ++i)
		{
			vector[i]-=min;
		}
	}
	for (int i = 0; i < tamano; ++i)
	{
		printf("Distacia %d es %d\n",i+1,vector[i]);
	}
	return 0;
}