typedef struct ContatoAux2{
  int cod;
  char nom[50];
  int dd, mm, aa;
  char cel[20];
  char em[50];
}ContatoAux2;

typedef struct No2{
  ContatoAux2 cont;
  struct No2 *esq, *dir;
}No2;

No2* novoNo2(Contato x);

void start2();
void inserirAB2(Contato *vet, int pos);
void inserirRecAB2(Contato x, No2** i);

void caminharCentral2();
void caminharCentralRec2(No2* i);

bool pesquisar2(char nome[]);
bool pesquisarRec2(char nome[], No2* i);