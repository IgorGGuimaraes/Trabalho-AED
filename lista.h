#ifndef _LISTA_H
#define _LISTA_H

typedef struct Artista {
	char nome[100];
	char cidade_origem[100];
	char periodo_atuacao[50];
	char principais_obras[200];
	char integrantes[200];
	char premiacoes[200];

	struct _artista *ant;
	struct _artista *prox;
} Artista;


typedef struct Genero{
    char nome[100];
    struct Genero *prox;
    struct Genero *ant;
    Artista *artistas;
} Genero;

//------------Igor
Genero *iniciarGenero();
void imprimirGeneros(Genero *g);
int contarGeneros(Genero *g);
void listarTodosArtistas(Genero *g);
int contarArtistas(Genero *g);
void listarArtistas(Genero *g);
void filtrarArtistasPorCidade(Genero *g, char *cidade);

//-----------------Rhuan
void alterarGenero(Genero *g, char nomeAtual[], char novoNome[]);
int removerGenero(Genero **g, char nome[]);

//---------Laura--------
Genero* buscar_genero(Genero *lista, const char *nome_genero);
Genero* inserir_genero(Genero *lista_generos, const char *nome_genero);
Artista* buscar_artista(Genero *lista_generos, const char *nome_artista);
void inserir_artista(Genero *genero, const char *nome, const char *cidade, 
                     const char *periodo, const char *obras, 
                     const char *integrantes, const char *premiacoes);

#endif
