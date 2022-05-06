#include "lista.h"

void FLVazia(Lista *lista) {
    lista->Primeiro = 0;
    lista->Ultimo = 0;
}

void Imprime(Lista *lista) {
    if(lista->Primeiro == lista->Ultimo) {
        printf("LISTA VAZIA!\n");
        return;
    }
    for(int i=0; i<lista->Ultimo; i++) {
        printf("%c%c%c", lista->vet[i].value[0], lista->vet[i].value[1], lista->vet[i].value[2]);
    }
}

bool Insere(Lista *lista, Item d) {
    if(lista->Ultimo >= MAXTAM) {
        printf("LISTA CHEIA!\n");
        return false;
    } 

	lista->vet[lista->Ultimo] = d;
	lista->Ultimo++;
    return true;
}

bool Remove(Lista *lista, Item *d) {
    bool ok = false;
    int aux;

    if(lista->Primeiro == lista->Ultimo) {
        printf("LISTA VAZIA!\n");
        return false;
    }
    
    for(int i=(lista->Ultimo-1); i>=0; i--){
        if(lista->vet[i].value[0] == d->value[0] && lista->vet[i].value[1] == d->value[1] && lista->vet[i].value[2] == d->value[2]) {
            aux = i;
            ok = true;
            i = -1;
        }
    }

    if(ok){
        for(int i=aux; i<=lista->Ultimo; i++) {
            lista->vet[i] = lista->vet[i+1];
        }
        lista->Ultimo--;
    }
    
    return ok;
}

bool LerArquivo(Lista *lista) {
    FILE *fp;
    Item D;
    char arquivo[FILE_MAXTAM];
    char seq[SEQ_MAXTAM];
    strcpy(D.value, "");

    printf("Nome do arquivo onde esta a sequencia: ");
	fgets(arquivo, FILE_MAXTAM-4, stdin);
	strtok(arquivo, "\n");
	strcat(arquivo, ".txt");

    fp = fopen(arquivo, "r");
    if (fp == NULL) {
        printf("\nErro!Nao foi possivel abrir o arquivo!\n");
        return false;
    } else {
        if (fgets(seq, SEQ_MAXTAM, fp) != NULL) {
            strtok(seq, "\n");
            if(strlen(seq) % 3 != 0) {
                printf("\nErro!O numero de caracteres da senquecia tem que ser multiplo de 3!\n");
                return false;
            } else {
                for(int i=0; i<(int)strlen(seq); i=i) {
                    D.value[0] = seq[i];
                    D.value[1] = seq[i+1];
                    D.value[2] = seq[i+2];
                    Insere(lista, D);
                    i = i+3;
                }
            }
        } else {
            printf("\nErro!Arquivo vazio!\n");
            return false;
        }
    }
    fclose(fp);
    return true;
}