#include <stdio.h>
#include <stdlib.h>
#define GNUPLOT "gnuplot -persist"
#define qtdinter 4

void main(){
    FILE *gp;
    gp = popen(GNUPLOT, "w");
    if (gp == NULL) {
        printf("Erro ao abrir pipe para o GNU plot.\n"
            "Instale com 'sudo apt-get install gnuplot'\n");
        exit(0);
    }
    fprintf(gp, "set title 'Vetor de Tamanho Aleatorio'\n");
    fprintf(gp, "set key above\n");
    fprintf(gp, "set xlabel 'Tamanho do vetor'\n");
    fprintf(gp, "set ylabel 'Tempo de processamento do algoritmo'\n");
    fprintf(gp, "plot 'insert.txt' title 'Paralelo' with linespoints,'select.txt' title 'Sequencial' with linespoints\n");
    fprintf(gp, "\n");
    fclose(gp);
    remove("gp");
    remove("select.txt");
    remove("insert.txt");
}