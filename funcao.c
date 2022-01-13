#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#include "funcao.h"

void pause(){
  printf("\nClique para continuar...");
  getchar();
  getchar();
}

void menu(){
  printf("\n**************** Agenda Telefonica ****************\n");
  printf("[1] - Inserir novo contato.\n");
  printf("[2] - Editar os dados de um contato.\n");
  printf("[3] - Remover um contato.\n");
  printf("[4] - Contatos ordenados por nome.\n");
  printf("[5] - Contatos ordenados por data de nascimento.\n");
  printf("[6] - Pesquisa um contato pelo codigo.\n");
  printf("[7] - Pesquisa um contato pelo nome.\n");
  printf("[8] - Pesquisa um contato pela data de nascimento.\n");
  printf("[9] - Pesquisa um contato pelo email.\n");
  printf("[0] - Sair.\n");
}

void menu_pesq(){
  printf("\n********** Pesquisa **********\n");
  printf("[1] - Sequencial.\n");
  printf("[2] - Binaria.\n");
  printf("[3] - Arvore Binaria.\n");
}

void maiusculo(char s1[]){
  int i = 0;

  while(s1[i] != '\0'){
    s1[i] = toupper(s1[i]);
    i++;
  }
}

void minusculo(char s1[]){
  int i = 0;

  while(s1[i] != '\0'){
    s1[i] = tolower(s1[i]);
    i++;
  }
}

void inserir(Contato *vet, int pos){
  int sn=0;
  do{
    printf("Codigo: ");
    scanf("%d", &vet[pos].codigo);
    fflush(stdin);
    getchar();

    if(vet[pos].codigo == 0){
        sn = 1;
        printf("Digite um codigo diferente de 0.\n");
    }
    else{
      sn=0;
      if(pos > 0){
        for(int i=0; i<pos; i++){
          if(vet[i].codigo == vet[pos].codigo){
            sn = 1;
            printf("Codigo ja existente!\n");
          }
        }
      }
    }
  }while(sn != 0);

  printf("Nome: ");
  gets(vet[pos].nome);
  fflush(stdin);
  maiusculo(vet[pos].nome);

  printf("Data de nascimento (dd mm aaaa): ");
  scanf("%d %d %d", &vet[pos].dia, &vet[pos].mes, &vet[pos].ano);
  fflush(stdin);
  getchar();

  printf("Celular ((xx)xxxxx-xxxx): ");
  gets(vet[pos].celular);
  fflush(stdin);

  printf("Email: ");
  gets(vet[pos].email);
  fflush(stdin);
  minusculo(vet[pos].email);
}

void mostrar(Contato *vet, int pos){
  for(int i=0; i<pos; i++){
    printf("Codigo = %d\n", vet[i].codigo);
    printf("Nome = %s\n", vet[i].nome);
    printf("Data de nascimento = %d/%d/%d\n", vet[i].dia, vet[i].mes, vet[i].ano);
    printf("Celular = %s\n", vet[i].celular);
    printf("Email = %s\n\n", vet[i].email);
  }
}

void editar(Contato *vet, int pos){
  if(pos == 0){
    printf("Nenhum contato na agenda!\n");
  }
  else{
    int op, sn1=0;
    mostrar(vet, pos);

    do{
      printf("\nDigite o codigo do contato que deseja alterar.");
      printf("\n(Caso nao deseje mais alterar digite 0): ");
      scanf("%d", &op);

      if(op == 0){
        sn1++;
      }
      else{
        for(int i=0; i<pos; i++){
          if(op == vet[i].codigo){
            sn1++;
          }
        }
      }
    }while(sn1 == 0);

    if(op == 0){
    }
    else{
      int sn=0;
      for(int i=0; i<pos; i++){
        if(op == vet[i].codigo){

          printf("\nDeseja alterar o codigo?");
          printf("\n(Digite [1] para sim ou [0] para nao): ");
          scanf("%d", &sn);
          if(sn == 1){
            int sn2 = 0;
            do{
              printf("Codigo: ");
              scanf("%d", &vet[i].codigo);
              fflush(stdin);
              getchar();

              if(vet[i].codigo == 0){
                sn2 = 1;
                printf("Digite um codigo diferente de 0.\n");
              }
              else{
                sn2 = 0;
                for(int y=0; y<i; y++){
                  if(vet[y].codigo == vet[i].codigo){
                    sn2 = 1;
                    printf("Codigo ja existente!\n");
                  }
                }
                for(int y=i+1; y<pos; y++){
                  if(vet[y].codigo == vet[i].codigo){
                    sn2 = 1;
                    printf("Codigo ja existente!\n");
                  }
                }
              }
            }while(sn2 != 0);
          }
          sn=0;

          printf("\nDeseja alterar o nome?");
          printf("\n(Digite [1] para sim ou [0] para nao): ");
          scanf("%d", &sn);
          getchar();
          if(sn == 1){
            printf("Nome: ");
            gets(vet[i].nome);
            fflush(stdin);
            maiusculo(vet[i].nome);
          }
          sn=0;

          printf("\nDeseja alterar a data de nascimento?");
          printf("\n(Digite [1] para sim ou [0] para nao): ");
          scanf("%d", &sn);
          if(sn == 1){
            printf("Data de nascimento (dd mm aa): ");
            scanf("%d %d %d", &vet[i].dia, &vet[i].mes, &vet[i].ano);
            fflush(stdin);
            getchar();
          }
          sn=0;

          printf("\nDeseja alterar o celular?");
          printf("\n(Digite [1] para sim ou [0] para nao): ");
          scanf("%d", &sn);
          getchar();
          if(sn == 1){
            printf("Celular ((xx)xxxxx-xxxx): ");
            gets(vet[i].celular);
            fflush(stdin);
          }
          sn=0;

          printf("\nDeseja alterar o email?");
          printf("\n(Digite [1] para sim ou [0] para nao): ");
          scanf("%d", &sn);
          getchar();
          if(sn == 1){
            printf("Email: ");
            gets(vet[i].email);
            fflush(stdin);
            minusculo(vet[i].email);
          }
        }
      }
    }
  }
}

int remover(Contato *vet, int pos){
  if(pos == 0){
    printf("Nenhum contato na agenda!\n");
    return 0;
  }
  else{
    int op, sn=0;
    mostrar(vet, pos);

    do{
      printf("\nDigite o codigo do contato que deseja remover.");
      printf("\n(Caso nao deseje mais remover digite 0): ");
      scanf("%d", &op);

      if(op == 0){
        sn++;
      }
      else{
        for(int i=0; i<pos; i++){
          if(op == vet[i].codigo){
            sn++;
          }
        }
      }
    }while(sn == 0);

    if(op == 0){
      return op;
    }
    else{
      for(int i=0; i<pos; i++){
        if(op == vet[i].codigo){
          for(int y=i; y<pos; y++){
            vet[y] = vet[y+1];
          }
        }
      }
      return op;
    }
  }
}

void vetaux(Contato *vet, Contato *vet2, int pos){
  for(int i=0; i<pos; i++){
    vet2[i] = vet[i];
  }
}