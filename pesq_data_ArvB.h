typedef struct ContatoAux1{
  int cod;
  char nom[50];
  int dd, mm, aa;
  char cel[20];
  char em[50];
}ContatoAux1;

typedef struct No1{
  ContatoAux1 cont;
  struct No1 *esq, *dir;
}No1;

No1* novoNo1(Contato x);

void start1();
void inserirAB1(Contato *vet, int pos);
void inserirRecAB1(Contato x, No1** i);

void caminharCentral1();
void caminharCentralRec1(No1* i);

bool pesquisar1(int dd, int mm, int aa);
bool pesquisarRec1(int dd, int mm, int aa, No1* i);