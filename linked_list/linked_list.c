/* 
   Source file : 'lista.c' 
   Escrito por : Allan Cedric G.B. Alves da Silva
   Profile : Aluno de graduação do curso de Ciência da Computação (UFPR)
   GRR : 20190351
*/

#include "lista.h"

void cria_lista(t_lista *l)
{
	l->tamanho = 0;
	l->ini = NULL;
}

int lista_vazia(t_lista *l)
{
	return (l->ini == NULL);
}

void destroi_lista(t_lista *l)
{

	if (lista_vazia(l))
		return;

	t_nodo *p;

	while (!lista_vazia(l))
	{

		p = l->ini->prox;
		free(l->ini);
		l->ini = p;
	}

	l->tamanho = 0;
}

int insere_inicio_lista(int x, t_lista *l)
{

	t_nodo *elemento = (t_nodo *)malloc(sizeof(t_nodo));

	if (!elemento)
		return 0;

	elemento->chave = x;
	elemento->prox = l->ini;
	l->ini = elemento;

	l->tamanho++;

	return 1;
}

int insere_fim_lista(int x, t_lista *l)
{
	if (lista_vazia(l))
		return (insere_inicio_lista(x, l));

	t_nodo *elemento, *p;

	elemento = (t_nodo *)malloc(sizeof(t_nodo));

	if (!elemento)
		return 0;

	p = l->ini;

	while (p->prox)
		p = p->prox;

	elemento->chave = x;
	p->prox = elemento;
	elemento->prox = NULL;

	l->tamanho++;

	return 1;
}

int insere_ordenado_lista(int x, t_lista *l)
{
	if (lista_vazia(l) || x < l->ini->chave)
		return (insere_inicio_lista(x, l));

	t_nodo *ant, *p;

	ant = NULL;
	p = l->ini;

	while (x >= p->chave && p->prox)
	{
		ant = p;
		p = p->prox;
	}

	if (x >= p->chave && !p->prox)
		return (insere_fim_lista(x, l));

	t_nodo *elemento = (t_nodo *)malloc(sizeof(t_nodo));

	if (!elemento)
		return 0;

	elemento->chave = x;
	ant->prox = elemento;
	elemento->prox = p;

	l->tamanho++;

	return 1;
}

int remove_primeiro_lista(int *item, t_lista *l)
{

	if (lista_vazia(l))
		return 0;

	t_nodo *p = l->ini->prox;

	*item = l->ini->chave;

	free(l->ini);

	l->ini = p;

	l->tamanho--;

	return 1;
}

int remove_ultimo_lista(int *item, t_lista *l)
{

	if (lista_vazia(l))
		return 0;

	t_nodo *ant, *p;

	ant = NULL;
	p = l->ini;

	while (p->prox)
	{
		ant = p;
		p = p->prox;
	}

	*item = p->chave;

	free(p);

	if (ant)
		ant->prox = NULL;

	l->tamanho--;

	return 1;
}

int remove_item_lista(int chave, int *item, t_lista *l)
{

	if (lista_vazia(l))
		return 0;

	t_nodo *ant, *p;

	ant = NULL;
	p = l->ini;

	while (p->chave != chave && p->prox)
	{
		ant = p;
		p = p->prox;
	}

	if (p->chave != chave)
		return 0;

	*item = p->chave;

	if (!ant)
		l->ini = l->ini->prox;
	else
		ant->prox = p->prox;

	free(p);

	l->tamanho--;

	return 1;
}

int pertence_lista(int chave, t_lista *l)
{

	if (lista_vazia(l))
		return 0;

	t_nodo *p = l->ini;

	while (p->chave != chave && p->prox)
		p = p->prox;

	return (p->chave == chave);
}

int concatena_listas(t_lista *l, t_lista *m)
{

	if (lista_vazia(m))
		return 0;

	t_nodo *p = l->ini;

	if (!lista_vazia(l))
	{
		while (p->prox)
			p = p->prox;
		p->prox = m->ini;
	}
	else
		l->ini = m->ini;

	l->tamanho += m->tamanho;

	return 1;
}

int copia_lista(t_lista *l, t_lista *m)
{
	cria_lista(m);

	if (lista_vazia(l))
		return 0;

	t_nodo *p = l->ini;

	while (p->prox)
	{
		insere_fim_lista(p->chave, m);
		p = p->prox;
	}

	insere_fim_lista(p->chave, m);

	return 1;
}

void imprime_lista(t_lista *l)
{
	if (!lista_vazia(l))
	{
		t_nodo *p = l->ini;

		while (p->prox)
		{
			printf("%d ", p->chave);
			p = p->prox;
		}
		printf("%d\n", p->chave);
	}
}
