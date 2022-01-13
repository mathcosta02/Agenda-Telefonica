typedef struct ContatoAux{
  int cod;
  char nom[50];
  int dd, mm, aa;
  char cel[20];
  char em[50];
}ContatoAux;

typedef struct No{
  ContatoAux cont;
  struct No *esq, *dir;
}No;

No* novoNo(Contato x);

void start();
void inserirAB(Contato *vet, int pos);
void inserirRecAB(Contato x, No** i);

void caminharCentral();
void caminharCentralRec(No* i);

bool pesquisar(int x);
bool pesquisarRec(int x, No* i);