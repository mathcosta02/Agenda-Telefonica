#include <stdio.h>
#include <stdlib.h>

#include "funcao.h"
#include "ord_nome.h"
#include "ord_data.h"
#include "pesq_cod.h"
#include "pesq_nome.h"
#include "pesq_data.h"
#include "pesq_email.h"

void grava_arqB(Contato *vet, int quant){
  FILE *pontArq;

  pontArq = fopen("binario.txt", "wb");

  if(pontArq){
    fprintf(pontArq, "%d\n", quant);
    fwrite(vet, sizeof(Contato), quant, pontArq);
    fclose(pontArq);
  }
  else{
    printf("\nErro\n");
  }
}

int le_arqB(Contato *vet, int quant){
  FILE *pontArq;

  pontArq = fopen("binario.txt", "rb");

  if(pontArq){
    fscanf(pontArq, "%d\n", &quant);
    fread(vet, sizeof(Contato), quant, pontArq);
    fclose(pontArq);
    return quant;
  }
  else{
    printf("\nErro\n");
    fclose(pontArq);
    return 0;
  }
}

int main(void){
  int N = 100;
  int opcao;
  Contato *vet = malloc(N*sizeof(Contato));
  Contato *vet2 = malloc(N*sizeof(Contato));

  int pos = le_arqB(vet, 0);

  do{
    menu();
    printf("Digite a opcao desejada: ");
    scanf("%d", &opcao);
    fflush(stdin);
    printf("\n");

    switch(opcao){
      case 1:
        inserir(vet, pos);
        pos++;
        break;
      case 2:
        editar(vet, pos);
        break;
      case 3:
        if(remover(vet, pos) != 0){
          pos--;
        }
        break;
      case 4:
        ord_nome(vet, vet2, pos);
        mostrar(vet2, pos);
        break;
      case 5:
        ord_data(vet, vet2, pos);
        mostrar(vet2, pos);
        break;
      case 6:
        pesq_cod(vet, vet2, pos);
        break;
      case 7:
        pesq_nome(vet, vet2, pos);
        break;
      case 8:
        pesq_data(vet, vet2, pos);
        break;
      case 9:
        pesq_email(vet, vet2, pos);
        break;
      default:
        if(opcao == 0){
          printf("Agenda fechada!\n");
        }
        else{
          printf("Opcao invalida!\n");
        }
    }

    pause();
    system("clear");
  }while(opcao != 0);

  grava_arqB(vet, pos);
  free(vet);
  return 0;
}