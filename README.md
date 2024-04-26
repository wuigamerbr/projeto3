# projeto3

#**Agenda de contatos**

**Objetivo**


Agenda de contatos permite o usuário registrar seu nome, número e e-mail em um arquivo.

Cada registro numera uma prioridade ao contato, sendo o limite de contatos 255.


**Compilação**


Será utilizado um programa que leia arquivos em formato C e por meio do seu terminal o usuário digita "gcc *.c && ./a.out" fazendo o código funcionar.

**Utilização**


Um menu aparecerá na tela dando 6 opções ao usuário, cada opção servindo a uma ação para serem digitadas, precisando ser um dos seguintes números:

- 1- Cria um contato na ordem do nome, e-mail e numero de telefone, será dada uma posição na memória desse contato. 
- 2- Pede a prioridade para identificar qual contato a ser deletado, caso seja digitado uma prioridade inexistente ele volta para o menu.
- 3- Lista todos os contatos com os dados na memória.
- 4- Salva em uma agenda em binário, os dados registrados ao criar o contato dando uma segurança maior porem dificultando sua leitura para programas C.
- 5- carrega a agenda para o usuário visualizar.
- 0- digitando "0" ele sairá do programa.
