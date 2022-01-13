#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#include "funcao.h"
#include "pesq_cod_ArvB.h"

No* novoNo(Contato x){
  No* novo = (No*) malloc(sizeof(No));
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

No* raiz;

void start(){
  raiz = NULL;
}

void inserirAB(Contato *vet, int pos){
  for(int i=0; i<pos; i++){
    inserirRecAB(vet[i], &raiz);
  }
}

void inserirRecAB(Contato x, No** i){
  if(*i == NULL){
    *i = novoNo(x);
  }
  else if(x.codigo < (*i)->cont.cod){
    inserirRecAB(x, &((*i)->esq));
  }
  else if(x.codigo > (*i)->cont.cod){
    inserirRecAB(x, &((*i)->dir));
  }
}

void caminharCentral(){
  caminharCentralRec(raiz);
}

void caminharCentralRec(No* i){
  if (i != NULL){
    caminharCentralRec(i->esq);
    caminharCentralRec(i->dir);
    printf("\nCogido: %d\n", i->cont.cod);
    printf("Nome = %s\n", i->cont.nom);
    printf("Data de nascimento = %d/%d/%d\n", i->cont.dd, i->cont.mm, i->cont.aa);
    printf("Celular = %s\n", i->cont.cel);
    printf("Email = %s\n", i->cont.em);
  }
}

bool pesquisar(int x){
  return pesquisarRec(x, raiz);
}

bool pesquisarRec(int x, No* i){
  bool resp;
  
  if(i == NULL){
    resp = false;
  }
  else if(x == i->cont.cod){
    printf("\nCogido: %d\n", i->cont.cod);
    printf("Nome = %s\n", i->cont.nom);
    printf("Data de nascimento = %d/%d/%d\n", i->cont.dd, i->cont.mm, i->cont.aa);
    printf("Celular = %s\n", i->cont.cel);
    printf("Email = %s\n", i->cont.em);
    resp = true;
  }
  else if(x < i->cont.cod){
    resp = pesquisarRec(x, i->esq);
  }
  else{
    resp = pesquisarRec(x, i->dir);
  }
  
  return resp;
}