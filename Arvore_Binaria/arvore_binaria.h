/*
  Header file: 'arvore_binaria.h'
  Escrito por: Allan Cedric G.B. Alves da Silva
  Profile: Aluno de graduação do curso de Ciência da Computação (UFPR)
*/

#include <stdio.h>
#include <stdlib.h>

/* 
  Estrutura de dado de um nodo
*/
struct nodo_t
{
	struct nodo_t *esq ;	
	struct nodo_t *dir ;
  	struct nodo_t *pai ;
	
	int chave ;
} ;
typedef struct nodo_t nodo_t ;

/*
  Estrutura de dado da árvore
*/
struct arvore_t
{
	struct nodo_t *raiz ;
} ;
typedef struct arvore_t arvore_t ;

/*
  Avalia se a árvore está vazia(1) ou não(0)
*/
int arvore_vazia (arvore_t *a) ;

/*
  Cria a árvore
*/
int inicializa_arvore (arvore_t *a) ;

/*
  Cria o nodo raiz
*/
int inicializa_raiz (arvore_t *a, int chave) ;

/*
  Cria um novo nodo p/ arvore
*/
int insere_nodo (arvore_t *a, int chave) ;

/*
  Imprime árvore para 3 opções: 'pre-order'= 1, 'in-order'= 2 ou 'pos-order'= 3
*/
void imprime_arvore (nodo_t *n, int i) ;

/*
  Desaloca a memória da árvore
*/
void destroi_arvore (nodo_t *n) ;

/*
  Busca em uma árvore binária, retorna um ponteiro para o nodo buscado
*/
void *busca (nodo_t *n, int chave) ;

/*
  Retorna um ponteiro para o nodo que contém a MENOR chave
*/
void *minimo (nodo_t *n) ;

/*
  Retorna um ponteiro para o nodo que contém a MAIOR chave
*/
void *maximo (nodo_t *n) ;
