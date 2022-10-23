#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

typedef struct nodeItem {
    int info;
    struct nodeItem *left, *right, *father;
} node;

node *makeTree(int value);
int info(node *n);
node *left(node *n);
node *right(node *n);
node *father(node *n);
int isLeft(node *n);
int isRight(node *n);
node *brother(node *n);

node *addLeft(node *n, int value);
node *setNodeLeft(node *t, node *n);
node *addRight(node *n, int value);
node *setNodeRight(node *t, node *n);
void freeTree(node *t);

void preOrdem(node *t);
void emOrdem(node *t);
void posOrdem(node *t);

int main() {
    setlocale(LC_ALL, "");
    node *tree = makeTree(14);

    addLeft(addLeft(tree, 4), 3);
    addRight(left(tree), 10);
    addLeft(addRight(tree, 22), 18);
    addRight(right(tree), 25);

    printf("Pre-ordem: ");
    preOrdem(tree);
    printf("\nEm ordem: ");
    emOrdem(tree);
    printf("\nPos-ordem: ");
    posOrdem(tree);
    printf("\n");

    return 0;
}

node *makeTree(int value) {
    node *tree = (node *) malloc(sizeof (node));
    tree->info = value;
    tree->father = tree->left = tree->right = NULL;

    return tree;
}

int info(node *n) {
    return n != NULL ? n->info : printf("O nó recebido é NULL!\n");
}

node *left(node *n) {
    if(n == NULL) printf("O nó recebido não possui filho esquerdo!\n");
    else return n->left;
}

node *right(node *n) {
    if(n == NULL) printf("O nó recebido não possui filho esquerdo!\n");
    else return n->right;
}

node *father(node *n) {
    if(n == NULL || n->father == NULL) printf("O nó recebido é o nó raiz!\n");
    else return n->father;
}

int isLeft(node *n) {
    if(n == NULL) return printf("O nó recebido é NULL!\n");
    else return left(father(n)) == n ? 1 : 0;
}

int isRight(node *n) {
    if(n == NULL) return printf("O nó recebido é NULL!\n");
    else return right(father(n)) == n ? 1 : 0;
}

node *brother(node *n) {
    if(father(n) == NULL) return NULL;
    else return isLeft(n) == 1 ? right(father(n)) : left(father(n));
}

node *addLeft(node *n, int value) {
    return setNodeLeft(n, makeTree(value));
}

node *setNodeLeft(node *t, node *n) {
    t->left = n;
    n->father = t;

    return n;
}

node *addRight(node *n, int value) {
    return setNodeRight(n, makeTree(value));
}

node *setNodeRight(node *t, node *n) {
    t->right = n;
    n->father = t;

    return n;
}

void freeTree(node *t) {
    node *aux = father(t);

    if(t != NULL) {
        if(aux && isLeft(t)) aux->left = NULL;
        if(aux && isRight(t)) aux->right = NULL;

        freeTree(left(t));
        freeTree(right(t));
        free(t);
    }
    else printf("O nó recebido é NULL!\n");
}

void preOrdem(node *t) {
    if(t != NULL) {
        printf("[%d]", info(t));
        preOrdem(left(t));
        preOrdem(right(t));
    }
}

void emOrdem(node *t) {
    if(t != NULL) {
        emOrdem(left(t));
        printf("[%d]", info(t));
        emOrdem(right(t));
    }
}

void posOrdem(node *t) {
    if(t != NULL) {
        posOrdem(left(t));
        posOrdem(right(t));
        printf("[%d]", info(t));
    }
}
