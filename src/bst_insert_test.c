#include <stdio.h>
#include "bst.h"

void test_bstree_insert(t_btree* root, int item)
{
    printf("Inserting item: %d\n", item);
    bstree_insert(root, item, bstree_cmp);
    printf("Root: %d\n", root->item);
    if (root->left)
        printf("Left child: %d\n", root->left->item);
    if (root->right)
        printf("Right child: %d\n", root->right->item);
    printf("\n");
}

int main()
{
    t_btree* root = bstree_create_node(10);
    printf("Root node created with item: %d\n\n", root->item);

    test_bstree_insert(root, 5);

    test_bstree_insert(root, 15);

    test_bstree_insert(root, 8);

    test_bstree_insert(root, 20);

    free(root->left->left);
    free(root->left);
    free(root->right->right);
    free(root->right);
    free(root);

    return 0;
}
