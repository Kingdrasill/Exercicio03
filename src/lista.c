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

Lista FindMaxSeq(Lista *l1, Lista *l2) {
    Lista mseq, aux;
    int pos=0;
    FLVazia(&mseq);
    FLVazia(&aux);

    for(int j=0; j<l2->Ultimo; j++) {
        for(int i=0; i<l1->Ultimo; i++) {
            if(l1->vet[i].value[0] == l2->vet[j].value[0] && l1->vet[i].value[1] == l2->vet[j].value[1] && l1->vet[i].value[2] == l2->vet[j].value[2]) {
                pos = i;
                Insere(&aux, l1->vet[i]);
                if(l2->Ultimo == 1) {
                    i = l1->Ultimo;
                    CopySeq(&mseq, &aux);
                } else {
                    FindEqualSeq(l1, l2, &aux, pos, j);
                    if(mseq.Ultimo < aux.Ultimo){
                        CopySeq(&mseq, &aux);
                    }
                    i = pos;
                }
                FLVazia(&aux);
            }
        }
    }

    return mseq;
}

void CopySeq(Lista *dest, Lista *src) {
    FLVazia(dest);
    for(int i=0; i<src->Ultimo; i++) {
        Insere(dest, src->vet[i]);
    }
}

void FindEqualSeq(Lista *l1, Lista *l2, Lista *aux, int posl1, int posl2) {
    int j = 1 + posl2;

    for(int i=(posl1+1); i<l1->Ultimo; i++) {
        if(l1->vet[i].value[0] == l2->vet[j].value[0] && l1->vet[i].value[1] == l2->vet[j].value[1] && l1->vet[i].value[2] == l2->vet[j].value[2]) {
            Insere(aux, l1->vet[i]);
        }
        posl1 = i;
        j++;
        if(j == l2->Ultimo)
            i = l1->Ultimo;
    }
}

bool LerArquivo(Lista *lista) {
    FILE *fp;
    Item D;
    char arquivo[FILE_MAXTAM];
    char seq[SEQ_MAXTAM];
    strcpy(D.value, "");

    printf("Nome do arquivo onde esta a sequencia(com extensao): ");
	fgets(arquivo, FILE_MAXTAM, stdin);
	strtok(arquivo, "\n");

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