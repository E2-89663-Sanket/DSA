#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *left;
    struct node *right;
} node_t;

typedef struct bst
{
    node_t *root;
} bst_t;

void bst_init(bst_t *tree)
{
    tree->root = NULL;
}
node_t *create_node(int value)
{
    node_t *newnode = (node_t *)malloc(sizeof(node_t));
    newnode->data = value;
    newnode->right = newnode->left = NULL;
    return newnode;
}

void add_node(bst_t *tree, int value)
{
    node_t *newnode = create_node(value);

    if (tree->root == NULL)
    {
        tree->root = newnode;
    }
    else
    {
        node_t *trav = tree->root;
        while (1)
        {
            if (value < trav->data)
            {
                if (trav->left == NULL)
                {
                    trav->left = newnode;
                    break;
                }
                else
                {
                    trav = trav->left;
                }
            }
            else
            {
                if (trav->right == NULL)
                {
                    trav->right = newnode;
                    break;
                }
                else
                {
                    trav = trav->right;
                }
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
void Inorder(node_t *trav)
{
    if (trav == NULL)
        return;
    Inorder(trav->left);
    printf("%-4d", trav->data);
    Inorder(trav->right);
}

void postorder(node_t *trav)
{
    if (trav == NULL)
        return;
    printf("%-4d", trav->data);
    postorder(trav->left);
    postorder(trav->right);
}
node_t *binary_search(bst_t *tree, int key)
{
    node_t *trav = tree->root;

    while (trav != NULL)
    {
        if (trav->data == key)
            return trav;
        else if (trav->data > key)
        {
            trav = trav->left;
        }
        else
        {
            trav = trav->right;
        }
    }
    return NULL;
}
node_t *binary_search_rec(node_t *root, int key){
    if(root == NULL || root->data == key){
        return root;
    if(key < root->data)
        return binary_search_rec(root->left, key);
    else
        return binary_search_rec(root->right, key);
    }
}

void delete_all(node_t *trav)
{
    if (trav == NULL)
        return;
    delete_all(trav->left);
    delete_all(trav->right);
    free(trav);
}

void delete_node(bst_t *bst, int key)
{
    node_t *trav = bst->root;
    node_t *parent = NULL;

    while (trav != NULL)
    {
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
    if (trav->left != NULL && trav->right != NULL)
    {
        node_t *pred = trav->left;
        parent = trav;
        while (pred->right != NULL)
        {
            parent = pred;
            pred = pred->right;
        }
        trav->data = pred->data;
        trav = pred;
    }
    if (trav->left != NULL)
    {
        if (trav == bst->root)
            bst->root = trav->left;
        else if (trav == parent->left)
            parent->left = trav->left;
        else if (trav == parent->right)
            parent->right = trav->right;
    }
    else{
        if(trav == bst->root)
            bst->root = trav->right;
        else if(trav== parent->left)
            parent->left = trav->right;
        else if(trav == parent->right)
            parent->right = trav->right;
    }
    free(trav);
}

void DFS_Traversal(bst_t *tree){
    node_t *st[10];
    int top = -1;

    st[++top] = tree->root;
    
    printf("DFS Traversal: ");
    while(top != -1){
        node_t *trav = st[top--];

        printf("%-4d",trav->data);
        
        if(trav->right != NULL)
            st[++top]=trav->right;
        if(trav->left != NULL)
            st[++top]=trav->left;
    }
printf(" \n");
}

void BFS_traversal(bst_t *bst)
{
    node_t *q[5]; int front = -1, rear = -1, count = 0;

    rear = (rear + 1) % 5;
    q[rear] = bst->root;
    count++;

    printf("BFS Traversal :  ");
    while(count != 0){
        node_t *trav = q[(front + 1) % 5];
        front = (front +1) % 5;
        count--;

        printf("%-4d",trav->data);

        if(trav->left != NULL){
            rear = (rear +1 ) % 5;
            q[rear] = trav->left;
            count++;
        }
        if(trav->right != NULL){
            rear = (rear + 1) % 5;
            q[rear] = trav->right;
            count++;
        }
    }
    printf("\n");
}
int height(node_t *trav){
    if(trav == NULL)
        return -1;
    int hl = height(trav->left);

    int hr = height(trav->right);

    int max = hl > hr ? hl : hr;

    return max+1;
}

int node_depth(bst_t *tree, node_t *trav, int key){
  
  trav = tree->root;
  int depth = 0;

    while (trav != NULL)
    {
        if (trav->data == key)

            return depth++;
        else if (trav->data > key)
        {
            depth++;
            trav = trav->left;
        }
        else
        {
            depth++;
            trav = trav->right;
        }
    }

}
int main(void)
{

    bst_t bst;
    bst_init(&bst);

    add_node(&bst, 8);
    add_node(&bst, 3);
    add_node(&bst, 10);
    add_node(&bst, 2);
    add_node(&bst, 15);
    add_node(&bst, 6);
    add_node(&bst, 14);
    add_node(&bst, 4);
    add_node(&bst, 7);

    int key = 7;

    DFS_Traversal(&bst);
   // BFS_traversal(&bst);

     node_t *ret = binary_search_rec(bst.root, key);

    printf("Key %d is found at %u \n", key, ret);

    int depth_node = node_depth(&bst, bst.root, key);
    printf("Node : %d has depth of : %d\n", key, depth_node);
    

 //   printf("Height of BST : %d\n", height(bst.root));

    delete_all(bst.root);
    bst.root = NULL;
    return 0;
}