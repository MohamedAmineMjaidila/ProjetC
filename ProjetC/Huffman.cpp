#include <stdlib.h>
#include <stdio.h>

struct node {
    int val;
    int depth;
    struct node* parent;
    struct node* left;
    struct node* right;
    bool is_full;
};

typedef struct node tree;

tree* create_node(int val)
{
    tree* node = (tree*)malloc(sizeof(tree));
    node->depth = 0;
    node->val = val;
    node->is_full = false;
    // NULL filling
    node->parent = NULL;
    node->right = NULL;
    node->left = NULL;
    return node;
}

tree* add_node_right(tree* node_src, int val)
{
    tree* node_new = create_node(val);
    node_src->right = node_new;
    node_new->parent = node_src;
    node_new->depth = node_src->depth + 1;
    // NULL filling
    node_new->left = NULL;
    node_new->right = NULL;
}

void add_node_left(tree* node_src, int val)
{
    tree* node_new = create_node(val);
    node_src->left = node_new;
    node_new->parent = node_src;
    node_new->depth = node_src->depth + 1;
    // NULL filling
    node_new->left = NULL;
    node_new->right = NULL;
}
tree* add_next(tree* node)
{

}

tree* find_next(tree* node)
{

}

bool add_node_at_hight(tree* root, int depth, int val)
{
    if (depth == 0 && root->is_full == true)
    {
        return false;
    }
    else if (depth == 1)
    {
        if (root->left == NULL)
        {
            add_node_left(root,val);
            return true;
        }
        else if (root->right == NULL)
        {
            add_node_right(root, val);
            return true;
        }
        else
        {
            if(root->parent == NULL && root->parent->right = root)
            {
                
            }
        }
    }
    else if (root->left == NULL && depth > 1)
    {
        bool is_added = add_node_at_hight(root->left, depth - 1, val);
        if (is_added == true)
        {
            return is_added;
        }
        is_added = add_node_at_hight(root->right, depth - 1, val);
        return is_added;
    }
}