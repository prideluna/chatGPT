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
    
    
    -------------------------------------------------------------------
        
        
        
        #include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct musica {
    int id;
    char titulo[200];
    int id_artista;
    int duracao; // segundos
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

void insere_artista(artista_no **head, artista *novo_artista) {
    artista_no *novo_no = (artista_no *)malloc(sizeof(artista_no));
    novo_no->artista = novo_artista;
    novo_no->prox = *head;
    *head = novo_no;
}

void insere_musica(musica_no **head, musica *nova_musica) {
    musica_no *novo_no = (musica_no *)malloc(sizeof(musica_no));
    novo_no->musica = nova_musica;
    novo_no->prox = *head;
    *head = novo_no;
}

char *busca_nome_artista(artista_no *head, int id_artista) {
    while (head != NULL) {
        if (head->artista->id == id_artista) {
            return head->artista->nome;
        }
        head = head->prox;
    }
    return NULL;
}

void imprime_musicas(musica_no *head, artista_no *artistas) {
    while (head != NULL) {
        int h, m, s;
        s = head->musica->duracao;
        h = s / 3600;
        s %= 3600;
        m = s / 60;
        s %= 60;

        printf("ID: %d\n", head->musica->id);
        printf("Titulo: %s\n", head->musica->titulo);
        printf("Artista: %s\n", busca_nome_artista(artistas, head->musica->id_artista));
        printf("Duracao: %02d:%02d:%02d\n\n", h, m, s);

        head = head->prox;
    }
}

int main() {
    artista_no *artistas = NULL;
    musica_no *musicas = NULL;

    // Adicione aqui a lógica para criar e cadastrar novos artistas e músicas usando as funções insere_artista e insere_musica.
    // Exemplo:
    // artista *novo_artista = (artista *)malloc(sizeof(artista));
    // novo_artista->id = 1;
    // strcpy(novo_artista->nome, "Nome do Artista");
    // strcpy(novo_artista->genero, "Gênero Musical");
    // insere_artista(&artistas, novo_artista);

    // musica *nova_musica = (musica *)malloc(sizeof(musica));
    // nova_musica->id = 1;
    // strcpy(nova_musica->titulo, "Título da Música");
    // nova_musica->id_artista = 1;
    // nova_musica->duracao = 200;
    // insere_musica(&musicas, nova_musica);

    // Imprime todas as músicas com todos os dados, inclu
    
    
    
    
    
    ------------------------------------------------------------------------------------------------------
        #include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct musica {
    int id;
    char titulo[200];
    int id_artista;
    int duracao; // segundos
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

void insere_artista(artista_no **head) {
    artista *novo_artista = (artista *)malloc(sizeof(artista));

    printf("Digite o ID do artista: ");
    scanf("%d", &novo_artista->id);
    printf("Digite o nome do artista: ");
    scanf(" %[^\n]s", novo_artista->nome);
    printf("Digite o genero musical do artista: ");
    scanf(" %[^\n]s", novo_artista->genero);

    artista_no *novo_no = (artista_no *)malloc(sizeof(artista_no));
    novo_no->artista = novo_artista;
    novo_no->prox = *head;
    *head = novo_no;
}

void insere_musica(musica_no **head, artista_no *artistas) {
    musica *nova_musica = (musica *)malloc(sizeof(musica));

    printf("Digite o ID da musica: ");
    scanf("%d", &nova_musica->id);
    printf("Digite o titulo da musica: ");
    scanf(" %[^\n]s", nova_musica->titulo);
    printf("Digite o ID do artista: ");
    scanf("%d", &nova_musica->id_artista);
    printf("Digite a duracao da musica em segundos: ");
    scanf("%d", &nova_musica->duracao);

    musica_no *novo_no = (musica_no *)malloc(sizeof(musica_no));
    novo_no->musica = nova_musica;
    novo_no->prox = *head;
    *head = novo_no;
}

char *busca_nome_artista(artista_no *head, int id_artista) {
    while (head != NULL) {
        if (head->artista->id == id_artista) {
            return head->artista->nome;
        }
        head = head->prox;
    }
    return NULL;
}

void imprime_musicas(musica_no *head, artista_no *artistas) {
    while (head != NULL) {
        int h, m, s;
        s = head->musica->duracao;
        h = s / 3600;
        s %= 3600;
        m = s / 60;
        s %= 60;

        printf("ID: %d\n", head->musica->id);
        printf("Titulo: %s\n", head->musica->titulo);
        printf("Artista: %s\n", busca_nome_artista(artistas, head->musica->id_artista));
        printf("Duracao: %02d:%02d:%02d\n\n", h, m, s);

        head = head->prox;
    }
}

int main() {
    artista_no *artistas = NULL;
    musica_no *musicas = NULL

            int opcao = 0;
    while (opcao != 3) {
        printf("Escolha uma opcao:\n");
        printf("1. Cadastrar novo artista\n");
        printf("2. Cadastrar nova musica\n");
        printf("3. Sair\n");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                insere_artista(&artistas);
                break;
            case 2:
                insere_musica(&musicas, artistas);
                break;
            case 3:
                break;
            default:
                printf("Opcao invalida. Tente novamente.\n");
                break;
        }
    }

    // Imprime todas as músicas com todos os dados, incluindo o nome do artista e a duração no formato HH:MM:SS.
    imprime_musicas(musicas, artistas);

    // Libera a memória alocada para a lista de artistas e músicas.
    artista_no *artista_atual;
    while (artistas != NULL) {
        artista_atual = artistas;
        artistas = artistas->prox;
        free(artista_atual->artista);
        free(artista_atual);
    }

    musica_no *musica_atual;
    while (musicas != NULL) {
        musica_atual = musicas;
        musicas = musicas->prox;
        free(musica_atual->musica);
        free(musica_atual);
    }

    return 0;
}


    
    
    
    
    
    -------------------------------------------------------------------------------
        
        void imprime_artistas(artista_no *head) {
    printf("Lista de artistas:\n\n");
    while (head != NULL) {
        printf("ID: %d\n", head->artista->id);
        printf("Nome: %s\n", head->artista->nome);
        printf("Genero: %s\n\n", head->artista->genero);
        head = head->prox;
    }
}

