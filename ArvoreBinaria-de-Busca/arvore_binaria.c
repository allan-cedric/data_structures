/* 
   Source file : 'arvore_binaria.c'
   Escrito por : Allan Cedric G.B. Alves da Silva
   Profile : Aluno de graduação do curso de Ciência da Computação (UFPR)
   GRR : 20190351
*/

#include "arvore_binaria.h"

int arvore_vazia(arvore_t *a)
{
	return (a->raiz == NULL);
}

int inicializa_arvore(arvore_t *a)
{
	a->raiz = NULL;
	a->tam = 0;
	return 1;
}

int inicializa_raiz(arvore_t *a, int chave)
{
	if (!arvore_vazia(a))
	{
		perror("Essa árvore já possui um NODO RAIZ!");
		return 0;
	}

	a->raiz = malloc(sizeof(nodo_t));

	if (!a->raiz)
	{
		perror("Memória insuficiente p/ criar um NODO RAIZ!");
		exit(1);
	}

	a->tam++;
	a->raiz->chave = chave;
	a->raiz->pai = NULL;
	a->raiz->esq = NULL;
	a->raiz->dir = NULL;

	return 1;
}

int insere_nodo(arvore_t *a, int chave)
{
	if (arvore_vazia(a))
		return inicializa_raiz(a, chave);

	nodo_t *novo = malloc(sizeof(nodo_t));

	if (!novo)
	{
		perror("Memória insuficiente p/ inserir um NODO!");
		exit(1);
	}

	a->tam++;
	novo->chave = chave;
	novo->esq = NULL;
	novo->dir = NULL;

	nodo_t *aux = a->raiz;
	nodo_t *ant = NULL;

	while (aux != NULL)
	{
		ant = aux;
		if (chave >= aux->chave)
			aux = aux->dir;
		else
			aux = aux->esq;
	}

	if (chave >= ant->chave)
		ant->dir = novo;
	else
		ant->esq = novo;
	novo->pai = ant;

	return 1;
}

void imprime_arvore(nodo_t *n, const char *opcao)
{
	if (!n)
		return;

	/* PRE-ORDER */
	if (!strcmp(opcao, "pre"))
	{
		printf("%i ", n->chave);
		imprime_arvore(n->esq, "pre");
		imprime_arvore(n->dir, "pre");
	}
	/* IN-ORDER */
	else if (!strcmp(opcao, "in"))
	{
		imprime_arvore(n->esq, "in");
		printf("%i ", n->chave);
		imprime_arvore(n->dir, "in");
	}
	/* POS-ORDER */
	else if (!strcmp(opcao, "pos"))
	{
		imprime_arvore(n->esq, "pos");
		imprime_arvore(n->dir, "pos");
		printf("%i ", n->chave);
	}
	else
		perror("Valor inválido do segundo argumento!");
}

void destroi_arvore(arvore_t *a, nodo_t *n)
{
	if (!n || arvore_vazia(a))
		return;

	a->tam--;
	/* POS-ORDER */
	destroi_arvore(a, n->esq);
	destroi_arvore(a, n->dir);
	free(n);
	n = NULL;
}

void *busca(nodo_t *n, int chave)
{
	if (!n || n->chave == chave)
		return n;

	if (chave >= n->chave)
		return (busca(n->dir, chave));
	return (busca(n->esq, chave));
}

void *minimo(nodo_t *n)
{
	if (!n)
		return n;
	while (n->esq)
		n = n->esq;
	return n;
}

void *maximo(nodo_t *n)
{
	if (!n)
		return n;
	while (n->dir)
		n = n->dir;
	return n;
}
