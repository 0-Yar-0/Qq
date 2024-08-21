#include "bst.h"
#include <stdio.h>

t_btree* bstree_create_node(int item)
{
    t_btree* node = (t_btree*)malloc(sizeof(t_btree));
    if (!node)
        return NULL;

    node->item = item;
    node->left = NULL;
    node->right = NULL;

    return node;
}

void bstree_insert(t_btree* root, int item, int (*cmpf)(int, int))
{
    if (!root)
        return;

    if (cmpf(item, root->item) < 0)
    {
        if (root->left)
            bstree_insert(root->left, item, cmpf);
        else
            root->left = bstree_create_node(item);
    }
    else
    {
        if (root->right)
            bstree_insert(root->right, item, cmpf);
        else
            root->right = bstree_create_node(item);
    }
}

int bstree_cmp(int a, int b)
{
    if (a < b)
        return -1;
    else if (a > b)
        return 1;
    else
        return 0;
}

void bstree_apply_infix(t_btree* root, void (*applyf)(int))
{
    if (!root)
        return;
    bstree_apply_infix(root->left, applyf);
    applyf(root->item);
    bstree_apply_infix(root->right, applyf);
}

void bstree_apply_prefix(t_btree* root, void (*applyf)(int))
{
    if (!root)
        return;
    applyf(root->item);
    bstree_apply_prefix(root->left, applyf);
    bstree_apply_prefix(root->right, applyf);
}

void bstree_apply_postfix(t_btree* root, void (*applyf)(int))
{
    if (!root)
        return;
    bstree_apply_postfix(root->left, applyf);
    bstree_apply_postfix(root->right, applyf);
    applyf(root->item);
}

void applyf(int item)
{
    printf("%d ", item);
}
