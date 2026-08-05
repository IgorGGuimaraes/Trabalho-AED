#include "genero.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

Genero *iniciarGenero() {
    return NULL;
}

// Inserir gênero
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
    if (lista_generos != NULL)
        lista_generos->ant = novo;

    printf("Gênero '%s' inserido com sucesso!\n", nome_genero);
    return novo;
}

// Buscar gênero
Genero* buscar_genero(Genero *lista, const char *nome_genero) {
    Genero *atual = lista;
    while (atual != NULL) {
        if (strcasecmp(atual->nome, nome_genero) == 0)
            return atual;
        atual = atual->prox;
    }
    return NULL;
}

// Alterar gênero
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

// Remover gênero
int removerGenero(Genero **g, char nome[]) {
    Genero *atual = *g;
    while (atual != NULL && strcmp(atual->nome, nome) != 0)
        atual = atual->prox;
    if (atual == NULL) {
        printf("Genero nao encontrado.\n");
        return 0;
    }
    if (atual->artistas != NULL) {
        printf("Nao e possivel remover um genero que possui artistas cadastrados.\n");
        return 0;
    }
	//se for o unico da lista
    if (atual->ant == NULL && atual->prox == NULL) {
        *g = NULL;
	//se for o primeiro da lista
    } else if (atual->ant == NULL) {
        *g = atual->prox;
        atual->prox->ant = NULL;
	//se for o ultimo da lista
    } else if (atual->prox == NULL) {
        atual->ant->prox = NULL;
	//se tiver no meio da lista
    } else {
        atual->ant->prox = atual->prox;
        atual->prox->ant = atual->ant;
    }
    free(atual);
    printf("Genero removido com sucesso!\n");
    return 1;
}

// Listar gêneros
void imprimirGeneros(Genero *g) {
    Genero *atual = g;
    if (atual == NULL) {
        printf("Lista de generos vazia\n");
        return;
    }
    while (atual != NULL) {
        printf("Genero: %s\n", atual->nome);
        Artista *artAtual = atual->artistas;
        if (artAtual == NULL) {
            printf("Nenhum artista neste genero.\n");
        } else {
            while (artAtual != NULL) {
                printf("Artista: %s\n", artAtual->nome);
                artAtual = artAtual->prox;
            }
        }
        atual = atual->prox;
    }
}

// Contar gêneros
int contarGeneros(Genero *g) {
    int count = 0;
    Genero *atual = g;

    while (atual != NULL) {
        count++;
        atual = atual->prox;
    }
    return count;
}

