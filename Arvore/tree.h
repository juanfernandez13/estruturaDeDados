typedef struct node {
  int data;
  struct node *left, *right;
  short altura;
} node;

typedef struct Btree {
  node *origin;
} Btree;

//1° Questão
node *inserirNovo(node *origin, int value);
//2° Questão
void imprimirPreOrdem(node *origin);
//3° Questão
void imprimirInordem(node *origin);
//4° Questão
void imprimirPosOrdem(node *origin);
//5° Questão
void imprimirInNivel(node *origin);
void imprimirEmNivel(node *origin, int ip);
//6° Questão
int tamanho(node *origin);
//7° Questão
int altura(node *origin);
//8° Questão
int quantidade_folhas(node *raiz);
//9° Questão
void arvoreCompleta(node *origin);
//10° Questão
int extritamentebinaria(node *origin);

//Extras
int buscar(node *origin, int value);
node *remover(node *origin, int chave);

