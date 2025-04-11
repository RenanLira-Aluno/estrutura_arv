#include <stdlib.h>
#include <stdio.h>

#define fmt "%d "

typedef int Item;

typedef struct arv
{
    struct arv *esq;
    struct arv *dir;
    Item item;
} *Arv;

Arv arv(Arv e, Item x, Arv d)
{
    Arv n = (Arv)malloc(sizeof(struct arv));

    n->esq = e;
    n->item = x;
    n->dir = d;

    return n;
}

void emordem(Arv a)
{
    if (a == NULL)
        return;

    emordem(a->esq);
    printf(fmt, a->item);
    emordem(a->dir);
}

void preordem(Arv a)
{
    if (a == NULL)
        return;

    printf(fmt, a->item);
    preordem(a->esq);
    preordem(a->dir);
}

void posordem(Arv a)
{
    if (a == NULL)
        return;

    posordem(a->esq);
    posordem(a->dir);
    printf(fmt, a->item);
}

void destroi(Arv *a) {
    if (*a == NULL)
        return;

    destroi(&(*a)->esq);
    destroi(&(*a)->dir);
    free(*a);
    *a = NULL;
}

void ins(Item x, Arv *a)
{
    if (*a == NULL)
    {
        *a = arv(NULL, x, NULL);
    }
    else if (x < (*a)->item)
        ins(x, &(*a)->esq);
    else
        ins(x, &(*a)->dir);
}

int busca(Item x, Arv a) {
    if (a == NULL)
        return 0;

    if (x == a->item)
        return 1;
    else if (x < a->item)
        return busca(x, a->esq);
    else
        return busca(x, a->dir);
}

Item renmax(Arv *a) {
    if (*a == NULL) abort();

    while ((*a)->dir != NULL) a = &(*a)->dir;

    Arv n = *a;
    Item x = n->item;
    *a = n->esq;

    free(n);
    return x;
}

void rem(Item x, Arv *a)
{
    if (*a == NULL) return;

    if (x == (*a)->item)
    {
        Arv n = *a;

        if (n->esq == NULL) *a = n->dir;
        else if (n->dir == NULL) *a = n->esq;
        else n->item = renmax(&n->esq);
        if (n != *a) free(n);
    }
    else if (x <= (*a)->item) rem(x, &(*a)->esq);
    else rem(x, &(*a)->dir);
}

int nos(Arv a) {
    if (a == NULL)
        return 0;

    return 1 + nos(a->esq) + nos(a->dir);
}

int folhas(Arv a) {
    if (a == NULL)
        return 0;

    if (a->esq == NULL && a->dir == NULL)
        return 1;

    return folhas(a->esq) + folhas(a->dir);
}

int altura(Arv a) {
    if (a == NULL)
        return 0;

    int h = 1 + altura(a->esq);
    int d = 1 + altura(a->dir);

    return h > d ? h : d;
}

int tem(Arv a, Item x) {
    if (a == NULL)
        return 0;

    if (x == a->item)
        return 1;
    else if (x < a->item)
        return tem(a->esq, x);
    else
        return tem(a->dir, x);
}

