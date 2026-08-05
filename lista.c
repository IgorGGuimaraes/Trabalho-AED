#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lista.h"


// OPERAÇÕES DA LISTA PRINCIPAL

// Inicializar lista de gêneros
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

// OPERAÇÕES DA LISTA SECUNDÁRIA

// Inserir um novo elemento associado a um elemento da lista principal
int inserir_artista_no_genero(Genero *genero_alvo,
                              const char *nome,
                              const char *cidade,
                              const char *periodo,
                              const char *obras,
                              const char *integrantes,
                              const char *premiacoes) {

    if (genero_alvo == NULL) {
        printf("Erro: O genero especificado nao existe.\n");
        return 0;
    }
    Artista *novo = (Artista*) malloc(sizeof(Artista));
    if (novo == NULL) {
        printf("Erro: Falha na alocacao de memoria para o artista.\n");
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
    printf("Sucesso: Artista '%s' inserido no genero '%s'.\n",
           nome, genero_alvo->nome);
    return 1;
}

// Buscar elemento da lista secundária

Artista* buscar_artista(Genero *lista_generos, const char *nome_artista) {
    Genero *g = lista_generos;
    int encontrado = 0;
    while (g != NULL) {
        Artista *a = g->artistas;
        while (a != NULL) {
            if (strcasecmp(a->nome, nome_artista) == 0) {
                printf("\n=== Artista Encontrado ===\n");
                printf("Genero: %s\n", g->nome);
                printf("Nome: %s\n", a->nome);
                printf("Origem: %s\n", a->cidade_origem);
                printf("Atuacao: %s\n", a->periodo_atuacao);
                printf("Obras: %s\n", a->principais_obras);
                printf("Integrantes: %s\n", a->integrantes);
                printf("Premiacoes: %s\n", a->premiacoes);
                printf("==========================\n");
                encontrado = 1;
            }
            a = a->prox;
        }
        g = g->prox;
    }
    if (!encontrado) {
        printf("\nArtista '%s' nao foi encontrado em nenhum genero.\n",
               nome_artista);
    }
    return NULL;
}

Artista* buscar_artista_no_genero(Genero *genero_alvo,
                                  const char *nome_artista) {
    if (genero_alvo == NULL) {
        printf("Genero invalido para busca.\n");
        return NULL;
    }
    Artista *atual = genero_alvo->artistas;
    while (atual != NULL) {
        if (strcasecmp(atual->nome, nome_artista) == 0)
            return atual;
        atual = atual->prox;
    }
    return NULL;
}

// Alterar dados do artista

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

// Remover artista

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
    if (atual->ant == NULL && atual->prox == NULL) {
        genero->artistas = NULL;
    } else if (atual->ant == NULL) {
        genero->artistas = atual->prox;
        atual->prox->ant = NULL;
    } else if (atual->prox == NULL) {
        atual->ant->prox = NULL;
    } else {
        atual->ant->prox = atual->prox;
        atual->prox->ant = atual->ant;
    }
    free(atual);
    printf("Artista removido com sucesso!\n");
    return 1;
}

// Listar todos os artistas de um gênero
void listarArtistas(Genero *g) {
    if (g == NULL) {
        printf("Genero invalido.\n");
        return;
    }
    Artista *atual = g->artistas;
    int num = 0;
    while (atual != NULL) {

        printf("\nArtista %d\n", num++);
        printf("Nome: %s\n", atual->nome);
        printf("Cidade de Origem: %s\n", atual->cidade_origem);
        printf("Periodo de Atuacao: %s\n", atual->periodo_atuacao);
        printf("Principais Obras: %s\n", atual->principais_obras);
        printf("Integrantes: %s\n", atual->integrantes);
        printf("Premiacoes: %s\n", atual->premiacoes);

        atual = atual->prox;
		num = 1;
    }
    if (num == 0) {
        printf("Nenhum artista encontrado.\n");
    }
}

// Contar artistas
int contarArtistas(Genero *g) {

    if (g == NULL) {
        return 0;
    }
    int count = 0;
    Artista *atual = g->artistas;
    while (atual != NULL) {
        count++;
        atual = atual->prox;
    }
    return count;
}

// CONSULTAS E CRUZAMENTOS

// Localizar um artista a partir de qualquer gênero

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

// Localizar um artista partindo de qualquer nó da lista principal

Artista* buscar_artista_qualquer(Genero *no_qualquer, const char *nome_artista, Genero **genero_encontrado) {
    if (no_qualquer == NULL)
        return NULL;
    Genero *inicio = no_qualquer;
    while (inicio->ant != NULL) {
        inicio = inicio->ant;
    }
    Genero *g_atual = inicio;
    while (g_atual != NULL) {
        Artista *a_atual = g_atual->artistas;
        while (a_atual != NULL) {
            if (strcasecmp(a_atual->nome, nome_artista) == 0) {
                if (genero_encontrado != NULL)
                    *genero_encontrado = g_atual;
                return a_atual;
            }
            a_atual = a_atual->prox;
        }
        g_atual = g_atual->prox;
    }
    return NULL;
}

// Listar todos os artistas

