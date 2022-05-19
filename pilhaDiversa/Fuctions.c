#include <stdio.h>
#include <stdlib.h>
#include "Stack.h"

void initStack(stack *initStack){
    initStack->topNodePointer = NULL;
    initStack->size = 0;
}

void listNodes(stack *Stack){
    node *aux = Stack->topNodePointer;
    printf("Tamanho da pilha: %d\n",Stack->size);
    while (aux){
        printf("%c[%d]",aux->data,aux->index);
        if(aux->pointerNextNode != NULL) printf(" - ");
        aux = aux->pointerNextNode;
    }printf("\n");
}

/////////////////////////////////////////////////////////////////////////////////////
// 2 Questão
node * push(stack *Stack, char data){

    node *newNode = malloc(sizeof(node));
    if(newNode){
        Stack->size++;
        newNode->data = data;
        newNode->index = Stack->size-1;
        newNode->pointerNextNode = Stack->topNodePointer;
        Stack->topNodePointer = newNode;
        newNode->index = Stack->size - 1;
        return newNode;
    } else printf("Erro ao alocar memoria\n");
    return NULL;
}
/////////////////////////////////////////////////////////////////////////////////////
// 3º questão
node * pop(stack *Stack){
    if(Stack->topNodePointer){
        node *delete = Stack->topNodePointer;
        Stack->topNodePointer = delete->pointerNextNode;
        Stack->size--;
        return delete;
    }else printf("Pilha vazia\n");
    return NULL;
}
/////////////////////////////////////////////////////////////////////////////////////
// 4º Questão
node * First(stack *Stack){
    return Stack->topNodePointer;
}

/////////////////////////////////////////////////////////////////////////////////////
// 5º Questão
int isEmpty(stack *Stack){
    if(Stack->size == 0){
        printf("Is Empty\n");
        return 1;
    } else{
        printf("not is empty\n");
        return 0;
    }
}
/////////////////////////////////////////////////////////////////////////////////////
// 6º Questão
int Lenght (stack *Stack){
    int lenght = Stack->size;
    return lenght;
}

/////////////////////////////////////////////////////////////////////////////////////
// 7º Questão
node * Last(stack *Stack){
    node *aux = Stack->topNodePointer;

    while (aux){
        if(aux->index == 0){
            return aux;
        }
        aux = aux->pointerNextNode;
    }
    return NULL;
}