void imprime_musicas_por_artista(musica_no *head, artista_no *artistas, int id_artista) {
    printf("Musicas do artista com ID %d:\n\n", id_artista);
    while (head != NULL) {
        if (head->musica->id_artista == id_artista) {
            int h, m, s;
            s = head->musica->duracao;
            h = s / 3600;
            s %= 3600;
            m = s / 60;
            s %= 60;

            printf("ID: %d\n", head->musica->id);
            printf("Titulo: %s\n", head->musica->titulo);
            printf("Duracao: %02d:%02d:%02d\n\n", h, m, s);
        }
        head = head->prox;
    }
}
------------------------------------------------------------------------
    
    typedef struct playlist_no {
    int id;
    musica *musica;
    struct playlist_no *prox;
} playlist_no;

typedef struct lplaylists_no {
    int id;
    char nome[200];
    playlist_no *musicas;
    struct lplaylists_no *prox;
} lplaylists_no;

void cria_playlist(lplaylists_no **head, musica_no *musicas) {
    int id_musica;
    char entrada[1000];

    printf("Digite os IDs das musicas separados por espaco:\n");
    scanf(" %[^\n]s", entrada);

    lplaylists_no *nova_lplaylist = (lplaylists_no *)malloc(sizeof(lplaylists_no));
    nova_lplaylist->id = 1; // ou defina um novo ID de acordo com sua necessidade
    printf("Digite um nome para a playlist:\n");
    scanf(" %[^\n]s", nova_lplaylist->nome);

    playlist_no *nova_playlist = NULL;
    playlist_no *playlist_atual = NULL;
    char *ptr = strtok(entrada, " ");
    while (ptr != NULL) {
        id_musica = atoi(ptr);
        musica_no *musica_atual = musicas;
        while (musica_atual != NULL) {
            if (musica_atual->musica->id == id_musica) {
                playlist_no *nova_musica = (playlist_no *)malloc(sizeof(playlist_no));
                nova_musica->id = id_musica;
                nova_musica->musica = musica_atual->musica;

                if (nova_playlist == NULL) {
                    nova_playlist = nova_musica;
                    nova_musica->prox = nova_musica;
                } else {
                    playlist_atual = nova_playlist;
                    while (playlist_atual->prox != nova_playlist) {
                        playlist_atual = playlist_atual->prox;
                    }
                    playlist_atual->prox = nova_musica;
                    nova_musica->prox = nova_playlist;
                }
                break;
            }
            musica_atual = musica_atual->prox;
        }
        ptr = strtok(NULL, " ");
    }

    nova_lplaylist->musicas = nova_playlist;
    nova_lplaylist->prox = *head;
    *head = nova_lplaylist;

    printf("Playlist criada com sucesso!\n");
}

    
    -------------------------------------------------------------------------------------------------
        void shuffle(playlist_no *head) {
    // contar o número de músicas na playlist
    int num_musicas = 0;
    playlist_no *playlist_atual = head;
    while (playlist_atual != NULL) {
        num_musicas++;
        playlist_atual = playlist_atual->prox;
    }

    // criar um array de índices das músicas na playlist
    int *indices = (int *)malloc(num_musicas * sizeof(int));
    playlist_atual = head;
    for (int i = 0; i < num_musicas; i++) {
        indices[i] = i;
        playlist_atual = playlist_atual->prox;
    }

    // embaralhar os índices aleatoriamente
    for (int i = 0; i < num_musicas; i++) {
        int j = rand() % num_musicas;
        int temp = indices[i];
        indices[i] = indices[j];
        indices[j] = temp;
    }

    // percorrer a lista encadeada de playlists, reordenando as músicas de acordo com os índices embaralhados
    playlist_no **playlist_array = (playlist_no **)malloc(num_musicas * sizeof(playlist_no *));
    playlist_atual = head;
    for (int i = 0; i < num_musicas; i++) {
        playlist_array[i] = playlist_atual;
        playlist_atual = playlist_atual->prox;
    }

    for (int i = 0; i < num_musicas; i++) {
        playlist_array[i]->musica = playlist_array[indices[i]]->musica;
    }

    // liberar a memória alocada
    free(indices);
    free(playlist_array);
}
    
    void imprime_playlist(playlist_no *head, artista_no *artistas) {
    playlist_no *playlist_atual = head;
    while (playlist_atual != NULL) {
        printf("ID: %d\n", playlist_atual->musica->id);
        printf("Titulo: %s\n", playlist_atual->musica->titulo);
        printf("Artista: %s\n", encontra_artista_por_id(artistas, playlist_atual->musica->id_artista)->artista->nome);
        printf("Duracao: %02d:%02d:%02d\n", playlist_atual->musica->duracao / 3600, (playlist_atual->musica->duracao / 60) % 60, playlist_atual->musica->duracao % 60);
        printf("\n");
        playlist_atual = playlist_atual->prox;
    }
}
    
    
    ---------------------------------------------------------------------------------------------------------------------
        void remove_musica(musica_no **head, playlist_no **playlists, int id_musica) {
    // remover a música da lista encadeada de músicas
    musica_no *musica_atual = *head;
    musica_no *musica_anterior = NULL;
    while (musica_atual != NULL) {
        if (musica_atual->musica->id == id_musica) {
            if (musica_anterior != NULL) {
                musica_anterior->prox = musica_atual->prox;
            } else {
                *head = musica_atual->prox;
            }
            free(musica_atual->musica);
            free(musica_atual);
            break;
        }
        musica_anterior = musica_atual;
        musica_atual = musica_atual->prox;
    }

    // remover a música de todas as playlists em que ela participa
    for (int i = 0; i < MAX_PLAYLISTS; i++) {
        playlist_no *playlist_atual = playlists[i];
        playlist_no *playlist_anterior = NULL;
        while (playlist_atual != NULL) {
            if (playlist_atual->musica->id == id_musica) {
                if (playlist_anterior != NULL) {
                    playlist_anterior->prox = playlist_atual->prox;
                } else {
                    playlists[i] = playlist_atual->prox;
                }
                free(playlist_atual);
                break;
            }
            playlist_anterior = playlist_atual;
            playlist_atual = playlist_atual->prox;
        }
    }
}
---------------------------------------------------------------------------------------------------------------------
    
    
    void remove_artista(artista_no **head_artista, musica_no **head_musica, playlist_no **playlists, int id_artista) {
    // remover todas as músicas do artista da lista encadeada de músicas e de todas as playlists em que participam
    musica_no *musica_atual = *head_musica;
    musica_no *musica_anterior = NULL;
    while (musica_atual != NULL) {
        if (musica_atual->musica->id_artista == id_artista) {
            remove_musica(head_musica, playlists, musica_atual->musica->id);
            musica_atual = (musica_anterior != NULL) ? musica_anterior->prox : *head_musica;
        } else {
            musica_anterior = musica_atual;
            musica_atual = musica_atual->prox;
        }
    }

    // remover o artista da lista encadeada de artistas
    artista_no *artista_atual = *head_artista;
    artista_no *artista_anterior = NULL;
    while (artista_atual != NULL) {
        if (artista_atual->artista->id == id_artista) {
            if (artista_anterior != NULL) {
                artista_anterior->prox = artista_atual->prox;
            } else {
                *head_artista = artista_atual->prox;
            }
            free(artista_atual->artista);
            free(artista_atual);
            break;
        }
        artista_anterior = artista_atual;
        artista_atual = artista_atual->prox;
    }
}

    
    -----------------------------------------------------------------------------------------------
        artista_no *encontra_artista_por_id(artista_no *head, int id) {
    artista_no *artista_atual = head;
    while (artista_atual != NULL) {
        if (artista_atual->artista->id == id) {
            return artista_atual;
        }
        artista_atual = artista_atual->prox;
    }
    return NULL;
}



    
    
    ----------------------------------------------------------------------------------------------
        #include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PLAYLISTS 20

