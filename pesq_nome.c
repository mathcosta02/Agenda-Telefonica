#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

#include "funcao.h"
#include "ord_nome.h"
#include "pesq_nome.h"
#include "pesq_nome_ArvB.h"

void pesq_nome(Contato *vet, Contato *vet2, int pos){
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
        seq_nome(vet, pos);
        break;
      case 2:
        bin_nome(vet, vet2, pos);
        break;
      case 3:
        arvBin_nome(vet, pos);
        break;
    }
  }
}

void seq_nome(Contato *vet, int pos){
  bool resp = false;
  char nome[50];
  
  printf("\nPESQUISA SEQUENCIAL\n");
  printf("\nDigite o nome do contato que deseja pesquisar: ");
  gets(nome);
  fflush(stdin);
  maiusculo(nome);

  for (int i = 0; i < pos; i++){
    if (strcmp(vet[i].nome, nome) == 0){
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

void bin_nome(Contato *vet, Contato *vet2, int pos){
  ord_nome(vet, vet2, pos);

  bool resp = false;
  int dir = pos - 1, esq = 0, meio;
  char nome[50];
  
  printf("\nPESQUISA BINARIA\n");
  printf("\nDigite o nome do contato que deseja pesquisar: ");
  gets(nome);
  fflush(stdin);
  maiusculo(nome);

  while(esq <= dir){
    meio = (esq + dir) / 2;

    if(strcmp(vet2[meio].nome, nome) == 0){
      printf("\nCodigo = %d\n", vet2[meio].codigo);
      printf("Nome = %s\n", vet2[meio].nome);
      printf("Data de nascimento = %d/%d/%d\n", vet2[meio].dia, vet2[meio].mes, vet2[meio].ano);
      printf("Celular = %s\n", vet2[meio].celular);
      printf("Email = %s\n", vet2[meio].email);
      resp = true;
      esq = pos;
    }
    else if(strcmp(vet2[meio].nome, nome) < 0){
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

void arvBin_nome(Contato *vet, int pos){
  inserirAB2(vet, pos);
  char nome[50];

  printf("\nPESQUISA ARVORE BINARIA\n");
  printf("\nDigite o nome do contato que deseja pesquisar: ");
  gets(nome);
  fflush(stdin);
  maiusculo(nome);

  if(pesquisar2(nome) == false){
    printf("\nContato nao encontrado!\n");
  }
}