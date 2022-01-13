#include <string.h>
#include <stdio.h>

#include "funcao.h"
#include "ord_data.h"

void ord_data(Contato *vet, Contato *vet2, int pos){
  if(pos == 0){
    printf("Nenhum contato na agenda!\n");
  }
  else{
    vetaux(vet, vet2, pos);
    for(int i=(pos-1); i>0; i--){
      for(int j=0; j<i; j++){
        if(vet2[j].ano > vet2[j+1].ano){
          Contato aux = vet2[j];
          vet2[j] = vet2[j+1];
          vet2[j+1] = aux;
        }
        else if(vet2[j].ano == vet2[j+1].ano){
          if(vet2[j].mes > vet2[j+1].mes){
            Contato aux = vet2[j];
            vet2[j] = vet2[j+1];
            vet2[j+1] = aux;
          }
          else if(vet2[j].mes == vet2[j+1].mes){
            if(vet2[j].dia > vet2[j+1].dia){
              Contato aux = vet2[j];
              vet2[j] = vet2[j+1];
              vet2[j+1] = aux;
            }
          }
        }
      }
    }
  }
}