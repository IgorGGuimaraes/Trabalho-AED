#ifndef _LISTA_H
#define _LISTA_H

typedef struct Artista {
    char nome[100];
    char cidade_origem[100];
    char periodo_atuacao[50];
    char principais_obras[200];
    char integrantes[200];
    char premiacoes[200];

    struct Artista *ant;
    struct Artista *prox;
} Artista;

int inserir_artista_no_genero(Genero *genero_alvo,
                              const char *nome,
                              const char *cidade,
                              const char *periodo,
                              const char *obras,
                              const char *integrantes,
                              const char *premiacoes);

Artista *buscar_artista_no_genero(Genero *genero_alvo, const char *nome_artista);
void alterarArtista(Genero *genero,
                    char nomeAtual[],
                    char novoNome[],
                    char cidade[],
                    char periodo[],
                    char obras[],
                    char integrantes[],
                    char premiacoes[]);
int removerArtista(Genero *genero, char nome[]);
void listarArtistas(Genero *g);
int contarArtistas(Genero *g);
Artista *buscar_artista_global(Genero *lista_generos,
                               const char *nome_artista,
                               Genero **genero_encontrado);

Artista *buscar_artista_qualquer(Genero *no_qualquer,
                                 const char *nome_artista,
                                 Genero **genero_encontrado);

void listarTodosArtistas(Genero *g);
void filtrarArtistasPorCidade(Genero *g, char *cidade);
void artistasPorGenero(Genero *lista);
void generoComMenosArtistas(Genero *lista);
void identificar_artistas_multi_genero(Genero *lista);

#endif
