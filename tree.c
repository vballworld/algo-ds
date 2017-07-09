/*
 binary search tree implementation
 */

#include <stdlib.h>
#include "tree.h"

/*static prototypes
 */
static tree_node_t* tree_initNode(int val);

/*return tree whose root has value val
 */
tree_t* tree_init(int val)
{
    tree_t* t = (tree_t*)malloc(sizeof(tree_t));
    t->root = tree_initNode(val);
    
    return t;
}

/*return a tree node that has value val
 */
static tree_node_t* tree_initNode(int val)
{
    tree_node_t* n = (tree_node_t*)malloc(sizeof(tree_node_t));
    n->left = NULL;
    n->right = NULL;
    n->val = val;
    
    return n;
}

/*recursively insert node into BST
 */
void tree_insert(tree_node_t* root, int val)
{
    if (val <= root->val)
    {
        if (root->left == NULL)
        {
            root->left = tree_initNode(val);
        }
        else
        {
            tree_insert(root->left, val);
        }
    }
    else
    {
        if (root->right == NULL)
        {
            root->right = tree_initNode(val);
        }
        else
        {
            tree_insert(root->right, val);
        }
    }
}

/*print tree in pre-order
 */
void tree_preOrder(tree_node_t* root)
{
    if (root == NULL)
    {
        return;
    }
    
    printf("%d ", root->val);
    
    tree_preOrder(root->left);
    tree_preOrder(root->right);
}

/*print tree in-order
 */
void tree_inOrder(tree_node_t* root)
{
    if (root == NULL)
    {
        return;
    }
    
    tree_inOrder(root->left);
    printf("%d ", root->val);
    tree_inOrder(root->right);
}

/*print tree in post-order
 */
void tree_postOrder(tree_node_t* root)
{
    if (root == NULL)
    {
        return;
    }
    
    tree_postOrder(root->left);
    tree_postOrder(root->right);
    printf("%d ", root->val);
}


