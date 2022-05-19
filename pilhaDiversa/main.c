#include <stdio.h>
#include <stdlib.h>
#include "Stack.h"


int main() {
    // 1 Questão
    stack Stack;
    initStack(&Stack);

    // 2 Questão
    push(&Stack,'j');
    push(&Stack,'a');
    push(&Stack,'a');
    push(&Stack,'a');
    push(&Stack,'p');
    push(&Stack,'w');
    push(&Stack,'o');
    push(&Stack,'x');
    push(&Stack,'b');
    push(&Stack,'y');
    push(&Stack,'b');
    push(&Stack,'v');
    push(&Stack,'k');
    push(&Stack,'i');
    push(&Stack,'d');
    push(&Stack,'f');
    push(&Stack,'o');
    listNodes(&Stack);
    printf("\n");

    // 3º questão
    printf("pop\n");
    free(pop(&Stack));
    listNodes(&Stack);
    printf("\n");

    // 4º questão
    printf("First\n");
    node *first = First(&Stack);
    printf("letra: %c, Index: [%d]\n",first->data,first->index);
    printf("\n");

    // 5º questão
    isEmpty(&Stack);
    printf("\n");

    // 6º Questão
    printf("Lenght\n");
    int lenght = Lenght(&Stack);
    printf("Lenght = %d\n",lenght);
    printf("\n");

    // 7º Questão
    printf("Last\n");
    node *last = Last(&Stack);
    printf("letra: %c, Index: [%d]\n",last->data,last->index);
    printf("\n");

    // 8º Questão
    printf("getValueByIndex\n");
    node *getValueByIndex1 = getValueByIndex(&Stack,2);
    printf("letra: %c, Index: [%d]\n",getValueByIndex1->data,getValueByIndex1->index);
    printf("\n");

    // 9º Questão
    printf("getIndexByValue\n");
    node *getIndexByValue1 = getIndexByValue(&Stack,'a');
    printf("letra: %c, Index: [%d]\n",getIndexByValue1->data,getIndexByValue1->index);
    printf("\n");

    // 10º Questão
    printf("getAllIndexByValue\n");
    int o[Stack.size]; int elementos;
    elementos = getAllIndexByValue(&Stack,'a',&o[0]);
    for(int i = 0; i<elementos;i++){
        printf("a[%d]",o[i]);
        if(elementos > i+1) printf(" - ");
    } printf("\n\n");

    // 11º Questão
    printf("getValuesByIndexs\n");
    char values1[Stack.size];
    int indexs[3] = {11,9,0};
    getValuesByIndexs(&Stack,&indexs[0],3,&values1[0]);
    for(int i = 0; i<3;i++){
        printf("%c[%d]",values1[i],indexs[i]);
        if(3 > i+1) printf(" - ");
    } printf("\n\n");

    // 12º Questão
    printf("getValuesBySlice\n");
    char values[Stack.size]; int repeticoes;
    repeticoes = getValuesBySlice(&Stack,5,2,&values[0]);
    for(int i = 0; i<repeticoes;i++){
        printf("%c[%d]",values[i],5-i);
        if(repeticoes > i+1) printf(" - ");
    } printf("\n\n");

    // 14º Questão
    printf("RemoveByIndex\n");
    removeByIndex(&Stack,4);
    listNodes(&Stack);
    printf("\n");

    // 15º Questão
    printf("RemoveByValue\n");
    removeByValue(&Stack,'v');
    listNodes(&Stack);
    printf("\n");

    // 16º Questão
    printf("RemoveAllByValue\n");
    removeAllByValue(&Stack,'a');
    listNodes(&Stack);
    printf("\n");

    // 17º Questão
    printf("removeAllByIndexes\n");
    int size[3] = {5,2,1};
    removeAllByIndexes(&Stack,&size[0],3);
    listNodes(&Stack);
    printf("\n");

    // 18º Questão
    printf("\n");
    printf("removeAllBySlice\n");
    removeAllBySlice(&Stack,2,5);
    listNodes(&Stack);
    printf("\n");

    // 19º Questão
    printf("setValueInIndex\n");
    setValueInIndex(&Stack,0,'k');
    setValueInIndex(&Stack,3,'p');
    listNodes(&Stack);
    printf("\n");

    // 20º Questão
    printf("setValuesInIndexes\n");
    int p[4] = {0,1,2,3}; char fd[4] = {'q','u','g','h'};
    setValuesInIndexes(&Stack,&p[0],&fd[0],4);
    listNodes(&Stack);
    printf("\n");

    // 13º Questão
    printf("removerAll\n");
    removerAll(&Stack);
    listNodes(&Stack);

    // 5º questão
    isEmpty(&Stack);
    printf("\n");

    getchar();
    return 0;
}
