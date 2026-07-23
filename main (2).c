#include "lista.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
    Genero *minha_lista = NULL;

    
    minha_lista = inserir_genero(minha_lista, "Rock");
    minha_lista = inserir_genero(minha_lista, "MPB");

    
    Genero *rock = buscar_genero(minha_lista, "Rock");
    if (rock) {
        inserir_artista(rock, "Legião Urbana", "Brasília - DF", "1982-1996",
                        "Dois, Que País É Este", "Renato Russo, Dado, Marcelo Bonfá", 
                        "Prêmio Sharp");
    }

    Genero *mpb = buscar_genero(minha_lista, "MPB");
    if (mpb) {
        inserir_artista(mpb, "Elis Regina", "Porto Alegre - RS", "1961-1982",
                        "Falso Brilhante, Elis & Tom", "Solo", 
                        "Festival de Música Popular Brasileira");
    }

    
    buscar_artista(minha_lista, "Legião Urbana");
    buscar_artista(minha_lista, "Iron Maiden"); // Deve avisar que não encontrou

    return 0;
}