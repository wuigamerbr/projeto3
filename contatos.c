#include <stdio.h>
#include <string.h>
#include "contatos.h"
#include <ctype.h>

ERROS criar(Agenda contatos[], int *pos) {
    if (*pos >= TOTAL)
        return MAX_AGENDA;

    printf("Entre com o nome do contato: ");
    scanf("%99s", contatos[*pos].nome);
    clearBuffer();

    printf("Entre com o email: ");
    scanf("%99s", contatos[*pos].email);
    clearBuffer();

    printf("Entre com o telefone: ");
    scanf("%19s", contatos[*pos].telefone);
    clearBuffer();

    (*pos)++;

    return OK;
}

ERROS listar(Agenda contatos[], int *pos) {
    if (*pos == 0)
        return SEM_CONTATOS;

    for (int i = 0; i < *pos; i++) {
        printAgenda(contatos[i], i + 1);
    }

    return OK;
}



ERROS deletar(Agenda contatos[], char *telefone, int *pos) {
    int i;
    int encontrado = 0;

    if (*pos <= 0) {
        return SEM_CONTATOS;
    }

    for (i = 0; i < *pos; i++) {
        if (strcmp(contatos[i].telefone, telefone) == 0) {
            encontrado = 1;

            for (int j = i; j < *pos - 1; j++) {
                strcpy(contatos[j].nome, contatos[j + 1].nome);
                strcpy(contatos[j].email, contatos[j + 1].email);
                strcpy(contatos[j].telefone, contatos[j + 1].telefone);
            }
            (*pos)--;
            printf("Contato removido com sucesso!\n");
            break;
        }
    }

    if (!encontrado) {
        printf("Contato com o número de telefone %s não encontrado.\n", telefone);
        return NAO_ENCONTRADO;
    }

    return OK;
}

ERROS salvar(Agenda contatos[], int *pos, int tamanho) {
    FILE *f = fopen("agenda.bin", "wb");
    if (f == NULL)
        return ABRIR;

    // Escrever cada contato no arquivo
    for (int i = 0; i < *pos; i++) {
        if (fwrite(&contatos[i], sizeof(Agenda), 1, f) != 1) {
            fclose(f);
            return ESCREVER;
        }
    }

    // Escrever o número total de contatos no arquivo
    if (fwrite(pos, sizeof(int), 1, f) != 1) {
        fclose(f);
        return ESCREVER;
    }

    // Fechar o arquivo após salvar os contatos e o número total
    if (fclose(f) != 0)
        return FECHAR;

    return OK;
}

ERROS carregar(Agenda contatos[], int *pos, int tamanho) {
    FILE *f = fopen("agenda.bin", "rb");
    if (f == NULL)
        return ABRIR;

    int i = fread(contatos, sizeof(Agenda), tamanho, f);
    if (i != *pos)
        return LER;

    if (fread(pos, sizeof(int), 1, f) != 1)
        return LER;

    if (fclose(f) != 0)
        return FECHAR;

    return OK;
}

void printAgenda(Agenda contatos, int pos) {
    printf("\nPosicao: %d\t", pos);
    printf("Nome: %s\tEmail: %s\t", contatos.nome, contatos.email);
    printf("Telefone: %s\n", contatos.telefone);
}

void clearBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}