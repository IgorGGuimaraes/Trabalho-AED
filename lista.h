#ifndef _LISTA_H
#define _LISTA_H

typedef struct Artista{
    char nome[100];
    char cidade_origem[100];
    char periodo_atuacao[50];
    char principais_obras[200];
    char integrantes[200];
    char premiacoes[200];

    struct Artista *ant;
    struct Artista *prox;
} Artista;

typedef struct Genero{
    char nome[100];
    struct Genero *prox;
    struct Genero *ant;
    Artista *artistas;
} Genero;


//==================== IGOR ====================

Genero *iniciarGenero();
void imprimirGeneros(Genero *g);
int contarGeneros(Genero *g);
void listarTodosArtistas(Genero *g);
int contarArtistas(Genero *g);
void listarArtistas(Genero *g);
void filtrarArtistasPorCidade(Genero *g, char *cidade);


//==================== RHUAN ====================

// Lista principal
void alterarGenero(Genero *g, char nomeAtual[], char novoNome[]);
int removerGenero(Genero **g, char nome[]);

// Lista secundária
void alterarArtista(Genero *genero,
                    char nomeAtual[],
                    char novoNome[],
                    char cidade[],
                    char periodo[],
                    char obras[],
                    char integrantes[],
                    char premiacoes[]);

int removerArtista(Genero *genero, char nome[]);

// Consultas
void artistasPorGenero(Genero *lista);
void generoComMenosArtistas(Genero *lista);


//==================== LAURA ====================

// Lista principal
Genero* inserir_genero(Genero *lista_generos, const char *nome_genero);
Genero* buscar_genero(Genero *lista, const char *nome_genero);

// Lista secundária
void inserir_artista(Genero *genero,
                     const char *nome,
                     const char *cidade,
                     const char *periodo,
                     const char *obras,
                     const char *integrantes,
                     const char *premiacoes);

Artista* buscar_artista(Genero *lista_generos, const char *nome_artista);

Artista* buscar_artista_no_genero(Genero *genero_alvo,
                                  const char *nome_artista);

Artista* buscar_artista_global(Genero *lista_generos,
                               const char *nome_artista,
                               Genero **genero_encontrado);

int inserir_artista_no_genero(Genero *genero_alvo,
                              const char *nome,
                              const char *cidade,
                              const char *periodo,
                              const char *obras,
                              const char *integrantes,
                              const char *premiacoes);

#endif
