#include <stdio.h>
#include <stdlib.h>
#include "Queue.h"


int main() {
    queue Queue;
    initQueue(&Queue);
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

    // 3º questão
    printf("\nRemove\n");
    Remove(&Queue);
    listNodes(&Queue);
    printf("\n");

    // 4º questão
    node *first = First(&Queue);
    printf("First: %c[0]\n",first->data);
    printf("\n");

    // 5º questão
    isEmpty(&Queue);
    printf("\n");

    // 6º Questão
    printf("Lenght = %d\n",lenght(&Queue));
    printf("\n");

    // 7º Questão
    node *last = Last(&Queue);
    printf("Last: %c[%d]\n",last->data,lenght(&Queue)-1);
    printf("\n");

    // 8º Questão
    printf("getValueByIndex\n");
    node *getValueByIndex1 = GetValueByIndex(&Queue,2);
    printf("letra: %c[2]\n",getValueByIndex1->data);
    printf("\n");


    // 9º Questão
     printf("getIndexByValue\n");
     printf("letra: j[%d]\n",GetIndexByValue(&Queue,'j'));
     printf("\n");

    // 10º Questão
    printf("getAllIndexByValue\n");
    int o[lenght(&Queue)]; int elementos; char letra ='h';
    elementos = GetAllIndexByValue(&Queue,letra,&o[0]);
    for(int i = 0; i<elementos;i++){
        printf("%c[%d]",letra,o[i]);
        if(elementos > i+1) printf(" - ");
    } printf("\n\n");

    // 11º Questão
    printf("getValuesByIndexs\n");
    char values1[lenght(&Queue)];
    int indexs[3] = {0,1,2};
    getValuesByIndexs(&Queue,&indexs[0],&values1[0]);
    for(int i = 0; i<3;i++){
        printf("%c[%d]",values1[i],indexs[i]);
        if(3 > i+1) printf(" - ");
    } printf("\n\n");

    // 12º Questão
    printf("getValuesBySlice\n");
    char GetValuesBySlice[lenght(&Queue)]; int repeticoes;
    repeticoes = getValuesBySlice(&Queue,4,0,&GetValuesBySlice[0]);
    for(int i = repeticoes-1; i>= 0;i--){
        printf("%c[%d]",GetValuesBySlice[i],repeticoes-i-1);
        if(i > 0) printf(" - ");
    } printf("\n\n");

    listNodes(&Queue);

    // 14º Questão
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
    removeAllBySlice(&Queue,1,0);
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
    setValueInIndex(&Queue,8,'1');
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
    removeAll(&Queue);
    listNodes(&Queue);

    // 5º questão
    isEmpty(&Queue);
    printf("\n");
    return 0;
}
