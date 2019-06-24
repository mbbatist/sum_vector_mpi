# Commands to run the code

1. make
2. mpirun -np <nº of processes> --hostfile host_file master_slave

# Commands to run the GNUplot code

3.gcc -o grafico grafico.c

4../grafico 

### To remove the created executable file use the command:

make clean