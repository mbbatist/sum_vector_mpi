#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define qtdinter 4
double sum_vector(int *a,int MAX)
{
    clock_t tic = clock();
    
    double n1,n2,n3,n4,ind=MAX/qtdinter;
    int v;
	for(v=1;v<=ind;v++){
		n1=n1+a[v];
		}
	printf("\n intervalo 1=%f " ,n1);

    for(v=v;v<=2*ind;v++){
		n2=n2+a[v];
		}
	printf("\n intervalo 2=%f " ,n2);

    for(v=v;v<=3*ind;v++){
		n3=n3+a[v];
		}
	printf("\n intervalo 3=%f " ,n3);

    for(v=v;v<=MAX-1;v++){
		n4=n4+a[v];
		}
	printf("\n intervalo 4=%f " ,n4);

    printf("\n \n * SOMA: %f \n",n1+n2+n3+n4);
    clock_t toc = clock();
  return (double)(toc - tic) / CLOCKS_PER_SEC;
}

void nparal(){
    FILE *file_select;

    file_select = fopen("select.txt","a");
    double result_time=0;

    int i,tam_vetor=100000; /* Lê o máximo de algarismos do vetor*/
    int aux,a[tam_vetor];

        for (i = 0; i < tam_vetor; i++) { a[i] = rand() % tam_vetor; } //valores aleatorios

        printf(" \n ***VETOR DE TAMANHO %d*** \n ",tam_vetor);

                result_time=sum_vector (a, tam_vetor);
                fprintf(file_select,"%d %f \n",tam_vetor,result_time);
}
