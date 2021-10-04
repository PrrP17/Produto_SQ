//
// Created by morpheus on 04/10/2021.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ListaSequencial.h"

struct lista{
    int qtd;
    struct produto dados[MAX];
};

Lista* criar_lista(){
    Lista* li;
    li =  (Lista *) malloc(sizeof(struct lista));
    if (li != NULL)
        li->qtd = 0;
    return  li;
}

void liberar_lista(Lista* li){
    free(li);
}

int tamanho_lista(Lista *li){
    if (li == NULL)
        return -1;
    else
        return li->qtd;
}

int lista_vazia(Lista *li){
    if(li == NULL)
        return -1;
    else
        return (li->qtd == 0);
}

int lista_cheia(Lista *li){
    if(li == NULL)
        return -1;
    else
        return (li->qtd == MAX);
}

int inserir_lista_inicio(Lista *li, struct produto pd){
    if (li == NULL)
        return 0;
    if(li->qtd == MAX)
        return 0;
    int i;
    for(i=li->qtd-1; i>=0; i--)
        li->dados[i+1] = li->dados[i];
    li->dados[0] = pd;
    li->qtd++;
    return 1;
}

int inserir_lista_final(Lista* li, struct produto pd){
    if(li == NULL)
        return 0;
    if(li->qtd == MAX)
        return 0;
    li->dados[li->qtd] = pd;
    li->qtd++;
    return 1;
}

int inserir_lista_ordenada(Lista* li, struct produto pd){
    if(li == NULL)
        return 0;
    if(li->qtd == MAX)
        return 0;
    int i,k = 0;
    while(i < li->qtd && li->dados[i].codido < pd.codido)
        i++;
    for(k=li->qtd-1; k>=1; k--)
        li->dados[k+1] = li->dados[k];
    li->dados[i] = pd;
    li->qtd++;
    return 1;
}

int remover_lista_final(Lista* li){
    if(li == NULL)
        return -1;
    if(li->qtd == 0)
        return -1;
    li->qtd--;
    return 1;
}

int remover_lista_inicio(Lista* li){
    if(li == NULL)
        return -1;
    if(li->qtd == 0)
        return -1;
    int k;
    for(k = 0; k < li->qtd-1; k++)
        li->dados[k] = li->dados[k+1];
    li->qtd--;
    return 1;
}

int remover_lista(Lista* li, int cod){
    if(li == NULL)
        return -1;
    if(li->qtd == 0)
        return -1;
    int k, i = 0;
    while(i < li->qtd && li->dados[i].codido != cod)
        i++;
    if(i == li->qtd)
        return 0;
    for(k = i; k < li->qtd-1; k++)
        li->dados[k] = li->dados[k+1];
    li->qtd--;
    return 1;
}

void imprimir_lista(Lista *li){
    int i;
    printf("-------------\n");
    for(i=0;i < li->qtd; i++){
        printf("Matricula: %d\n", li->dados[i].codido);
        printf("Nome: %s\n",li->dados[i].nome);
        printf("Quantidade: %d\n", li->dados[i].qtd);
        printf("Preco: %.2f\n", li->dados[i].preco);
    }
    printf("\n-------------");
}




