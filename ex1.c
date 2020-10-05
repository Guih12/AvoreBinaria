#include <stdio.h>
#include <stdlib.h>


typedef struct sTree{
    int element;
    struct sTree *left;
    struct sTree *right;

}TREE;

void initTree(TREE **sTree){
    *sTree = NULL;
}

TREE* getNode(){
    return (TREE*)malloc(sizeof(TREE));
}

int empty(TREE *Stree){
    if(Stree == NULL) return 1;
    
    return 0;
}


void insertElement(TREE **sTree, int element){
    TREE *node;
    if(empty(*sTree)){
        node = getNode();
        node->left = NULL;
        node->right = NULL;
        node->element = element;
        *sTree = node;
    }
    else{
        if(element < (*sTree)->element){
            insertElement(&((*sTree)->left), element);
        }
        else{
            insertElement(&((*sTree)->right), element);
        }
    }
}


int height(TREE *sTree){
    if(empty(sTree)){
        return 1;
    }
    int height_left = height((sTree)->left);
    int height_right = height((sTree)->right);

    if(height_left > height_right){
        return (height_left + 1);
    }
    else{
        return (height_right + 1);
    }
}


int totalTree(TREE *sTree){
    if(empty(sTree)){
        return 0;
    }
    int height_left = totalTree((sTree)->left);
    int height_right = totalTree((sTree)->right);
    return (height_left + height_right) + 1;

}

int totalLeaf(TREE *sTree){
    if(empty(sTree)){
        return 0;
    }
    else{
    
        if(!empty(sTree->left) || !empty(sTree->right)){

            int leaf_left = totalLeaf((sTree)->left);
            int leaf_right = totalLeaf((sTree)->right);
            return (leaf_right + leaf_left);
        }
        return 1;
    }
}

void visit(TREE *sTree){
    printf("%d\t", sTree->element);
}

void pre_order(TREE *sTree){
    if(empty(sTree)){
        return;
    }
    else{
        visit(sTree);
        pre_order((sTree)->left);
        pre_order((sTree)->right);
    }
}

void order(TREE *sTree){
    if(empty(sTree)){
        return;
    }
    else{
        pre_order((sTree)->left);
        visit(sTree);
        pre_order((sTree)->right);
    }
}

void pos_order(TREE *sTree){
    if(empty(sTree)){
        return;
    }
    else{
        pre_order((sTree)->left);
        pre_order((sTree)->right);
        visit(sTree);
    }
}
void search(TREE *sTree, int element){
    if(element == sTree->element){
        printf("elemento buscado: %d\n", sTree->element);
    }
    else{
        if(element < sTree->element){
            search((sTree)->left, element);
        }
        else{
            search((sTree)->right, element);
        }
    }
}
void bigElementRight(TREE *sTree){
    if(!empty(sTree->right)){
        maiorElementRight(sTree->right);
    }
    else{
        visit(sTree);
    }
}

void smallElementLeft(TREE *sTree){
    if(!empty(sTree->left)){
        minorElementLeft(sTree->left);
    }
    else{
        visit(sTree);
    }
}

int main(){
    int options, element;
    TREE *raiz;
    initTree(&raiz);
   
    do{
        printf("1 - inserir elemento\n");
        printf("2 - listar em pre ordem\n");
        printf("3 - listar em ordem\n");
        printf("4 - listar em pos ordem\n");
        printf("5 - altura da arvore\n");
        printf("6 - total de nó\n");
        printf("7 - total de folhas\n");
        printf("8 - buscar elemento\n");
        printf("9 - maior elemento da arvore\n");
        printf("10 - menor elemento da arvore\n");
        scanf("%d", &options);

        switch(options){
            case 1:
                printf("Digite um elemento: ");
                scanf("%d", &element);
                insertElement(&raiz, element);
            break;

            case 2:
                pre_order(raiz);
                printf("\n");
            break;

            case 3:
                order(raiz);
                printf("\n");
            break;

            case 4:
               pos_order(raiz);
               printf("\n");
            break;

            case 5:
                printf("altura: %d\n", height(raiz));
            break;

            case 6:
                printf("total de arvore: %d\n", totalTree(raiz));
            break;


            case 7:
                printf("Total de folhas: %d", totalLeaf(raiz));
            break;

            case 8:
                printf("Digite o elemento a ser procurado: ");
                scanf("%d", &element);
                search(raiz, element);
            break;

            case 9:
                bigElementRight(raiz);
            break;

            case 10:
                smallElementLeft(raiz);
            break;
        }
        printf("\n");
    }while(options!=0);


}