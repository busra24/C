#include <stdio.h>
#include <stdlib.h>

double cubukkirma(){
	
	double x = rand()/(double) RAND_MAX;
	double kisa;
	
	if (x < 0.001){
		x = 0.001;
	}
	else {
		kisa = 1 - x;
	}
	
	return kisa;
}

int main(){
	int i=0;
	double toplam=0;
	int n=100;
	while(i < n){
		i++;
		double x = cubukkirma();
		toplam = toplam + x;
		printf("\n\n %i.deney: %lf\n\n",i,x);
	}
	printf("toplam: %lf, ortalama: %lf\n", toplam, toplam/n);
	}
