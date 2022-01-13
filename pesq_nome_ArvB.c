#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#include "funcao.h"
#include "pesq_nome_ArvB.h"

No2* novoNo2(Contato x){
  No2* novo = (No2*) malloc(sizeof(No2));
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

No2* raiz;

void start2(){
  raiz = NULL;
}

void inserirAB2(Contato *vet, int pos){
  for(int i=0; i<pos; i++){
    inserirRecAB2(vet[i], &raiz);
  }
}

void inserirRecAB2(Contato x, No2** i){
  if(*i == NULL){
    *i = novoNo2(x);
  }
  else if(strcmp(x.nome, (*i)->cont.nom) < 0){
    inserirRecAB2(x, &((*i)->esq));
  }
  else if(strcmp(x.nome, (*i)->cont.nom) > 0){
    inserirRecAB2(x, &((*i)->dir));
  }
}

void caminharCentral2(){
  caminharCentralRec2(raiz);
}

void caminharCentralRec2(No2* i){
  if (i != NULL){
    caminharCentralRec2(i->esq);
    printf("\nCogido: %d\n", i->cont.cod);
    printf("Nome = %s\n", i->cont.nom);
    printf("Data de nascimento = %d/%d/%d\n", i->cont.dd, i->cont.mm, i->cont.aa);
    printf("Celular = %s\n", i->cont.cel);
    printf("Email = %s\n", i->cont.em);
    caminharCentralRec2(i->dir);
  }
}

bool pesquisar2(char nome[]){
  return pesquisarRec2(nome, raiz);
}

bool pesquisarRec2(char nome[], No2* i){
  bool resp;

  if(i == NULL){
    resp = false;
  }
  else if(strcmp(i->cont.nom, nome) == 0){
    printf("\nCogido: %d\n", i->cont.cod);
    printf("Nome = %s\n", i->cont.nom);
    printf("Data de nascimento = %d/%d/%d\n", i->cont.dd, i->cont.mm, i->cont.aa);
    printf("Celular = %s\n", i->cont.cel);
    printf("Email = %s\n", i->cont.em);
    resp = true;
  }
  else if(strcmp(i->cont.nom, nome) > 0){
    resp = pesquisarRec2(nome, i->esq);
  }
  else{
    resp = pesquisarRec2(nome, i->dir);
  }
  
  return resp;
}