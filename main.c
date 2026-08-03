/******************************************************************************

Welcome to GDB Online.
  GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
  C#, OCaml, VB, Perl, Swift, Prolog, Javascript, Pascal, COBOL, HTML, CSS, JS
  Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lista.h"

int main() {
    Genero *listaGeneros = iniciarGenero();
    int opcao = 0;

    // Variáveis auxiliares para leitura dos dados
    char nomeGen[100], novoNomeGen[100];
    char nomeArt[100], novoNomeArt[100], cidade[100], periodo[100], obras[200], integrantes[200], premiacoes[200];
    Genero *genEncontrado = NULL;

    // População inicial para testes
    listaGeneros = inserir_genero(listaGeneros, "Rock");
    listaGeneros = inserir_genero(listaGeneros, "Pop");
    
    Genero *rock = buscar_genero(listaGeneros, "Rock");
    inserir_artista(rock, "Queen", "Londres", "1970-presente", "Bohemian Rhapsody", "Freddie, Brian, Roger, John", "Grammy Hall of Fame");
    Genero *pop = buscar_genero(listaGeneros, "Pop");
    inserir_artista(pop, "Queen", "Londres", "1970-presente", "Radio Ga Ga", "Freddie, Brian, Roger, John", "Grammy");

    do {
        printf("\n============================================\n");
        printf("       SISTEMA DE GESTAO DE MUSICA          \n");
        printf("============================================\n");
        printf(" 1. Inserir Genero\n");
        printf(" 2. Alterar Genero\n");
        printf(" 3. Remover Genero\n");
        printf(" 4. Inserir Artista em um Genero\n");
        printf(" 5. Alterar Artista\n");
        printf(" 6. Remover Artista\n");
        printf(" 7. Listar todos os Generos\n");
        printf(" 8. Listar Artistas de um Genero\n");
        printf(" 9. Listar TODOS os Artistas\n");
        printf("10. Filtrar Artistas por Cidade\n");
        printf("11. Buscar Genero por Nome\n");
        printf("12. Buscar Artista Globalmente\n");
        printf("13. Contar total de Generos\n");
        printf("14. Exibir quantidade de Artistas por Genero\n");
        printf("15. Exibir Genero com menor quantidade de Artistas\n");
        printf("16. Identificar Artistas em multiplos Generos\n");
        printf(" 0. Sair\n");
        printf("============================================\n");
        printf("Escolha uma opcao: ");
        
        if (scanf("%d", &opcao) != 1) {
            opcao = -1;
        }

        switch (opcao) {
            case 1:
                printf("\n--- INSERIR GÊNERO ---\n");
                printf("Nome do gênero: ");
                scanf(" %[^\n]", nomeGen);
                listaGeneros = inserir_genero(listaGeneros, nomeGen);
                break;

            case 2:
                printf("\n--- ALTERAR GÊNERO ---\n");
                printf("Nome atual do gênero: ");
                scanf(" %[^\n]", nomeGen);
                printf("Novo nome do gênero: ");
                scanf(" %[^\n]", novoNomeGen);
                alterarGenero(listaGeneros, nomeGen, novoNomeGen);
                break;

            case 3:
                printf("\n--- REMOVER GÊNERO ---\n");
                printf("Nome do gênero a remover: ");
                scanf(" %[^\n]", nomeGen);
                removerGenero(&listaGeneros, nomeGen);
                break;

            case 4:
                printf("\n--- INSERIR ARTISTA ---\n");
                printf("Nome do gênero alvo: ");
                scanf(" %[^\n]", nomeGen);
                genEncontrado = buscar_genero(listaGeneros, nomeGen);
                
                if (genEncontrado != NULL) {
                    printf("Nome do artista: ");
                    scanf(" %[^\n]", nomeArt);
                    printf("Cidade de origem: ");
                    scanf(" %[^\n]", cidade);
                    printf("Período de atuação: ");
                    scanf(" %[^\n]", periodo);
                    printf("Principais obras: ");
                    scanf(" %[^\n]", obras);
                    printf("Integrantes: ");
                    scanf(" %[^\n]", integrantes);
                    printf("Premiações: ");
                    scanf(" %[^\n]", premiacoes);

                    inserir_artista_no_genero(genEncontrado, nomeArt, cidade, periodo, obras, integrantes, premiacoes);
                } else {
                    printf("Erro: Gênero não encontrado.\n");
                }
                break;

            case 5:
                printf("\n--- ALTERAR ARTISTA ---\n");
                printf("Gênero do artista: ");
                scanf(" %[^\n]", nomeGen);
                genEncontrado = buscar_genero(listaGeneros, nomeGen);
                
                if (genEncontrado != NULL) {
                    printf("Nome atual do artista: ");
                    scanf(" %[^\n]", nomeArt);
                    printf("Novo nome: ");
                    scanf(" %[^\n]", novoNomeArt);
                    printf("Nova cidade: ");
                    scanf(" %[^\n]", cidade);
                    printf("Novo período: ");
                    scanf(" %[^\n]", periodo);
                    printf("Novas obras: ");
                    scanf(" %[^\n]", obras);
                    printf("Novos integrantes: ");
                    scanf(" %[^\n]", integrantes);
                    printf("Novas premiações: ");
                    scanf(" %[^\n]", premiacoes);

                    alterarArtista(genEncontrado, nomeArt, novoNomeArt, cidade, periodo, obras, integrantes, premiacoes);
                } else {
                    printf("Erro: Gênero não encontrado.\n");
                }
                break;

            case 6:
                printf("\n--- REMOVER ARTISTA ---\n");
                printf("Gênero do artista: ");
                scanf(" %[^\n]", nomeGen);
                genEncontrado = buscar_genero(listaGeneros, nomeGen);
                
                if (genEncontrado != NULL) {
                    printf("Nome do artista a remover: ");
                    scanf(" %[^\n]", nomeArt);
                    removerArtista(genEncontrado, nomeArt);
                } else {
                    printf("Erro: Gênero não encontrado.\n");
                }
                break;

            case 7:
                printf("\n--- LISTA DE GÊNEROS ---\n");
                imprimirGeneros(&listaGeneros);
                break;

            case 8:
                printf("\n--- LISTAR ARTISTAS DE UM GÊNERO ---\n");
                printf("Nome do gênero: ");
                scanf(" %[^\n]", nomeGen);
                genEncontrado = buscar_genero(listaGeneros, nomeGen);
                if (genEncontrado != NULL) {
                    listarArtistas(genEncontrado);
                } else {
                    printf("Erro: Gênero não encontrado.\n");
                }
                break;

            case 9:
                printf("\n--- TODOS OS ARTISTAS CADASTRADOS ---\n");
                listarTodosArtistas(listaGeneros);
                break;

            case 10:
                printf("\n--- FILTRAR ARTISTAS POR CIDADE ---\n");
                printf("Nome da cidade: ");
                scanf(" %[^\n]", cidade);
                filtrarArtistasPorCidade(listaGeneros, cidade);
                break;

            case 11:
                printf("\n--- BUSCAR GÊNERO ---\n");
                printf("Nome do gênero: ");
                scanf(" %[^\n]", nomeGen);
                genEncontrado = buscar_genero(listaGeneros, nomeGen);
                if (genEncontrado != NULL) {
                    printf("Gênero encontrado: %s\n", genEncontrado->nome);
                } else {
                    printf("Gênero não encontrado.\n");
                }
                break;

            case 12:
                printf("\n--- BUSCAR ARTISTA GLOBALMENTE ---\n");
                printf("Nome do artista: ");
                scanf(" %[^\n]", nomeArt);
                buscar_artista(listaGeneros, nomeArt);
                break;

            case 13:
                printf("\nTotal de gêneros cadastrados: %d\n", contarGeneros(&listaGeneros));
                break;

            case 14:
                printf("\n--- ARTISTAS POR GÊNERO ---\n");
                artistasPorGenero(listaGeneros);
                break;

            case 15:
                printf("\n--- GÊNERO COM MENOR QUANTIDADE DE ARTISTAS ---\n");
                generoComMenosArtistas(listaGeneros);
                break;

            case 16:
                identificar_artistas_multi_genero(listaGeneros);
                break;

            case 0:
                printf("\nEncerrando o programa...\n");
                break;

            default:
                printf("\nOpção inválida! Tente novamente.\n");
                break;
        }

    } while (opcao != 0);

    return 0;
}
