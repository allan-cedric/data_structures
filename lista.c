#include <stdio.h>
#include <stdlib.h>
#include "lista.h"


/*Cria a lista com tamanho 0, e a o primeiro ponteiro aponta para NULL */
int cria_lista(t_lista *l){

	l->tamanho = 0;
	l->ini = NULL;
	return 1;

}

/*Se o primeiro ponteiro da lista aponta para NULL, então a lista está vazia*/
int lista_vazia(t_lista *l){
	return(l->ini == NULL);
}

void destroi_lista(t_lista *l){

	if(lista_vazia(l)) /*Não tem nada para destruir*/
		return;

	t_nodo *p = NULL;  

	while(!(lista_vazia(l))){

		p = l->ini->prox; /*Armazena o ponteiro pro SEGUNDO NODO*/

        	free(l->ini);  /*Libera o PRIMEIRO NODO*/

        	l->ini = p; /*Conecta o SEGUNDO NODO com o ponteiro inicial*/

	}

        l->tamanho = 0; /*Redefine tamanho para zero*/
}

int insere_inicio_lista(int x, t_lista *l){

	t_nodo *elemento = (t_nodo *)malloc(sizeof(t_nodo)); /*Novo NODO formado*/

	if(elemento == NULL) /*Se não tiver memória*/
		return 0;
	

	elemento->chave = x;       /*Novo valor*/
	elemento->prox = l->ini;   /*Faz o novo NODO apontar para o PRIMEIRO NODO*/
	l->ini = elemento;         /*Faz o ponteiro inicial apontar para o novo NODO */
	
	(l->tamanho)++;

	return 1;

}

int insere_fim_lista(int x,t_lista *l){

	if(lista_vazia(l))   /*Se a lista estiver vazia, pode preencher como se fosse para inserir no inicio*/
		return(insere_inicio_lista(x,l));
	else{
	
		t_nodo *elemento = (t_nodo *)malloc(sizeof(t_nodo));  /*Novo NODO*/

		if(elemento == NULL)  /*Se não tiver memória*/
			return 0;

		elemento->chave = x; /*Novo valor*/

		t_nodo *p = l->ini;  /*Ponteiro auxiliar para varrer a lista*/

		while(p->prox != NULL)  /*Quando encontra NULL, entao estou no último NODO*/
			p = p->prox;

		p->prox = elemento;      /*Último NODO aponta para o novo NODO*/
		elemento->prox = NULL;   /*Novo NODO aponta para NULL*/

		(l->tamanho)++;
	}

	return 1;
}

int insere_ordenado_lista(int x,t_lista *l){

	if(lista_vazia(l))
		return(insere_inicio_lista(x,l));  /*Se a lista estiver vazia, o novo NODO já está ordenado*/
	else{
		t_nodo *elemento = (t_nodo *)malloc(sizeof(t_nodo)); /*Novo NODO*/
		
		t_nodo *ant = NULL;    /*Armazena NODO anterior*/
		t_nodo *p = l->ini;    /*Armazena NODO atual */

		if(elemento == NULL)  /*Se não tiver memória*/
			return 0;

		elemento->chave = x;  /*Novo valor*/

		while((p->chave <= x) && (p->prox != NULL)){  /*Varre como se fosse 'busca por sentinela'*/
			ant = p;
			p = p->prox;
		}

		if((p == l->ini) && (p->chave > x)){ /*Menor elemento da lista*/
			elemento->prox = l->ini;
			l->ini = elemento;
		}else if((p->prox == NULL) && (p->chave <= x)){ /*Maior elemento da lista*/
			p->prox = elemento;
			elemento->prox = NULL;
		}else{                           /*Caso geral no meio da lista*/
			ant->prox = elemento;
			elemento->prox = p;
		}

		
		(l->tamanho)++;
	}
	return 1;
}

int remove_primeiro_lista(int *item,t_lista *l){

	if(lista_vazia(l)) /*Não tem elementos para remover*/
		return 0;

	*item = l->ini->chave; /*Guarda o valor do PRIMEIRO NODO*/

	t_nodo *p = l->ini->prox; /*Armazena o ponteiro para o SEGUNDO NODO*/

	free(l->ini);  /*Libera memória do PRIMEIRO NODO*/

	l->ini = p;  /*Conecta o ponteiro inicial com o SEGUNDO NODO*/

	(l->tamanho)--;

	return 1;

}

