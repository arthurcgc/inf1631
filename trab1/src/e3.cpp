#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>
#include <assert.h>


using namespace std;

// void show(int*matirx, int nv,int* p) {// printa na tela o ciclo se hamiltoniano
// 	cout << "Ciclo: ";

// 	for (int i = 0; i < nv; i++)
// 		cout << p[i] << " ";
// 	cout << p[0] << endl;
// }

// bool valido(int v, int k, int *p,int *matrix) {// verifica se tem vertice, se ja tiver ocupado, para ambos os casos retorna false, se nao, retorna true
// 	if (matrix[p[k - 1]][&v] == 0)
// 		return false;

// 	for (int i = 0; i < k; i++)
// 		if (p[i] == v)
// 			return false;
// 	return true;
// }

bool achaciclo(int k,int *p,  int ** matrix, int nv ) {// confere se todos os vertices estao no passeio, verifica se pode realizar um ciclo
	if (k == nv) {
		if (matrix[p[k - 1]][p[0]] == 1)
			return true;
		else
			return false;
	}

	for (int v = 1; v < nv; v++) {
		// if (valido(v, k, p, matrix)) {
		// 	p[k] = v;
		// 	if (achaciclo(k + 1, p, matrix, nv ) == true)
		// 		return true;
		// 	p[k] = -1;
		// }
	}
	return false;
}

// bool hamiltoniano(int ** matrix,int nv) {
// 	int p[nv];
// 	int i,j;
// 	for (int i = 0; i < nv; i++)
// 		p[i] = -1;
// 	p[0] = 0; //first vertex as 0
// 	for(i=0;i<nv;i++){/*print matrix, DO NOT FORGET TO DELETE THIS PART*/
// 		for(j=0;j<nv;j++){
// 			printf( "%d \t", matrix[i][j]);
// 		}
// 	}

// 	if (achaciclo(1,p,matrix, nv) == false) {/*try to find a cycle, if false, there is no cycle, therefore, no hamiltonian cycle*/
// 		cout << "Nao tem solucao" << endl;
// 		return false;
// 	}

// 	//show(matrix,nv,p);
// 	return true;
// }
 
bool Matrix(char *f){
	int i,j,nv,na, origem,destino;
	int p[nv];
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
	}
	for(i=0;i<nv;i++){/*print matrix, DO NOT FORGET TO DELETE THIS PART*/
		for(j=0;j<nv;j++){
			printf( "%d \t", matrix[i][j]);
		}
	}
	
	for (int i = 0; i < nv; i++)
		p[i] = -1;
		p[0] = 0;/*set teh first aux vertex to 0*/

 	if (achaciclo(1,p,matrix, nv) == false) {/*try to find a cycle, if false, there is no cycle, therefore, no hamiltonian cycle*/
 		cout << "Nao tem solucao" << endl;
 		return false;
 	}

	
}

int main() {

	Matrix("Hamilton_10_1.txt");

}
