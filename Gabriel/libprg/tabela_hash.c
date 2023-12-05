#include "tabela_hash.h"
#include "lista_encadeada.h"

//Função de hash para mapear a chave para um índice na tabela hash
int hash(const char *chave, int m) {
    int soma = 0;
    for (int i = 0; chave[i] != '\0'; i++) {
        soma += (i + 1) * chave[i];
    }
    return soma % m;
}

//Função para criar um novo dicionário tabela hash com um tamanho específico
dicionario_t *criar_dicionario(int m) {
    dicionario_t *d = NULL;
    if (m < 1) {
        return NULL;
    }
    if ((d = (dicionario_t *)malloc(sizeof(dicionario_t))) == NULL) {
        return NULL;
    }
    d->tamanho = m;
    if ((d->vetor = calloc(m, sizeof(no_t *))) == NULL) {
        return NULL;
    }

    FILE *Arq = fopen("../database.dat", "rb");
    if (Arq == NULL) {
        printf("Erro ao abrir arquivo!\n");
        destruir_dicionario(d);
        return NULL;
    }

    pessoa_t usuario;

    //Lê cada registro do arquivo e insere na tabela hash
    while (fread(&usuario, sizeof(pessoa_t), 1, Arq) == 1) {
        pessoa_t *p = malloc(sizeof(pessoa_t));
        strcpy(p->login, usuario.login);
        strcpy(p->senha, usuario.senha);
        strcpy(p->nome, usuario.nome);

        inserir_pessoa(d, p->login, p);
    }

    fclose(Arq);

    return d;
}

bool inserir_pessoa(dicionario_t *d, char *chave, pessoa_t *valor) {
    int indice = hash(chave, d->tamanho);

    if (d->vetor[indice] == NULL) {
        no_t *no = malloc(sizeof(no_t));
        if (no == NULL) {
            return false;
        }

        strcpy(no->chave, chave);
        memcpy(&no->valor, valor, sizeof(pessoa_t));
        no->prox = NULL;
        d->vetor[indice] = no;
    } else {
        no_t *no = malloc(sizeof(no_t));
        if (no == NULL) {
            return false;
        }

        strcpy(no->chave, chave);
        memcpy(&no->valor, valor, sizeof(pessoa_t));
        no->prox = d->vetor[indice];
        d->vetor[indice] = no;
    }

    return true;
}

pessoa_t *buscar(dicionario_t *d, char *chave) {
    int indice = hash(chave, d->tamanho);
    no_t *no = d->vetor[indice];

    while (no != NULL) {
        if (strcmp(no->chave, chave) == 0) {
            return &no->valor;
        }
        no = no->prox;
    }

    return NULL;
}