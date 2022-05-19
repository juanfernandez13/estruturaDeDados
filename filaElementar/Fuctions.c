#include <stdio.h>
#include <stdlib.h>
#include "Queue.h"

/////////////////////////////////////////////////////////////////////////////////
// 1º Questão
void initQueue(queue *Queue){
    Queue->first = NULL;
}

void listNodes(queue *Queue){
    queue auxQueue;
    initQueue(&auxQueue);
    int index = 0;
    while (Queue->first){
        printf("%c[%d]",Queue->first->data,index);
        if(Queue->first->next) printf(" - ");
        node *delete = Remove(Queue);
        insert(&auxQueue, delete->data);
        index++; free(delete);
    }

    while (auxQueue.first){
        node *delete = Remove(&auxQueue);
        insert(Queue, delete->data);
        free(delete);
    }
    printf("\n");
    lenght(Queue);
}

///////////////////////////////////////////////////////////////////////////////////
// 2 Questão
void insert(queue *Queue, char value){
    node *new = malloc(sizeof(node));
    node *aux = Queue->first;
    if(new){
        new->data = value;
        new->next = NULL;
        if(Queue->first == NULL){
            Queue->first = new;
        } else{
            while (aux->next){
                aux = aux->next;
            }
            aux->next = new;
        }


    } else printf("\nErro na alocação\n");
}
///////////////////////////////////////////////////////////////////////////////////
// 3º questão
node * Remove(queue *Queue){
    node *delete = NULL;
    if(Queue->first){
        delete = Queue->first;
        Queue->first = delete->next;

    } else printf("Queue empty\n");

    return delete;
}

///////////////////////////////////////////////////////////////////////////////////
// 4º questão
node * First(queue *Queue){
    node *first;
    node *percorrer = malloc(sizeof(queue));
    queue auxQueue;
    initQueue(&auxQueue);
    int index = 0;
    while (Queue->first){
        percorrer = Remove(Queue);
        if(index == 0) first = percorrer;
        insert(&auxQueue, percorrer->data);
        index++;

    }

    while (auxQueue.first){
        node *delete = Remove(&auxQueue);
        insert(Queue, delete->data);
        free(delete);
    }

    return first;
}

///////////////////////////////////////////////////////////////////////////////////
// 6º Questão
int lenght(queue *Queue){
    int lenght = 0;
    node *percorrer = malloc(sizeof(queue));
    queue auxQueue;
    initQueue(&auxQueue);
    while (Queue->first){
        percorrer = Remove(Queue);
        insert(&auxQueue, percorrer->data);
        lenght++;
    }

    while (auxQueue.first){
        node *delete = Remove(&auxQueue);
        insert(Queue, delete->data);
        free(delete);
    }
    return lenght;
}
///////////////////////////////////////////////////////////////////////////////////
// 7º Questão
node * Last(queue *Queue){
    node *last;
    node *percorrer = malloc(sizeof(queue));
    queue auxQueue;
    initQueue(&auxQueue);
    int index = 0;
    while (Queue->first){
        if(percorrer->next) last = percorrer->next;
        percorrer = Remove(Queue);
        insert(&auxQueue, percorrer->data);
        index++;
    }

    while (auxQueue.first){
        node *delete = Remove(&auxQueue);
        insert(Queue, delete->data);
        free(delete);
    }
    return last;
}

