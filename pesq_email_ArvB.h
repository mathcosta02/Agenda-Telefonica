typedef struct ContatoAux3{
  int cod;
  char nom[50];
  int dd, mm, aa;
  char cel[20];
  char em[50];
}ContatoAux3;

typedef struct No3{
  ContatoAux3 cont;
  struct No3 *esq, *dir;
}No3;

No3* novoNo3(Contato x);

void start3();
void inserirAB3(Contato *vet, int pos);
void inserirRecAB3(Contato x, No3** i);

void caminharCentral3();
void caminharCentralRec3(No3* i);

bool pesquisar3(char email[]);
bool pesquisarRec3(char email[], No3* i);