#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#define MAXTAM 100
#define SEQ_MAXTAM 300
#define FILE_MAXTAM 50

typedef struct Item Item;
typedef struct Lista Lista;

struct Item
{
    char value[3];
};

struct Lista
{
    Item vet[MAXTAM];
    int Primeiro;
    int Ultimo;
};

void FLVazia(Lista *lista);

void Imprime(Lista *lista);

bool Insere(Lista *lista, Item d);

bool Remove(Lista *lista, Item *d);

bool LerArquivo(Lista *lista);