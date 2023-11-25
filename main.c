#include <stdio.h>
#include <stdlib.h>
#include "lista_sequencial.h"

int main(int argc, char *argv) {
//variaveis para as funções
 int opcao, valor, posicao, soma, quantidade, primos;

//declaração da lista
struct lista *l1;
l1 = (struct lista *) malloc(sizeof(struct lista));
    inicializar(l1);

    //iniciar o case
    //utilizo windows, portanto, uso system cls para limpar a tela em linux o código é diferente
    while (1){
    system ("cls");
    printf("         LISTA SEQUENCIAL\n");
    printf("   DIGITE UMA OPCAO PARA MANIPULAR A LISTA\n");
    printf("\t1 - Inserir um numero na primeira posicao da lista\n");
    printf("\t2 - Inserir um numero na ultima posicao da lista\n");
    printf("\t3 - Inserir um numero na posicao que deseja\n");
    printf("\t4 - Inserir um numero mantendo a ordem crescente da lista\n");
    printf("\t5 - Exibir a lista completa\n");
    printf("\t6 - Reverter a lista\n");
    printf("\t7 - Remover o numero que esta na primeira posicao\n");
    printf("\t8 - Remover o numero que esta na ultima posicao\n");
    printf("\t9 - Remover um numero da posicao que escolher\n");
    printf("\t10 - Remover valor\n");
    printf("\t11 - Procurar um numero\n");
    printf("\t12 - Somar todos os numeros da lista\n");
    printf("\t13 - Tamanho da lista\n");
    printf("\t14 - Elevar cada numero da lista ao quadrado\n");
    printf("\t15 - Saber a quantidade de primos na lista\n");
    printf("\t99 - Fechar o programa\n");
    scanf("%d", &opcao);

     switch(opcao){
        case 1:
    preencherLista(l1);
        printf("\nDigite o numero que deseja inserir na primeira posicao da lista: ");
        scanf("%d", &valor);
    inserir_inicio(l1, valor);
        printf("Essa eh a nova lista: ");
    exibir_lista(l1);
            break;
        case 2:
    preencherLista(l1);
        printf("\nDigite o numero que deseja inserir na ultima posicao da lista: ");
        scanf("%d", &valor);
    inserir_fim(l1, valor);
        printf("Essa eh a nova lista: ");
    exibir_lista(l1);
            break;
        case 3:
    preencherLista(l1);
        printf("\nDigite o numero que deseja inserir na lista:");
        scanf("%d", &valor);
        printf("\nDigite a posicao para o numero: ");
        scanf("%d", &posicao);
    inserir_posicao(l1,valor,posicao);
        printf("Essa eh a nova lista: ");
    exibir_lista(l1);
            break;
    case 4:
         printf("\nESSA LISTA PRECISA SEGUIR A ORDEM CRESCENTE ");
    preencherLista(l1);
        printf("\nDigite o numero que deseja inserir na lista: ");
        scanf("%d", &valor);
    inserir_ordem(l1, valor);
    break;
    case 5:
    preencherLista(l1);
        break;
    case 6:
        preencherLista(l1);
        reverter(l1);
    break;
    case 7:
    preencherLista(l1);
        printf("\nLista apos a remocao do primeiro numero: ");
    remover_inicio(l1);
    exibir_lista(l1);
    break;
    case 8:
    preencherLista(l1);
        printf("\nLista apos a remocao do ultimo numero: ");
    remover_fim(l1);
    exibir_lista(l1);
    break;
    case 9:
    preencherLista(l1);
        printf("\nDigite a posicao que deseja remover: ");
        scanf("%d", &posicao);
    remover_posicao(l1,posicao);
    printf("Essa eh a nova lista: ");
    exibir_lista(l1);
    break;
    case 10:
    preencherLista(l1);
        printf("\nDigite o numero que deseja remover: ");
        scanf("%d", &valor);
    remover(l1, valor);
    break;
    case 11:
    preencherLista(l1);
        printf("\nDigite o numero que deseja encontrar a posicao: ");
        scanf("%d", &valor);
    procurar(l1, valor);
    break;
    case 12:
    preencherLista(l1);
    soma = somatorio(l1);
        printf("\nEssa eh a soma dos numeros da lista: %d", soma);
    break;
    case 13:
    preencherLista(l1);
    quantidade = quantidadeElementos(l1);
        printf("\nEssa eh a  quantidade de elementos armazenados na lista: %d", quantidade);
    break;
    case 14:
    preencherLista(l1);
    aoQuadrado(l1);
    break;
    case 15:
    preencherLista(l1);
    primos = qtdPrimo(l1);
        printf("\nEssa eh a quantidade de elementos com valores primos: %d", primos);
    case 99:

    exit(0);
            break;
            default: printf("OPCAO INVALIDA");
     } getchar();
       getchar();
}
}
