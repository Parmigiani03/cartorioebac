#include <stdio.h> // biblioteca de comunicação com o usuário
#include <stdlib.h> // biblioteca de alocação de espaço de memória
#include <locale.h> // biblioteca de alocações de texto por região
#include <strings.h> // biblioteca responsável por cuidar das strings

int registro() //funçao responsável por cadastrar os usuários no sistema
{
	//início criação de variáveis / string
	char arquivo[40];
	char cpf[40];
    char nome[40];
    char sobrenome[40];
    char cargo[40];
    
    printf("Digite o CPF a ser cadastrado:"); // coletando informação do usuário
    scanf("%s" , cpf); // %s refere-se a string (está armazenando a string)
    
    strcpy(arquivo , cpf); // responsável por copiar os valores das strings
    
    FILE *file; //cria o arquivo
    file =fopen(arquivo , "w"); //abre o arquivo , "w" escrever , "r" ler , "a" atualizar
    fprintf(file , cpf); // salva oa valor da variavel
    fclose(file); // fecha o arquivo
    
    file = fopen(arquivo , "a");
    fprintf(file , ",");
    fclose(file);
    
    printf("Digete o nome a ser cadastrado:");
    scanf("%s" , nome);
    
    file = fopen(arquivo , "a");
    fprintf(file , nome);
    fclose(file);
    
    file = fopen(arquivo , "a");
    fprintf(file , ",");
    fclose(file);
    
    printf("Digite o sobrenome a ser cadastrado:");
    scanf("%s" , sobrenome);
    
    file = fopen(arquivo , "a");
    fprintf(file , sobrenome);
    fclose(file);
    
    file = fopen(arquivo , "a");
    fprintf(file , ",");
    fclose(file);
    
    printf("Digite o cargo a ser cadastrado:");
    scanf("%s" , cargo);
    
    file = fopen(arquivo , "a");
    fprintf(file , cargo);
    fclose(file);
    
    file = fopen(arquivo , "a");
    fprintf(file , ",");
    fclose(file);
    
}

int consulta()
{
	setlocale(LC_ALL, "Portuguese");
	
 	char cpf[40];
 	char conteudo[200];
 	
  	   printf("Digite o CPF a ser consultado:");
 	   scanf("%s" , cpf);
 	
 	   FILE * file;
       file = fopen(cpf , "r");
    
    if(file == NULL)
    {
       printf	("Não foi possível abrir o aquivo , não localizado! \n");
	}
    
 	while(fgets(conteudo, 200, file) !=NULL)
 	{
 	   printf("\n Essas são as informações do usuário;");
 	   printf("%s", conteudo);
 	   printf("\n\n");
    }
 	   system("pause");
}

int deletar()
{
    char cpf[40];
    
       printf("Digete o CPF do usuário a ser deletado:");
       scanf("%s" , cpf);
    
       remove(cpf);
    
       FILE *file;
       file = fopen(cpf , "r");
    
    if (file == NULL);
    {
    	printf("O usuário não se encontra no sistema! \n");
    	system("pause");
	}
    
}

int main()
{
	int opcao=0; // definindo variáveis
    int x=1;
    
    for(x=1;x=1;)
    {
    system("cls");	
    
	setlocale(LC_ALL, "Portuguese"); // definindo a linguagem
	
	printf("###Cartório SGP###\n\n"); // início do menu
	printf("escolha a opção desejada do menu:\n\n");
	printf("\t1 - Registrar Nomes\n");
	printf("\t2 - Consultar Nomes\n");
	printf("\t3 - Deletar Nomes\n\n"); 
	printf("Opção:"); // final do menu

    scanf ("%d" , &opcao); // armazenando a escolha do usuário
    
    system("cls"); // responsável por limpar a tela
    
    switch(opcao)
       {
           case 1:	
           registro(); // responsável por chamar as funções
           break;
           
           case 2:
           consulta();
           break;
           
           case 3:
           deletar();
           break;
        
           default:
           printf("Essa opção não está disponivel\n");
	       system("pause");
	       break;
            // final da seleção
	
           
	   
       } 
	}
	
}


