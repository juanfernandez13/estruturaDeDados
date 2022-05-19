/////////////////////////////////////////////////////////////////////////////////////
// 1º Questão
typedef struct node {
    struct node *pointerNextNode;
    int index;
    char data;

}node;

typedef struct stack{
    node *topNodePointer;
    int size;

}stack;
void initStack(stack *initStack);
void listNodes(stack *Stack);
// 2 Questão
node * push(stack *Stack, char data);
// 3º questão
node * pop(stack *Stack);
// 4º Questão
node * First(stack *Stack);
// 5º Questão
void isEmpty(stack *Stack);
// 6º Questão
int Lenght (stack *Stack);
// 7º Questão
node * Last(stack *Stack);
// 8º Questão
node * GetValueByIndex(stack *Stack, int index);
// 9º Questão
int GetIndexByValue(stack *Stack, char value);
// 10º Questão
int GetAllIndexByValue(stack *Stack, char value, int *p);
// 11º Questão
void getValuesByIndexs(stack *Stack, int *p, char *values);
// 12º Questão
int getValuesBySlice(stack *Stack, int inicio, int final, char *values);
// 13º Questão
void removeAll(stack *Stack);
// 14º Questão
void removeByIndex(stack *Stack,int index);
// 15º Questão
void removeByValue(stack *Stack,char value);
// 16º Questão
void removeAllByValue(stack *Stack, char value);
// 17º Questão
void removeAllByIndexes(stack *Stack,int p[],int limite);
// 18º Questão
void removeAllBySlice(stack *Stack, int inicio,int final);
// 19º Questão
void setValueInIndex(stack *Stack, int index, char value);
// 20º Questão
void setValuesInIndexes(stack *Stack,int *indexs, char *values, int limite);

