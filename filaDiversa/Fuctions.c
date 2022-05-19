#include <stdio.h>
#include <stdlib.h>
#include "Queue.h"
/////////////////////////////////////////////////////////////////////////////////
// 1º Questão
void initQueue(queue *Queue){
    Queue->first = NULL;
    Queue->last = NULL;
    Queue->size = 0;
}
/////////////////////////////////////////////////////////////////////////////////
// 2º Questão
void insert(queue *Queue, char value){
    node *new = malloc(sizeof(node));
    if(new){
        Queue->size++;
        new->data = value;
        new->next = NULL;
        new->index = Queue->size - 1;
        if(Queue->first == NULL){
            Queue->first = new;
            Queue->last = new;
        } else{
            Queue->last->next = new;
            Queue->last = new;
        }


    } else printf("\nErro na alocação\n");
}

/////////////////////////////////////////////////////////////////////////////////
// 3º Questão
node * Remove(queue *Queue){
    node *delete = NULL;
    node *indexs = NULL;
    if(Queue->first){
        delete = Queue->first;
        Queue->first = delete->next;
        Queue->size--;
        indexs = delete;
        while(indexs){
        indexs->index--;
        indexs = indexs->next;
      }
    } else printf("Queue empty\n");
  
    return delete;
}

void listNodes(queue *Queue){
    node *aux = Queue->first;
    while (aux){
        printf("%c[%d]",aux->data,aux->index);
        if(aux->next) printf(" - ");
        aux = aux->next;
    }
    printf("\n");
}
/////////////////////////////////////////////////////////////////////////////////
// 4º Questão
node *First(queue *Queue){
    node *aux = Queue->first;
    if(aux) return aux;
    return NULL;
}

/////////////////////////////////////////////////////////////////////////////////
// 5º Questão
void isEmpty(queue *Queue){
    if(Queue->first) printf("Not is empty\n");
    else printf("is Empty\n");
}
/////////////////////////////////////////////////////////////////////////////////
// 6º Questão
int lenght(queue *Queue) {
    return Queue->size;
}
/////////////////////////////////////////////////////////////////////////////////
// 7º Questão
node *Last(queue *Queue){
    node *aux = Queue->last;
    /*while (aux){
        if(aux->index == Queue->size - 1) break;
        aux = aux->next;
    }*/
    if(aux) return aux;
    return NULL;
}
/////////////////////////////////////////////////////////////////////////////////
// 8º Questão
node *GetValueByIndex(queue *Queue, int index){
    node *getValueByIndex = Queue->first;
    while (getValueByIndex){
        if(getValueByIndex->index == index) return getValueByIndex;
        getValueByIndex = getValueByIndex->next;
    }
    return NULL;
}
/////////////////////////////////////////////////////////////////////////////////
// 9º Questão
node *GetIndexByValue(queue *Queue, char value){
    node *getIndexByValue = Queue->first;
    while (getIndexByValue){
        if(getIndexByValue->data == value) return getIndexByValue;
        getIndexByValue = getIndexByValue->next;
    }
    return NULL;
}
/////////////////////////////////////////////////////////////////////////////////
// 10º Questão
int GetAllIndexByValue(queue *Queue, char value, int *indexs){
    int limite = 0;
    node *getAllIndexByValue = Queue->first;
    while (getAllIndexByValue){
        if(getAllIndexByValue->data == value) {
            *indexs = getAllIndexByValue->index;
            indexs++; limite++;
        }
        getAllIndexByValue = getAllIndexByValue->next;
    }
    return limite;
}
/////////////////////////////////////////////////////////////////////////////////
// 11º Questão
void GetValuesByIndexs(queue *Queue, int *p, int limite, char *values){
    node *getValuesByIndexs = Queue->first;
    int passou = 0;
    while (getValuesByIndexs){
        if(limite == passou){
            break;
        }
        if(getValuesByIndexs->index == *p){
            *values = getValuesByIndexs->data;
            values++; passou++;
            p++;
        }
        getValuesByIndexs = getValuesByIndexs->next;
    }
}
/////////////////////////////////////////////////////////////////////////////////
// 12º Questão
int GetValuesBySlice(queue *Queue, int inicio, int final, char *values){
    node *getValuesBySlice = Queue->first;
    int elements = 0;
    while (getValuesBySlice){
        if(inicio == getValuesBySlice->index){
            while (final >= getValuesBySlice->index){
                *values = getValuesBySlice->data;
                values++; elements++;
                getValuesBySlice = getValuesBySlice->next;
            }
        }
        getValuesBySlice = getValuesBySlice->next;
    }
    return elements;
}

/////////////////////////////////////////////////////////////////////////////////
// 13º Questão
void removerAll(queue *Queue){
    node *removerAll = Queue->first;

    while (removerAll){
        node *delete = Remove(Queue);
        removerAll = removerAll->next;
        free(delete);
    }
}
/////////////////////////////////////////////////////////////////////////////////
// 14º Questão
void removeByIndex(queue *Queue,int index){
    node *removeByIndex = Queue->first;
    node *acima, *delete;
    if(index == 0) Remove(Queue);
    else {
        while (removeByIndex){
            if(removeByIndex->index == index-1){
                acima = removeByIndex;
            }

            if(removeByIndex->index == index){
                delete = removeByIndex;
                acima->next = delete->next;
                Queue->size--;

            }
            if(removeByIndex->index > index) removeByIndex->index--;
            if(removeByIndex->next) Queue->last = removeByIndex;
            removeByIndex = removeByIndex->next;

        }
    }


}

/////////////////////////////////////////////////////////////////////////////////
// 15º Questão
void removeByValue(queue *Queue,char value){
    int existe = 0;
    node *aux = Queue->first;
    node *acima; node *delete;

        while (aux){
            //printf("ponteiro %d\n",aux->next);
            if(aux->data == value && existe !=2){
                    delete = aux;
                    acima->next = delete->next;
                    Queue->size--;
                    existe = 2;
                    Queue->last = aux;
            }

            if(existe == 2) aux->index--;
            acima = aux;
            aux = aux->next;
        }


}
/////////////////////////////////////////////////////////////////////////////////
// 16º Questão
void removeAllByValue(queue *Queue,char value){
    int existe = 1;
    node *aux = Queue->first;
    node *acima; node *delete;

    if(aux->data != value ){
        existe = 0;
        while (aux){
            if(aux->data == value){
                delete = aux;
                if(delete->next->data == value){
                    while (delete->next){
                        if(delete->next->data != value) break;
                        delete = delete->next;
                    }
                }
                acima->next = delete->next;
                aux = delete->next;

            }
            Queue->size = existe+1;
            aux->index = existe; existe++;
            acima = aux;
            if(aux) Queue->last = aux;
            aux = aux->next;
        }

    } else Remove(Queue);

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
void removeAllBySlice(queue *Queue, int inicio,int final)
{   int n = inicio;
    for (int i = inicio; i <= final; ++i) {
        removeByIndex(Queue,n);
    }
}
/////////////////////////////////////////////////////////////////////////////////////
// 19º Questão
void setValueInIndex(queue *Queue, int index, char value){
    node *aux = Queue->first;
    while (aux){
        if(aux->index == index){
            aux->data = value;
        }
        aux = aux->next;
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
