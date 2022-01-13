#include <stdbool.h>
#include <stdio.h>

#include "funcao.h"
#include "pesq_cod.h"
#include "pesq_cod_ArvB.h"

void pesq_cod(Contato *vet, Contato *vet2, int pos){
  if(pos == 0){
    printf("Nenhum contato na agenda!\n");
  }
  else{
    int opcao;
    menu_pesq();
    printf("Digite a opcao desejada: ");
    scanf("%d", &opcao);

    switch(opcao){
      case 1:
        seq_cod(vet, pos);
        break;
      case 2:
        bin_cod(vet, vet2, pos);
        break;
      case 3:
        arvBin_cod(vet, pos);
        break;
    }
  }
}

void seq_cod(Contato *vet, int pos){
  bool resp = false;
  int cod;

  printf("\nPESQUISA SEQUENCIAL\n");
  printf("\nDigite o codigo do contato que deseja pesquisar: ");
  scanf("%d", &cod);

  for (int i = 0; i < pos; i++){
    if (vet[i].codigo == cod){
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

void ord_cod(Contato *vet, Contato *vet2, int pos){
  vetaux(vet, vet2, pos);

  for(int i=(pos-1); i>0; i--){
    for(int j=0; j<i; j++){
      if(vet2[j].codigo > vet2[j+1].codigo){
        Contato aux = vet2[j];
        vet2[j] = vet2[j+1];
        vet2[j+1] = aux;
      }
    }
  }
}

void bin_cod(Contato *vet, Contato *vet2, int pos){
  ord_cod(vet, vet2, pos);

  bool resp = false;
  int dir = pos - 1, esq = 0, meio;
  int cod;

  printf("\nPESQUISA BINARIA\n");
  printf("\nDigite o codigo do contato que deseja pesquisar: ");
  scanf("%d", &cod);

  while(esq <= dir){
    meio = (esq + dir) / 2;

    if(cod == vet2[meio].codigo){
      printf("\nCodigo = %d\n", vet2[meio].codigo);
      printf("Nome = %s\n", vet2[meio].nome);
      printf("Data de nascimento = %d/%d/%d\n", vet2[meio].dia, vet2[meio].mes, vet2[meio].ano);
      printf("Celular = %s\n", vet2[meio].celular);
      printf("Email = %s\n", vet2[meio].email);
      resp = true;
      esq = pos;
    }
    else if(cod > vet2[meio].codigo){
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

void arvBin_cod(Contato *vet, int pos){
  inserirAB(vet, pos);
  //caminharCentral();
  int cod;

  printf("\nPESQUISA ARVORE BINARIA\n");
  printf("\nDigite o codigo do contato que deseja pesquisar: ");
  scanf("%d", &cod);

  if(pesquisar(cod) == false){
    printf("\nContato nao encontrado!\n");
  }
}