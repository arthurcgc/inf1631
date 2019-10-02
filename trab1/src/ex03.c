#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

typedef struct _viz Viz;
typedef struct _grafo Grafo;
typedef struct suniaoBusca UniaoBusca;



struct _viz {
	int noj;//
	Viz* prox;
};


struct _grafo {
	int nv;           /* numero de nos ou vertices */
	int na;           /* numero de arestas */
	Viz** viz;         /* viz[i] aponta para a lista de arestas vizinhas do no i */
};


struct suniaoBusca {
	int n;
	int* v;
};

UniaoBusca* ub_cria(int tam) {
	int i;
	UniaoBusca* ub = (UniaoBusca*)malloc(sizeof(UniaoBusca));
	assert(ub);
	ub->n = tam;
	ub->v = (int*)malloc(tam * sizeof(int));
	assert(ub->v);
	for (i = 0; i < tam; i++)
		ub->v[i] = -1;
	return ub;
}

int ub_busca(UniaoBusca* ub, int u) {
	int x = u;
	int aux;
	if ((u < 0) || (u > ub->n)) return -1;
	while (ub->v[u] >= 0) u = ub->v[u];
	while (ub->v[x] >= 0) {
		aux = x;
		x = ub->v[x];
		ub->v[aux] = u;
	}
	return u;
}

int ub_uniao(UniaoBusca* ub, int u, int v) {
	u = ub_busca(ub, u);
	v = ub_busca(ub, v);
	if ((u < 0) || (v < 0)) return -1;
	if (ub->v[u] > ub->v[v]) { /* negativos: v[u] menor em modulo! */
		ub->v[v] += ub->v[u];
		ub->v[u] = v;
		return v;
	}
	else {
		ub->v[u] += ub->v[v];
		ub->v[v] = u;
		return u;
	}
}

void  ub_libera(UniaoBusca* ub) {
	free(ub->v);
	free(ub);
}

void debug(UniaoBusca* ub) {
	int i;
	for (i = 0; i < ub->n; i++) printf("ub[%d]=%d\n", i, ub->v[i]);
}


static Viz* criaViz(Viz* head, int noj) {
	/* insere vizinho no inicio da lista */
	Viz* no = (Viz*)malloc(sizeof(Viz));
	assert(no);
	no->noj = noj;
	no->prox = head;
	return no;
}

static Grafo* grafoCria(int nv, int na) {

	int i;
	Grafo* g = (Grafo*)malloc(sizeof(Grafo));
	g->nv = nv;
	g->na = na;
	g->viz = (Viz**)malloc(sizeof(Viz*) * nv);

	for (i = 0; i < nv; i++)
		g->viz[i] = NULL;
	return g;
}

Grafo* grafoLe(char* filename) {
	/* cria grafo não orientado - supõe que arquivo está correto! */

	FILE* arq = fopen(filename, "rt");
	int nv, na, no1, no2 = 0;
	Grafo* novo;

	fscanf(arq, "%d %d", &nv, &na);
	novo = grafoCria(nv, na);
	assert(novo);
	while (fscanf(arq, "%d %d ", &no1, &no2) == 2) {
		novo->viz[no1] = criaViz(novo->viz[no1], no2);
		novo->viz[no2] = criaViz(novo->viz[no2], no1);

	}
	return novo;
}


Grafo* grafoLibera(Grafo* grafo) {
	if (grafo) {
		int i = 0;
		Viz* no, * aux;
		for (i = 0; i < grafo->nv; i++) {
			no = grafo->viz[i];
			while (no) {
				aux = no->prox;
				free(no);
				no = aux;
			}
		}
		free(grafo->viz);
		free(grafo);
	}
	return NULL;
}

void grafoMostra(char* title, Grafo* grafo) {
	int i;
	if (title)
		printf("%s", title);
	if (grafo) {
		printf("NV: %d, NA: %d\n", grafo->nv, grafo->na);
		for (i = 0; i < grafo->nv; i++) {
			Viz* viz = grafo->viz[i];
			printf("[%d]->", i);
			while (viz) {
				printf("%d->", viz->noj);
				viz = viz->prox;
			}
			printf("NULL\n");
		}
	}
}





int grafoConexo(Grafo* grafo) {
	int no;
	UniaoBusca* ub = ub_cria(grafo->nv);
	Viz* aux;

	for (no = 0; no < grafo->nv; no++) {
		aux = grafo->viz[no];
		while (aux) {
			if (ub_busca(ub, no) != ub_busca(ub, aux->noj))
				ub_uniao(ub, no, aux->noj);
			aux = aux->prox;
		}
	}

	int raiz = ub_busca(ub, 0);
	for (no = 1; no < grafo->nv; no++) {
		if (raiz != ub_busca(ub, no)) return 0;
	}

	return 1;
	ub_libera(ub);
	free(aux);
}



void PercorreProfundidade(Grafo* grafo, int* visitados, int no_inicial) {
	Viz* viz = grafo->viz[no_inicial];
	visitados[no_inicial] = 1;
	printf("%d \n", no_inicial);

	while (viz) {
		if (!visitados[viz->noj]) {// se nao tiver ali, visitamos, adicionamos e visita vizinho
			PercorreProfundidade(grafo, visitados, viz->noj);
		}
		viz = viz->prox;
	}
}




void Hamiltoniano(Grafo* g, int no_inicial) {
	
	int i = 0;
	int conexo = grafoConexo(g);
	int* visitados = (int*)malloc(sizeof(int) * g->nv);

	if (conexo != 1) {
		printf("Grafo não é conexo, logo, existem arestas que não estão ligadas, não podendo ser hamiltoniano");
		return;
	}
	for (i = 0; i < g->nv; i++) {
		visitados[i] = 0;
	}
	PercorreProfundidade(g, visitados, no_inicial);


}


int main()
{
	int noinicial;
	Grafo* g = grafoLe("Hamilton_10_1.txt");
	grafoMostra("Grafo dado: ", g);
	Hamiltoniano(g,3);

	return 0;
}