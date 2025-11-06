#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

// Código da Ilha – Edição Free Fire
// Nível: Novato
// Este programa simula o gerenciamento avançado de uma mochila com componentes coletados durante a fuga de uma ilha.
// Ele introduz ordenação com critérios e busca binária para otimizar a gestão dos recursos.

#define MAX_ITENS 10 // Tamanho máximo de itens na mochila
#define MAX_CHAR_NOME 30
#define MAX_CHAR_TIPO 20
typedef struct {
    char nome[MAX_CHAR_NOME];
    char tipo[MAX_CHAR_TIPO];
    int quantidade;
} Item;

void inserirItem(Item mochila[], int *totalItens);
void removerItem(Item mochila[], int *totalItens);
void listarItens(Item mochila[], int *totalItens);
void listarNomes(Item mochila[], int *totalItens);

int main() {
    Item mochila[MAX_ITENS];
    int totalItens = 0;
    int opcao = -1;

    // Menu principal com opções:
    printf("=========================================\n");
    printf("          Iniciando o jogo!\n");
    printf("=========================================\n");

    while (opcao != 0)
    {
        printf("\n=== ITENS DA MOCHILA %d:/10 ===\n", totalItens);
        printf("1. Adicionar um item\n");
        printf("2. Remover um item\n");
        printf("3. Listar todos os itens\n");
        printf("0. Sair\n");
        printf("Opção: ");
        scanf("%d", &opcao);

        getchar();

        switch (opcao){
            case 1:
                // 1. Adicionar um item
                inserirItem(mochila, &totalItens);
                break;
            case 2:
                // 2. Remover um item
                listarNomes(mochila, &totalItens);
                removerItem(mochila, &totalItens);
                break;
            case 3:
                // 3. Listar todos os itens
                listarItens(mochila, &totalItens);
                break;

            
                // 4. Ordenar os itens por critério (nome, tipo, prioridade)
                // 5. Realizar busca binária por nome
            case 0:
                break;
                // 0. Sair
            default:
                printf("Essa opção é inválida, por favor escolha um opção válida");

                // A estrutura switch trata cada opção chamando a função correspondente.
                // A ordenação e busca binária exigem que os dados estejam bem organizados.
        }
    };
    return 0;
}

// Struct Item:
// Representa um componente com nome, tipo, quantidade e prioridade (1 a 5).
// A prioridade indica a importância do item na montagem do plano de fuga.

// Enum CriterioOrdenacao:
// Define os critérios possíveis para a ordenação dos itens (nome, tipo ou prioridade).

// Vetor mochila:
// Armazena até 10 itens coletados.
// Variáveis de controle: numItens (quantidade atual), comparacoes (análise de desempenho), ordenadaPorNome (para controle da busca binária).

// limparTela():
// Simula a limpeza da tela imprimindo várias linhas em branco.

// exibirMenu():
// Apresenta o menu principal ao jogador, com destaque para status da ordenação.

// inserirItem():
// Adiciona um novo componente à mochila se houver espaço.
// Solicita nome, tipo, quantidade e prioridade.
// Após inserir, marca a mochila como "não ordenada por nome".
void inserirItem(Item mochila[], int *totalItens){
    if (*totalItens != MAX_ITENS){
        printf("\n --- INSERINDO ITEM NA MOCHILA --- \n");

        printf("Nome: ");
        scanf("%s", mochila[*totalItens].nome);

        printf("Tipo: ");
        scanf("%s", mochila[*totalItens].tipo);

        printf("Quantidade: ");
        scanf("%d", &mochila[*totalItens].quantidade);

        getchar();

        (*totalItens)++;
        printf("Item inserido com sucesso!\n");
    }
    else
    {
        printf("Mochila cheia, remova um item e adicione novamente.\n");
    }
}

// removerItem():
// Permite remover um componente da mochila pelo nome.
// Se encontrado, reorganiza o vetor para preencher a lacuna.
void removerItem(Item mochila[], int *totalItens){
    char nome[MAX_CHAR_NOME];
    int i, pos = -1;

    printf("\n--- ESCOLHA UM ITEM PARA REMOVER ---\n");
    printf("Nome: ");
    scanf("%s", nome);

    for (i = 0; i < *totalItens; i++){
        if (strcmp(mochila[i].nome, nome) == 0){
            pos = i;
            break;
        }
    }

    if (pos == -1) {
        printf("Item não encontrado.\n");
        return;
    }

    for (i = pos; i < *totalItens - 1; i++){
        strcpy(mochila[i].nome, mochila[i + 1].nome);
    }
    (*totalItens)--;
    printf("Item \"%s\" removido com sucesso.\n", nome);
}

// listarItens():
// Exibe uma tabela formatada com todos os componentes presentes na mochila.
void listarItens(Item mochila[], int *totalItens){
    if (*totalItens != 0){
        printf("\n  -----  ITENS NA MOCHILA  -----\n");
        printf("___________________________________\n");
        printf("|   NOME   |   TIPO   | QUANTIDADE |\n");
        for (int i = 0; i < *totalItens; i++) {
            printf("| \"%s\" | \"%s\" | \"%d\" |\n", mochila[i].nome, mochila[i].tipo, mochila[i].quantidade);
        }
        printf("___________________________________\n");
    }
}

// menuDeOrdenacao():
// Permite ao jogador escolher como deseja ordenar os itens.
// Utiliza a função insertionSort() com o critério selecionado.
// Exibe a quantidade de comparações feitas (análise de desempenho).

// insertionSort():
// Implementação do algoritmo de ordenação por inserção.
// Funciona com diferentes critérios de ordenação:
// - Por nome (ordem alfabética)
// - Por tipo (ordem alfabética)
// - Por prioridade (da mais alta para a mais baixa)

// buscaBinariaPorNome():
// Realiza busca binária por nome, desde que a mochila esteja ordenada por nome.
// Se encontrar, exibe os dados do item buscado.
// Caso contrário, informa que não encontrou o item.

// Função auxiliar para ajudar na remoção de um item
void listarNomes(Item mochila[], int *totalItens){
    if (*totalItens != 0){
        printf("\n  -----  ITENS NA MOCHILA  -----\n");
        printf("[ ");
        for (int i = 0; i < *totalItens; i++) {
            printf("\"%s\" ", mochila[i].nome);
        }
        printf(" ]");
    }
}