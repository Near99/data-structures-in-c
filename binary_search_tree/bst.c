#include <stdio.h>
#include <stdlib.h>

#define MAX(X, Y) ((X) > (Y) ? (X) : (Y))

typedef struct tree
{
    struct tree *parent;
    struct tree *left;
    struct tree *right;
    int data;
} Tree;

Tree *bst_create();
void bst_insert(Tree **tree, int value, Tree *parent);
void bst_print_ascending(Tree *tree);
void bst_print_descending(Tree *tree);
int bst_get_min(Tree *tree);
int bst_get_max(Tree *tree);
int bst_node_count(Tree *tree);
int bst_get_height(Tree *tree);
void bst_traverse_inorder(Tree *tree);
void bst_traverse_preorder(Tree *tree);
void bst_traverse_postorder(Tree *tree);

// todos..
int bst_is_in_tree();
int bst_valid();
int bst_delete_node();
int bst_successor();

int main()
{
    Tree *tree = bst_create();

    // const int arr[] = {50, 20, 70, 15, 30, 10, 21, 22, 60, 100, 200};
    const int arr[] = {10, 5, 15, 2, 5, 22, 1};
    for (int i = 0; i < sizeof(arr) / sizeof(int); i++)
    {
        bst_insert(&tree, arr[i], tree);
    }
    int h = bst_get_height(tree);
    printf("%d\n", h);
    return 0;
}

Tree *bst_create()
{
    Tree *new_tree = NULL;
    return new_tree;
}

void bst_insert(Tree **tree, int value, Tree *parent)
{
    if (*tree == NULL)
    {
        Tree *new_node = malloc(sizeof(Tree));
        new_node->data = value;
        new_node->left = NULL;
        new_node->right = NULL;
        new_node->parent = parent;
        *tree = new_node;
    }
    else if ((*tree)->data > value)
    {
        bst_insert(&(*tree)->left, value, *tree);
    }
    else
    {
        bst_insert(&(*tree)->right, value, *tree);
    }
}

void bst_print_ascending(Tree *tree)
{
    if (tree == NULL)
    {
        return;
    }
    bst_print_ascending(tree->left);
    printf("%d\n", tree->data);
    bst_print_ascending(tree->right);
}

void bst_print_descending(Tree *tree)
{
    if (tree == NULL)
    {
        return;
    }
    bst_print_descending(tree->right);
    printf("%d\n", tree->data);
    bst_print_descending(tree->left);
}

int bst_get_min(Tree *tree)
{
    if (tree->left == NULL)
    {
        return tree->data;
    }
    bst_get_min(tree->left);
}

int bst_get_max(Tree *tree)
{
    if (tree->right == NULL)
    {
        return tree->data;
    }
    bst_get_max(tree->right);
}

int bst_node_count(Tree *tree)
{
    if (tree == NULL)
    {
        return 0;
    }
    printf("%d\n", tree->data);
    return 1 + bst_node_count(tree->left) + bst_node_count(tree->right);
}

// 1 2 5 5 10 15 22
void bst_traverse_inorder(Tree *tree)
{
    if (tree == NULL)
    {
        return;
    }
    bst_traverse_inorder(tree->left);
    printf("%d ", tree->data);
    bst_traverse_inorder(tree->right);
}

// 10 5 2 1 5 15 22
void bst_traverse_preorder(Tree *tree)
{
    if (tree == NULL)
    {
        return;
    }
    printf("%d ", tree->data);
    bst_traverse_preorder(tree->left);
    bst_traverse_preorder(tree->right);
}

// 1 2 5 5 22 15 10
void bst_traverse_postorder(Tree *tree)
{
    if (tree == NULL)
    {
        return;
    }
    bst_traverse_postorder(tree->left);
    bst_traverse_postorder(tree->right);
    printf("%d ", tree->data);
}

int bst_get_height(Tree *tree)
{
    if (tree == NULL)
    {
        return 0;
    }
    return 1 + MAX(bst_get_height(tree->left), bst_get_height(tree->right));
}
