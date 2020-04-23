#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"

void inicializa_pilha(tad_pilha *p){
	p->indice_topo = -1;
}

int pilha_vazia(tad_pilha *p){
	return(p->indice_topo == -1);
}

int tamanho_pilha(tad_pilha *p){
	return(p->indice_topo + 1);
}

/* Se o tamanho da pilha não foi extrapolado,
   então empilha o elemento x */
int empilha(int x,tad_pilha *p){

	if(tamanho_pilha(p) < MAX){
		p->v[++(p->indice_topo)] = x;
		return 1;
	}

	return 0;
}

/*Retorna o topo da pilha em t, e o desempilha */
int desempilha(int *t,tad_pilha *p){
	
	if(pilha_vazia(p))
		return 0;

	*t = p->v[(p->indice_topo)--];
	return 1;
}

/*Retorna o topo da pilha em t */
int topo(int *t,tad_pilha *p){
	
	if(pilha_vazia(p))
		return 0;

	*t = p->v[p->indice_topo];
	return 1;

}
