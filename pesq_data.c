#include <stdbool.h>
#include <stdio.h>

#include "funcao.h"
#include "ord_data.h"
#include "pesq_data.h"
#include "pesq_data_ArvB.h"

void pesq_data(Contato *vet, Contato *vet2, int pos){
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
        seq_data(vet, pos);
        break;
      case 2:
        bin_data(vet, vet2, pos);
        break;
      case 3:
        arvBin_data(vet, pos);
        break;
    }
  }
}

void seq_data(Contato *vet, int pos){
  bool resp = false;
  int dd, mm, aa;

  printf("\nPESQUISA SEQUENCIAL\n");
  printf("\nDigite a data de nascimento do contato que deseja pesquisar (dd mm aaaa): ");
  scanf("%d %d %d", &dd, &mm, &aa);

  for (int i = 0; i < pos; i++){
    if (vet[i].dia == dd && vet[i].mes == mm && vet[i].ano == aa){
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

void bin_data(Contato *vet, Contato *vet2, int pos){
  ord_data(vet, vet2, pos);

  bool resp = false;
  int dir = pos - 1, esq = 0, meio;
  int dd, mm, aa;

  printf("\nPESQUISA BINARIA\n");
  printf("\nDigite a data de nascimento do contato que deseja pesquisar (dd mm aaaa): ");
  scanf("%d %d %d", &dd, &mm, &aa);

  while(esq <= dir){
    meio = (esq + dir) / 2;

    if(vet2[meio].ano == aa){
      
      if(vet2[meio].mes == mm){
        
        if(vet2[meio].dia == dd){
          printf("\nCodigo = %d\n", vet2[meio].codigo);
          printf("Nome = %s\n", vet2[meio].nome);
          printf("Data de nascimento = %d/%d/%d\n", vet2[meio].dia, vet2[meio].mes, vet2[meio].ano);
          printf("Celular = %s\n", vet2[meio].celular);
          printf("Email = %s\n", vet2[meio].email);
          resp = true;
          esq = pos;
        }
        else if(dd > vet2[meio].dia){
          esq = meio + 1;
        }
        else{
          dir = meio - 1;
        }
      }
      else if(mm > vet2[meio].mes){
        esq = meio + 1;
      }
      else{
        dir = meio - 1;
      }
    }
    else if(aa > vet2[meio].ano){
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

void arvBin_data(Contato *vet, int pos){
  inserirAB1(vet, pos);
  int dd, mm, aa;

  printf("\nPESQUISA ARVORE BINARIA\n");
  printf("\nDigite a data de nascimento do contato que deseja pesquisar (dd mm aaaa): ");
  scanf("%d %d %d", &dd, &mm, &aa);

  if(pesquisar1(dd, mm, aa) == false){
    printf("\nContato nao encontrado!\n");
  }
}