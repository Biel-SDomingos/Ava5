#ifndef TABELA_HASH_H
#define TABELA_HASH_H

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

//Definição da estrutura de uma pessoa
typedef struct {
    char login[10];
    char senha[10];
    char nome[30];
} pessoa_t;

//Definição da estrutura de um nó na lista encadeada
typedef struct no {
    char chave[10];
    pessoa_t valor;
    struct no *prox;
} no_t;

//Definição da estrutura do dicionário tabela hash
typedef struct dicionario {
    int tamanho;
    no_t **vetor;
} dicionario_t;

int hash(const char *chave, int m);
dicionario_t *criar_dicionario(int m);
bool inserir_pessoa(dicionario_t *d, char *chave, pessoa_t *valor);
pessoa_t *buscar(dicionario_t *d, char *chave);

#endif /* TABELA_HASH_H */