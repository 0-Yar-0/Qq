#include <stdio.h>
#include "bst.h"

void test_bstree_create_node(int item)
{
    t_btree* node = bstree_create_node(item);
    if (node)
    {
        printf("Node created with item = %d\n", node->item);
        printf("Node left = %p, right = %p\n", (void*)node->left, (void*)node->right);
    }
    else
    {
        printf("Failed to create node with item = %d\n", item);
    }

    free(node); 
}

int main()
{
    test_bstree_create_node(42);

    test_bstree_create_node(-1);

    return 0;
}
