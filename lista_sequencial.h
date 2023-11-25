#ifndef LISTA_SEQUENCIAL_H_INCLUDED
#define LISTA_SEQUENCIAL_H_INCLUDED
#define MAX 1000


//usando para chamar as funções e declarar a lista
struct lista{
        int elementos[MAX];
        int particao;
};
void inicializar(struct lista *l);
int inserir_fim(struct lista *l, int valor);
int inserir_inicio(struct lista *l, int valor);
int inserir_posicao(struct lista *l, int numero, int posicao);
void exibir_lista(struct lista *l);
int remover_inicio(struct lista *l);
int remover_fim(struct lista *l);
int remover_posicao(struct lista *l, int posicao);
int somatorio(struct lista *l);
void aoQuadrado(struct lista *l);
int qtdPrimo(struct lista *l);
int quantidadeElementos(struct lista *l);
void preencherLista(struct lista *l);
void inserir_ordem(struct lista *l, int numero);
int procurar(struct lista *l, int valor);
void remover(struct lista *l, int numero);
void reverter(struct lista *l);

#endif // LISTA_SEQUENCIAL_H_INCLUDED
