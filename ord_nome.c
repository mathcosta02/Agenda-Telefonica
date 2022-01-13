#include <string.h>
#include <stdio.h>

#include "funcao.h"
#include "ord_nome.h"

void ord_nome(Contato *vet, Contato *vet2, int pos){
  if(pos == 0){
    printf("Nenhum contato na agenda!\n");
  }
  else{
    vetaux(vet, vet2, pos);
    for(int i=(pos-1); i>0; i--){
      for(int j=0; j<i; j++){
        if(strcmp(vet2[j].nome, vet2[j+1].nome) > 0){
          Contato aux = vet2[j];
          vet2[j] = vet2[j+1];
          vet2[j+1] = aux;
        }
      }
    }
  }
}