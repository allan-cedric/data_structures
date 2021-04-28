/* 
   Header file : 'lista.h' 
   Escrito por : Allan Cedric G.B. Alves da Silva
   Profile : Aluno de graduação do curso de Ciência da Computação (UFPR)
   GRR : 20190351
*/

#ifndef __LISTA_H__
#define __LISTA_H__

#include <stdio.h>
#include <stdlib.h>

/*
    Nodo da lista
*/
struct t_nodo
{
    int chave;
    struct t_nodo *prox;
};
typedef struct t_nodo t_nodo;

/*
    Estrutura p/ representar a lista
*/
struct t_lista
{
    t_nodo *ini;
    int tamanho;
};
typedef struct t_lista t_lista;

/*
    Função que inicializa uma lista.
*/
void cria_lista(t_lista *l);

/*
    Função que retorna 1 se a lista está vazia, senão 0.
*/
int lista_vazia(t_lista *l);

/*
    Função que destrói uma lista.
*/
void destroi_lista(t_lista *l);

/*
    Função que insere um NOVO NODO com uma chave 'x' no início da lista.
    Retorna 1 se foi bem sucedida, senão 0.
*/
int insere_inicio_lista(int x, t_lista *l);

/*
    Função que insere um NOVO NODO com uma chave 'x' no fim da lista.
    Retorna 1 se foi bem sucedida, senão 0.
*/
int insere_fim_lista(int x, t_lista *l);

/*
    Função que insere um NOVO NODO com uma chave 'x' de forma ordenada.
    Retorna 1 se foi bem sucedido, senão 0.
*/
int insere_ordenado_lista(int x, t_lista *l);

/*
    Função que remove o primeiro nodo da lista.
    Além disso, retorna em *item a chave removida.
    Retorna 1 se foi bem sucedido, senão 0.
*/
int remove_primeiro_lista(int *item, t_lista *l);

/*
    Função que remove o último nodo da lista.
    Além disso, retorna em *item a chave removida.
    Retorna 1 se foi bem sucedido, senão 0.
*/
int remove_ultimo_lista(int *item, t_lista *l);

/*
    Função que remove um nodo com uma certa 'chave' da lista.
    Além disso, retorna em *item a chave removida.
    Retorna 1 se foi bem sucedido, senão 0.
*/
int remove_item_lista(int chave, int *item, t_lista *l);

/*
    Função que busca um nodo com uma certa 'chave' na lista.
    Retorna 1 se encontrou, senão 0.
*/
int pertence_lista(int chave, t_lista *l);

/*
    Função que concatena uma lista 'm' na lista 'l'.
    Retorna 1 se foi bem sucedida, senão 0.
*/
int concatena_listas(t_lista *l, t_lista *m);

/*
    Função que cria uma cópia (lista 'm') de uma
    lista 'l'. Retorna 1 se foi bem sucedida, senão 0.
*/
int copia_lista(t_lista *l, t_lista *m);

/*
    Função que imprime uma lista.
*/
void imprime_lista(t_lista *l);

#endif