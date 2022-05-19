#include "tree.h"
#include <stdio.h>
int main() {

  //1° Questão
  Btree arv;
  arv.origin = NULL;
  arv.origin = inserirNovo(arv.origin, 6);
  arv.origin = inserirNovo(arv.origin, 4);
  arv.origin = inserirNovo(arv.origin, 9);
  arv.origin = inserirNovo(arv.origin, 3);
  arv.origin = inserirNovo(arv.origin, 1);
  arv.origin = inserirNovo(arv.origin, 5);
  arv.origin = inserirNovo(arv.origin, 1);
  arv.origin = inserirNovo(arv.origin, 9);
  arv.origin = inserirNovo(arv.origin, 12);
  arv.origin = inserirNovo(arv.origin, 11);
  arv.origin = inserirNovo(arv.origin, 15);

  //2° Questão
  printf("\npre ordem\n");
  imprimirPreOrdem(arv.origin);

  //3° Questão
  printf("\nIn ordem\n");
  imprimirInordem(arv.origin);

  //4° Questão
  printf("\npos ordem\n");
  imprimirPosOrdem(arv.origin);

  //5° Questão
  printf("\nEm nível\n");
  imprimirInNivel(arv.origin);

  //6° Questão
  printf("\nAltura da árvore: %d\n",altura(arv.origin));

  //7° Questão
  printf("\nFolhas da árvore: %d\n",quantidade_folhas(arv.origin));

  //8° Questão
  printf("\nTamanho da árvore: %d\n",tamanho(arv.origin));
  
  //9° Questão
  arvoreCompleta(arv.origin);
  
  //10° Questão
  if (extritamentebinaria(arv.origin) != 0)
    printf("\nNao e extritamente binaria\n");
  else
    printf("\nextritamente binaria\n");
}
