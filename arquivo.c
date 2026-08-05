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
