#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

//definição da strunct.
 typedef struct 
 {
    char nome[30];
    char cor[10];
    int tropas;
    int dados;
 } territorio;
 // cadastro do usuário.
 void cadastro(territorio* ponteiro_territorio, int tamanho){
    for (int i = 0; i < tamanho; i++)
    {

      printf("--- cardastrando território: %d---\n", i+1);
      printf("digite o nome do território:\n");
      scanf("%s",ponteiro_territorio[i].nome);
      printf("digite o nome da cor das tropas:\n");
      scanf("%s",ponteiro_territorio[i].cor);
      printf("digite o numero de tropas:\n");
      scanf("%d",& ponteiro_territorio[i].tropas);
    }
 }
// exibição dos dados.
void exibicao(territorio* ponteiro_territorio, int tamanho){
    for (int i =0;i < tamanho; i++)
    {
        printf("\nTERRITÓRIO:%d\n", i+1);
        printf("nome do território:%s\n",ponteiro_territorio[i].nome);
        printf("cor exército:%s\n",ponteiro_territorio[i].cor);
        printf("quantidade de tropas:%d\n",ponteiro_territorio[i].tropas);
    }
}
// aqui vai ser trocado caractere por caractere do array "cor" caso o território seja dominado.
void caracteres(territorio*ponteiro_territorio, int valor, int valor2){
   
        for (int i = 0; i < 10; i++){
        ponteiro_territorio[valor].cor[i] = ponteiro_territorio[valor2].cor[i];
        if (ponteiro_territorio[valor].cor[i] == '\0')
        {
            break;
        }
    }
}
//aqui temos uma função que vai atualizar os dados de tropas com base em condições, simulando o ataque.
int atacar(territorio*ponteiro_territorio,int valor,int valor2){
    int condição;
    ponteiro_territorio[valor].dados = (rand() % 6) + 1 ;
    ponteiro_territorio[valor2].dados = (rand() % 6) + 1;
    printf("o atacante: %s rolou um dado e tirou: %d \n", ponteiro_territorio[valor].nome, ponteiro_territorio[valor].dados);
    printf("o defensor: %s rolou um dado e tirou: %d \n", ponteiro_territorio[valor2].nome, ponteiro_territorio[valor2].dados);
    condição = ponteiro_territorio[valor].dados > ponteiro_territorio[valor2].dados;
    if (condição) 
    {
       ponteiro_territorio[valor2].tropas--;
       printf("VITÓRIA DO ATAQUE! o defensor perdeu 1 tropa.\n");
       return ponteiro_territorio[valor2].tropas;           
    } else {
       ponteiro_territorio[valor].tropas--;
       printf("VITÓRIA DA DEFESA! o atacante perdeu 1 tropa.\n");
       return ponteiro_territorio[valor].tropas;
    }
  }
// aqui temos o main
int main(){
    //definição dos dados.
     int tamanho;
     int atacante;
     int defensor;
     char proseguir = 'S';
    // o uso da função srand para que seja possivel a criação dos números pseudoaleatórios.
    srand(time(NULL));
    //exibição da parte inicial
    printf("=======================================\n");
    printf("   WAR ESTRUTURADO - CADASTRO INICIAL  \n");
    printf("=======================================\n");
    // coleta do número da quantidade de territórios para o jogo.
    printf("digite a quantidade de territórios.\n");
    scanf("%d", &tamanho);
    //o uso do malloc para a alocação dinâmica.
    territorio* ponteiro_territorio = (territorio*)malloc(tamanho *sizeof(territorio));

    //parte da exibição dos dados.
      void (*ponteiro_x)(territorio* ponteiro_territorio,int tamanho ) = cadastro;
    //chamando o procedimento com o ponteiro.
      ponteiro_x(ponteiro_territorio,tamanho);
      printf("cadastro inicial concluido com sucesso!\n");
    //aqui temos um loop do tipo while, que vai repetir instruções com base no dado do usuário.
    while (proseguir == 'S') 
    {   
        //exibe infomações da etapa do estado atual.
        printf("\n==================================================\n");
        printf("           MAPA DO MUNDO - ESTADO ATUAL             \n");
        printf("==================================================\n");
        //exibição dos dados
        ponteiro_x = exibicao;
        //chamando o procedimento com o ponteiro.
        ponteiro_x(ponteiro_territorio, tamanho);
        //exibe infomações da etapa de ataque.
        printf("\n------FASE DE ATAQUE------\n");
        printf("os territórios estão numerados, use o numero correspodente para sua escolha.\n");
        //coleta dados.
        printf("digite o numero do território atacante:");
        scanf("%d", &atacante);
        printf("digite o numero do território defensor:");
        scanf("%d", &defensor);
        //reduz o número uma unidade de cada.
        atacante--;
        defensor--;
        //exibe o resultado da batalha.
        printf("\n-----RESULTADO DA BATALHA------\n");
        int (*ponteiro_y)(territorio* ponteiro_territorio, int valor1, int valor2) = atacar;
        //chama a função usando ponteiro.
        ponteiro_y(ponteiro_territorio,atacante,defensor);
        //definição de condições
        int condição_ = ponteiro_territorio[atacante].tropas == 0 ;
        int condição_2 = ponteiro_territorio[defensor].tropas == 0 ;
        if (condição_)
        {   //exibi a conquista.
            printf("CONQUISTA! o território %s foi dominado pelo exército %s!\n", ponteiro_territorio[atacante].nome, ponteiro_territorio[defensor].cor);
            void (*ponteiro_z)(territorio* ponteiro_territorio,int atacante, int defensor ) = caracteres;
            // chama o procedimento usando o ponteiro.
            ponteiro_z(ponteiro_territorio,  atacante,  defensor);

        }else if (condição_2)
        {
             printf("CONQUISTA! o território %s foi dominado pelo exército %s!\n", ponteiro_territorio[defensor].nome, ponteiro_territorio[atacante].cor);
              void (*ponteiro_z)(territorio* ponteiro_territorio,int defensor, int atacante ) = caracteres;
              // chama o procedimento usando o ponteiro.
              ponteiro_z(ponteiro_territorio,  defensor,  atacante);
        } else{}
        //coleta o dado para continuar.
        printf("digite S em maiúsculo se quiser proseguir ou qualquer outro valor para encerrar o turno.\n");
        scanf(" %c", &proseguir);
        // A condição para continuar.
        if (proseguir == 'S')
        {
            printf("continuando turno.\n");
        } else{
            printf("encerrando turno.\n");
        }
    } 
    //libera memória. 
    free(ponteiro_territorio);
    return 0;
}