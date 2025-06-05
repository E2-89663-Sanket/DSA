
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

void init_bst(bst_t *bst)
{
    bst->root = NULL;
}

int isEmpty(bst_t *bst)
{
    return bst->root == NULL;
}

node_t *create_node(int value)
{
    node_t *nn = (node_t *)malloc(sizeof(node_t));
    nn->data = value;
    nn->left = nn->right = NULL;
    return nn;
}

void add_Node(bst_t *bst, int value)
{
    node_t *newnode = create_node(value);
    if (bst->root == NULL)
        bst->root = newnode;
    else {
        node_t *trav = bst->root;
        while (1) {
            if (value < trav->data) {
                if (trav->left == NULL) {
                    trav->left = newnode;
                    break;
                }
                else
                    trav = trav->left;
            }
            else {
                if (trav->right == NULL) {
                    trav->right = newnode;
                    break;
                }
                else
                    trav = trav->right;
            }
        }
    }
}

void preorder(node_t *trav)
{
    if (trav == NULL)
        return;
    printf("%-4d", trav->data);
    preorder(trav->left);
    preorder(trav->right);
}

void inorder(node_t *trav)
{
    if (trav == NULL)
        return;
    inorder(trav->left);
    printf("%-4d", trav->data);
    inorder(trav->right);
}

void postorder(node_t *trav)
{
    if (trav == NULL)
        return;
    postorder(trav->left);
    postorder(trav->right);
    printf("%-4d", trav->data);
}

node_t *binary_search(bst_t *bst, int key)
{
    node_t *trav = bst->root;
    while (trav != NULL) {
        if (key == trav->data)
            return trav;
        else if (key < trav->data)
            trav = trav->left;
        else
            trav = trav->right;
    }
    return NULL;
}


node_t *binary_search_recursive(node_t *trav, int key)
{
    if (trav == NULL || trav->data == key)
        return trav;

    if (key < trav->data)
        return binary_search_recursive(trav->left, key);

    return binary_search_recursive(trav->right, key);
}

void delete_Node(bst_t *bst, int key)
{
    node_t *trav = bst->root;
    node_t *parent = NULL;
    while (trav != NULL) {
        if (key == trav->data)
            break;
        parent = trav;
        if (key < trav->data)
            trav = trav->left;
        else
            trav = trav->right;
    }

    if (trav == NULL)
        return;

    if (trav->left != NULL && trav->right != NULL) {
        node_t *pred = trav->left;
        parent = trav;
        while (pred->right != NULL) {
            parent = pred;
            pred = pred->right;
        }
        trav->data = pred->data;
        trav = pred;
    }

    if (trav->left != NULL) {
        if (trav == bst->root)
            bst->root = trav->left;
        else if (trav == parent->left)
            parent->left = trav->left;
        else if (trav == parent->right)
            parent->right = trav->left;
    }
    else {
        if (trav == bst->root)
            bst->root = trav->right;
        else if (trav == parent->left)
            parent->left = trav->right;
        else if (trav == parent->right)
            parent->right = trav->right;
    }
    free(trav);
}

void delete_all(node_t *trav)
{
    if (trav == NULL)
        return;
    delete_all(trav->left);
    delete_all(trav->right);
    free(trav);
}

void DFS_traversal(bst_t *bst)
{
    node_t *st[10];
    int top = -1;
    st[++top] = bst->root;
    printf("DFS Traversal : ");
    while (top != -1) {
        node_t *trav = st[top--];
        printf("%-4d", trav->data);
        if (trav->right != NULL)
            st[++top] = trav->right;
        if (trav->left != NULL)
            st[++top] = trav->left;
    }
    printf("\n");
}

void BFS_traversal(bst_t *bst)
{
    node_t *q[5];
    int front = -1, rear = -1, count = 0;
    rear = (rear + 1) % 5;
    q[rear] = bst->root;
    count++;
    printf("BFS Traversal : ");
    while (count != 0) {
        node_t *trav = q[(front + 1) % 5];
        front = (front + 1) % 5;
        count--;
        printf("%-4d", trav->data);
        if (trav->left != NULL) {
            rear = (rear + 1) % 5;
            q[rear] = trav->left;
            count++;
        }
        if (trav->right != NULL) {
            rear = (rear + 1) % 5;
            q[rear] = trav->right;
            count++;
        }
    }
    printf("\n");
}

int height(node_t *trav)
{
    if (trav == NULL)
        return -1;
    int hl = height(trav->left);
    int hr = height(trav->right);
    return (hl > hr ? hl : hr) + 1;
}

int main(void)
{
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

    printf("Inorder : ");
    inorder(bst.root);
    printf("\n");

    printf("Postorder : ");
    postorder(bst.root);
    printf("\n");

    
    int key = 6;
    node_t *ret = binary_search_recursive(bst.root, key);
    if (ret != NULL)
        printf("Key %d found (Recursive), addr = %p\n", key, (void *)ret);
    else
        printf("Key %d not found (Recursive)\n", key);

    DFS_traversal(&bst);
    BFS_traversal(&bst);

    printf("Height of BST : %d\n", height(bst.root));

    delete_all(bst.root);
    bst.root = NULL;

    return 0;
}
