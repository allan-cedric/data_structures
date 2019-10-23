#include <stdio.h>
#include <stdlib.h>
#include "lista.h"


int cria_lista(t_lista *l){

	l->tamanho = 0;
	l->ini = NULL;
	return 1;

}

int lista_vazia(t_lista *l){
	return(l->ini == NULL);
}

void destroi_lista(t_lista *l){

	if(lista_vazia(l)){
	        printf("Nao destruida: lista vazia\n");	
		return;
	}

	t_nodo *p;
      		
	p = NULL;

	/* Enquanto a lista não estiver vazia,
	 libera memória do primeiro nodo */
	while(!(lista_vazia(l))){

		p = l->ini->prox; 
        	free(l->ini); 
        	l->ini = p; 

	}

        l->tamanho = 0; 
}

int insere_inicio_lista(int x, t_lista *l){

	t_nodo *elemento;

	elemento = (t_nodo *)malloc(sizeof(t_nodo));

	if(elemento == NULL)
		return 0;
	
	elemento->chave = x;       
	elemento->prox = l->ini;   
	l->ini = elemento;         
	
	(l->tamanho)++;

	return 1;

}

int insere_fim_lista(int x,t_lista *l){

	/* Caso base: Lista vazia, então insere no inicio */
	if(lista_vazia(l))   
		return(insere_inicio_lista(x,l));
	else{
	
		t_nodo *elemento, *p;

		elemento = (t_nodo *)malloc(sizeof(t_nodo));

		if(elemento == NULL)  
			return 0;

		p = l->ini; 

		/*No final da iteração, temos um ponteiro auxiliar
		 apontando para o último nodo*/
		while(p->prox != NULL)  
			p = p->prox;

		elemento->chave = x;
		p->prox = elemento;      
		elemento->prox = NULL;   

		(l->tamanho)++;
	}

	return 1;
}

int insere_ordenado_lista(int x,t_lista *l){
	
	/* Caso base: Lista vazia, então insere no inicio */
	if(lista_vazia(l))
		return(insere_inicio_lista(x,l));  
	else{
		t_nodo *elemento, *ant, *p;
		
		elemento = (t_nodo *)malloc(sizeof(t_nodo));

		if(elemento == NULL)  
			return 0;

		elemento->chave = x;
		ant = NULL;
		p = l->ini;

		while((p->chave <= x) && (p->prox != NULL)){

			ant = p;
			p = p->prox;

		}

		/*Primeiro 'if': MENOR ELEMENTO
		  'else if' : MAIOR ELEMENTO
		  'else' : Caso geral no meio */
		if((p == l->ini) && (p->chave > x)){ 
			elemento->prox = l->ini;
			l->ini = elemento;
		}else if((p->prox == NULL) && (p->chave <= x)){ 
			p->prox = elemento;
			elemento->prox = NULL;
		}else{                           
			ant->prox = elemento;
			elemento->prox = p;
		}

		
		(l->tamanho)++;
	}
	return 1;
}

int remove_primeiro_lista(int *item,t_lista *l){

	if(lista_vazia(l)) 
		return 0;

	t_nodo *p;

	p = l->ini->prox;

	*item = l->ini->chave; 

	free(l->ini);  

	l->ini = p;  

	(l->tamanho)--;

	return 1;

}

int remove_ultimo_lista(int *item,t_lista *l){

	if(lista_vazia(l))
		return 0;

	t_nodo *ant,*p;

	ant = NULL;

	p = l->ini;	

	while(p->prox != NULL){ 

		ant = p;
		p = p->prox;

	}

	*item = p->chave; 

	/*'if': APENAS UM ELEMENTO NA LISTA
	  'else': MAIS DE UM ELEMENTO NA LISTA */
	if(ant == NULL)       
		l->ini = ant;
	else               
		ant->prox = NULL;

	free(p); 

	(l->tamanho)--;

	return 1;
}

int remove_item_lista(int chave, int *item, t_lista *l){
	
	if(lista_vazia(l)){
		printf("Nao removido: elemento nao encontrado\n");
		return 0;
	}
	
	t_nodo *ant,*p;

	ant = NULL;

	p = l->ini;

        while((p->chave != chave) && (p->prox != NULL)){

		ant = p;
                p = p->prox;

	}

	if(p->chave != chave){
		printf("Nao removido: elemento nao encontrado\n");
		return 0;
	}

	*item = p->chave; 

	/* 'if': APENAS UM ELEMENTO NA LISTA
	   'else': MAIS DE UM ELEMENTO NA LISTA */
	if(ant == NULL)  
		l->ini = l->ini->prox;
	else     
		ant->prox = p->prox;
		
	free(p); 

	(l->tamanho)--;
		
	return 1;
}

int pertence_lista(int chave, t_lista *l){

	if(lista_vazia(l)) 
		return 0;

	t_nodo *p;

	p = l->ini;

	while((p->chave != chave) && (p->prox != NULL))
		p = p->prox;
	
	/*Garantir que vai ser igual*/
	if(p->chave == chave)
		return 1;

	return 0;

}

int concatena_listas(t_lista *l, t_lista *m){
	
	if(lista_vazia(m)) 
		return 0;

	t_nodo *p;

	p = l->ini;

	if(!(lista_vazia(l))){ 

		while(p->prox != NULL)
			p = p->prox;

		p->prox = m->ini;

	}else
		l->ini = m->ini;

	l->tamanho += m->tamanho;	

	cria_lista(m); 	

	return 1;
}

int copia_lista(t_lista *l, t_lista *m){
	
	cria_lista(m); 

	if(lista_vazia(l)) 
		return 0;
	
	t_nodo *p;

	p =  l->ini;

	while(p->prox != NULL){

		insere_fim_lista(p->chave,m); 
		p = p->prox;

	}

	insere_fim_lista(p->chave,m); 

	return 1;

}

void imprime_lista(t_lista *l){

	if(!(lista_vazia(l))){

		t_nodo *p;

		p = l->ini;

		while(p->prox != NULL){

			printf("%d ",p->chave); 
			p = p->prox;

		}

		printf("%d\n",p->chave);

	}
}
