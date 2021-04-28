/* 
   Header file : 'pilha.h'
   Escrito por : Allan Cedric G.B. Alves da Silva
   Profile : Aluno de graduação do curso de Ciência da Computação (UFPR)
   GRR : 20190351
*/

#ifndef __PILHA_H__
#define __PILHA_H__

#include <stdio.h>

#define MAX 100 /* Tamanho da pilha */

typedef struct pilha_t
{
	int v[MAX];
	int topo;
} pilha_t;

/*
	Função que inicializa uma pilha.
	Se ela já existir, então será sobrescrita uma nova.
*/
void inicializa_pilha(pilha_t *p);

/*
	Função que verifica se a pilha está vazia ou não.
	Se estiver vazia retorna 1, senão 0.
*/
int pilha_vazia(pilha_t *p);

/*
	Função que retorna o tamanho da pilha.
*/
int tamanho_pilha(pilha_t *p);

/*
	Retorna 1 se o empilhamento do elemento 'x' foi bem sucedido,
	e 0 em caso contrário.
*/
int empilha(int x, pilha_t *p);

/*
	Retorna 1 se o desempilhamento foi bem sucedido,
	e 0 em caso contrário.
*/
int desempilha(pilha_t *p);

/*
	Retorna o elemento do topo da pilha na variável 't'.
	A função retorna 1 se a operação foi bem sucedida, e
	0 em caso contrário.
*/
int topo(int *t, pilha_t *p);

#endif
