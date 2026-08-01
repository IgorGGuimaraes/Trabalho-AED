#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lista.h"

//funções rhuan

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
        return 0;
    }

    if (atual->artistas != NULL) {
        printf("Nao e possivel remover um genero que possui artistas cadastrados.\n");
        return 0;
    }

    // Único elemento
    if (atual->ant == NULL && atual->prox == NULL) {
        *g = NULL;
    }

    // Primeiro elemento
    else if (atual->ant == NULL) {
        *g = atual->prox;
        atual->prox->ant = NULL;
    }

    // Último elemento
    else if (atual->prox == NULL) {
        atual->ant->prox = NULL;
    }

    // Elemento do meio
    else {
        atual->ant->prox = atual->prox;
        atual->prox->ant = atual->ant;
    }

    free(atual);

    printf("Genero removido com sucesso!\n");
    return 1;
}

void alterarArtista(Genero *genero,
                    char nomeAtual[],
                    char novoNome[],
                    char cidade[],
                    char periodo[],
                    char obras[],
                    char integrantes[],
                    char premiacoes[]) {

    Artista *artista = buscar_artista_no_genero(genero, nomeAtual);

    if (artista == NULL) {
        printf("Artista nao encontrado.\n");
        return;
    }

    strcpy(artista->nome, novoNome);
    strcpy(artista->cidade_origem, cidade);
    strcpy(artista->periodo_atuacao, periodo);
    strcpy(artista->principais_obras, obras);
    strcpy(artista->integrantes, integrantes);
    strcpy(artista->premiacoes, premiacoes);

    printf("Artista alterado com sucesso!\n");
}

int removerArtista(Genero *genero, char nome[]) {

    if (genero == NULL) {
        return 0;
    }

    Artista *atual = genero->artistas;

    while (atual != NULL && strcmp(atual->nome, nome) != 0) {
        atual = atual->prox;
    }

    if (atual == NULL) {
        printf("Artista nao encontrado.\n");
        return 0;
    }

    // Único artista
    if (atual->ant == NULL && atual->prox == NULL) {
        genero->artistas = NULL;
    }

    // Primeiro artista
    else if (atual->ant == NULL) {
        genero->artistas = atual->prox;
        atual->prox->ant = NULL;
    }

    // Último artista
    else if (atual->prox == NULL) {
        atual->ant->prox = NULL;
    }

    // Artista do meio
    else {
        atual->ant->prox = atual->prox;
        atual->prox->ant = atual->ant;
    }

    free(atual);

    printf("Artista removido com sucesso!\n");
    return 1;
}

