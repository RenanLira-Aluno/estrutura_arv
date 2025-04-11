#include "arv.h"

int main()
{
    Arv a = arv(arv(arv(NULL, 4, NULL), 1, NULL), 2, arv(NULL, 3, NULL));
    printf("Em ordem: ");
    emordem(a);
    printf("\n");
    printf("Pre ordem: ");
    preordem(a);
    printf("\n");
    printf("Pos ordem: ");
    posordem(a);
    printf("\n");

    printf("Numero de nos: %d\n", nos(a));
    printf("Numero de folhas: %d\n", folhas(a));

    destroi(&a);

    return 0;
}