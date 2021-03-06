/////////////////////////////////////////////////////////////////////////////////
// 1º Questão
typedef struct Node{
    char data;
    int index;
    struct Node *next;
}node;

typedef struct queue{
    node *first;
   node *last;
    int size;
}queue;
void initQueue(queue *Queue);
/////////////////////////////////////////////////////////////////////////////////
// 2º Questão
void insert(queue *Queue, char value);
/////////////////////////////////////////////////////////////////////////////////
// 3º Questão
node * Remove(queue *Queue);
void listNodes(queue *Queue);
/////////////////////////////////////////////////////////////////////////////////
// 4º Questão
node *First(queue *Queue);
/////////////////////////////////////////////////////////////////////////////////
// 5º Questão
void isEmpty(queue *Queue);
/////////////////////////////////////////////////////////////////////////////////
// 6º Questão
int lenght(queue *Queue);
/////////////////////////////////////////////////////////////////////////////////
// 7º Questão
node *Last(queue *Queue);
/////////////////////////////////////////////////////////////////////////////////
// 8º Questão
node *GetValueByIndex(queue *Queue, int index);
/////////////////////////////////////////////////////////////////////////////////
// 9º Questão
node *GetIndexByValue(queue *Queue, char value);
/////////////////////////////////////////////////////////////////////////////////
// 10º Questão
int GetAllIndexByValue(queue *Queue, char value, int *indexs);
/////////////////////////////////////////////////////////////////////////////////
// 11º Questão
void GetValuesByIndexs(queue *Queue, int *p, int limite, char *values);
/////////////////////////////////////////////////////////////////////////////////
// 12º Questão
int GetValuesBySlice(queue *Queue, int inicio, int final, char *values);
/////////////////////////////////////////////////////////////////////////////////
// 13º Questão
void removerAll(queue *Queue);
/////////////////////////////////////////////////////////////////////////////////
// 14º Questão
void removeByIndex(queue *Queue,int index);
/////////////////////////////////////////////////////////////////////////////////
// 15º Questão
void removeByValue(queue *Queue,char value);
/////////////////////////////////////////////////////////////////////////////////
// 16º Questão
void removeAllByValue(queue *Queue,char value);
/////////////////////////////////////////////////////////////////////////////////////
// 17º Questão
void removeAllByIndexes(queue *Queue,int p[],int limite);
/////////////////////////////////////////////////////////////////////////////////////
// 18º Questão
void removeAllBySlice(queue *Queue, int inicio,int final);
/////////////////////////////////////////////////////////////////////////////////////
// 19º Questão
void setValueInIndex(queue *Queue, int index, char value);
/////////////////////////////////////////////////////////////////////////////////////
// 20º Questão
void setValuesInIndexes(queue *Queue,int *indexs, char *values, int limite);