void listarTodosArtistas(Genero *g) {

    Genero *genAtual = g;
    int encontrou = 0;
    if (genAtual == NULL) {
        printf("Lista vazia.\n");
        return;
    }
    printf("Artistas:\n");
    while (genAtual != NULL) {
        Artista *artAtual = genAtual->artistas;
        while (artAtual != NULL) {

            printf("Nome: %s\n", artAtual->nome);
            printf("Genero: %s\n", genAtual->nome);
            printf("Cidade de Origem: %s\n", artAtual->cidade_origem);
            printf("Periodo: %s\n", artAtual->periodo_atuacao);
            printf("Principais Obras: %s\n", artAtual->principais_obras);
            printf("Integrantes: %s\n", artAtual->integrantes);
            printf("Premiacoes: %s\n", artAtual->premiacoes);
            printf("-------------------------\n");
            encontrou = 1;
            artAtual = artAtual->prox;
        }
        genAtual = genAtual->prox;
    }
    if (encontrou == 0) {
        printf("Nenhum artista encontrado.\n");
    }
}

// Filtrar artistas por cidade

void filtrarArtistasPorCidade(Genero *g, char *cidade) {
    Genero *genAtual = g;
    int encontrou = 0;
    if (genAtual == NULL) {
        printf("Lista vazia.\n");
        return;
    }
    printf("Artistas da cidade %s:\n", cidade);
    while (genAtual != NULL) {
        Artista *artAtual = genAtual->artistas;
        while (artAtual != NULL) {
            if (strcmp(artAtual->cidade_origem, cidade) == 0) {
				
                printf("Nome: %s\n", artAtual->nome);
                printf("Genero: %s\n", genAtual->nome);
                printf("Periodo: %s\n", artAtual->periodo_atuacao);
                printf("Principais Obras: %s\n", artAtual->principais_obras);
                printf("Integrantes: %s\n", artAtual->integrantes);
                printf("Premiacoes: %s\n", artAtual->premiacoes);
                printf("-------------------------\n");
                encontrou = 1;
            }
            artAtual = artAtual->prox;
        }
        genAtual = genAtual->prox;
    }
    if (encontrou == 0) {
        printf("Nao ha nenhum artista desta cidade.\n");
    }
}

// Contabilizar quantos artistas existem em cada gênero

void artistasPorGenero(Genero *g) {
    if (g == NULL) {
        printf("Lista vazia.\n");
        return;
    }
    Genero *atual = g;

    while (atual != NULL) {
        printf("Genero: %s\n", atual->nome);
        printf("Quantidade de artistas: %d\n\n", contarArtistas(atual));
        atual = atual->prox;
    }
}

// Encontrar o gênero com menor quantidade de artistas

void generoComMenosArtistas(Genero *g) {
    if (g == NULL) {
        printf("Lista vazia.\n");
        return;
    }
    Genero *menor = g;
    int menorQtd = contarArtistas(g);
    Genero *atual = g->prox;
    while (atual != NULL) {
        int qtd = contarArtistas(atual);
        if (qtd < menorQtd) {
            menorQtd = qtd;
            menor = atual;
        }
        atual = atual->prox;
    }
    printf("Genero com menor quantidade de artistas:\n");
    printf("%s (%d artistas)\n", menor->nome, menorQtd);
}

// Identificar artistas que aparecem em mais de um gênero

void identificar_artistas_multi_genero(Genero *lista) {

    if (lista == NULL) {
        printf("Lista vazia.\n");
        return;
    }
    char impressos[100][100];
    int qtdImpressos = 0;
	
    Genero *g1 = lista;
    while (g1 != NULL) {
        Artista *a1 = g1->artistas;
        while (a1 != NULL) {
            int jaImpresso = 0;
            for (int i = 0; i < qtdImpressos; i++) {
                if (strcmp(impressos[i], a1->nome) == 0) {
                    jaImpresso = 1;
                    break;
                }
            }
            if (!jaImpresso) {
                Genero *g2 = g1->prox;
                int repetido = 0;
                while (g2 != NULL) {
                    Artista *a2 = g2->artistas;
                    while (a2 != NULL) {
                        if (strcasecmp(a1->nome, a2->nome) == 0) {
                            repetido = 1;
                        }
                        a2 = a2->prox;
                    }
                    g2 = g2->prox;
                }
                if (repetido) {
                    printf("%s aparece em mais de um genero.\n", a1->nome);
                    strcpy(impressos[qtdImpressos++], a1->nome);
                }
            }
            a1 = a1->prox;
        }
        g1 = g1->prox;
    }
}

void carregarArquivo(Genero **lista) {
    FILE *arq = fopen("musicas.txt", "r");

    if (arq == NULL) {
        printf("Nao foi possivel abrir o arquivo musicas.txt.\n");
        return;
    }

    char linha[1024];

    while (fgets(linha, sizeof(linha), arq) != NULL) {

        linha[strcspn(linha, "\n")] = '\0';

        char *nomeGenero = strtok(linha, ";");
        char *nomeArtista = strtok(NULL, ";");
        char *cidade = strtok(NULL, ";");
        char *periodo = strtok(NULL, ";");
        char *obras = strtok(NULL, ";");
        char *integrantes = strtok(NULL, ";");
        char *premiacoes = strtok(NULL, ";");

        if (nomeGenero == NULL || nomeArtista == NULL)
            continue;
        Genero *g = buscar_genero(*lista, nomeGenero);
        if (g == NULL) {
            *lista = inserir_genero(*lista, nomeGenero);
            g = buscar_genero(*lista, nomeGenero);
        }
        inserir_artista_no_genero(g,
                                  nomeArtista,
                                  cidade,
                                  periodo,
                                  obras,
                                  integrantes,
                                  premiacoes);
    }
    fclose(arq);
}
