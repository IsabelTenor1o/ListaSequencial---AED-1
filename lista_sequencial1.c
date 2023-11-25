#include <stdio.h>
#include <stdlib.h>
#include "lista_sequencial.h"
#define MAX 1000

//inicializando a lista
void inicializar(struct lista *l) {
l-> particao= 0;
}
//função 0, preecher a lista como o usuario quiser, uso -1 como condicao de parada
void preencherLista(struct lista *l) {
    int i = 0, numero;
    printf("\nDigite os numeros que deseja adicionar a lista (digite -1 para parar):\n");

    while (1) {
        printf("Numero %d: ", i + 1);
        scanf("%d", &numero);
        if (numero == -1) {
            break;
        }
        l-> elementos[i] = numero;
        i++;
    }
    l-> particao = i;
    printf("A lista que voce declarou: ");
     for(i = 0; i < l-> particao; i++) {
        printf("[%d]", l-> elementos[i]);
}}


//função 1, inserir um numero na primeira posição
int inserir_inicio(struct lista *l, int numero) {
//movimentação de todos os valores para a direita
//repetição do fim para o início
    int i;
    if(l-> particao < MAX) {
        for(i = l ->particao; i > 0; i--) {
        l-> elementos[i] = l-> elementos[i-1];
        }
        l-> elementos[0] = numero;
        l-> particao++;
        return 1;
    } else {
        return 0;
    }
}
//função 2, recebe um número e o ponteiro para lista e adiciona o numero ao fim.
int inserir_fim(struct lista *l, int numero) {
    if(l-> particao < MAX) {
        l-> elementos[l-> particao] = numero;
        l-> particao++;
        return 1;
    } else {
        return 0;
    }
}

// função 3, inserindo um numero na posicao que deseja
//deslocando a lista ate chegar no numero da posicao
int inserir_posicao(struct lista *l, int numero, int posicao){
int i;
    if(l-> particao < MAX) {
        for(i = l -> particao; i > posicao; i--) {
        l-> elementos[i] = l-> elementos[i-1];
        }
        l-> elementos[posicao] = numero;
        l-> particao++;
        return 1;
    } else {
        return 0;
    }
}

//função 4, inserir um número em uma lista sequencial ordenada, encontra a posição correta e depois desloca os elementos.
void inserir_ordem(struct lista *l, int numero) {
    int posicao = 0;
    // Encontrar a posição correta para inserção
    while (posicao < l-> particao && l-> elementos[posicao] < numero) {
        posicao++;
    }
    for (int i = l-> particao; i > posicao; i--) {
        l-> elementos[i] = l-> elementos[i - 1];
    }
    l-> elementos[posicao] = numero;
    l-> particao++;
    printf("Lista apos insercao: ");
    for (int i = 0; i < l-> particao; i++) {
        printf("[%d]", l-> elementos[i]);
    }
}

//função 5, print da lista
void exibir_lista(struct lista *l){
    int i;
    for(i= 0; i < l-> particao; i++) {
        printf("[%d]", l-> elementos[i]);
    }
    printf("\n");
}
//função 6, trocando a ordem da lista
void reverter(struct lista *l) {
    int comeco = 0;
    int fim = l-> particao - 1;
    int i;
    int temp;

    while (comeco < fim) {
        temp = l-> elementos[comeco];
        l-> elementos[comeco] = l-> elementos[fim];
        l-> elementos[fim] = temp;
        comeco++;
        fim--;
    }
    printf("\nLista revertida: ");
    for (i = 0; i < l-> particao; i++) {
        printf("[%d]", l-> elementos[i]);
    }
}

//funcao 7, para isso arrastarei todos os numeros para a posição anterior do indice
//inicio o loop conferindo se a lista tem numeros em seguida desloco para a esquerda
int remover_inicio (struct lista *l){
 int i;
 if (l-> particao != 0) {
        for (i = 0; i < l-> particao - 1; i++) {
            l-> elementos[i] = l-> elementos[i+1];
        }
        l-> particao--;
        return 1;
    } else {
        return 0;
    }
}

//funcao 8, removendo o fim da lista
//nessa para remover o ultimo numero eu coloco a partição na penúltima posição
int remover_fim (struct lista *l){
 int i;
     if(l-> particao > 0) {
        l-> particao--;
        return 1;
    } else {
        return 0;
    }
 }

//função 9, removendo um número na posição desejada
//para isso,
int remover_posicao(struct lista *l, int posicao){
    int i;
        if (posicao <= l-> particao) {
            for (i = posicao; i < l-> particao; i++) {
                l-> elementos[i] = l-> elementos[i+1];
       }
    l-> particao--;
    return 1;
    } else {
    return 0;
    }
}

//função 10, encontra a posição do número na lista e depois desloca para a esquerda
void remover(struct lista *l, int numero) {
    int i, j;

    for (i = 0; i < l-> particao; i++) {
        if (l->elementos[i] == numero) {
            for (j = i; j < l->particao - 1; j++) {
                l-> elementos[j] = l-> elementos[j + 1];
            }
            l-> particao--;

            printf("\nLista apos remocao: ");
            for (j = 0; j < l-> particao; j++) {
                printf("[%d]", l-> elementos[j]);
            }
            printf("\n");
            return;
        }
    }
     printf("Numero nao encontrado na lista.\n");
}

//função 11, procurando um elemento e retornando a posição do primeiro encontrado com o valor solicitado
int procurar(struct lista *l, int numero) {
    int i;
    for (i = 0; i < l->particao; i++) {
        if (l->elementos[i] == numero) {
            numero = l->elementos[i];
            printf("A posicao eh %d ", i);
            return 1;
        }
    }
    printf("NUMERO NAO ENCONTRADO");
    return 0;
}

//função 12, somando os elementos da lista
//recebe a lista e arrasta a partição para direita enquanto adiciona o valor que esta armazenado em determinado indice da lista a somatorio
int somatorio(struct lista *l) {
    int i;
    int somatorio = 0;

    for (i = 0; i < l-> particao; i++) {
        somatorio = somatorio + l-> elementos[i];
    }

    return somatorio;
}

//funcão 13, para isso só retornei a posição da partição
int quantidadeElementos(struct lista *l){
    return l-> particao;
}

//função 14, mesma base do anterior só que pega o valor do elemento e add ao quadrado
void aoQuadrado(struct lista *l) {
    int i;
    printf("\nEssa eh a lista com todos os elementos elevados ao quadrado: ");
    for (i = 0; i < l-> particao; i++) {
        l-> elementos[i] = l-> elementos[i] * l-> elementos[i];
        printf("[%d]", l-> elementos[i]);
    }
}
//função 15
int qtdPrimo(struct lista *l) {
int qtd = 0;

    for (int i = 0; i < l-> particao; i++) {
        int num = l-> elementos[i];
        int primo = 1;

        if (num <= 1) {
            primo = 0;
        } else {
            for (int k = 2; k * k <= num; k++) {
                if (num % k == 0) {
                    primo = 0;
                    break; }
}
} if (primo == 1) {
        qtd++;
        }
} return qtd;
}




