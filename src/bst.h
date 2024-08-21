#ifndef BST_H
#define BST_H

#include <stdlib.h>

typedef struct s_btree
{
    int item;
    struct s_btree* left;
    struct s_btree* right;
} t_btree;

t_btree* bstree_create_node(int item);
void bstree_insert(t_btree* root, int item, int (*cmpf)(int, int));

void bstree_apply_infix(t_btree* root, void (*applyf)(int));
void bstree_apply_prefix(t_btree* root, void (*applyf)(int));
void bstree_apply_postfix(t_btree* root, void (*applyf)(int));

int bstree_cmp(int a, int b);

#endif // BST_H