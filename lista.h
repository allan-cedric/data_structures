struct t_nodo {
    int chave;
    struct t_nodo *prox;
};
typedef struct t_nodo t_nodo;

struct t_lista {
    t_nodo *ini;
    int tamanho;
};
typedef struct t_lista t_lista;

int cria_lista(t_lista *l);
int lista_vazia(t_lista *l);
void destroi_lista(t_lista *l);
int insere_inicio_lista(int x, t_lista *l);
int insere_fim_lista(int x, t_lista *l);
int insere_ordenado_lista(int x, t_lista *l);
void imprime_lista(t_lista *l);
int remove_primeiro_lista(int *item,t_lista *l);
int remove_ultimo_lista(int *item,t_lista *l);
int remove_item_lista(int chave, int *item, t_lista *l);
int pertence_lista(int chave, t_lista *l);
int concatena_listas(t_lista *l, t_lista *m);
int copia_lista(t_lista *l, t_lista *m);
