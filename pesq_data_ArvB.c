#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#include "funcao.h"
#include "pesq_data_ArvB.h"

No1* novoNo1(Contato x){
  No1* novo = (No1*) malloc(sizeof(No1));
  novo->cont.cod = x.codigo;
  novo->cont.dd = x.dia;
  novo->cont.mm = x.mes;
  novo->cont.aa = x.ano;
  strcpy(novo->cont.nom, x.nome);
  strcpy(novo->cont.cel, x.celular);
  strcpy(novo->cont.em, x.email);
  novo->esq = NULL;
  novo->dir = NULL;
  return novo;
}

No1* raiz;

void start1(){
  raiz = NULL;
}

void inserirAB1(Contato *vet, int pos){
  for(int i=0; i<pos; i++){
    inserirRecAB1(vet[i], &raiz);
  }
}

void inserirRecAB1(Contato x, No1** i){
  if(*i == NULL){
    *i = novoNo1(x);
  }
  else if(x.ano < (*i)->cont.aa){
    inserirRecAB1(x, &((*i)->esq));
  }
  else if(x.ano > (*i)->cont.aa){
    inserirRecAB1(x, &((*i)->dir));
  }
  else{
    if(x.mes < (*i)->cont.mm){
      inserirRecAB1(x, &((*i)->esq));
    }
    else if(x.mes > (*i)->cont.mm){
      inserirRecAB1(x, &((*i)->dir));
    }
    else{
      if(x.dia < (*i)->cont.dd){
        inserirRecAB1(x, &((*i)->esq));
      }
      else if(x.dia > (*i)->cont.dd){
        inserirRecAB1(x, &((*i)->dir));
      }
    }
  }
}

void caminharCentral1(){
  caminharCentralRec1(raiz);
}

void caminharCentralRec1(No1* i){
  if (i != NULL){
    caminharCentralRec1(i->esq);
    printf("\nCogido: %d\n", i->cont.cod);
    printf("Nome = %s\n", i->cont.nom);
    printf("Data de nascimento = %d/%d/%d\n", i->cont.dd, i->cont.mm, i->cont.aa);
    printf("Celular = %s\n", i->cont.cel);
    printf("Email = %s\n", i->cont.em);
    caminharCentralRec1(i->dir);
  }
}

bool pesquisar1(int dd, int mm, int aa){
  return pesquisarRec1(dd, mm, aa, raiz);
}

bool pesquisarRec1(int dd, int mm, int aa, No1* i){
  bool resp;

  if(i == NULL){
    resp = false;
  }
  else if(aa == i->cont.aa && mm == i->cont.mm && dd == i->cont.dd){
    printf("\nCogido: %d\n", i->cont.cod);
    printf("Nome = %s\n", i->cont.nom);
    printf("Data de nascimento = %d/%d/%d\n", i->cont.dd, i->cont.mm, i->cont.aa);
    printf("Celular = %s\n", i->cont.cel);
    printf("Email = %s\n", i->cont.em);
    resp = true;
  }
  else if(aa < i->cont.aa){
    resp = pesquisarRec1(dd, mm, aa, i->esq);
  }
  else if(aa > i->cont.aa){
    resp = pesquisarRec1(dd, mm, aa, i->dir);
  }
  else{
    if(mm < i->cont.mm){
      resp = pesquisarRec1(dd, mm, aa, i->esq);
    }
    else if(mm > i->cont.mm){
      resp = pesquisarRec1(dd, mm, aa, i->dir);
    }
    else{
      if(dd < i->cont.dd){
        resp = pesquisarRec1(dd, mm, aa, i->esq);
      }
      else if(dd > i->cont.dd){
        resp = pesquisarRec1(dd, mm, aa, i->dir);
      }
    }
  }
  return resp;
}