// Contabilizar quantos artistas existem em cada gênero
void artistasPorGenero(Genero *lista) {

    Genero *atual = lista;

    if (atual == NULL) {
        printf("Lista de generos vazia.\n");
        return;
    }

    while (atual != NULL) {

        printf("\nGenero: %s\n", atual->nome);
        printf("Quantidade de artistas: %d\n", contarArtistas(atual));

        atual = atual->prox;
    }
}
// Encontrar o gênero com menos artistas
void generoComMenosArtistas(Genero *lista) {

    if (lista == NULL) {
        printf("Lista de generos vazia.\n");
        return;
    }

    Genero *menor = lista;
    Genero *atual = lista->prox;

    while (atual != NULL) {

        if (contarArtistas(atual) < contarArtistas(menor)) {
            menor = atual;
        }

        atual = atual->prox;
    }

    printf("\nGenero com menor quantidade de artistas:\n");
    printf("Nome: %s\n", menor->nome);
    printf("Quantidade de artistas: %d\n", contarArtistas(menor));
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

void listarArtistas(Genero *g) {
    if(genero == NULL) {
        printf("Gênero inválido");
        return;
    }
    
    Artista *atual = g->artistas;
    int num = 0;
    
    while(atual != NULL) {
        printf("Artista nº %d : %s", num++, atual->nome);
        printf("Cidade de Origem: %s\n", atual->cidade_origem);
        printf("Período de Atuação: %s\n", atual->periodo_atuacao);
        printf("Principais Obras: %s\n", atual->principais_obras);
        printf("Integrantes: %s\n", atual->integrantes);
        printf("Premiações: %s\n", atual->premiacoes);
        
        atual = atual->prox;
    }
}

int contarArtistas(Genero *g) {
    if(Genero == NULL) {
        return 0;
    }
    int count = 0;
    Artista *atual = g->artistas;
    while(atual != NULL) {
        count++;
        atual = atual->prox;
    }
    return count;
}

//Listar todos os Artistas (elementos da lista secundária)

void listarTodosArtistas(Genero *g){
    Genero *genAtual = g;
    int encontrou = 0;
    
    if(atual == NULL) {
        printf("Lista vazia\n");
        return;
    }
    
    printf("Artistas:\n");
    while(genAtual != NULL) {
		Artista *artAtual = genAtual->artistas;
			
		while(artAtual != NULL) {
			printf("Nome: %s\n", art_atual->nome);
       		 printf("Genero: %s\n", gen_atual->nome);
        	printf("Cidade de Origem: %s\n", art_atual->cidade_origem);
	        printf("Periodo: %s\n", art_atual->periodo_atuacao);
        	printf("Principais Obras: %s\n", art_atual->principais_obras);
        	printf("Integrantes: %s\n", art_atual->integrantes);
        	printf("Premiacoes: %s\n", art_atual->premiacoes);

        	encontrou = 1;
        	artAtual = artAtual->prox;
		}

		genAtual = genAtual->prox;
        
    }
    
    if(encontrou == 0){
        printf("Nenhum artista encontrado\n");
    }
}

//Filtrar elementos da lista secundária por atributos

void filtrarArtistasPorCidade(Genero *g, char *cidade) {
    Genero *genAtual = g;
    int encontrou = 0;
    
    if(genAtual == NULL) {
        printf("Lista vazia\n");
        return;
    }
    
    printf("Artistas da cidade %s", genAtual->cidade_origem);
    while(genAtual != NULL) {
        
        Artista artAtual = genAtual->artistas;
        
        while(artAtual != NULL) {
            if(strcmp(artAtual->cidade_origem, cidade) == 0) {
                printf("Nome: %s\n", art_atual->nome);
                printf("Genero: %s\n", gen_atual->nome);
                printf("Periodo: %s\n", art_atual->periodo_atuacao);
                printf("Principais Obras: %s\n", art_atual->principais_obras);
                printf("Integrantes: %s\n", art_atual->integrantes);
                printf("Premiacoes: %s\n", art_atual->premiacoes);
                printf("-------------------------\n");
                
                encontrou = 1;
            }
            artAtual = artAtual->prox;
        }
        
        genAtual = genAtual->prox;
    }
    
    if(encontrou == 0) {
        printf("Não há nenhum artista desta cidade\n");
    }
    
}

//---------------FUNÇÕES LAURA-----------------

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
//-----------------------------------Lista secundária-Laura-----------------------------------------------
int inserir_artista_no_genero(Genero *genero_alvo, 
                             const char *nome, 
                             const char *cidade, 
                             const char *periodo, 
                             const char *obras, 
                             const char *integrantes, 
                             const char *premiacoes) {
    
    if (genero_alvo == NULL) {
        printf("Erro: O gênero especificado não existe.\n");
        return 0; 
    }

    
    Artista *novo = (Artista*) malloc(sizeof(Artista));
    if (novo == NULL) {
        printf("Erro: Falha na alocação de memória para o artista.\n");
        return 0; 
    }

    
    strncpy(novo->nome, nome, sizeof(novo->nome) - 1);
    strncpy(novo->cidade_origem, cidade, sizeof(novo->cidade_origem) - 1);
    strncpy(novo->periodo_atuacao, periodo, sizeof(novo->periodo_atuacao) - 1);
    strncpy(novo->principais_obras, obras, sizeof(novo->principais_obras) - 1);
    strncpy(novo->integrantes, integrantes, sizeof(novo->integrantes) - 1);
    strncpy(novo->premiacoes, premiacoes, sizeof(novo->premiacoes) - 1);

    
    novo->ant = NULL;
    novo->prox = genero_alvo->artistas; 


    if (genero_alvo->artistas != NULL) {
        genero_alvo->artistas->ant = novo;
    }

    
    genero_alvo->artistas = novo;

    printf("Sucesso: Artista '%s' inserido no gênero '%s'.\n", nome, genero_alvo->nome);
    return 1; 
}
//---------------------------------------------------------------------------------------

Artista* buscar_artista_no_genero(Genero *genero_alvo, const char *nome_artista) {
    if (genero_alvo == NULL) {
        printf("Gênero inválido para busca.\n");
        return NULL;
    }

    Artista *atual = genero_alvo->artistas;

    
    while (atual != NULL) {
        if (strcasecmp(atual->nome, nome_artista) == 0) {
            return atual; 
        }
        atual = atual->prox;
    }

    return NULL; 
}
//--------------------------------------------------------------------------------------

Artista* buscar_artista_global(Genero *lista_generos, const char *nome_artista, Genero **genero_encontrado) {
    Genero *g_atual = lista_generos;

    while (g_atual != NULL) {
        Artista *a_atual = g_atual->artistas;
        
        while (a_atual != NULL) {
            if (strcasecmp(a_atual->nome, nome_artista) == 0) {
                if (genero_encontrado != NULL) {
                    *genero_encontrado = g_atual; 
                }
                return a_atual;
            }
            a_atual = a_atual->prox;
        }
        g_atual = g_atual->prox;
    }

    return NULL; 
}
