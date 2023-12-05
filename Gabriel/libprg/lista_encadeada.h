#ifndef LISTA_ENCADEADA_H
#define LISTA_ENCADEADA_H

#include "tabela_hash.h"

void destruir_dicionario(dicionario_t *d);
void buscar_lista_encadeada(dicionario_t *d, char *chave);
void buscar_tabela_hash(dicionario_t *d, char *chave);

#endif /* LISTA_ENCADEADA_H */