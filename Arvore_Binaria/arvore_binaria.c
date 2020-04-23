/*
  Implementação das funções p/ manipular uma
  árvore binária simples
*/

#include "arvore_binaria.h"

int arvore_vazia (arvore_t *a)
{
	return (a->raiz == NULL) ;
}

int inicializa_arvore (arvore_t *a)
{
	a->raiz = NULL ;
	return 1 ;
}

int inicializa_raiz (arvore_t *a, int chave)
{
	if (!arvore_vazia(a))
	{
		perror ("Essa árvore já possui um NODO RAIZ!") ;
		exit (1) ;
	}

	a->raiz = malloc (sizeof(nodo_t)) ;

	if (!a->raiz)
	{
		perror ("Memória insuficiente p/ criar um NODO RAIZ!") ;
		exit (1) ;
	}

	a->raiz->chave = chave ;
	a->raiz->pai = NULL ;
	a->raiz->esq = NULL ;
	a->raiz->dir = NULL ;

	return 1 ;
}

int insere_nodo (arvore_t *a, int chave)
{
	if (arvore_vazia(a))
		return inicializa_raiz (a, chave) ;

	nodo_t *novo = malloc (sizeof(nodo_t)) ;

	if (!novo)
	{
		perror ("Memória insuficiente p/ inserir um NODO!") ;
		exit (1) ;
	}

	novo->chave = chave ;
	novo->esq = NULL ;
	novo->dir = NULL ;

	nodo_t *aux = a->raiz;
	nodo_t *ant = NULL ;

	/* Inserção de um novo nodo como folha */
	while (aux != NULL)
	{
		ant = aux ;
		if (chave >= aux->chave)
			aux = aux->dir ;
		else
			aux = aux->esq ;
	}

	if (chave >= ant->chave)
		ant->dir = novo ;
	else
		ant->esq = novo ;
	novo->pai = ant ;

	return 1 ;
}

void imprime_arvore (nodo_t *n, int i)
{
	if (!n)
		return ;

	/* PRE-ORDER */
	if (i == 1)
	{
		printf ("%i ",n->chave) ;
		imprime_arvore (n->esq, 1) ;
		imprime_arvore (n->dir, 1) ;
	}
	/* IN-ORDER */
	else if (i == 2)
	{
		imprime_arvore (n->esq, 2) ;
		printf ("%i ",n->chave) ;
		imprime_arvore (n->dir, 2) ;
	}
	/* POS-ORDER */
	else if (i == 3)
	{
		imprime_arvore (n->esq, 3) ;
		imprime_arvore (n->dir, 3) ;
		printf ("%i ",n->chave) ;
	}
	else
	{
		printf ("Valor inválido do segundo argumento\n") ;
		return ;
	}
}

void destroi_arvore (nodo_t *n)
{
	if (!n)
		return ;

	/* POS-ORDER */
	destroi_arvore (n->esq) ;
	destroi_arvore (n->dir) ;
	free (n) ;
}

void *busca (nodo_t *n, int chave)
{
	if (!n || n->chave == chave)
		return n ;

	if (chave >= n->chave)
		return (busca(n->dir, chave)) ;
	return (busca(n->esq, chave)) ;
}

void *minimo (nodo_t *n)
{
	while (n->esq)
		n = n->esq ;
	return n;
}

void *maximo (nodo_t *n)
{
	while (n->dir)
		n = n->dir ;
	return n ;
}
