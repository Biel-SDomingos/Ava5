#include "tabela_hash.h"
#include "lista_encadeada.h"

int main(int argc, char **argv) {
    dicionario_t *dicionario = criar_dicionario(5);

    if (dicionario == NULL) {
        printf("Não foi possível reservar memória\n");
        exit(EXIT_FAILURE);
    }

    char login[10];
    char senha[10];

    pessoa_t *usuario = NULL;

    // Exemplo de credenciais pré-definidas para teste
    const char *loginPreDefinido = NULL;
    const char *senhaPreDefinida = NULL;

    if (argc == 3) {
        // Se foram fornecidos argumentos de linha de comando
        strcpy(login, argv[1]);
        strcpy(senha, argv[2]);

        usuario = buscar(dicionario, login);
    } else {
        // Se não foram fornecidos argumentos
        if (loginPreDefinido != NULL && senhaPreDefinida != NULL) {
            // Utiliza as credenciais pré-definidas
            strcpy(login, loginPreDefinido);
            strcpy(senha, senhaPreDefinida);
        } else {
            // Solicita ao usuário que insira o login e senha
            printf("Digite o login: ");
            scanf("%s", login);

            printf("Digite a senha: ");
            scanf("%s", senha);
        }

        usuario = buscar(dicionario, login);
    }

    if (usuario != NULL && strcmp(usuario->senha, senha) == 0) {
        printf("Saudacoes, %s!\n", usuario->nome);
    } else {
        printf("Credenciais invalidas!\n");
    }

    // Realiza a busca utilizando lista encadeada ordenada
    buscar_lista_encadeada(dicionario, login);

    // Realiza a busca utilizando tabela hash
    buscar_tabela_hash(dicionario, login);

    destruir_dicionario(dicionario);
    return 0;
}