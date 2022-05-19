#include <stdio.h>
#include <stdlib.h>
#include "Stack.h"

void initStack(stack *initStack){
    initStack->topNodePointer = NULL;
}
int Lenght(stack *Stack);

void listNodes(stack *Stack){
    int size = 0;
    int lenght = Lenght(Stack);
    node *aux = Stack->topNodePointer;
    while (aux){
        size++;
        printf("%c[%d]",aux->data,lenght-size);
        if(aux->pointerNextNode != NULL) printf(" - ");
        aux = aux->pointerNextNode;
    }
    printf("\nTamanho da pilha: %d\n",size);
}
///////////////////////////////////////////////////////////////////////////////////
// 2 Questão
node * push(stack *Stack, char data){
    node *newNode = malloc(sizeof(node));
    if(newNode){
        newNode->data = data;
        newNode->pointerNextNode = Stack->topNodePointer;
        Stack->topNodePointer = newNode;
        return newNode;
    } else printf("Erro ao alocar memoria\n");
    return NULL;
}
///////////////////////////////////////////////////////////////////////////////////
// 3º questão
node * pop(stack *Stack){
    if(Stack->topNodePointer){
        node *delete = Stack->topNodePointer;
        Stack->topNodePointer = delete->pointerNextNode;
        return delete;
    }else printf("Pilha vazia\n");
    return NULL;
}
///////////////////////////////////////////////////////////////////////////////////
// 4º questão
node * First(stack *Stack){
    node *first = malloc(sizeof(node));
    first = pop(Stack);
    push(Stack,first->data);
    return first;
}

