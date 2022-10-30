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

node *addLeft(node *tree, int value);
node *setNodeLeft(node *tree, node *n);
node *addRight(node *tree, int value);
node *setNodeRight(node *tree, node *n);
void freeTree(node *tree);
void verifyParent(node *tree);
void freePosOrdem(node *tree);

void preOrdem(node *tree);
void emOrdem(node *tree);
void posOrdem(node *tree);

int isLeaf(node *n);
node *root(node *n);
int level(node *n);
int depth(node *n);
int isEstrita(node *tree);
int isCompleta(node *tree);
int length(node *tree);
int larger(node *tree);
int sum(node *tree);

int main() {
    setlocale(LC_ALL, "");

    node *tree = makeTree(14);
    addLeft(addLeft(tree, 4), 3);
    addRight(left(tree), 10);
    addLeft(addRight(tree, 22), 18);
    addRight(right(tree), 25);

    printf("Pré-ordem: ");
    preOrdem(tree);
    printf("\nEm ordem: ");
    emOrdem(tree);
    printf("\nPós-ordem: ");
    posOrdem(tree);
    printf("\n");

    freeTree(tree);
    return 0;
};

node *makeTree(int value) {
    node *n = (node *) malloc(sizeof (node));
    n->info = value;
    n->right = n->left = n->father = NULL;

    return n;
}

int info(node *n) {
    return n == NULL ? printf("Unable to access information from a null node\n") : n->info;
}

node *left(node *n) {
    if(n == NULL) printf("Cannot access child of a null node\n");
    else return n->left;
}

node *right(node *n) {
    if(n == NULL) printf("Cannot access child of a null node\n");
    else return n->right;
}

node *father(node *n) {
    return n->father;
}

int isLeft(node *n) {
    return father(n) == NULL ? 0 : left(father(n)) == n ? 1 : 0;
}

int isRight(node *n) {
    return father(n) == NULL ? 0 : right(father(n)) == n ? 1 : 0;
}

node *brother(node *n) {
    if(father(n)) return isLeft(n) ? right(father(n)) : left(father(n));
    else return NULL;
}

node *addLeft(node *tree, int value) {
    return setNodeLeft(tree, makeTree(value));
}

node *setNodeLeft(node *tree, node *n) {
    tree->left = n;
    n->father = tree;

    return n;
}

node *addRight(node *tree, int value) {
    return setNodeRight(tree, makeTree(value));
}

node *setNodeRight(node *tree, node *n) {
    tree->right = n;
    n->father = tree;

    return n;
}

void freeTree(node *tree) {
    if(tree != NULL) {
        verifyParent(tree);
        freePosOrdem(tree);
    }
    else return;
}

void verifyParent(node *tree) {
    node *parent = father(tree);

    if(parent != NULL) {
        if(isLeft(tree)) parent->left = NULL;
        else parent->right = NULL;
    }
    else return;
}

void freePosOrdem(node *tree) {
    freeTree(left(tree));
    freeTree(right(tree));
    free(tree);
}

void preOrdem(node *tree) {
    if(tree != NULL) {
        printf("[%d]", info(tree));
        preOrdem(left(tree));
        preOrdem(right(tree));
    }
    else return;
}

void emOrdem(node *tree) {
    if(tree != NULL) {
        emOrdem(left(tree));
        printf("[%d]", info(tree));
        emOrdem(right(tree));
    }
    else return;
}

void posOrdem(node *tree) {
    if(tree != NULL) {
        posOrdem(left(tree));
        posOrdem(right(tree));
        printf("[%d]", info(tree));
    }
    else return;
}

int isLeaf(node *n) {
    return left(n) == NULL && right(n) == NULL;
}

node *root(node *n) {

}

int level(node *n) {

}

int depth(node *n) {

}

int isEstrita(node *tree) {

}

int isCompleta(node *tree) {

}

int length(node *tree) {

}

int larger(node *tree) {

}

int sum(node *tree) {

}
