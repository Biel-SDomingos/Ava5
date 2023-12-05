#include "lista_encadeada.h"

//Função para destruir o dicionário e liberar a memória alocada
void destruir_dicionario(dicionario_t *d) {
    if (d != NULL) {
        for (int i = 0; i < d->tamanho; ++i) {
            no_t *no = d->vetor[i];
            while (no != NULL) {
                no_t *temp = no->prox;
                free(no);
                no = temp;
            }
        }
        free(d->vetor);
        free(d);
    }
}

//Função para buscar uma pessoa na lista encadeada e medir o tempo de processamento
void buscar_lista_encadeada(dicionario_t *d, char *chave) {
    struct timespec start_time, end_time;
    clock_gettime(CLOCK_MONOTONIC, &start_time);

    pessoa_t *p = buscar(d, chave);

    clock_gettime(CLOCK_MONOTONIC, &end_time);

    if (p != NULL) {
        printf("Login: %s\tSenha: %s\tNome: %s\n", p->login, p->senha, p->nome);
    } else {
        printf("Pessoa com login %s não encontrada\n", chave);
    }

    double elapsed_time = (end_time.tv_sec - start_time.tv_sec) +
                          (end_time.tv_nsec - start_time.tv_nsec) / 1e9;
    printf("Tempo de processamento (Lista Encadeada): %f segundos\n", elapsed_time);
}

//Funçao para buscar uma pessoa na tabela hash e medir o tempo de processamneto
void buscar_tabela_hash(dicionario_t *d, char *chave) {
    struct timespec start_time, end_time;
    clock_gettime(CLOCK_MONOTONIC, &start_time);

    pessoa_t *p = buscar(d, chave);

    clock_gettime(CLOCK_MONOTONIC, &end_time);

    if (p != NULL) {
        printf("Login: %s\tSenha: %s\tNome: %s\n", p->login, p->senha, p->nome);
    } else {
        printf("Pessoa com login %s não encontrada\n", chave);
    }

    double elapsed_time = (end_time.tv_sec - start_time.tv_sec) +
                          (end_time.tv_nsec - start_time.tv_nsec) / 1e9;
    printf("Tempo de processamento (Tabela Hash): %f segundos\n", elapsed_time);
}