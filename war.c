#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

//definição da strunct.
 typedef struct 
 {
    char nome[30];
    char cor[20];
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
 void missao(territorio* ponteiro_territorio, int tamanho,int numeroaleatorio1,int numeroaleatorio2,int numeroaleatorio3){
       printf("\n====================================================================\n");
       printf("                   sua missão exercito %s\n", ponteiro_territorio[numeroaleatorio1].cor);
       printf("====================================================================\n");

    if (tamanho > 2)
    {
         printf("conquiste os territórios %s e %s\n", ponteiro_territorio[numeroaleatorio2].nome,ponteiro_territorio[numeroaleatorio3].nome);

    } else if  (tamanho == 2)
    {
         printf("conquiste o território %s\n", ponteiro_territorio[numeroaleatorio2].nome);      
    }}
void verificar(territorio* ponteiro_territorio, int tamanho,int numeroaleatorio1,int numeroaleatorio2,int numeroaleatorio3){
    if (tamanho > 2)
    {
       if (strcmp(ponteiro_territorio[numeroaleatorio1].cor,ponteiro_territorio[numeroaleatorio2].cor) == 0 && strcmp(ponteiro_territorio[numeroaleatorio1].cor,
        ponteiro_territorio[numeroaleatorio3].cor) ==0)
       {
        printf("território %s sua missão foi cumprida com sucesso\n",  ponteiro_territorio[numeroaleatorio1].nome );
       } else{
            printf("sua missão ainda não foi concluida.\n");
       }
       
    }else if (tamanho ==2)
    {
        if (strcmp(ponteiro_territorio[numeroaleatorio1].cor,ponteiro_territorio[numeroaleatorio2].cor) == 0)
        {
          printf("território %s sua missão foi cumprida com sucesso\n",  ponteiro_territorio[numeroaleatorio1].nome );
        } else{
            printf("sua missão ainda não foi concluida.\n");
        }
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
     int entrada_;
     int numeroaleatorio1;
     int numeroaleatorio2;
     int numeroaleatorio3;
    
    // o uso da função srand para que seja possivel a criação dos números pseudoaleatórios.
    srand(time(NULL));
    //exibição da parte inicial
    printf("=======================================\n");
    printf("   WAR ESTRUTURADO - CADASTRO INICIAL  \n");
    printf("=======================================\n");
    // coleta do número da quantidade de territórios para o jogo.
    printf("digite a quantidade de territórios. obs(tem que ser um numero inteiro maior que 1)\n");
    scanf("%d", &tamanho);
    //o uso do malloc para a alocação dinâmica.
    if(tamanho <2){
        printf("Quantidade insuficiente de territórios para jogar.\n");
        return 0 ;
    }
    territorio* ponteiro_territorio = (territorio*)malloc(tamanho *sizeof(territorio));
    //parte da exibição dos dados.
    void (*ponteiro_x)(territorio* ponteiro_territorio,int tamanho ) = cadastro;
    //chamando o procedimento com o ponteiro.
      ponteiro_x(ponteiro_territorio,tamanho);
      printf("cadastro inicial concluido com sucesso!\n");
      int continue_ = 2;
      void(*ponteiro_z)(territorio* ponteiro_territorio,int tamanho,int numeroaleatorio1, int numeroaleatorio2,int numeroaleatorio3) = missao;
      while (continue_ == 2 )
        {
              numeroaleatorio1 = (rand() % tamanho) ;
              numeroaleatorio2 = (rand() % tamanho) ;
              numeroaleatorio3 = (rand() % tamanho) ;
             if (numeroaleatorio1!= numeroaleatorio2 && numeroaleatorio2 != numeroaleatorio3 && numeroaleatorio1 != numeroaleatorio3 && tamanho >2 )
             {
                ponteiro_z(ponteiro_territorio, tamanho, numeroaleatorio1,numeroaleatorio2,numeroaleatorio3);
                continue_ = 3;
             } else if (numeroaleatorio1 != numeroaleatorio2 && tamanho == 2 )
             {
                ponteiro_z(ponteiro_territorio, tamanho, numeroaleatorio1,numeroaleatorio2,numeroaleatorio3);
                continue_ = 3;
             }
        }
    
    
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
       
            printf("\n--------------MENU----------------\n");
            printf("digite 1 se deseja atacar.\n");
            printf("digite 2 se deseja verificar a missão\n");
            printf("digite 3 se quiser sair.\n");
            scanf("%d",&entrada_);
        switch (entrada_)
        {
        case 1:
            printf("\n------FASE DE ATAQUE------\n");
            printf("os territórios estão numerados, use o numero correspodente para sua escolha.\n");
        //coleta dados.
            printf("digite o numero do território atacante:\n");
            scanf("%d", &atacante);
            printf("digite o numero do território defensor:\n");
            scanf("%d", &defensor);
        //reduz o número uma unidade de cada.
           atacante--;
           defensor--;
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
                strcpy(ponteiro_territorio[atacante].cor, ponteiro_territorio[defensor].cor);
              }else if (condição_2)
              {
               printf("CONQUISTA! o território %s foi dominado pelo exército %s!\n", ponteiro_territorio[defensor].nome, ponteiro_territorio[atacante].cor);
               strcpy(ponteiro_territorio[defensor].cor, ponteiro_territorio[atacante].cor);
              } else{}
              printf("digite S se quiser voltar para o menu\n");
              //coleta o dado para continuar.
              scanf(" %c", &proseguir);

             

            break;
        case 2:
           ponteiro_z = verificar;
           ponteiro_z(ponteiro_territorio,tamanho,numeroaleatorio1,numeroaleatorio2,numeroaleatorio3);
            printf("digite S se quiser voltar para o menu.\n");
            //coleta o dado para continuar.
            scanf(" %c", &proseguir);
           break;
        case 3:
          proseguir = 'N';
        break;
        default:
          proseguir = 'N';
            break;
        }
        
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