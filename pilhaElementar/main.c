#include <stdio.h>
#include <stdlib.h>
#include "Stack.h"

int main(void) {
    // 1 Questão
    stack Stack;
    initStack(&Stack);

    // 2 Questão
    printf("Push\n");
    push(&Stack,'j');
    push(&Stack,'a');
    push(&Stack,'v');
    push(&Stack,'h');
    push(&Stack,'o');
    push(&Stack,'o');
    push(&Stack,'o');
    push(&Stack,'p');
    push(&Stack,'y');
    push(&Stack,'g');
    push(&Stack,'r');
    push(&Stack,'n');
    push(&Stack,'m');
    push(&Stack,'d');
    push(&Stack,'k');
    listNodes(&Stack);

    // 3º questão
    printf("pop\n");
    free(pop(&Stack));
    listNodes(&Stack);
    printf("\n");

    // 4º questão
    node *first = First(&Stack);
    printf("First: %c\n",first->data);

    // 5º questão
    isEmpty(&Stack);

    // 6º Questão
    printf("Lenght: %d\n",Lenght(&Stack));

    // 7º Questão
    node *last = Last(&Stack);
    printf("Last: %c\n",last->data);
    printf("\n");

    // 8º Questão
    node *getValueByIndex = GetValueByIndex(&Stack,3);
    printf("GetValueByIndex: %c\n",getValueByIndex->data);
    printf("\n");

    // 9º Questão
    char value9 = 'd'; int getIndexByValue = GetIndexByValue(&Stack,value9);
    printf("GetIndexByValue: %c[%d]\n",value9,getIndexByValue);
    printf("\n");

    // 10º Questão
    printf("getAllIndexByValue:");
    int indexs[Lenght(&Stack)]; char value10 = 'o';
    int repeticoes1 = GetAllIndexByValue(&Stack,value10,&indexs[0]);
    for (int i = repeticoes1-1; i >= 0; --i) {
        printf("%c[%d]",value10,indexs[i]);
        if(i != 0) printf(" - ");
    }   printf("\n");

    // 11º Questão
    char values11[3];   int indexs1[4] = {1,2,4};
    getValuesByIndexs(&Stack,&indexs1[0],&values11[0]);
    printf("GetValuesByIndexs: ");
    for (int i = 2; i>=0; --i) {
        printf("%c[%d]",values11[i],indexs1[i]);
        if(i != 0) printf(" - ");
    }printf("\n\n");

    // 12º Questão
    printf("getValuesBySlice: ");
    char GetValuesBySlice[Lenght(&Stack)]; int repeticoes;
    repeticoes = getValuesBySlice(&Stack,6,0,&GetValuesBySlice[0]);
    for(int i = 0; i<repeticoes;i++){
        printf("%c[%d]",GetValuesBySlice[i],6-i);
        if(repeticoes > i+1) printf(" - ");
    } printf("\n\n");
    listNodes(&Stack);

    // 14º Questão
    printf("\nRemoveByIndex\n");
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
    removeAllByValue(&Stack,'o');
    listNodes(&Stack);
    printf("\n");

    // 17º Questão
    printf("removeAllByIndexes\n");
    int size[3] = {5,2,1};
    removeAllByIndexes(&Stack,&size[0],3);
    listNodes(&Stack);
    printf("\n");

    // 18º Questão
    printf("removeAllBySlice\n");
    removeAllBySlice(&Stack,5,2);
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
    removeAll(&Stack);
    listNodes(&Stack);

    // 5º questão
    isEmpty(&Stack);
    printf("\n");

    return 0;
}