int remove_ultimo_lista(int *item,t_lista *l){

	if(lista_vazia(l))
		return 0;

	t_nodo *ant = NULL;  /*Armazena NODO anterior*/
	t_nodo *p = l->ini;  /*Armazena NODO atual*/

	while(p->prox != NULL){  /*Varre até o último NODO*/
		ant = p;
		p = p->prox;
	}

	*item = p->chave; /*Armazena o valor do último NODO*/

	if(ant == NULL)       /*A lista tem apenas 1 NODO*/
		l->ini = ant;
	else               /*A lista tem MAIS de 1 NODO*/
		ant->prox = NULL;

	free(p); /*Libera memória do ÚLTIMO NODO*/

	(l->tamanho)--;

	return 1;
}

int remove_item_lista(int chave, int *item, t_lista *l){
	
	if(lista_vazia(l))
		return 0;
	
	t_nodo *ant = NULL;  /*Armazena NODO anterior*/
	t_nodo *p = l->ini;  /*Armazena NODO atual*/

        while((p->chave != chave) && (p->prox != NULL)){ /*Busca por sentinela*/
		ant = p;
                p = p->prox;
	}

	if(p->chave != chave) /*Garante se é diferente, pois o 'while' anterior pode ter a combinação TRUE and FALSE*/
		return 0;

	*item = p->chave; /*Armazena valor do NODO ATUAL*/

	if(ant == NULL)  /*O elemento para remover é na verdade o PRIMEIRO NODO*/
		l->ini = l->ini->prox;
	else     
		ant->prox = p->prox;
		
	free(p); /*Libera memória do NODO atual*/

	(l->tamanho)--;
		
	return 1;
}

int pertence_lista(int chave, t_lista *l){

	if(lista_vazia(l)) /*Não tem elementos*/
		return 0;

	t_nodo *p = l->ini; /*Armazena NODO atual*/

	while((p->chave != chave) && (p->prox != NULL))
		p = p->prox;
	
	if(p->chave == chave) /*Garante que o elemento foi encontrado, pois pode haver a combinação do 'while' anterior: TRUE and FALSE*/
		return 1;

	return 0;

}

int concatena_listas(t_lista *l, t_lista *m){
	
	if(lista_vazia(m)) /*Se a segunda lista(m) é vazia, então não existe concatenação*/
		return 0;

	l->tamanho += m->tamanho; /* Junção de tamanhos para a primeira lista(l)*/

	if(!(lista_vazia(l))){ /*Se a primeira lista(l) não for vazia, então conecta o último nodo da lista l com o primeiro nodo da lista m*/

		t_nodo *p = l->ini;

		while(p->prox != NULL)
			p = p->prox;

		p->prox = m->ini;
	}else
		l->ini = m->ini;  /*Se a lista l for vazia, então apenas conecte o ponteiro inicial da lista l no primeiro nodo da lista m*/

	cria_lista(m); 	/*Como a lista m reseta, entao utilizei uma função que garante uma 'lista nova' */

	return 1;
}

int copia_lista(t_lista *l, t_lista *m){
	
	cria_lista(m); /*Cria uma nova lista para copiar*/

	if(lista_vazia(l)) /*Apenas cria uma lista nova*/
		return 0;
	
	t_nodo *p = l->ini; /*Armazena NODO atual da lista l*/

	while(p->prox != NULL){ 
		insere_fim_lista(p->chave,m); /*Garante inserção na lista m em ordem igual a da lista l*/
		p = p->prox;
	}

	insere_fim_lista(p->chave,m); /*Insere último nodo da lista l*/

	return 1;

}

void imprime_lista(t_lista *l){

	if(!(lista_vazia(l))){

		t_nodo *p = l->ini;/*Armazena NODO atual*/

		while(p->prox != NULL){ 
			printf("%d ",p->chave); /*Imprime o valor do NODO atual*/
			p = p->prox;
		}
		printf("%d\n",p->chave);/*Imprime o valor do último NODO*/

	}
}
