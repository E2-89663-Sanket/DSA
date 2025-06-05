#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int data;
    struct node *left;
    struct node *right;
}node_t;

typedef struct bst{
    node_t *root;
    
}bst_t;

void init_bst(bst_t *bst)
{
    bst->root = NULL;

}

int isempty(bst_t *bst)
{
    return bst->root == NULL;

}

node_t *create_node(int value)
{
    node_t *nn = (node_t *) malloc(sizeof (node_t ));
    nn ->data = value;
    nn->left = nn->right = NULL;
    return nn;

}

void add_node(bst_t *bst, int value)
{
    node_t *newnode = create_node(value);
    if(bst->root == NULL)
    bst->root = newnode;
    else {
        node_t *trav = bst->root;
        while(1){
            if(value <trav->data){
                if(trav->left == NULL){
                    trav->left = newnode;
                    break;
                }
                else
                trav = trav->left; 
            }
            else{
                if(trav->right == NULL){
                    trav->right = newnode;
                    break;
                }
                else
                trav = trav->right;

            }

        }
    }
}

void preorder (node_t *trav){
    if(trav == NULL)
    return ;
    printf("%-4d", trav->data);
    preorder(trav->left );
    preorder(trav->right);

}

void inorder(node_t *trav)
{
    if(trav == NULL)
    return;
    inorder(trav->left);
    printf("%-4d", trav->data);
    inorder(trav->right);
}

void postorder(node_t *trav)
{
    if(trav == NULL)
    return ;
    postorder(trav->left);
    postorder(trav->right);
    printf("%-4d", trav->data);    
}

node_t *binary_search(bst_t *bst, int key){
    node_t *trav =bst->root;
    while(trav != NULL){
        if(key == trav->data)
        return trav;
        else if(key < trav->data)
        trav = trav->left;
        else
        trav = trav->right;
    }
    return NULL;
}

void delete_node(bst_t *bst, int key)
{
    node_t *trav = bst->root;
    node_t *parent = NULL;
    while(trav != NULL){
        if(key == trav->data)
        break;
        parent = trav;
        if(key < trav->data )
        trav = trav->left;
        else 
        trav = trav->right;
    }
    if(trav == NULL)
    return;
    if(trav->left != NULL && trav -> right != NULL){
        node_t *pred = trav->left;
        parent = trav;
        while(pred->right != NULL){
            parent = pred;
            pred = pred->right;
        }
        trav->data = pred->data;
        trav = pred;
    }
    if(trav->left != NULL){
        if(trav == bst->root)
        bst->root = trav->left;
        else if(trav == parent->left)
        parent->left = trav->left;
        else if(trav ==  parent->right)
        parent->right = trav->left;
    }
    else{
        if(trav == bst ->root)
        bst->root = trav->right;
        else if(trav == parent->left)
        parent->left = trav->right;
        else if(trav == parent->right)
        parent->right = trav->right;
    }
    free(trav);
}

void delete_all(node_t *trav)
{
    if(trav == NULL)
    return;
    delete_all(trav->left);
    delete_all(trav->right);
    free(trav);
}

void DFS_traversal(bst_t *bst)
{
    node_t *st[10]; int top = -1;
    st[++top] = bst->root;
    printf("DFS traversal : ");
    while(top != -1){
        node_t *trav = st[top--];
        printf("%-4d", trav->data);
        if(trav->right != NULL)
        st[++top] = trav->right;
        if(trav->left != NULL)
        st[++top] = trav->left;

    }
    printf("\n");

}

void BFS_traversal(bst_t *bst)
{
    node_t *q[5]; int front = -1,rear = -1, count = 0;
    rear = (rear + 1)%5;
    q[rear] = bst->root;
    count++;
printf("BFS Traversal : ");
    while(count != 0){
        //2. pop node from queue
        node_t *trav = q[(front + 1) % 5];
        front = (front + 1) % 5;
        count--;
        //3. visit the current node
        printf("%-4d", trav->data);
        //4. if left exist, push it on queue
        if(trav->left != NULL){
            rear = (rear + 1) % 5;
            q[rear] = trav->left;
            count++;   
        }
        //5. if right exists, then push it on queue
        if(trav->right != NULL){
            rear = (rear + 1) % 5;
            q[rear] = trav->right;
            count++;   
        }
    }
    printf("\n");
}


int height(node_t *trav)
{
    //1. if tree is empty return -1
    if(trav == NULL)
        return -1;
    //2. find height of left sub tree
    int hl = height(trav->left);
    //3. find height of right sub tree
    int hr = height(trav->right);
    //4. find max height
    int max = hl > hr ? hl : hr;
    //5. return max height + 1
    return max + 1;
}

node_t* find_min(node_t* root) {
    while (root && root->left != NULL)
        root = root->left;
    return root;
}

node_t* find_successor(bst_t* bst, int key) {
    node_t* curr = bst->root;
    node_t* successor = NULL;

    while (curr != NULL) {
        if (key < curr->data) {
            successor = curr;
            curr = curr->left;
        }
        else if (key > curr->data) {
            curr = curr->right;
        }
        else {
            break;
        }
    }

    if (curr == NULL) {
        printf("Node with key %d not found.\n", key);
        return NULL;
    }

    // Extra condition: check if it's a leaf node
    if (curr->left == NULL && curr->right == NULL) {
        printf("Leaf node (%d) has no successor.\n", key);
        return NULL;
    }

    // If right subtree exists, successor is the minimum in right subtree
    if (curr->right != NULL) {
        successor = find_min(curr->right);
    }

    return successor;
}



int main()

{
    bst_t bst;
    init_bst(&bst);

    add_node(&bst, 8);
    add_node(&bst, 19);
    add_node(&bst, 2);
    add_node(&bst, 6);
    add_node(&bst, 1);
    add_node(&bst, 4);
    add_node(&bst, 5);
    add_node(&bst, 10);

    printf("preorder : ");
    preorder(bst.root);
    printf("\n");

    printf("inorder : ");
    inorder(bst.root);
    printf("\n");

    printf("postorder : ");
    postorder(bst.root);
    printf("\n");

    DFS_traversal(&bst);
    BFS_traversal(&bst);
    printf("height of bst : %d\n", height(bst.root));
    
    int key = 6;
    node_t* succ = find_successor(&bst, key);
    if (succ)
    printf("Successor of %d is %d\n", key, succ->data);

    
    return 0;


}