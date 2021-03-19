#include <stdio.h>
#include <string.h>
#include <stdlib.h>


int main()
{

    struct lista_equipamentos
    {
        char nome[100];
        double preco[100];
        int numero_serie[100];
        int data_fabricacao[100];
        char fabricante[100];
        char espaco[100];
    };



    struct lista_equipamentos equipamento[1000];
    int i; //variavel pros loops
    int j; //numero de produtos inseridos pelo usuario
    int escolha_usuario;
    

    FILE *fpointer;

    char check_nome [6] = "tiagoo";
    char espacamento [100] = "------------------------------------\n";

    printf("O PROGRAMA A SEGUIR IRA AUXILIAR VOCE NA MANUTENCAO DO ESTOQUE.\nPOR FAVOR ESCOLHA UMA DAS OPCOES ABAIXO:\n0 - INSERIR NOVO ITEM NO ESTOQUE \n1 - LISTAR ESTOQUE\nPARA FINALIZAR O PROGRAMA APERTE CTRL+Z AO MESMO TEMPO\n");
    scanf("%i", &escolha_usuario);
    

    if(escolha_usuario == 0)
    {
        printf("INSIRA O NUMERO DE ITENS QUE VOCE DESEJA INSERIR NO ESTOQUE\n");
        scanf("%i", &j);   

        j = j - 1; //essa redefinicao de "j" se faz necessaria porque o usuario sempre inserira um item a mais do que o real

        
        printf("INSIRA O NOME, PRECO, NUMERO DE SERIE, DATA DE FABRICACAO E FABRICANTE, UM DO LADO DO OUTRO COM ESPACOS\n");
        for(i = 0; i <= j; i++)
        {
                fpointer = fopen("file.txt", "a");
                if(fpointer == NULL)
                {
                    exit(0);
                }   
                fpointer= fopen("file2.txt", "a");
                {
                    if(fpointer == NULL)
                    {
                        exit(0);
                    }
                }

            scanf("%s", equipamento[i].nome);
            scanf("%lf", *&equipamento[i].preco);
            scanf("%i", *&equipamento[i].numero_serie);
            scanf("%i", *&equipamento[i].data_fabricacao);
            scanf("%s", equipamento[i].fabricante);
            fprintf(fpointer, "%s\n", equipamento[i].nome);
            fprintf(fpointer, "%lf\n", *equipamento[i].preco); //AGAIN, WHY IS THE FUCKING * NECESSARY
            fprintf(fpointer, "%i\n", *equipamento[i].numero_serie);
            fprintf(fpointer, "%i\n", *equipamento[i].data_fabricacao);
            fprintf(fpointer, "%s\n", equipamento[i].fabricante); 
            fprintf(fpointer, "%s\n\n", espacamento);  
        }    
        fclose(fpointer);
    }

    if (escolha_usuario == 1)
    {

        for (i = 0; i <= j; i++)
        {
            if ((fpointer = fopen("file.txt","r")) == NULL)
            {
                printf("Error! The file does not exist.");
                exit(0);
            }
            fscanf(fpointer, "%s%lf%i%i%s%s",
            equipamento[i].nome, equipamento[i].preco, equipamento[i].numero_serie, equipamento[i].data_fabricacao, equipamento[i].fabricante, espacamento);
            printf("%s\n%lf\n%i\n%i\n%s\n%s\n", equipamento[i].nome, *equipamento[i].preco, *equipamento[i].numero_serie, *equipamento[i].data_fabricacao, equipamento[i].fabricante, espacamento);
            fclose(fpointer);
        }
        
    }

            



//Deve mostrar o nome;
//• Deve mostrar o número de série;
//• Deve mostrar a fabricante;
   
    


    return 0;
}




















































/*
int array[10] = {45, 53, 84, 514, 512, 5, 8, 10, 86, 4112};

for(int i = 0; i < 10 - 1; i++)
{
    for(int j = 0; j < 10 - 1 - i; j++)
    {
        if(array[j] > array[j + 1])
        {
            int aux = array[j];
            array[j] = array[j + 1];
            array[j + 1] = aux;
        }

    }
}

for(int i = 0; i < 10; i++)
{
    printf("%i\n", array[i]);
}
*/


