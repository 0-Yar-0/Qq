#include <stdio.h>
#include "bst.h"

int main()
{
    t_btree* root = bstree_create_node(10);
    bstree_insert(root, 5, bstree_cmp);
    bstree_insert(root, 15, bstree_cmp);
    bstree_insert(root, 8, bstree_cmp);
    bstree_insert(root, 20, bstree_cmp);

    printf("Infix order: ");
    bstree_apply_infix(root, applyf);
    printf("\n");

    printf("Prefix order: ");
    bstree_apply_prefix(root, applyf);
    printf("\n");

    printf("Postfix order: ");
    bstree_apply_postfix(root, applyf);
    printf("\n");

    free(root->left->left);
    free(root->left);
    free(root->right->right);
    free(root->right);
    free(root);

    return 0;
}
