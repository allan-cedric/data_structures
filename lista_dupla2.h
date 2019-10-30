/*
  Feito por Marcos Castiho para a disciplina CI1001 - Programacao I
  Em 18/10/2019.
  Biblioteca auxiliar que manipula o TAD lista. 
*/
#define MAX 5

/*
  Funcao que imprime todos os elementos da lista, do inicio ao fim.
  Caso a lista seja vazia nao imprime nada, nem um \n
*/
void imprime_lista(t_lista *l);

/*
  Funcao que copia todos os elementos da lista l na lista c.
  Retorna 1 se a operação foi bem sucedida e zero caso contrário.
*/
int copia_lista(t_lista *l, t_lista *c);

/*
  Concatena os elementos da lista m (na mesma ordem) ao final
  da lista l e destroi a lista m.
  Retorna 1 se a operação foi bem sucedida e zero caso contrário.
*/
int concatena_listas(t_lista *l, t_lista *c);

/*
  Ordena a lista l em ordem crescente.
  Retorna 1 se a operação foi bem sucedida e zero caso contrário.
*/
int ordena_lista(t_lista *l);

/*
  Funcao que cria uma nova lista i pela intercalacao dos elementos
  das listas l e c. As listas l e c devem estar ordenadas.
  Retorna 1 se a operação foi bem sucedida e zero caso contrário.
*/
int intercala_listas(t_lista *l, t_lista *m, t_lista *i);
