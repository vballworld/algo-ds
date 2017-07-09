/*
 binary tree implementation
 */

#ifndef tree_h
#define tree_h

#include <stdio.h>

typedef struct tree_node_t
{
    int val;
    struct tree_node_t* left;
    struct tree_node_t* right;
} tree_node_t;

typedef struct tree_t
{
    tree_node_t* root;
} tree_t;

tree_t* tree_init(int val);
void tree_add(tree_node_t* root, int val);

void tree_preOrder(tree_node_t* root);
void tree_inOrder(tree_node_t* root);
void tree_postOrder(tree_node_t* root);

#endif /* tree_h */
