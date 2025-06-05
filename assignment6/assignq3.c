#include <stdio.h>
#include <stdlib.h>


typedef struct node {
    int data;
    struct node *left;
    struct node *right;
} node_t;
typedef struct bst {
    node_t *root;
} bst_t;
void init_bst(bst_t *bst) {
    bst->root = NULL;
}
int isEmpty(bst_t *bst) {
    return bst->root == NULL;
}
node_t *create_node(int value) {
    node_t *nn = (node_t *)malloc(sizeof(node_t));
    nn->data = value;
    nn->left = nn->right = NULL;
    return nn;
}

node_t* add_node_recursive(node_t *root, int value) {
    if (root == NULL) {
        return create_node(value);
    }

    if (value < root->data)
        root->left = add_node_recursive(root->left, value);
    else
        root->right = add_node_recursive(root->right, value);

    return root;
}

void add_Node(bst_t *bst, int value) {
    bst->root = add_node_recursive(bst->root, value);
}


void preorder(node_t *trav) {
    if (trav == NULL)
        return;
    printf("%-4d", trav->data);
    preorder(trav->left);
    preorder(trav->right);
}


int main(void) {
    bst_t bst;
    init_bst(&bst);
    add_Node(&bst, 8);
    add_Node(&bst, 3);
    add_Node(&bst, 10);
    add_Node(&bst, 2);
    add_Node(&bst, 15);
    add_Node(&bst, 6);
    add_Node(&bst, 14);
    add_Node(&bst, 4);
    add_Node(&bst, 7);
   printf("Preorder : ");
    preorder(bst.root);
    printf("\n");

    return 0;
}
