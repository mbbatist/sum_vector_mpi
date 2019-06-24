#include <mpi.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "nparal.c"
#define RANK_MESTRE 0
#define TAG_OPERACOES 50
#define tam_vector 100000
double n=0,tempo;

int main(int argc, char** argv){
    MPI_Init(NULL,NULL);

    int world_size;
    MPI_Comm_size(MPI_COMM_WORLD, &world_size);

    int world_rank;
    MPI_Comm_rank(MPI_COMM_WORLD, &world_rank);

    int name_len;
    char processor_name[MPI_MAX_PROCESSOR_NAME];
    MPI_Get_processor_name(processor_name, &name_len);

    double response[2],ind;
    response[1]=1;
    if(world_rank == RANK_MESTRE){
        nparal();
	FILE *file_insert;

    	file_insert = fopen("insert.txt","a");
    	double result_time=0;

    	int i; /* Lê o máximo de algarismos do vetor*/
        int aux,a[tam_vector];

        for (i = 0; i < tam_vector; i++) { a[i] = rand() % tam_vector; } //valores aleatorios

        printf(" \n ***VETOR DE TAMANHO %d*** \n ",tam_vector);
		double ind=tam_vector/3;
        for(int i=1; i<world_size; i++){
        MPI_Send(&ind, 2, MPI_INT, i, TAG_OPERACOES, MPI_COMM_WORLD);}
	    clock_t tic = clock();
        printf("Processo mestre executando em %s.\n", processor_name);
        for(int i=1; i<world_size; i++){
        MPI_Recv(&response[1], 2, MPI_INT, i, TAG_OPERACOES, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
        n=n+response[1];}
        clock_t toc = clock();
	    tempo=(toc - tic) / CLOCKS_PER_SEC;
        printf("*SOMA: %f",n);
        fprintf(file_insert,"%d %f \n",tam_vector,tempo);
    }
    else{
        MPI_Recv(&ind, 2, MPI_INT, RANK_MESTRE, TAG_OPERACOES, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
        
        if(world_rank == 1){
            response[0] = 1;
            double v;
	        for(v=1;v<=ind;v++){
		        response[1]=response[1]+v;
		    }
	        //printf("inter1=%f " ,response[1]);
        }
        else if(world_rank == 2){
            response[0] = 2;
            double v;
	        for(v=ind+1;v<=2*ind;v++){
		        response[1]=response[1]+v;
		    }
	        //printf("inter2=%f " ,response[1]);
        }
        else if(world_rank == 3){
            response[0] = 3;
            double v;
	        for(v=2*ind+1;v<=3*ind;v++){
		        response[1]=response[1]+v;
		    }
	        //printf("inter3=%.0f " ,response[1]);
        }
        printf("Escravo %.0f calculou: %.0f \n",response[0],response[1]);
        MPI_Send(&response[1], 2, MPI_INT, RANK_MESTRE, TAG_OPERACOES, MPI_COMM_WORLD);
    }
    MPI_Finalize();
    }