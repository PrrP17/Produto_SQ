//
// Created by morpheus on 04/10/2021.
//

#ifndef PRODUTO_SQ_LISTASEQUENCIAL_H
#define PRODUTO_SQ_LISTASEQUENCIAL_H
#include <stdio.h>
#include <stdlib.h>

#define MAX 50

struct produto{
    int codido;
    char nome[30];
    float preco;
    int qtd;
};

typedef struct lista Lista;

Lista* criar_lista();
void liberar_lista(Lista* li);
int buscar_lista_pos(Lista* li, int cod, struct produto *pd);
int inserir_lista_final(Lista* li, struct produto pd);
int inserir_lista_inicio(Lista* li, struct produto pd);
int inserir_lista_ordenada(Lista* li, struct produto pd);
int remover_lista_inicio(Lista* li);
int remover_lista_final(Lista* li);
int remover_lista(Lista* li, int cod);
int tamanho_lista(Lista* li);
int lista_cheia(Lista *li);
int lista_vazia(Lista *li);
void imprimir_lista(Lista *li);
#endif //PRODUTO_SQ_LISTASEQUENCIAL_H
