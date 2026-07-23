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

#endif
