#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lista.h"

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
