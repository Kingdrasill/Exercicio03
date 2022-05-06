#include "lista.h"

int main() {
    Lista S1;
    Lista S2;
    FLVazia(&S1);
    FLVazia(&S2);

    if(!LerArquivo(&S1)) {
        exit(1);
    }
    if(!LerArquivo(&S2)) {
        exit(1);
    }

    return 0;
}