/////////////////////////////////////////////////////////////////////////////////////
// 8º Questão
node * getValueByIndex(stack *Stack, int index){
    node *aux = Stack->topNodePointer;

    while (aux){
        if(aux->index == index){
            return aux;
        }
        aux = aux->pointerNextNode;
    }
    return NULL;
}
/////////////////////////////////////////////////////////////////////////////////////
// 9º Questão
node * getIndexByValue(stack *Stack, char value){
    node *aux = Stack->topNodePointer;

    while (aux){
        if(aux->data == value){
            return aux;
        }
        aux = aux->pointerNextNode;
    }
    return NULL;
}
/////////////////////////////////////////////////////////////////////////////////////
// 10º Questão
int getAllIndexByValue(stack *Stack, char value, int *p) {
    node *aux = Stack->topNodePointer;
    int i = 0;
    while (aux){
        if(aux->data == value){
            *p = aux->index;
            p++;
            i++;
        }
        aux = aux->pointerNextNode;
    }
    return i;
}
/////////////////////////////////////////////////////////////////////////////////////
// 11º Questão
void getValuesByIndexs(stack *Stack, int *p, int limite, char *values){
    node *aux = Stack->topNodePointer;
    int passou = 0;
    while (aux){
        if(limite == passou){
            break;
        }
        if(aux->index == *p){
            *values = aux->data;
            values++; passou++;
            p++;
        }
        aux = aux->pointerNextNode;
    }
}
/////////////////////////////////////////////////////////////////////////////////////
// 12º Questão
int getValuesBySlice(stack *Stack, int inicio, int final, char *values){
    node *aux = Stack->topNodePointer;
    int elements = 0;
    while (aux){
        if(inicio == aux->index){
            while (final <= aux->index){
                *values = aux->data;
                values++;
                elements++;
                aux = aux->pointerNextNode;
            }
        }
        aux = aux->pointerNextNode;
    }
    return elements;

}
/////////////////////////////////////////////////////////////////////////////////////
// 13º Questão
void removerAll(stack *Stack){
    node *aux = Stack->topNodePointer;

    while (aux){

        node *delete = pop(Stack);
        aux = aux->pointerNextNode;
        free(delete);
    }
}
/////////////////////////////////////////////////////////////////////////////////////
// 14º Questão
void removeByIndex(stack *Stack,int index){
    node *aux = Stack->topNodePointer;
    node *acima;
    if(index < Stack->size-1){
        while (aux){
            if(aux->index == index+1){
                acima = aux;
            }
            if(aux->index == index){
                node *delete = aux;
                acima->pointerNextNode = delete->pointerNextNode;
                Stack->size--;
                free(aux);
                break;
            }
            aux->index--;
            aux = aux->pointerNextNode;
        }
    } else pop(Stack);
}
/////////////////////////////////////////////////////////////////////////////////////
// 15º Questão
void removeByValue(stack *Stack,char value){
    int existe = 0;
    node *aux = Stack->topNodePointer;
    node *acima;
    while (aux){
        if(aux->data == value){
            existe = 1;
        }
        aux = aux->pointerNextNode;
    }
    aux = Stack->topNodePointer;
    if(existe == 0){
        printf("Nao existe\n");
    }
    else if(aux->data != value ){
        while (aux){
            if(aux->data == value){
                node *delete = aux;
                acima->pointerNextNode = delete->pointerNextNode;
                Stack->size--;
                free(aux);
                break;
            }
            aux->index--;
            acima = aux;
            aux = aux->pointerNextNode;
        }
    } else pop(Stack);

}
/////////////////////////////////////////////////////////////////////////////////////
// 16º Questão
void removeAllByValue(stack *Stack, char value){

    node *aux = Stack->topNodePointer;
    node *top;

    while (aux){
        if(Stack->topNodePointer->data == value){
            pop(Stack);
        }
        else if(aux->data == value){
            node *aux2 = aux;
            while(aux2){
                if(aux2->data == value){
                    node *delete = aux2;
                    aux2 = aux2->pointerNextNode;
                    aux = aux->pointerNextNode;
                    Stack->size--;
                    free(delete);
                } else break;

            }
            top->pointerNextNode = aux2;
        }
        if(aux->data != value) top = aux;
        aux = aux->pointerNextNode;
    }
    aux = Stack->topNodePointer;
    while(aux){
        aux->index = aux == Stack->topNodePointer ? Stack->size-1: top->index-1;
        top = aux;
        aux = aux->pointerNextNode;
    }
}
/////////////////////////////////////////////////////////////////////////////////////
// 17º Questão
void removeAllByIndexes(stack *Stack,int p[],int limite){
    for (int i = 0; i < limite; ++i) {
        removeByIndex(Stack,p[i]);
    }

}
/////////////////////////////////////////////////////////////////////////////////////
// 18º Questão
void removeAllBySlice(stack *Stack, int inicio,int final)
{   int n = inicio;
    for (int i = inicio; i <= final; ++i) {
        removeByIndex(Stack,n);
    }
}
/////////////////////////////////////////////////////////////////////////////////////
// 19º Questão
void addValueInIndex(stack *Stack, int index, char value){
    node *aux = Stack->topNodePointer;
    while (aux){
        if(index > Stack->size-1) { push(Stack, value); break; }
        if(aux->index == index){
            node *new = malloc(sizeof(node));
            new->index = index;
            new->data = value;
            aux->index++;
            new->pointerNextNode = aux->pointerNextNode;
            aux->pointerNextNode = new;
            Stack->size++;
            break;
        }
        aux->index++;
        aux = aux->pointerNextNode;
    }
}


/////////////////////////////////////////////////////////////////////////////////////
// 20º Questão
void addValuesInIndexes(stack *Stack,int *indexs, char *values, int limite){
    for (int i = 0; i < limite; i++) {
        setValueInIndex(Stack, *indexs, *values);

        ++indexs; ++values;
    }

}

/////////////////////////////////////////////////////////////////////////////////////
// 21º Questão
void setValueInIndex(stack *Stack, int index, char value){
    node *aux = Stack->topNodePointer;
    while (aux){
        if(aux->index == index){
            aux->data = value;
        }
        aux = aux->pointerNextNode;
    }
}


/////////////////////////////////////////////////////////////////////////////////////
// 22º Questão
void setValuesInIndexes(stack *Stack,int *indexs, char *values, int limite){
    for (int i = 0; i < limite; i++) {
        setValueInIndex(Stack, *indexs, *values);
        ++indexs; ++values;
    }

}