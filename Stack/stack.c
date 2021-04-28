/* 
   Source file : 'pilha.c'
   Escrito por : Allan Cedric G.B. Alves da Silva
   Profile : Aluno de graduação do curso de Ciência da Computação (UFPR)
   GRR : 20190351
*/

#include "pilha.h"

void inicializa_pilha(pilha_t *p)
{
	p->topo = -1;
}

int pilha_vazia(pilha_t *p)
{
	return (p->topo == -1);
}

int tamanho_pilha(pilha_t *p)
{
	return (p->topo + 1);
}

int empilha(int x, pilha_t *p)
{
	if (tamanho_pilha(p) < MAX)
	{
		p->v[++(p->topo)] = x;
		return 1;
	}
	return 0;
}

int desempilha(pilha_t *p)
{
	if (pilha_vazia(p))
		return 0;
	p->topo--;
	return 1;
}

int topo(int *t, pilha_t *p)
{
	if (pilha_vazia(p))
		return 0;
	*t = p->v[p->topo];
	return 1;
}
