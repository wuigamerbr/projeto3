#include <stdio.h>
#include <string.h>
#include "contatos.h"

ERROS criar(Agenda contatos[], int *pos){
    if(*pos >= TOTAL)
        return MAX_AGENDA;

    printf("Entre com o nome do contato: ");
    scanf("%d", &contatos[*pos].nome);
    clearBuffer();

    printf("Entre com o email: ");
    scanf("%s", &contatos[*pos].email, 255, stdin);

    printf("Entre com o telefone: ");
    scanf("%s", &contatos[*pos].telefone, 255, stdin);

    *pos = *pos + 1;

    return OK;
}

ERROS deletar(Agenda contatos[], int *pos){
    if(*pos == 0)
        printf("Não há dados a serem apagados\n");
        return SEM_CONTATOS;

    int pos_deletar;
    printf("Entre com o numero do contato que deseja deletar: ");
    scanf("%d", &pos_deletar);
    pos_deletar--;
    if(pos_deletar >= *pos || pos_deletar < 0)
        return NAO_ENCONTRADO;

    for(int i = pos_deletar; i < *pos; i++){
        contatos[i].telefone = contatos[i+1].telefone;
        strcpy(contatos[i].nome,contatos[i+1].nome);
        strcpy(contatos[i].email, contatos[i+1].email);
    }

    *pos = *pos - 1;

    return OK;
}

ERROS listar(Agenda contatos[], int *pos){
    if(*pos == 0)
        return SEM_CONTATOS;

    for(int i=0; i<*pos; i++){
        printf("Pos: %d\t", i+1);
        printf("Nome: %d\t", contatos[i].nome);
        printf("email: %d\t", contatos[i].email);
        printf("telefone: %d\n", contatos[i].telefone);
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

    return OK;
}

ERROS carregar(Agenda contatos[], int *pos, int tamanho){
  FILE *f = fopen("agenda.bin", "rb");
  if (f == NULL)
    return ABRIR;

  int i = fread(contatos, tamanho, sizeof(Agenda), f);
  if(i <= 0)
    return LER;

  i = fread(pos, 1, sizeof(int), f);
  if(i <= 0)
    return LER;
  
  i = fclose(f);
  if(i == 0)
    return FECHAR;
  
  return OK;

}