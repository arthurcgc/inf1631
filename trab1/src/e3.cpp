#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>
#include <assert.h>

#define num 5
using namespace std;

int grafo[num][num] = {
   {0, 1, 0, 1, 0},
   {1, 0, 1, 1, 1},
   {0, 1, 0, 0, 1},
   {1, 1, 0, 0, 1},
   {0, 1, 1, 1, 0},
};

 int grafo[num][num] = {
   {0, 1, 0, 1, 0},
   {1, 0, 1, 1, 1},
   {0, 1, 0, 0, 1},
   {1, 1, 0, 0, 0},
   {0, 1, 1, 0, 0},
}; 

int p[num];

void mostra() {// printa na tela o ciclo se hamiltoniano
	cout << "Ciclo: ";

	for (int i = 0; i < num; i++)
		cout << p[i] << " ";
	cout << p[0] << endl;
}

bool valido(int v, int k) {// verifica se tem vertice, se ja tiver ocupado, para ambos os casos retorna false, se nao, retorna true
	if (grafo[p[k - 1]][v] == 0)
		return false;

	for (int i = 0; i < k; i++)
		if (p[i] == v)
			return false;
	return true;
}

bool achaciclo(int k) {// confere se todos os vertices estao no passeio, verifica se pode realizar um ciclo
	if (k == num) {
		if (grafo[p[k - 1]][p[0]] == 1)
			return true;
		else
			return false;
	}

	for (int v = 1; v < num; v++) {
		if (valido(v, k)) {
			p[k] = v;
			if (achaciclo(k + 1) == true)
				return true;
			p[k] = -1;
		}
	}
	return false;
}

bool hamiltoniano() {
	for (int i = 0; i < num; i++)
		p[i] = -1;
	p[0] = 0; //first vertex as 0

	if (achaciclo(1) == false) {
		cout << "Nao tem solucao" << endl;
		return false;
	}

	mostra();
	return true;
}

int main() {
	hamiltoniano();
}
