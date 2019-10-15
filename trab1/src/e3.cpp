#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>
#include <assert.h>
#include <time.h>

void ShowMatrix(int ** m, int nv){
	int i,j;
	for(i=0;i<nv;i++){/*print matrix, DO NOT FORGET TO DELETE THIS PART*/
		for(j=0;j<nv;j++){
			printf( "%d \t", m[i][j]);
		}
	}	
}

/*Verifica se o vértice v pode ser adcionado ao index p no ciclo hamiltoniano construido em p[]*/
bool valido(int v, int posicao, int *p,int **matrix) {// verifica se tem vertice, se ja tiver ocupado, para ambos os casos retorna false, se nao, retorna true
	if (matrix[p[posicao-1]][v] == 0)//verifica se vertices posicao-1 e v sao adjacentes, se nao forem, nao tem aresta entre eles 
		return false;

	for (int i = 0; i <= posicao; i++){//ve se ja foi incluido
		if (p[i]!=v)// se o vertice v ja foi ocupado
			return true;
	}
	return true;
}

/**/
bool achaciclo(int posicao,int *p,  int ** matrix, int nv ) {// confere se todos os vertices estao no passeio, verifica se pode realizar um ciclo
	if (posicao == nv) {// se ja verificou todos os vértices e falta um so
		if (matrix[p[posicao - 1]][p[0]] == 1)//elemento[0][0]
			return true;
		else
			return false;
	}
/* verifica todos os vértices candidatos, nao testa para zero que é o caso base*/
	for (int v = 1; v < nv; v++) {
		 if (valido(v, posicao, p, matrix)) {// ve se o=pode ser adicionado no ciclo... se nv nao tiver ali, marca v 
		 	p[posicao] = v;
			 /*percorre o resto do caminho*/ 
		 	if (achaciclo(posicao+1 , p, matrix, nv ) == true)// analisa a proxima posicao 
		 		return true;
		 	else
			 	p[posicao] = -1;
		 }
	}/* se nenhum vertice for adjacente a outro que nao esteja la, nao fecha ciclo*/
	
	return false;
}

bool hamiltoniano(int ** matrix,int nv) {
	int p[nv];
	int i,j;
	for (int i = 0; i < nv; i++)
		p[i] = -1;
	p[0]= 0; //first vertex as 0
	
	if (achaciclo(1,p,matrix, nv) == false) {/*try to find a cycle, if false, there is no cycle, therefore, no hamiltonian cycle*/
	 	printf("Nao tem solucao\n");
	 	return false;
	}

	//ShowMatrix(matrix,nv);
	return true;
}
 
int**  CreateMatrix(char *f){
	int i,j;
	int nv=0; int na=0;
	int origem,destino;
	FILE *arq = fopen(f,"rt");
	fscanf(arq, "%d %d", &nv, &na);
	int ** matrix=(int**)malloc(nv*sizeof(int*));
	for(i=0;i<nv;i++){
		matrix[i]=(int*)malloc(nv*sizeof(int));
	}
	for(i=0;i<nv;i++){/*set fields to zero*/
		for(j=0;j<nv;j++){
			matrix[i][j]=0;
		}
	}
	for(i=0;i<nv;i++){/*if there is a edge between vertices we set it to 1 if there is not, is 0*/
			fscanf(arq, "%d %d ", &origem,&destino);
			matrix[origem-1][destino-1]=1;
			matrix[destino-1][origem-1]=1;
	}

return matrix;}


