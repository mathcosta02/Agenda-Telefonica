typedef struct Contato{
  int codigo;
  char nome[50];
  int dia, mes, ano;
  char celular[20];
  char email[50];
}Contato;

void pause();

void menu();

void menu_pesq();

void maiusculo(char s1[]);

void minusculo(char s1[]);

void inserir(Contato *vet, int pos);

void mostrar(Contato *vet, int pos);

void editar(Contato *vet, int pos);

int remover(Contato *vet, int pos);

void vetaux(Contato *vet, Contato *vet2, int pos);