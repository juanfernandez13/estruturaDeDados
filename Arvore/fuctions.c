#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "tree.h"

//1° Questão
node *inserirNovo(node *origin, int value) {
  if (origin == NULL) {
    node *new = malloc(sizeof(node));
    new->data = value;
    new->left = NULL;
    new->right = NULL;
    return new;
  } else {
    if (origin->data > value)
      origin->left = inserirNovo(origin->left, value);
    if (origin->data < value)
      origin->right = inserirNovo(origin->right, value);
    return origin;
  }
}

//2° Questão
void imprimirPreOrdem(node *origin) {
  if (origin != NULL) {
    printf("%d ", origin->data);
    imprimirPreOrdem(origin->left);
    imprimirPreOrdem(origin->right);
  }
}

//3° Questão
void imprimirInordem(node *origin) {
  if (origin != NULL) {
    imprimirPreOrdem(origin->left);
    printf("%d ", origin->data);
    imprimirPreOrdem(origin->right);
  }
}

//4° Questão
void imprimirPosOrdem(node *origin) {

  if (origin != NULL) {
    imprimirPreOrdem(origin->left);
  }

  if (origin != NULL) {
    imprimirPreOrdem(origin->right);
  }
  if (origin != NULL)
    printf("%d ", origin->data);
}

//5° Questao
int vetor[14];
void imprimirEmNivel(node *origin, int ip) {

  if (origin != NULL) { 
    vetor[ip] = origin->data;
    if (origin->left != NULL) {
      imprimirEmNivel(origin->left, 2 * ip + 1);
    }
    if (origin->right != NULL) {
      imprimirEmNivel(origin->right, 2 * ip + 2);

    }
  }
}
void imprimirInNivel(node *origin){
  imprimirEmNivel(origin,0);
  
  for (int i = 0; i < 15; i++) {
    if (vetor[i] != NULL)
      printf("%d ", vetor[i]);
  }
  printf("\n");
}

//6° Questão
int altura(node *origin) {
  if (origin == NULL || origin->right == NULL && origin->left == NULL)
    return 0;
  else {
    int left = 1 + altura(origin->left);
    int right = 1 + altura(origin->right);
    if (left > right)
      return left;
    return right;
  }
}

//7° Questão
int tamanho(node *origin) {
  if (origin == NULL)
    return 0;
  else
    return 1 + tamanho(origin->left) + tamanho(origin->right);
}

//8° Questão
int quantidade_folhas(node *raiz) {
  if (raiz == NULL)
    return 0;
  else if (raiz->left == NULL && raiz->right == NULL)
    return 1;
  else
    return quantidade_folhas(raiz->left) + quantidade_folhas(raiz->right);
}

//9° Questão
void arvoreCompleta(node *origin){
  //printf("\n%.0f\n",pow(2,4));
  if(pow(2,altura(origin)+1)-1 == tamanho(origin)){
   printf("\narvore completa\n");
  } else printf("\narvore nao completa\n");
}

//10° Questão
int extritamentebinaria(node *origin) {
  if (origin != NULL) {
    if (origin->right == NULL && origin->left != NULL || origin->right != NULL && origin->left == NULL)
      return 1;

    return extritamentebinaria(origin->left) &&
           extritamentebinaria(origin->right);
  }
  return 0;
}


int buscar(node *origin, int value) {
  if (origin == NULL) {
    return -1;
  } else {
    if (origin->data == value)
      return origin->data;
    else {
      if (value < origin->data)
        buscar(origin->left, value);
      else
        buscar(origin->right, value);
    }
  }
}

node *remover(node *origin, int chave) {
  if (origin == NULL) {
    printf("Valor nao encontrado!\n");
    return NULL;
  } else {

    if (origin->data == chave) {
      // remove nós folhas (nós sem filhos)
      if (origin->left == NULL && origin->right == NULL) {
        free(origin);
        return NULL;
      } else {
        // remover nós que possuem 2 filhos
        if (origin->left != NULL && origin->right != NULL) {
          node *aux = origin->left;
          while (aux->right != NULL)
            aux = aux->right;
          origin->data = aux->data;
          aux->data = chave;
          origin->left = remover(origin->left, chave);
          return origin;
        } else {
          // remover nós que possuem apenas 1 filho
          node *aux;
          if (origin->left != NULL)
            aux = origin->left;
          else
            aux = origin->right;
          free(origin);
          return aux;
        }
      }
    } else {
      if (chave < origin->data)
        origin->left = remover(origin->left, chave);
      else
        origin->right = remover(origin->right, chave);
      return origin;
    }
  }
}