#include <stdio.h>
#include <stdlib.h>
#include "lista_dupla.h"
#include "lista_dupla2.h"

void imprime_lista(t_lista *l){

        if(lista_destruida(l) || lista_vazia(l))
                return;

        inicializa_atual_inicio(l);

        while(l->atual != l->fim){

                printf("%d ",l->atual->chave);
                incrementa_atual(l);

        }

	printf("\n");

}

int copia_lista(t_lista *l, t_lista *c){
	
	if(lista_destruida(l) || lista_destruida(c) || lista_vazia(l))
		return 0;

	if(!(lista_vazia(c))){  /* C sendo uma lista vazia, então devemos destrui-la, e depois inicializa-la */

		destroi_lista(c);
		inicializa_lista(c);

	}

	inicializa_atual_inicio(l);

	while(l->atual != l->fim){

		insere_fim_lista(l->atual->chave,c);
		incrementa_atual(l);

	}

	c->tamanho = l->tamanho;

	return 1;

}

int concatena_listas(t_lista *l, t_lista *c){

	if(lista_destruida(l) || lista_destruida(c) || lista_vazia(c))
		return 0;
	
	/* Ultimo NODO de l <==> Primeiro NODO de c */
	l->fim->prev->prox = c->ini->prox;
	c->ini->prox->prev = l->fim->prev;

	/* Libera memória das SENTINELAS que não estão
	 na concatenação */
	free(l->fim);
	free(c->ini);
	l->fim = NULL;
	c->ini = NULL;

	l->fim = c->fim;
	c->fim = NULL;

	l->tamanho += c->tamanho;
	c->tamanho = 0;

	return 1;

}

int ordena_lista(t_lista *l){

	if(lista_destruida(l) || lista_vazia(l))
		return 0;

	/* Lista auxiliar que ao final
	 estará ORDENADA */
	t_lista aux;

	inicializa_lista(&aux);

	int chave = 0;

	/* Remove os elementos da lista l, e devolve inserindo ordenado na lista aux */
	while(!(lista_vazia(l))){

		remove_inicio_lista(&chave,l);
		insere_ordenado_lista(chave,&aux);

	}
	
	/* Mais eficiente que copiar a lista aux na lista l*/
	concatena_listas(l,&aux);

	return 1;

}

int intercala_listas(t_lista *l, t_lista *c, t_lista *i){

	if((lista_vazia(l) && lista_vazia(c)) || !(lista_vazia(i)))
		return 0;

	if(lista_destruida(l) || lista_destruida(c))
		return 0;

	ordena_lista(l);
	ordena_lista(c);

	inicializa_atual_inicio(l);
	inicializa_atual_inicio(c);

	/* Intercala igual ao do MERGE SORT */
	while((l->atual != l->fim) && (c->atual != c->fim)){

		if(l->atual->chave < c->atual->chave){

			insere_fim_lista(l->atual->chave,i);
			incrementa_atual(l);

		}else{

			insere_fim_lista(c->atual->chave,i);
			incrementa_atual(c);

		}

	}

	while(l->atual != l->fim){

	        insere_fim_lista(l->atual->chave,i);
		incrementa_atual(l);

	}	
	
	while(c->atual != c->fim){

	        insere_fim_lista(c->atual->chave,i);
		incrementa_atual(c);

	}	

	return 1;

}
