#include <stdio.h>  // biblioteca de comunicação com o usuário
#include <stdlib.h> // bibliotéca de alocação de espaço em memória
#include <locale.h> // biblioteca de alocação de texto pr região
#include <string.h> // biblioteca que cuida das strings

int registro() // criação da função de cadastrar usuarios
{
    setlocale(LC_ALL, "Portuguese_Brasil.1252"); // definindo a linguagem

    char arquivo[40]; // criando as variaveis do banco de dados de registro como char e definindo o máximo de 40 caracteres para cada
    char cpf[40];
    char nome[40];
    char sobrenome[40];
    char cargo[40];

    printf("Digite o CPF a ser cadastrado: ");
    scanf("%s", cpf); // armazenando o que foi digitado na variavel cpf

    strcpy(arquivo, cpf); // responsavel por copiar/igualar os valores de cpf com arquivo

    FILE *file;                 // sistema acesse o arquivo FILE do pc e execute o comando file
    file = fopen(arquivo, "w"); // comando file manda criar e abrir (fopen) um arquivo novo para o cpf digitado e começar a escrever (w de write) nele
    fprintf(file, cpf);         // escreva o cpf no novo arquivo criado
    fclose(file);               // feche o novo arquivo criado

    file = fopen(arquivo, "a"); // comando file agora manda abrir o arquivo ja criado e atualizar-lo (a)
    fprintf(file, ", ");        // escreva uma virgula no arquivo
    fclose(file);               // feche o novo arquivo criado

    printf("Digite o nome a ser cadastrado: ");
    scanf("%s", nome); // armazenando o que foi digitado na variavel nome

    file = fopen(arquivo, "a"); // comando file agora manda abrir o arquivo ja criado e atualizar-lo (a)
    fprintf(file, nome);        // escreva o nome digitado no arquivo
    fclose(file);               // feche o arquivo

    file = fopen(arquivo, "a"); // comando file agora manda abrir o arquivo ja criado e atualizar-lo (a)
    fprintf(file, ", ");        // escreva uma virgula no arquivo
    fclose(file);               // feche o novo arquivo criado

    printf("Digite o sobrenome a ser cadastrado: ");
    scanf("%s", sobrenome);

    file = fopen(arquivo, "a");
    fprintf(file, sobrenome);
    fclose(file);

    file = fopen(arquivo, "a");
    fprintf(file, ", ");
    fclose(file);

    printf("Digite o cargo a ser cadastrado: ");
    scanf("%s", cargo);

    file = fopen(arquivo, "a");
    fprintf(file, cargo);
    fclose(file);

    system("pause");

    return 0;
}

int consulta() // criação da função de consultar usuarios
{
    setlocale(LC_ALL, "Portuguese_Brasil.1252"); // definindo a linguagem

    char cpf[40];       // criando as variaveis do banco de dados de consulta como char e definindo o máximo de 40 caracteres para cada
    char conteudo[200]; // a variavel cpf armazenara o cpf que o usuário quer consultar e a variavel conteudo armazenara o conteudo do cpf que sera mostrado na tela

    printf("Digite o CPF a ser consultado: ");
    scanf("%s", cpf); // armazenando o que foi digitado na variavel cpf

    FILE *file;             // sistema acesse o arquivo FILE do pc e execute o comando file
    file = fopen(cpf, "r"); // comando file manda abrir o arquivo ja criado e lê-lo (r de read)

    if (file == NULL) // se não for encontrado o arquivo escrevo a mensagem abaixo
    {
        printf("O CPF não foi cadastrado.\n");
    }

    while (fgets(conteudo, 200, file) != NULL) //  Pegue (gets) a váriavel conteudo e coloque nela até 200 caracteres do arquivo selecionado acima, enquanto ter coisa escrita no aquivo, ou seja, for diferente de nulo, faça o que esta abaixo
    {
        printf("\nEssas são as informações do usuário: ");
        printf("%s", conteudo);
        printf("\n\n");
    }

    system("pause");

    return 0;
}

int deletar() // criação da função de deletar usuarios
{
    char cpf[40]; // criando as variaveis do banco de dados de deletar como char e definindo o máximo de 40 caracteres

    printf("Digite o CPF do usuário a ser deletado: ");
    scanf("%s", cpf); // armazenando o que foi digitado na variavel cpf

    remove(cpf); // delete o cpf do banco de dados

    FILE *file; // sistema acesse o arquivo FILE do pc e execute o comando file
    file = fopen(cpf, "r"); // comando file manda abrir o arquivo ja criado e lê-lo (r de read)

    if(file == NULL) // se o arquivo não for encontrado, ou seja, for nulo, faça o que esta abaixo
    {
        printf("O CPF não foi cadastrado. \n");
        system("pause");
    }
    else // se o arquivo for encontrado, ou seja, não for nulo, faça o que esta abaixo
    {
        printf("O CPF foi deletado com sucesso. \n");
        system("pause");
    }

    return 0;
}

int main()
{                  // início do int main
    int opcao = 0; // definindo variavel opcao
    int laco = 1;  // definindo variavel laco

    for (laco = 1; laco = 1;) // início do laço de repetição for
    {
        system("cls");

        setlocale(LC_ALL, "Portuguese_Brasil.1252"); // definindo a linguagem

        printf("##### Cartório da EBAC #####\n\n"); // início do menu
        printf("Escolha a opção desejada:\n\n");
        printf("\t1 - Registrar nomes\n");
        printf("\t2 - Consultar nomes\n");
        printf("\t3 - Deletar nomes\n\n"); // fim do menu
        printf("Opção: ");

        scanf("%i", &opcao); // armazenando a escolha do usuário

        system("cls"); // apagando o menu

        switch (opcao) // início do laço de repetição switch
        {
        case 1:
            registro();
            break;

        case 2:
            consulta();
            break;

        case 3:
            deletar();
            break;

        default:
            printf("Essa opção não esta disponivel\n");
            system("pause");
            break;
        } // fim do laço de repetição switch
    }     // fim do laço de repetição for
} // fim do int main
