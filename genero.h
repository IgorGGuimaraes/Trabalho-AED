#ifndef GENERO_H
#define GENERO_H

typedef struct Artista Artista;

typedef struct Genero {
    char nome[100];
    struct Genero *prox;
    struct Genero *ant;
    Artista *artistas;
} Genero;

Genero *iniciarGenero();
void carregarArquivo(Genero **lista);
Genero *inserir_genero(Genero *lista_generos, const char *nome_genero);
Genero *buscar_genero(Genero *lista, const char *nome_genero);
void alterarGenero(Genero *g, char nomeAtual[], char novoNome[]);
int removerGenero(Genero **g, char nome[]);
void imprimirGeneros(Genero *g);
int contarGeneros(Genero *g);