typedef struct musica {
    int id;
    char titulo[200];
    int id_artista;
    int duracao; // segundos
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

typedef struct playlist_no {
    int id;
    musica *musica;
    struct playlist_no *prox;
} playlist_no;

typedef struct lplaylists_no { 
    int id;
    char nome[200];
    playlist_no *playlist;
    struct lplaylists_no *prox;
} lplaylists_no;

// ... restante do código

void cria_playlist(lplaylists_no **head, musica_no *musicas) {
    // ... código omitido

    nova_lplaylist->playlist = nova_playlist;
    nova_lplaylist->prox = *head;
    *head = nova_lplaylist;

    printf("Playlist criada com sucesso!\n");
}

void imprime_playlist(lplaylists_no *head, artista_no *artistas) {
    lplaylists_no *playlist_atual = head;

    while (playlist_atual != NULL) {
        playlist_no *musicas_playlist = playlist_atual->playlist;
        while (musicas_playlist != NULL) {
            printf("ID: %d\n", musicas_playlist->musica->id);
            printf("Titulo: %s\n", musicas_playlist->musica->titulo);
            printf("Artista: %s\n", encontra_artista_por_id(artistas, musicas_playlist->musica->id_artista)->artista->nome);
            printf("Duracao: %02d:%02d:%02d\n", musicas_playlist->musica->duracao / 3600, (musicas_playlist->musica->duracao / 60) % 60, musicas_playlist->musica->duracao % 60);
            printf("\n");
            musicas_playlist = musicas_playlist->prox;
        }
        playlist_atual = playlist_atual->prox;
    }
}

    
// ... restante do código

    
    
    ---------------------------------------------------------------------------------------------------------
        
        
        void cria_playlist(lplaylists_no **head, musica_no *musicas) {
    int id_musica;
    char entrada[1000];

    printf("Digite os IDs das musicas separados por espaco:\n");
    scanf(" %[^\n]s", entrada);

    lplaylists_no *nova_lplaylist = (lplaylists_no *)malloc(sizeof(lplaylists_no));
    nova_lplaylist->id = 1; // ou defina um novo ID de acordo com sua necessidade
    printf("Digite um nome para a playlist:\n");
    scanf(" %[^\n]s", nova_lplaylist->nome);

    playlist_no *nova_playlist = NULL;
    playlist_no *playlist_atual = NULL;
    char *ptr = strtok(entrada, " ");
    while (ptr != NULL) {
        id_musica = atoi(ptr);
        musica_no *musica_atual = musicas;
        while (musica_atual != NULL) {
            if (musica_atual->musica->id == id_musica) {
                playlist_no *nova_musica = (playlist_no *)malloc(sizeof(playlist_no));
                nova_musica->id = id_musica;
                nova_musica->musica = musica_atual->musica;
                nova_musica->prox = NULL;

                if (nova_playlist == NULL) {
                    nova_playlist = nova_musica;
                } else {
                    playlist_atual->prox = nova_musica;
                }
                playlist_atual = nova_musica;
                break;
            }
            musica_atual = musica_atual->prox;
        }
        ptr = strtok(NULL, " ");
    }

    nova_lplaylist->musicas = nova_playlist;
    nova_lplaylist->prox = *head;
    *head = nova_lplaylist;

    printf("Playlist criada com sucesso!\n");
}

    
    void imprime_playlist(lplaylists_no *lplaylists, artista_no *artistas) {
    lplaylists_no *lplaylist_atual = lplaylists;
    while (lplaylist_atual != NULL) {
        printf("Playlist: %s\n\n", lplaylist_atual->nome);
        playlist_no *playlist_atual = lplaylist_atual->musicas;
        while (playlist_atual != NULL) {
            printf("ID: %d\n", playlist_atual->musica->id);
            printf("Titulo: %s\n", playlist_atual->musica->titulo);
            printf("Artista: %s\n", busca_nome_artista(artistas, playlist_atual->musica->id_artista));
            printf("Duracao: %02d:%02d:%02d\n\n", playlist_atual->musica->duracao / 3600, (playlist_atual->musica->duracao / 60) % 60, playlist_atual->musica->duracao % 60);
            playlist_atual = playlist_atual->prox;
        }
        lplaylist_atual = lplaylist_atual->prox;
        printf("\n");
    }
}


     --------------------------------------------------------------------------------------------
         
         
         // remover a música de todas as playlists em que ela participa
for (int i = 0; i < MAX_PLAYLISTS; i++) {
    if(playlists[i] != NULL) {  // Adicione esta linha para verificar se a playlist é válida
        playlist_no *playlist_atual = playlists[i];
        playlist_no *playlist_anterior = NULL;
        while (playlist_atual != NULL) {
            if (playlist_atual->musica->id == id_musica) {
                if (playlist_anterior != NULL) {
                    playlist_anterior->prox = playlist_atual->prox;
                } else {
                    playlists[i] = playlist_atual->prox;
                }
                free(playlist_atual);
                break;
            }
            playlist_anterior = playlist_atual;
            playlist_atual = playlist_atual->prox;
        }
    }
    
}

    
    
    
    
    
    
    
    
    
    
    -----------------------------------------------------------------------------------------------
        void remove_musica(musica_no **head, lplaylists_no **lplaylists, int id_musica) {
    // remover a música da lista encadeada de músicas
    musica_no *musica_atual = *head;
    musica_no *musica_anterior = NULL;
    while (musica_atual != NULL) {
        if (musica_atual->musica->id == id_musica) {
            if (musica_anterior != NULL) {
                musica_anterior->prox = musica_atual->prox;
            } else {
                *head = musica_atual->prox;
            }
            free(musica_atual->musica);
            free(musica_atual);
            break;
        }
        musica_anterior = musica_atual;
        musica_atual = musica_atual->prox;
    }

    // remover a música de todas as playlists em que ela participa
    lplaylists_no *lplaylist_atual = *lplaylists;
    while (lplaylist_atual != NULL) {
        playlist_no *playlist_atual = lplaylist_atual->playlist;
        playlist_no *playlist_anterior = NULL;
        while (playlist_atual != NULL) {
            if (playlist_atual->musica->id == id_musica) {
                if (playlist_anterior != NULL) {
                    playlist_anterior->prox = playlist_atual->prox;
                } else {
                    lplaylist_atual->playlist = playlist_atual->prox;
                }
                free(playlist_atual);
                break;
            }
            playlist_anterior = playlist_atual;
            playlist_atual = playlist_atual->prox;
        }
        lplaylist_atual = lplaylist_atual->prox;
    }
}