///////////////////////////////////////////////////////////////////////////////////
// 5º questão
void isEmpty(stack *Stack){
    if(Lenght(Stack) == 0) printf("Is empty\n");
    else printf("Not is empty\n");
}
///////////////////////////////////////////////////////////////////////////////////
// 6º Questão
int Lenght(stack *Stack){
    stack newStack;
    initStack(&newStack);
    node *percorrer = malloc(sizeof(node));
    int lenght = 0;
    while(Stack->topNodePointer){
        percorrer = pop(Stack);
        lenght++;
        push(&newStack,percorrer->data);
    }

    while(newStack.topNodePointer){
        percorrer = pop(&newStack);
        push(Stack,percorrer->data);
    }
    return lenght;
}
///////////////////////////////////////////////////////////////////////////////////
// 7º Questão
node * Last(stack *Stack){
    stack newStack;
    initStack(&newStack);
    node *percorrer = malloc(sizeof(node));
    node *last;
    int lenght = 0;
    while(Stack->topNodePointer){
        percorrer = pop(Stack);
        lenght++;
        push(&newStack,percorrer->data);
    }
    last = percorrer;
    while(newStack.topNodePointer){
        percorrer = pop(&newStack);
        push(Stack,percorrer->data);
    }

    return last;
}
///////////////////////////////////////////////////////////////////////////////////
// 8º Questão
node * GetValueByIndex(stack *Stack, int index){
    int size = Lenght(Stack);
    stack newStack;
    initStack(&newStack);
    node *percorrer = malloc(sizeof(node));
    node *getValueByIndex = malloc(sizeof(node));
    int newIndex = 0;
    while(Stack->topNodePointer){
        percorrer = pop(Stack);
        newIndex++;
        if(size-newIndex == index) getValueByIndex = percorrer;
        push(&newStack,percorrer->data);
    }

    while(newStack.topNodePointer){
        percorrer = pop(&newStack);
        push(Stack,percorrer->data);
    }

    return getValueByIndex;
}
///////////////////////////////////////////////////////////////////////////////////
// 9º Questão
int GetIndexByValue(stack *Stack, char value){
    stack newStack;
    initStack(&newStack);
    node *percorrer = malloc(sizeof(node));
    int true = 0;
    int newIndex = Lenght(Stack)-1;
    int index = 0;
    while(Stack->topNodePointer){
        percorrer = pop(Stack);
        if(percorrer->data == value && true == 0) { true = 1;
            index = newIndex;}
        push(&newStack,percorrer->data);
        newIndex--;

    }
    while(newStack.topNodePointer){
        percorrer = pop(&newStack);
        push(Stack,percorrer->data);
    }

    return index;
}
///////////////////////////////////////////////////////////////////////////////////
// 10º Questão
int GetAllIndexByValue(stack *Stack, char value, int *indexs){
    stack newStack;
    initStack(&newStack);
    node *percorrer;
    int repeticoes = 0;
    int newIndex = 0;
    while(Stack->topNodePointer){
        percorrer = pop(Stack);
        push(&newStack,percorrer->data);
    }
    while(newStack.topNodePointer){
        newIndex++;
        percorrer = pop(&newStack);
        if(percorrer->data == value) {
            *indexs = newIndex-1;
            indexs++; repeticoes++;
        }

        push(Stack,percorrer->data);
    }
    return repeticoes;
}
///////////////////////////////////////////////////////////////////////////////////
// 11º Questão
void getValuesByIndexs(stack *Stack, int *indexs,  char *values){
    stack newStack;
    initStack(&newStack);
    node *percorrer ;
    int newIndex = 0;
    while(Stack->topNodePointer){
        percorrer = pop(Stack);
        push(&newStack,percorrer->data);
    }
    while(newStack.topNodePointer){
        percorrer = pop(&newStack);
        if(*indexs == newIndex) {
            *values = percorrer->data;
            values++;
            indexs++;
        }
        newIndex++;
        push(Stack,percorrer->data);
    }
    printf("\n");
}
///////////////////////////////////////////////////////////////////////////////////
// 12º Questão
int getValuesBySlice(stack *Stack, int inicio, int final, char *values){
    node *Node;
    int repeticoes = 0;
    int i = inicio;
    while(i >= final){
        Node = GetValueByIndex(Stack,i);
        *values = Node->data;
        values++;
        i--; repeticoes++;
    }
    return repeticoes;

}
///////////////////////////////////////////////////////////////////////////////////
// 13º Questão
void removeAll(stack *Stack){
    while(Stack->topNodePointer){
        pop(Stack);
    }
}
///////////////////////////////////////////////////////////////////////////////////
// 14º Questão
void removeByIndex(stack *Stack,int index){
    int size = Lenght(Stack);
    stack newStack;
    initStack(&newStack);
    node *percorrer;
    node *acima;
    if(size-1 == index) pop(Stack);
    else{
        int newIndex = 0;
        while (Stack->topNodePointer) {
            acima = percorrer;
            percorrer = pop(Stack);
            newIndex++;
            if (size - newIndex == index) {
                node *delete = percorrer->pointerNextNode;
                //printf("Node percorrer: %c\nNode acima: %c\nNode delete: %c\n",percorrer->data,acima->data,delete->data);
                acima->pointerNextNode = delete;
            }
            else push(&newStack, percorrer->data);
        }

        while (newStack.topNodePointer) {
            percorrer = pop(&newStack);
            push(Stack, percorrer->data);
        }
    }
}
///////////////////////////////////////////////////////////////////////////////////
// 15º Questão
void removeByValue(stack *Stack,char value){
    int index = GetIndexByValue(Stack,value);
    removeByIndex(Stack,index);
}
///////////////////////////////////////////////////////////////////////////////////
// 16º Questão
void removeAllByValue(stack *Stack, char value){
    int o[Lenght(Stack)];
    int i = GetAllIndexByValue(Stack,value,o)-1;
    for (; i >= 0 ; --i) {
        removeByIndex(Stack,o[i]);
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
void removeAllBySlice(stack *Stack, int inicio,int final){
    for (int i = inicio; i >= final; --i) {
        removeByIndex(Stack,i);
    }
}

/////////////////////////////////////////////////////////////////////////////////////
// 19º Questão
void setValueInIndex(stack *Stack, int index, char value){
    int size = Lenght(Stack);
    stack newStack;
    initStack(&newStack);
    node *percorrer = malloc(sizeof(node));
    node *getValueByIndex = malloc(sizeof(node));
    int newIndex = 0;
    while(Stack->topNodePointer){
        percorrer = pop(Stack);
        newIndex++;
        if(size-newIndex == index) percorrer->data = value;
        push(&newStack,percorrer->data);
    }

    while(newStack.topNodePointer){
        percorrer = pop(&newStack);
        push(Stack,percorrer->data);
    }
}
/////////////////////////////////////////////////////////////////////////////////////
// 20º Questão
void setValuesInIndexes(stack *Stack,int *indexs, char *values, int limite){
    for (int i = 0; i < limite; i++) {
        setValueInIndex(Stack, *indexs, *values);
        ++indexs; ++values;
    }
}