#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#include "funcao.h"
#include "pesq_email_ArvB.h"

No3* novoNo3(Contato x){
  No3* novo = (No3*) malloc(sizeof(No3));
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

No3* raiz;

void start3(){
  raiz = NULL;
}

void inserirAB3(Contato *vet, int pos){
  for(int i=0; i<pos; i++){
    inserirRecAB3(vet[i], &raiz);
  }
}

void inserirRecAB3(Contato x, No3** i){
  if(*i == NULL){
    *i = novoNo3(x);
  }
  else if(strcmp(x.email, (*i)->cont.em) < 0){
    inserirRecAB3(x, &((*i)->esq));
  }
  else if(strcmp(x.email, (*i)->cont.em) > 0){
    inserirRecAB3(x, &((*i)->dir));
  }
}

void caminharCentral3(){
  caminharCentralRec3(raiz);
}

void caminharCentralRec3(No3* i){
  if (i != NULL){
    caminharCentralRec3(i->esq);
    printf("\nCogido: %d\n", i->cont.cod);
    printf("Nome = %s\n", i->cont.nom);
    printf("Data de nascimento = %d/%d/%d\n", i->cont.dd, i->cont.mm, i->cont.aa);
    printf("Celular = %s\n", i->cont.cel);
    printf("Email = %s\n", i->cont.em);
    caminharCentralRec3(i->dir);
  }
}

bool pesquisar3(char email[]){
  return pesquisarRec3(email, raiz);
}

bool pesquisarRec3(char email[], No3* i){
  bool resp;

  if(i == NULL){
    resp = false;
  }
  else if(strcmp(i->cont.em, email) == 0){
    printf("\nCogido: %d\n", i->cont.cod);
    printf("Nome = %s\n", i->cont.nom);
    printf("Data de nascimento = %d/%d/%d\n", i->cont.dd, i->cont.mm, i->cont.aa);
    printf("Celular = %s\n", i->cont.cel);
    printf("Email = %s\n", i->cont.em);
    resp = true;
  }
  else if(strcmp(i->cont.em, email) > 0){
    resp = pesquisarRec3(email, i->esq);
  }
  else{
    resp = pesquisarRec3(email, i->dir);
  }
  
  return resp;
}