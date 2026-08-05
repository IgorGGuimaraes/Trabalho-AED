#include "genero.h"
#include "artista.h"
#include "arquivo.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {

    Genero *listaGeneros = iniciarGenero();
    carregarArquivo(&listaGeneros);

    Genero *genEncontrado = NULL;

    int opcao = 0;

    char nomeGen[100], novoNomeGen[100];
    char nomeArt[100], novoNomeArt[100];
    char cidade[100], periodo[100];
    char obras[200], integrantes[200], premiacoes[200];
    
    do {

        printf("\n============================================\n");
        printf("      SISTEMA DE GESTAO DE MUSICAS\n");
        printf("============================================\n");
        printf(" 1. Inserir Genero\n");
        printf(" 2. Buscar Genero\n");
        printf(" 3. Alterar Genero\n");
        printf(" 4. Remover Genero\n");
        printf(" 5. Listar Generos\n");
        printf(" 6. Contar Generos\n");
        printf(" 7. Inserir Artista\n");
        printf(" 8. Buscar Artista\n");
        printf(" 9. Alterar Artista\n");
        printf("10. Remover Artista\n");
        printf("11. Listar Artistas de um Genero\n");
        printf("12. Contar Artistas de um Genero\n");
        printf("13. Listar Todos os Artistas\n");
        printf("14. Filtrar Artistas por Cidade\n");
        printf("15. Quantidade de Artistas por Genero\n");
        printf("16. Genero com Menor Quantidade de Artistas\n");
        printf("17. Identificar Artistas em Multiplos Generos\n");
        printf(" 0. Sair\n");
        printf("============================================\n");
        printf("Opcao: ");

        if (scanf("%d", &opcao) != 1)
            opcao = -1;

        switch (opcao) {
            case 1:
                printf("\n--- INSERIR GENERO ---\n");
                printf("Nome do genero: ");
                scanf(" %[^\n]", nomeGen);
                listaGeneros = inserir_genero(listaGeneros, nomeGen);
                break;

            case 2:
                printf("\n--- BUSCAR GENERO ---\n");
                printf("Nome do genero: ");
                scanf(" %[^\n]", nomeGen);

                genEncontrado = buscar_genero(listaGeneros, nomeGen);

                if (genEncontrado != NULL)
                    printf("Genero encontrado: %s\n", genEncontrado->nome);
                else
                    printf("Genero nao encontrado.\n");
                break;

            case 3:
                printf("\n--- ALTERAR GENERO ---\n");
                printf("Nome atual: ");
                scanf(" %[^\n]", nomeGen);
                printf("Novo nome: ");
                scanf(" %[^\n]", novoNomeGen);

                alterarGenero(listaGeneros, nomeGen, novoNomeGen);
                break;

            case 4:
                printf("\n--- REMOVER GENERO ---\n");
                printf("Nome do genero: ");
                scanf(" %[^\n]", nomeGen);

                removerGenero(&listaGeneros, nomeGen);
                break;

            case 5:
                printf("\n--- LISTA DE GENEROS ---\n");
                imprimirGeneros(listaGeneros);
                break;

            case 6:
                printf("\nTotal de generos cadastrados: %d\n",
                       contarGeneros(listaGeneros));
                break;

            case 7:
                printf("\n--- INSERIR ARTISTA ---\n");
                printf("Genero: ");
                scanf(" %[^\n]", nomeGen);

                genEncontrado = buscar_genero(listaGeneros, nomeGen);

                if (genEncontrado != NULL) {

                    printf("Nome: ");
                    scanf(" %[^\n]", nomeArt);

                    printf("Cidade de origem: ");
                    scanf(" %[^\n]", cidade);

                    printf("Periodo de atuacao: ");
                    scanf(" %[^\n]", periodo);

                    printf("Principais obras: ");
                    scanf(" %[^\n]", obras);

                    printf("Integrantes: ");
                    scanf(" %[^\n]", integrantes);

                    printf("Premiacoes: ");
                    scanf(" %[^\n]", premiacoes);

                    inserir_artista_no_genero(genEncontrado,
                                              nomeArt,
                                              cidade,
                                              periodo,
                                              obras,
                                              integrantes,
                                              premiacoes);
                } else {
                    printf("Genero nao encontrado.\n");
                }

                break;

            case 8:
                printf("\n--- BUSCAR ARTISTA ---\n");
                printf("Nome do artista: ");
                scanf(" %[^\n]", nomeArt);

                buscar_artista_global(listaGeneros, nomeArt);
                break;

            case 9:
                printf("\n--- ALTERAR ARTISTA ---\n");
                printf("Genero do artista: ");
                scanf(" %[^\n]", nomeGen);

                genEncontrado = buscar_genero(listaGeneros, nomeGen);

                if (genEncontrado != NULL) {

                    printf("Nome atual: ");
                    scanf(" %[^\n]", nomeArt);

                    printf("Novo nome: ");
                    scanf(" %[^\n]", novoNomeArt);

                    printf("Nova cidade: ");
                    scanf(" %[^\n]", cidade);

                    printf("Novo periodo: ");
                    scanf(" %[^\n]", periodo);

                    printf("Novas obras: ");
                    scanf(" %[^\n]", obras);

                    printf("Novos integrantes: ");
                    scanf(" %[^\n]", integrantes);

                    printf("Novas premiacoes: ");
                    scanf(" %[^\n]", premiacoes);

                    alterarArtista(genEncontrado,
                                    nomeArt,
                                    novoNomeArt,
                                    cidade,
                                    periodo,
                                    obras,
                                    integrantes,
                                    premiacoes);

                } else {
                    printf("Genero nao encontrado.\n");
                }

                break;

            case 10:
                printf("\n--- REMOVER ARTISTA ---\n");
                printf("Genero do artista: ");
                scanf(" %[^\n]", nomeGen);

                genEncontrado = buscar_genero(listaGeneros, nomeGen);

                if (genEncontrado != NULL) {

                    printf("Nome do artista: ");
                    scanf(" %[^\n]", nomeArt);

                    removerArtista(genEncontrado, nomeArt);

                } else {
                    printf("Genero nao encontrado.\n");
                }

                break;

            case 11:
                printf("\n--- LISTAR ARTISTAS DO GENERO ---\n");
                printf("Nome do genero: ");
                scanf(" %[^\n]", nomeGen);

                genEncontrado = buscar_genero(listaGeneros, nomeGen);

                if (genEncontrado != NULL)
                    listarArtistas(genEncontrado);
                else
                    printf("Genero nao encontrado.\n");

                break;

            case 12:
                printf("\n--- CONTAR ARTISTAS DO GENERO ---\n");
                printf("Nome do genero: ");
                scanf(" %[^\n]", nomeGen);

                genEncontrado = buscar_genero(listaGeneros, nomeGen);

                if (genEncontrado != NULL)
                    printf("Quantidade de artistas: %d\n",
                           contarArtistas(genEncontrado));
                else
                    printf("Genero nao encontrado.\n");

                break;

            case 13:
                printf("\n--- TODOS OS ARTISTAS CADASTRADOS ---\n");
                listarTodosArtistas(listaGeneros);
                break;

            case 14:
                printf("\n--- FILTRAR ARTISTAS POR CIDADE ---\n");
                printf("Nome da cidade: ");
                scanf(" %[^\n]", cidade);

                filtrarArtistasPorCidade(listaGeneros, cidade);
                break;

            case 15:
                printf("\n--- QUANTIDADE DE ARTISTAS POR GENERO ---\n");
                artistasPorGenero(listaGeneros);
                break;

            case 16:
                printf("\n--- GENERO COM MENOR QUANTIDADE DE ARTISTAS ---\n");
                generoComMenosArtistas(listaGeneros);
                break;

            case 17:
                printf("\n--- ARTISTAS EM MULTIPLOS GENEROS ---\n");
                identificar_artistas_multi_genero(listaGeneros);
                break;

            case 0:
                printf("\nEncerrando o programa...\n");
                break;

            default:
                printf("\nOpcao invalida! Tente novamente.\n");
                break;

            return 0;
        }

    } while (opcao != 0);

    return 0;
}
