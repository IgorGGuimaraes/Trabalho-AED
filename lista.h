#ifndef _LISTA_H
#define _LISTA_H


typedef struct Artista{
    char nome[100];
    struct Artista *ant;
    struct Artista *prox;
} Artista;


typedef struct Genero{
    char nome[100];
    struct Genero *prox;
    struct Genero *ant;
    Artista *artistas;
} Genero;

Genero *iniciarGenero();
void imprimirGeneros(Genero *g);
int contarGeneros(Genero *g);

void alterarGenero(Genero *g, char nomeAtual[], char novoNome[]);
int removerGenero(Genero **g, char nome[]);

//---------Laura--------
typedef struct _artista Artista;
typedef struct _genero Genero;
Genero* buscar_genero(Genero *lista, const char *nome_genero);
Genero* inserir_genero(Genero *lista_generos, const char *nome_genero);
Artista* buscar_artista(Genero *lista_generos, const char *nome_artista);
void inserir_artista(Genero *genero, const char *nome, const char *cidade, 
                     const char *periodo, const char *obras, 
                     const char *integrantes, const char *premiacoes);

#endif
