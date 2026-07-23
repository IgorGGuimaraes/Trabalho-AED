#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lista.h"

//funçoes rhuan

void alterarGenero(Genero *g, char nomeAtual[], char novoNome[]) {
    Genero *atual = g;
    while (atual != NULL) {
        if (strcmp(atual->nome, nomeAtual) == 0) {
            strcpy(atual->nome, novoNome);
            printf("Genero alterado com sucesso!\n");
            return;
        }
        atual = atual->prox;
    }
    printf("Genero nao encontrado.\n");
}

int removerGenero(Genero **g, char nome[]) {
    Genero *atual = *g;
    while (atual != NULL && strcmp(atual->nome, nome) != 0) {
        atual = atual->prox;
    }
    if (atual == NULL) {
        printf("Genero nao encontrado.\n");
        return 0; }
    if (atual->artistas != NULL) {
        printf("Nao e possivel remover um genero que possui artistas cadastrados.\n");
        return 0;
    }
    
    //elemento unico da lista
    if (atual->ant == NULL && atual->prox == NULL) {
        *g = NULL;
    }
    
    // removendo no inicio 
    else if (atual->ant == NULL) {
        *g = atual->prox;
        atual->prox->ant = NULL;
    }

    // removendo no final
    else if (atual->prox == NULL) {
        atual->ant->prox = NULL;
    }

    // removendo no meio
    else {
        atual->ant->prox = atual->prox;
        atual->prox->ant = atual->ant;
    }

    free(atual);
    printf("Genero removido com sucesso!\n");
    return 1;
}

//Funçoes do Igor

Genero *iniciarGenero() {
    return NULL;
}

void imprimirGeneros(Genero *g) {
    Genero *atual = *g;
    if(atual == NULL) {
        printf("Lista de generos vazia\n");
        return;
    }
    while(atual != NULL) {
        printf("Genero: %s", atual->nome);
        Artista *artAtual = atual->artistas;
        
        if(artAtual == NULL) {
            printf("Nenhum artista no gênero atual\n");
        } else {
            while(artAtual != NULL) {
                printf("Artista atual: %s", artAtual->nome);
                artAtual = artAtual->prox;
            }
        }
        atual = atual->prox;
    }
}

int contarGeneros(Genero *g) {
    int count = 0;
    Genero *atual = *g;
    while(atual != NULL) {
        count++;
        atual = atual->prox;
    }
    return count;
}

//FUNÇÕES LAURA-----------------
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


