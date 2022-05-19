#include <stdio.h>
#include <stdlib.h>
#include "Queue.h"

int main() {
    // 1º Questão
    queue Queue;
    initQueue(&Queue);

    // 2 Questão
    printf("Insert\n");
    insert(&Queue,'f');
    insert(&Queue,'e');
    insert(&Queue,'j');
    insert(&Queue,'f');
    insert(&Queue,'b');
    insert(&Queue,'h');
    insert(&Queue,'h');
    insert(&Queue,'h');
    insert(&Queue,'h');
    insert(&Queue,'d');
    insert(&Queue,'s');
    insert(&Queue,'a');
    insert(&Queue,'v');
    insert(&Queue,'h');
    insert(&Queue,'n');
    insert(&Queue,'x');
    insert(&Queue,'u');
    listNodes(&Queue);

    // 3º questão
    printf("\nRemove\n");
    Remove(&Queue);
    listNodes(&Queue);
    printf("\n");

    // 4º questão
    node *first = First(&Queue);
    printf("First: %c[%d]\n",first->data,first->index);
    printf("\n");

    // 5º questão
    isEmpty(&Queue);
    printf("\n");

    // 6º Questão
    printf("Lenght\n");
    printf("Lenght = %d\n",lenght(&Queue));
    printf("\n");

    // 7º Questão
    printf("Last\n");
    node *last = Last(&Queue);
    printf("Last: %c[%d]\n",last->data,last->index);
    printf("\n");
  
    // 8º Questão
    printf("getValueByIndex\n");
    node *getValueByIndex1 = GetValueByIndex(&Queue,2);
    printf("letra: %c[%d]\n",getValueByIndex1->data,getValueByIndex1->index);
    printf("\n");

    // 9º Questão
    printf("getIndexByValue\n");
    node *getIndexByValue1 = GetIndexByValue(&Queue,'d');
    printf("letra: %c[%d]\n",getIndexByValue1->data,getIndexByValue1->index);
    printf("\n");

  // 10º Questão
    printf("getAllIndexByValue\n");
    int o[Queue.size]; int elementos; char letra ='h';
    elementos = GetAllIndexByValue(&Queue,letra,&o[0]);
    for(int i = 0; i<elementos;i++){
        printf("%c[%d]",letra,o[i]);
        if(elementos > i+1) printf(" - ");
    } printf("\n\n");

  // 11º Questão
    printf("getValuesByIndexs\n");
    char values1[Queue.size];
    int indexs[3] = {0,9,11};
    GetValuesByIndexs(&Queue,&indexs[0],3,&values1[0]);
    for(int i = 0; i<3;i++){
        printf("%c[%d]",values1[i],indexs[i]);
        if(3 > i+1) printf(" - ");
    } printf("\n\n");

  // 12º Questão
    printf("getValuesBySlice\n");
    char values[Queue.size]; int repeticoes; int inicio = 4;
    repeticoes = GetValuesBySlice(&Queue,inicio,6,&values[0]);
    for(int i = 0; i<repeticoes;i++){
        printf("%c[%d]",values[i],inicio+i);
        if(repeticoes > i+1) printf(" - ");
    } printf("\n\n");

    // 14º Questão
    listNodes(&Queue);
    printf("RemoveByIndex\n");
    removeByIndex(&Queue,3);
    listNodes(&Queue);
    printf("\n");

    // 15º Questão
    printf("RemoveByValue\n");
    removeByValue(&Queue,'v');
    listNodes(&Queue);
    printf("\n");

    // 16º Questão
    printf("RemoveAllByValue\n");
    removeAllByValue(&Queue,'h');
    listNodes(&Queue);
    printf("\n");

    // 17º Questão
    printf("removeAllByIndexes\n");
    int size[3] = {5,2,1};
    removeAllByIndexes(&Queue,&size[0],3);
    listNodes(&Queue);
    printf("\n");

    // 18º Questão
    printf("removeAllBySlice\n");
    removeAllBySlice(&Queue,3,5);
    listNodes(&Queue);
    printf("\n");

    insert(&Queue,'h');
    insert(&Queue,'d');
    insert(&Queue,'s');
    insert(&Queue,'a');
    insert(&Queue,'v');
    insert(&Queue,'h');
    insert(&Queue,'n');
    insert(&Queue,'x');
    insert(&Queue,'u');

    // 19º Questão
    printf("setValueInIndex\n");
    setValueInIndex(&Queue,0,'k');
    setValueInIndex(&Queue,8,'p');
    listNodes(&Queue);
    printf("\n");

    // 20º Questão
    printf("setValuesInIndexes\n");
    int p[4] = {2,6,8,11}; char fd[4] = {'q','u','g','h'};
    setValuesInIndexes(&Queue,&p[0],&fd[0],4);
    listNodes(&Queue);
    printf("\n");
  
    // 13º Questão
    printf("removerAll");
    removerAll(&Queue);
    listNodes(&Queue);

    // 5º questão
    isEmpty(&Queue);
    printf("\n");
   
}