int main() {
	int ** newmatrix=NULL;
	int nv,na;
	clock_t start, end;
    double cpu_time_used;

	
	newmatrix=CreateMatrix("Hamilton_10_1.txt");
	FILE *arq1 = fopen("Hamilton_10_1.txt","rt");
	fscanf(arq1, "%d %d", &nv, &na);
	start = clock();
	hamiltoniano(newmatrix,nv);
	end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
	printf("\n \n Tempo CPU: %f \n\n",cpu_time_used);

	printf("\n\n\n");
	newmatrix=CreateMatrix("Hamilton_20_1.txt");
	FILE *arq2 = fopen("Hamilton_20_1.txt","rt");
	fscanf(arq2, "%d %d", &nv, &na);
	start = clock();
	hamiltoniano(newmatrix,nv);
	end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
	printf("\n \n Tempo CPU: %f \n\n",cpu_time_used);

	printf("\n\n\n");
	newmatrix=CreateMatrix("Hamilton_20_2.txt");
	FILE *arq3 = fopen("Hamilton_20_2.txt","rt");
	fscanf(arq3, "%d %d", &nv, &na);
	start = clock();
	hamiltoniano(newmatrix,nv);
	end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
	printf("\n \n Tempo CPU: %f \n\n",cpu_time_used);

	printf("\n\n\n");
	newmatrix=CreateMatrix("Hamilton_20_3.txt");
	FILE *arq4 = fopen("Hamilton_20_3.txt","rt");
	fscanf(arq4, "%d %d", &nv, &na);
	start = clock();
	hamiltoniano(newmatrix,nv);
	end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
	printf("\n \n Tempo CPU: %f \n\n",cpu_time_used);

	printf("\n\n\n");
	newmatrix=CreateMatrix("Hamilton_20_4.txt");
	FILE *arq5 = fopen("Hamilton_20_4.txt","rt");
	fscanf(arq5, "%d %d", &nv, &na);
	start = clock();
	hamiltoniano(newmatrix,nv);
	end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
	printf("\n \n Tempo CPU: %f \n\n",cpu_time_used);

	// printf("\n\n\n");
	// newmatrix=CreateMatrix("Hamilton_20_5.txt");
	// FILE *arq6 = fopen("Hamilton_20_5.txt","rt");
	// fscanf(arq6, "%d %d", &nv, &na);
	// start = clock();
	// hamiltoniano(newmatrix,nv);
	// end = clock();
    // cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
	// printf("\n \n Tempo CPU: %f \n\n",cpu_time_used);

	// printf("\n\n\n");
	// newmatrix=CreateMatrix("Hamilton_50_1.txt");
	// FILE *arq7 = fopen("Hamilton_50_1.txt","rt");
	// fscanf(arq7, "%d %d", &nv, &na);
	// start = clock();
	// hamiltoniano(newmatrix,nv);
	// end = clock();
    // cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
	// printf("\n \n Tempo CPU: %f \n\n",cpu_time_used);

	// printf("\n\n\n");
	// newmatrix=CreateMatrix("Hamilton_50_2.txt");
	// FILE *arq8 = fopen("Hamilton_50_2.txt","rt");
	// fscanf(arq8, "%d %d", &nv, &na);
	// start = clock();
	// hamiltoniano(newmatrix,nv);
	// end = clock();
    // cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
	// printf("\n \n Tempo CPU: %f \n\n",cpu_time_used);

	// printf("\n\n\n");
	// newmatrix=CreateMatrix("Hamilton_50_3.txt");
	// FILE *arq9 = fopen("Hamilton_50_3.txt","rt");
	// fscanf(arq9, "%d %d", &nv, &na);
	// start = clock();
	// hamiltoniano(newmatrix,nv);
	// end = clock();
    // cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
	// printf("\n \n Tempo CPU: %f \n\n",cpu_time_used);

	// printf("\n\n\n");
	// newmatrix=CreateMatrix("Hamilton_50_4.txt");
	// FILE *arq10 = fopen("Hamilton_50_4.txt","rt");
	// fscanf(arq10, "%d %d", &nv, &na);
	// start = clock();
	// hamiltoniano(newmatrix,nv);
	// end = clock();
    // cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
	// printf("\n \n Tempo CPU: %f \n\n",cpu_time_used);

	// 	printf("\n\n\n");
	// newmatrix=CreateMatrix("Hamilton_50_5.txt");
	// FILE *arq11 = fopen("Hamilton_50_5.txt","rt");
	// fscanf(arq11, "%d %d", &nv, &na);
	// start = clock();
	// hamiltoniano(newmatrix,nv);
	// end = clock();
    // cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
	// printf("\n \n Tempo CPU: %f \n\n",cpu_time_used);

	// printf("\n\n\n");
	// newmatrix=CreateMatrix("Hamilton_100_1.txt");
	// FILE *arq12 = fopen("Hamilton_100_1.txt","rt");
	// fscanf(arq12, "%d %d", &nv, &na);
	// start = clock();
	// hamiltoniano(newmatrix,nv);
	// end = clock();
    // cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
	// printf("\n \n Tempo CPU: %f \n\n",cpu_time_used);

	// printf("\n\n\n");
	// newmatrix=CreateMatrix("Hamilton_100_2.txt");
	// FILE *arq13 = fopen("Hamilton_100_2.txt","rt");
	// fscanf(arq13, "%d %d", &nv, &na);
	// start = clock();
	// hamiltoniano(newmatrix,nv);
	// end = clock();
    // cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
	// printf("\n \n Tempo CPU: %f \n\n",cpu_time_used);

	// printf("\n\n\n");
	// newmatrix=CreateMatrix("Hamilton_100_3.txt");
	// FILE *arq14 = fopen("Hamilton_100_3.txt","rt");
	// fscanf(arq14, "%d %d", &nv, &na);
	// start = clock();
	// hamiltoniano(newmatrix,nv);
	// end = clock();
    // cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
	// printf("\n \n Tempo CPU: %f \n\n",cpu_time_used);

	// printf("\n\n\n");
	// newmatrix=CreateMatrix("Hamilton_100_4.txt");
	// FILE *arq15 = fopen("Hamilton_100_4.txt","rt");
	// fscanf(arq15, "%d %d", &nv, &na);
	// start = clock();
	// hamiltoniano(newmatrix,nv);
	// end = clock();
    // cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
	// printf("\n \n Tempo CPU: %f \n\n",cpu_time_used);

	// printf("\n\n\n");
	// newmatrix=CreateMatrix("Hamilton_100_5.txt");
	// FILE *arq16 = fopen("Hamilton_100_5.txt","rt");
	// fscanf(arq16, "%d %d", &nv, &na);
	// start = clock();
	// hamiltoniano(newmatrix,nv);
	// end = clock();
    // cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
	// printf("\n \n Tempo CPU: %f \n\n",cpu_time_used);

	// printf("\n\n\n");
	// newmatrix=CreateMatrix("Hamilton_200_1.txt");
	// FILE *arq17 = fopen("Hamilton_200_1.txt","rt");
	// fscanf(arq17, "%d %d", &nv, &na);
	// start = clock();
	// hamiltoniano(newmatrix,nv);
	// end = clock();
    // cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
	// printf("\n \n Tempo CPU: %f \n\n",cpu_time_used);

	// printf("\n\n\n");
	// newmatrix=CreateMatrix("Hamilton_200_2.txt");
	// FILE *arq18 = fopen("Hamilton_200_2.txt","rt");
	// fscanf(arq18, "%d %d", &nv, &na);
	// start = clock();
	// hamiltoniano(newmatrix,nv);
	// end = clock();
    // cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
	// printf("\n \n Tempo CPU: %f \n\n",cpu_time_used);

	// printf("\n\n\n");
	// newmatrix=CreateMatrix("Hamilton_500_1.txt");
	// FILE *arq19 = fopen("Hamilton_500_1.txt","rt");
	// fscanf(arq19, "%d %d", &nv, &na);
	// start = clock();
	// hamiltoniano(newmatrix,nv);
	// end = clock();
    // cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
	// printf("\n \n Tempo CPU: %f \n\n",cpu_time_used);

	// printf("\n\n\n");
	// newmatrix=CreateMatrix("Hamilton_500_2.txt");
	// FILE *arq20 = fopen("Hamilton_500_2.txt","rt");
	// fscanf(arq20, "%d %d", &nv, &na);
	// start = clock();
	// hamiltoniano(newmatrix,nv);
	// end = clock();
    // cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
	// printf("\n \n Tempo CPU: %f \n\n",cpu_time_used);

}
