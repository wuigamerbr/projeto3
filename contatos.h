#define TOTAL 255

typedef struct {
    char nome;
    char email;
    int telefone;
} Agenda;

typedef enum {OK, MAX_AGENDA, SEM_CONTATOS, NAO_ENCONTRADO, ABRIR, FECHAR, ESCREVER, LER} ERROS;

typedef ERROS (*funcao)(Agenda[], int*);

ERROS criar(Agenda contatos[], int *pos);
ERROS deletar(Agenda contatos[], int *pos);
ERROS listar(Agenda contatos[], int *pos);
ERROS salvar(Agenda contatos[], int *pos, int tamanho);
ERROS carregar(Agenda contatos[], int *pos, int tamanho);

void clearBuffer();