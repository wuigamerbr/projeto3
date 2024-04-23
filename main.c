#include <stdio.h>
#include <stdio.h>
#include "contatos.h"

int main(){
    int opcao;
    int pos = 0;
    Agenda contatos[TOTAL];

    do{
        printf("\nMenu principal\n");
        printf("1 - Criar contato\n");
        printf("2 - Deletar contato\n");
        printf("3 - Listar contatos\n");
        printf("4 - Salvar agenda\n");
        printf("5 - Carregar agenda\n");
        printf("0 - Sair\n");
        printf("Escolha uma opcao: ");
scanf("%d", &opcao);
    printf("Opcao escolhida: %d\n", opcao);

    if (opcao == 1) {
      ERROS erro = criar(contatos, &pos);
      if(erro == MAX_AGENDA)
        printf("Maximo de tarefas atingido\n");

    } else if (opcao == 2) {
      ERROS erro = deletar(contatos, &pos);
      if(erro == SEM_CONTATOS)
        printf("Tarefa nao encontrada\n");
    } else if (opcao == 3) {
      ERROS erro = listar(contatos, &pos);
      if(erro == SEM_CONTATOS)
        printf("Nao ha tarefas\n");
      listar(contatos, &pos);
    } else if (opcao == 0)
      printf("Sair...\n");
      ERROS erro = salvar(contatos, &pos, TOTAL);
      if(erro == LER || erro == FECHAR)
        printf("Erro ao ler as tarefas do arquivo\n");
      else if (erro == ABRIR){
        pos = 0;
        printf("Arquivo não encontrado\n");
      }
      else
        printf("Opcao invalida\n");

  } while (opcao != 0);
}

void clearBuffer(){
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}