///////////////////////////////////////////////////////////////////////////////////
// 5º questão
void isEmpty(queue *Queue){
    if(lenght(Queue) == 0) printf("Is empty\n");
    else printf("Not is empty\n");
}
///////////////////////////////////////////////////////////////////////////////////
// 8º Questão
node * GetValueByIndex(queue *Queue, int index){
    int size = lenght(Queue);
    queue newQueue;
    initQueue(&newQueue);
    node *percorrer = malloc(sizeof(node));
    node *getValueByIndex = malloc(sizeof(node));
    int newIndex = 0;
    while(Queue->first){
        percorrer = Remove(Queue);
        insert(&newQueue,percorrer->data);
    }

    while(newQueue.first){
        percorrer = Remove(&newQueue);
        if(newIndex == index) getValueByIndex = percorrer;
        newIndex++;
        insert(Queue,percorrer->data);
    }

    return getValueByIndex;
}
///////////////////////////////////////////////////////////////////////////////////
// 9º Questão
int GetIndexByValue(queue *Queue, char value){
    queue newQueue;
    initQueue(&newQueue);
    node *percorrer = malloc(sizeof(node));
    int true = 0;
    int newIndex = 0;
    int index = 0;
    while(Queue->first){
        percorrer = Remove(Queue);
        if(percorrer->data == value && true == 0) {
            true = 1;
            index = newIndex;
        }
        insert(&newQueue,percorrer->data);
        newIndex++;

    }
    while(newQueue.first){
        percorrer = Remove(&newQueue);
        insert(Queue,percorrer->data);
    }

    return index;
}
///////////////////////////////////////////////////////////////////////////////////
// 10º Questão
int GetAllIndexByValue(queue *Queue, char value, int *indexs){
    queue newQueue;
    initQueue(&newQueue);
    node *percorrer;
    int repeticoes = 0;
    int newIndex = 0;
    while(Queue->first){
        percorrer = Remove(Queue);
        insert(&newQueue,percorrer->data);
    }
    while(newQueue.first){
        newIndex++;
        percorrer = Remove(&newQueue);
        if(percorrer->data == value) {
            *indexs = newIndex-1;
            indexs++; repeticoes++;
        }

        insert(Queue,percorrer->data);
    }
    return repeticoes;
}
///////////////////////////////////////////////////////////////////////////////////
// 11º Questão
void getValuesByIndexs(queue *Queue, int *indexs,  char *values){
    queue newQueue;
    initQueue(&newQueue);
    node *percorrer ;
    int newIndex = 0;
    while(Queue->first){
        percorrer = Remove(Queue);
        insert(&newQueue,percorrer->data);
    }
    while(newQueue.first){
        percorrer = Remove(&newQueue);
        if(*indexs == newIndex) {
            *values = percorrer->data;
            values++;
            indexs++;
        }
        newIndex++;
        insert(Queue,percorrer->data);
    }
    printf("\n");
}
///////////////////////////////////////////////////////////////////////////////////
// 12º Questão
int getValuesBySlice(queue *Queue, int inicio, int final, char *values){
    node *Node;
    int repeticoes = 0;
    int i = inicio;
    while(i >= final){
        Node = GetValueByIndex(Queue,i);
        *values = Node->data;
        values++;
        i--; repeticoes++;
    }
    return repeticoes;

}
///////////////////////////////////////////////////////////////////////////////////
// 13º Questão
void removeAll(queue *Queue){
    while(Queue->first){
        Remove(Queue);
    }
}

///////////////////////////////////////////////////////////////////////////////////
// 14º Questão
void removeByIndex(queue *Queue,int index){
    int size = lenght(Queue);
    queue newQueue;
    initQueue(&newQueue);
    node *percorrer;
    node *acima;
    if(0 == index) Remove(Queue);
    else{
        int newIndex = 0;
        while (Queue->first) {
            acima = percorrer;
            percorrer = Remove(Queue);
            newIndex++;
            if (newIndex-1 == index) {
                node *delete = percorrer->next;

                acima->next = delete;
            }
            else insert(&newQueue, percorrer->data);
        }

        while (newQueue.first) {
            percorrer = Remove(&newQueue);
            insert(Queue, percorrer->data);
        }
    }
}
///////////////////////////////////////////////////////////////////////////////////
// 15º Questão
void removeByValue(queue *Queue,char value){
    int index = GetIndexByValue(Queue,value);
    removeByIndex(Queue,index);
}
///////////////////////////////////////////////////////////////////////////////////
// 16º Questão
void removeAllByValue(queue *Queue, char value){
    int o[lenght(Queue)];
    int i = GetAllIndexByValue(Queue,value,o)-1;
    for (; i >= 0 ; --i) {
        removeByIndex(Queue,o[i]);
    }
}

/////////////////////////////////////////////////////////////////////////////////////
// 17º Questão
void removeAllByIndexes(queue *Queue,int p[],int limite){
    for (int i = 0; i < limite; ++i) {
        removeByIndex(Queue,p[i]);
    }
}

/////////////////////////////////////////////////////////////////////////////////////
// 18º Questão
void removeAllBySlice(queue *Queue, int inicio,int final){
    for (int i = inicio; i >= final; --i) {
        removeByIndex(Queue,i);
    }
}

/////////////////////////////////////////////////////////////////////////////////////
// 19º Questão
void setValueInIndex(queue *Queue, int index, char value){
    int size = lenght(Queue);
    queue newQueue;
    initQueue(&newQueue);
    node *percorrer = malloc(sizeof(node));
    node *getValueByIndex = malloc(sizeof(node));
    int newIndex = 0;
    while(Queue->first){
        percorrer = Remove(Queue);
        insert(&newQueue,percorrer->data);
    }

    while(newQueue.first){
        percorrer = Remove(&newQueue);
        if(newIndex == index) percorrer->data = value;
        newIndex++;
        insert(Queue,percorrer->data);
    }
}

/////////////////////////////////////////////////////////////////////////////////////
// 20º Questão
void setValuesInIndexes(queue *Queue,int *indexs, char *values, int limite){
    for (int i = 0; i < limite; i++) {
        setValueInIndex(Queue, *indexs, *values);
        ++indexs; ++values;
    }
}