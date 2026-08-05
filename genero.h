typedef struct Artista Artista;

typedef struct Genero {
    char nome[100];
    struct Genero *prox;
    struct Genero *ant;
    Artista *artistas;
} Genero;

