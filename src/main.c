#include "lista.h"

int main() {
    Lista S1;
    Lista S2;
    Lista MS;
    FLVazia(&S1);
    FLVazia(&S2);

    if(!LerArquivo(&S1)) {
        exit(1);
    }
    if(!LerArquivo(&S2)) {
        exit(1);
    }

    MS = FindMaxSeq(&S1, &S2);

    printf("\nMaior sequencia de codons da sequencia 2 na sequencia 1: ");
    Imprime(&MS);
    printf("\n");

    return 0;
}