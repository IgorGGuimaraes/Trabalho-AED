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
