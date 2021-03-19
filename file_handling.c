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
    FILE *fpointer2;
    char check_nome [6] = "tiagoo";
    char espacamento [100] = "------------------------------------";

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
                
                fpointer2 = fopen("file2.txt", "a");   
                if(fpointer == NULL)
                {
                    exit(0);
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
            fprintf(fpointer, "%s\n", espacamento);

            fprintf(fpointer2, "%s\n", equipamento[i].nome); 
            fprintf(fpointer2, "%i\n", *equipamento[i].numero_serie);
            fprintf(fpointer2, "%s\n", equipamento[i].fabricante); 
            fprintf(fpointer2, "%s\n", espacamento);
        }    
        fclose(fpointer);

    }

    if (escolha_usuario == 1)
    {

        
            //if ((fpointer = fopen("file.txt","r")) == NULL)
            //{
            //    printf("Erro!");
            //    exit(0);
            //}
            //while(fscanf(fpointer, "%s%lf%i%i%s%s",
            //equipamento[i].nome, equipamento[i].preco, equipamento[i].numero_serie, equipamento[i].data_fabricacao, equipamento[i].fabricante, espacamento) != EOF)
            //{
                //printf("%s\n%lf\n%i\n%i\n%s\n%s\n", equipamento[i].nome, *equipamento[i].preco, *equipamento[i].numero_serie, *equipamento[i].data_fabricacao, equipamento[i].fabricante, espacamento);
            //}
            //fclose(fpointer);

            if ((fpointer2 = fopen("file2.txt", "r+")) == NULL)
            {
                printf("Erro! O arquivo nao existe\n");
                exit(0);
            }
            while(fscanf(fpointer2, "%s%i%s%s", equipamento[i].nome, equipamento[i].numero_serie, equipamento[i].fabricante, espacamento) != EOF)
            {
                printf("%s\n%i\n%s\n%s\n", equipamento[i].nome, *equipamento[i].numero_serie, equipamento[i].fabricante, espacamento);
            }
        
    }

            






    return 0;
}






















































