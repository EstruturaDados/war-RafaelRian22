#include <stdio.h>
#include <string.h>
//definiçãop da strunct
struct territorio
{
    char nome[30];
    char cor[10];
    int tropas;
};

//definição do main
int main(){
    //instância da struct
    struct territorio dados[6];
    //coleta de dados
    for (int i = 0; i < 5; i++)
    {
      printf("---território: %d---\n", i+1);
      printf("digite o nome do território:\n");
      scanf("%s",dados[i].nome);
      printf("digite o nome da cor das tropas:\n");
      scanf("%s",dados[i].cor);
      printf("digite o numero de tropas:\n");
      scanf("%d",& dados[i].tropas);
    }
    //parte da exibição dos dados
    printf("cadastro inicial concluido com sucesso!\n");
    printf("==================================================\n");
    printf("           MAPA DO MUNDO - ESTADO ATUAL           \n");
    printf("==================================================\n");
    //exibição dos dados
    for (int i = 0; i < 5; i++)
    {
        printf("TERRITÓRIO:%d\n", i+1);
        printf("-%s\n",dados[i].nome);
        printf("-%s\n",dados[i].cor);
        printf("-%d\n",dados[i].tropas);
    }
    return 0;
}


