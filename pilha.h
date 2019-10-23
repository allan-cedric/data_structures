#define MAX 5

typedef struct tad_pilha{
	int v[MAX];
	int indice_topo;
}tad_pilha;

void inicializa_pilha(tad_pilha *p);

int pilha_vazia(tad_pilha *p);

int tamanho_pilha (tad_pilha *p);

int empilha(int x,tad_pilha *p);

int desempilha(int *t,tad_pilha *p);

int topo (int *t,tad_pilha *p);
