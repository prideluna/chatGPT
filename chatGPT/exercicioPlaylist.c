#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct musica {
    int id;
    char titulo[200];
    int id_artista;
    int duracao; //segundos
} musica;

typedef struct artista {
    int id;
    char nome[200];
    char genero[200];
} artista;

typedef struct musica_no {
    musica *musica;
    struct musica_no *prox;
} musica_no;

typedef struct artista_no {
    artista *artista;
    struct artista_no *prox;
} artista_no;

// Função para cadastrar um novo artista e adicioná-lo à lista encadeada
void cadastrar_artista(artista_no **lista_artista) {
    artista *novo_artista = (artista*) malloc(sizeof(artista)); // alocar memória para um novo artista
    printf("Digite o id do artista: ");
    scanf("%d", &novo_artista->id);
    printf("Digite o nome do artista: ");
    scanf(" %[^\n]", novo_artista->nome);
    printf("Digite o genero do artista: ");
    scanf(" %[^\n]", novo_artista->genero);

    artista_no *novo_no = (artista_no*) malloc(sizeof(artista_no)); // alocar memória para um novo nó
    novo_no->artista = novo_artista;
    novo_no->prox = NULL;

    if (*lista_artista == NULL) { // se a lista estiver vazia, o novo nó será o primeiro
        *lista_artista = novo_no;
    } else { // caso contrário, adicionar o novo nó no final da lista
        artista_no *ultimo = *lista_artista;
        while (ultimo->prox != NULL) {
            ultimo = ultimo->prox;
        }
        ultimo->prox = novo_no;
    }
}

// Função para cadastrar uma nova música e adicioná-la à lista encadeada
void cadastrar_musica(musica_no **lista_musica, artista_no *lista_artista) {
    musica *nova_musica = (musica*) malloc(sizeof(musica)); // alocar memória para uma nova música
    printf("Digite o id da musica: ");
    scanf("%d", &nova_musica->id);
    printf("Digite o titulo da musica: ");
    scanf(" %[^\n]", nova_musica->titulo);
    printf("Digite a duracao da musica em segundos: ");
    scanf("%d", &nova_musica->duracao);
    printf("Digite o id do artista da musica: ");
    scanf("%d", &nova_musica->id_artista);

    artista_no *artista_atual = lista_artista;
    while (artista_atual != NULL && artista_atual->artista->id != nova_musica->id_artista) {
        artista_atual = artista_atual->prox;
    }

    if (artista_atual == NULL) { // o artista não foi encontrado
        printf("Artista nao encontrado.\n");
        free(nova_musica); // liberar memória alocada para a nova música
        return;
    }

    musica_no *novo_no = (musica_no*) malloc(sizeof(musica_no)); // alocar memória para um novo nó
    novo_no->musica = nova_musica;



typedef struct musica {
    int id;
    char titulo[200];
    int id_artista;
    int duracao; //segundos
} musica;

typedef struct artista {
    int id;
    char nome[200];
    char genero[200];
} artista;

typedef struct musica_no {
    musica *musica;
    struct musica_no *prox;
} musica_no;

typedef struct artista_no {
    artista *artista;
    struct artista_no *prox;
} artista_no;

// Função para imprimir todas as músicas com seus dados, incluindo o nome do artista e a duração no formato HH:MM:SS
void imprimir_musicas(musica_no *lista_musica, artista_no *lista_artista) {
    printf("ID\tTitulo\t\t\t\tArtista\t\t\tDuracao\n");
    printf("-----------------------------------------------------------------\n");

    musica_no *musica_atual = lista_musica;
    while (musica_atual != NULL) {
        artista_no *artista_atual = lista_artista;
        while (artista_atual != NULL && artista_atual->artista->id != musica_atual->musica->id_artista) {
            artista_atual = artista_atual->prox;
        }

        if (artista_atual != NULL) { // o artista foi encontrado
            printf("%d\t%-25s%-25s%02d:%02d:%02d\n", 
                musica_atual->musica->id, 
                musica_atual->musica->titulo, 
                artista_atual->artista->nome, 
                musica_atual->musica->duracao / 3600, 
                (musica_atual->musica->duracao % 3600) / 60, 
                musica_atual->musica->duracao % 60);
        } else { // o artista não foi encontrado
            printf("%d\t%-25sArtista nao encontrado\t%02d:%02d:%02d\n", 
                musica_atual->musica->id, 
                musica_atual->musica->titulo, 
                musica_atual->musica->duracao / 3600, 
                (musica_atual->musica->duracao % 3600) / 60, 
                musica_atual->musica->duracao % 60);
        }
        musica_atual = musica_atual->prox;
    }
 int main() {
    artista_no *lista_artistas = NULL;
    musica_no *lista_musicas = NULL;

    int opcao = 0;
    while (opcao != 4) {
        printf("\nEscolha uma opcao:\n");
        printf("1 - Cadastrar novo artista\n");
        printf("2 - Cadastrar nova musica\n");
        printf("3 - Imprimir todas as musicas\n");
        printf("4 - Sair\n");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                cadastrar_artista(&lista_artistas);
                break;
            case 2:
                cadastrar_musica(&lista_musicas, lista_artistas);
                break;
            case 3:
                imprimir_musicas(lista_musicas, lista_artistas);
                break;
            case 4:
                printf("Saindo...\n");
                break;
            default:
                printf("Opcao invalida.\n");
        }
    }

    return 0;
}
    
}
