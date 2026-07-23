#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lista.h"

struct _artista {
	char nome[100];
	char cidade_origem[100];
	char periodo_atuacao[50];
	char principais_obras[200];
	char integrantes[200];
	char premiacoes[200];

	struct _artista *ant;
	struct _artista *prox;
};

typedef struct _artista Artista;

struct _genero {
	char nome[50];
	Artista *artistas;

	struct _genero *ant;
	struct _genero *prox;
};

typedef struct _genero Genero;

Genero* inserir_genero(Genero *lista_generos, const char *nome_genero) {
	Genero *novo = (Genero*) malloc(sizeof(Genero));
	if (!novo) {
		printf("Erro ao alocar memória!\n");
		return lista_generos;
	}

	strcpy(novo->nome, nome_genero);
	novo->artistas = NULL;
	novo->ant = NULL;
	novo->prox = lista_generos;

	if (lista_generos != NULL) {
		lista_generos->ant = novo;
	}

	printf("Gênero '%s' inserido com sucesso!\n", nome_genero);
	return novo;
}

//---------------------------------------------------------------

void inserir_artista(Genero *genero, const char *nome, const char *cidade, 
                     const char *periodo, const char *obras, 
                     const char *integrantes, const char *premiacoes) {
    if (!genero) {
        printf("Gênero inválido!\n");
        return;
    }

    Artista *novo = (Artista*) malloc(sizeof(Artista));
    if (!novo) {
        printf("Erro ao alocar memória!\n");
        return;
    }

    strcpy(novo->nome, nome);
    strcpy(novo->cidade_origem, cidade);
    strcpy(novo->periodo_atuacao, periodo);
    strcpy(novo->principais_obras, obras);
    strcpy(novo->integrantes, integrantes);
    strcpy(novo->premiacoes, premiacoes);

    // Inserção no início da sublista de artistas
    novo->ant = NULL;
    novo->prox = genero->artistas;

    if (genero->artistas != NULL) {
        genero->artistas->ant = novo;
    }

    genero->artistas = novo;
    printf("Artista '%s' adicionado ao gênero '%s'!\n", nome, genero->nome);
}

//---------------------------------------------------------------

Genero* buscar_genero(Genero *lista, const char *nome_genero) {
	Genero *atual = lista;
	while (atual != NULL) {
		if (strcasecmp(atual->nome, nome_genero) == 0) {
			return atual;
		}
		atual = atual->prox;
	}
	return NULL;
}


Artista* buscar_artista(Genero *lista_generos, const char *nome_artista) {
	Genero *g = lista_generos;
	int encontrado = 0;

	while (g != NULL) {
		Artista *a = g->artistas;
		while (a != NULL) {
			if (strcasecmp(a->nome, nome_artista) == 0) {
				printf("\n=== Artista Encontrado ===\n");
				printf("Gênero: %s\n", g->nome);
				printf("Nome: %s\n", a->nome);
				printf("Origem: %s\n", a->cidade_origem);
				printf("Atuação: %s\n", a->periodo_atuacao);
				printf("Obras: %s\n", a->principais_obras);
				printf("Integrantes: %s\n", a->integrantes);
				printf("Premiações: %s\n", a->premiacoes);
				printf("==========================\n");
				encontrado = 1;
			}
			a = a->prox;
		}
		g = g->prox;
	}

	if (!encontrado) {
		printf("\nArtista '%s' não foi encontrado em nenhum gênero.\n", nome_artista);
	}
}

