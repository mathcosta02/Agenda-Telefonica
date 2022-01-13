#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

#include "funcao.h"
#include "pesq_email.h"
#include "pesq_email_ArvB.h"

void pesq_email(Contato *vet, Contato *vet2, int pos){
  if(pos == 0){
    printf("Nenhum contato na agenda!\n");
  }
  else{
    int opcao;
    menu_pesq();
    printf("Digite a opcao desejada: ");
    scanf("%d", &opcao);
    getchar();

    switch(opcao){
      case 1:
        seq_email(vet, pos);
        break;
      case 2:
        bin_email(vet, vet2, pos);
        break;
      case 3:
        arvBin_email(vet, pos);
        break;
    }
  }
}

void seq_email(Contato *vet, int pos){
  bool resp = false;
  char email[50];

  printf("\nPESQUISA SEQUENCIAL\n");
  printf("\nDigite o email do contato que deseja pesquisar: ");
  gets(email);
  fflush(stdin);
  minusculo(email);

  for (int i = 0; i < pos; i++){
    if (strcmp(vet[i].email, email) == 0){
      printf("\nCodigo = %d\n", vet[i].codigo);
      printf("Nome = %s\n", vet[i].nome);
      printf("Data de nascimento = %d/%d/%d\n", vet[i].dia, vet[i].mes, vet[i].ano);
      printf("Celular = %s\n", vet[i].celular);
      printf("Email = %s\n", vet[i].email);
      resp = true;
      i = pos;
    }
  }

  if(resp == false){
    printf("\nContato nao encontrado!\n");
  }
}

void ord_email(Contato *vet, Contato *vet2, int pos){
  vetaux(vet, vet2, pos);

  for(int i=(pos-1); i>0; i--){
    for(int j=0; j<i; j++){
      if(strcmp(vet2[j].email, vet2[j+1].email) > 0){
        Contato aux = vet2[j];
        vet2[j] = vet2[j+1];
        vet2[j+1] = aux;
      }
    }
  }
}

void bin_email(Contato *vet, Contato *vet2, int pos){
  ord_email(vet, vet2, pos);

  bool resp = false;
  int dir = pos - 1, esq = 0, meio;
  char email[50];
  
  printf("\nPESQUISA BINARIA\n");
  printf("\nDigite o email do contato que deseja pesquisar: ");
  gets(email);
  fflush(stdin);
  minusculo(email);

  while(esq <= dir){
    meio = (esq + dir) / 2;

    if(strcmp(vet2[meio].email, email) == 0){
      printf("\nCodigo = %d\n", vet2[meio].codigo);
      printf("Nome = %s\n", vet2[meio].nome);
      printf("Data de nascimento = %d/%d/%d\n", vet2[meio].dia, vet2[meio].mes, vet2[meio].ano);
      printf("Celular = %s\n", vet2[meio].celular);
      printf("Email = %s\n", vet2[meio].email);
      resp = true;
      esq = pos;
    }
    else if(strcmp(vet2[meio].email, email) < 0){
      esq = meio + 1;
    } 
    else{
      dir = meio - 1;
    }
  }

  if(resp == false){
    printf("\nContato nao encontrado!\n");
  }
}

void arvBin_email(Contato *vet, int pos){
  inserirAB3(vet, pos);
  char email[50];

  printf("\nPESQUISA ARVORE BINARIA\n");
  printf("\nDigite o email do contato que deseja pesquisar: ");
  gets(email);
  fflush(stdin);
  minusculo(email);

  if(pesquisar3(email) == false){
    printf("\nContato nao encontrado!\n");
  }
}