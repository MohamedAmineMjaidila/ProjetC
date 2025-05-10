#include <stdlib.h>
#include <stdio.h>
#include "Huffman.h"


Node* create_node()
{
    Node* node = (Node*)malloc(sizeof(Node));
    node->depth = 0;
    node->val = 0;
    node->is_full = false;
    // NULL filling
    node->parent = NULL;
    node->right = NULL;
    node->left = NULL;
    return node;
}
Node* create_node(int val)
{
    Node* node = (Node*)malloc(sizeof(Node));
    node->depth = 0;
    node->val = val;
    node->is_full = false;
    // NULL filling
    node->parent = NULL;
    node->right = NULL;
    node->left = NULL;
    return node;
}

void add_node_right(Node* node_src, int val)
{
    Node* node_new = create_node(val);
    node_src->right = node_new;
    node_new->parent = node_src;
    node_new->depth = node_src->depth + 1;
    // NULL filling
    node_new->left = NULL;
    node_new->right = NULL;
}
void add_node_left(Node* node_src, int val)
{
    Node* node_new = create_node(val);
    node_src->left = node_new;
    node_new->parent = node_src;
    node_new->depth = node_src->depth + 1;
    // NULL filling
    node_new->left = NULL;
    node_new->right = NULL;
}

void add_next(Node* node)
{

}
void find_next(Node* node)
{

}


// Algorithm to build the Node giving priority to the left
// 0 is an impossible value for a symbol, it is given to the empty nodes then
// We build the nodes by going left, then right when we reach a leaf, therefore it is by recursion
bool add_node_at_hight(Node* root, int depth, int val)
{
    if (depth == 0)
    {
        root->val = 0;
        return false;
    }
    if (root->is_full == true)
    {
        return false;
    }
    // if we reach the depth
    else if (depth == 1)
    {

        // Check if we can add on the left or right
        // We don't need to check if the node is empty as it is impossible to find a zero node already built
        if (root->left == NULL)
        {
            add_node_left(root,val);
            root->left->is_full = true;
            return true;
        }
        else if (root->right == NULL)
        {
            add_node_right(root, val);
            root->right->is_full = true;
            return true;
        }
        return false;
    }
    // If we didn't reach the depth yet
    else if (depth > 1)
    {
        // If the left is NULL
        if (root->left == NULL)
        {
            add_node_left(root, 0);
            add_node_at_hight(root->left, depth - 1, val);
        }
        // If the left node is a zero, we go through the left subtree
        bool is_added = add_node_at_hight(root->left, depth - 1, val);
        // We stop the search if we find a leaf in the left subtree
        if (is_added)
        {
            return true;
        }
        // Now the right node
        else
        {
            if (root->right == NULL)
            {
                add_node_right(root, 0);
                add_node_at_hight(root->right, depth - 1, val);
            }
            else if(root->right->val == 0)
            {
                return add_node_at_hight(root->right, depth - 1, val);
            }
        }
    }
}

Node* build_huffman_tree(Hex* huffman_lengths, Hex2* huffman_symbols, int* count)
{
    //Every empty value will be given a 0, as 0 is impossible value to have as a symbol
    Node* root = create_node(0);
    int count_lengths = count[0];
    int count_symbols = count[1];
    int iteration_symbols = 0;
    for(int i = 0; i < count_lengths; i++)
    {
        // Iterations on the same length
        for (int j = 0;j < huffman_lengths[i]; j++)
        {
            Hex2 symbol = huffman_symbols[iteration_symbols];
            add_node_at_hight(root, i, symbol);
            iteration_symbols += 1;
            if (iteration_symbols == count_symbols)
            {
                return root;
            }
        }
    }
    return root;
}

Hex2 get_symbole_from_char(char* code)
{
    return NULL;
}

void draw_tree_hor2(Node* tra, int depth, char* path, int right)
{
    // stopping condition
    if (tra == NULL)
        return;

    // increase spacing
    depth++;

    // start with right Node
    draw_tree_hor2(tra->right, depth, path, 1);

    if (depth > 1)
    {
        // set | draw map
        path[depth - 2] = 0;

        if (right)
            path[depth - 2] = 1;
    }

    if (tra->left)
        path[depth - 1] = 1;

    // print root after spacing
    printf("\n");

    for (int i = 0; i < depth - 1; i++)
    {
        if (i == depth - 2)
            printf("+");
        else if (path[i])
            printf("|");
        else
            printf(" ");

        for (int j = 1; j < space; j++)
            if (i < depth - 2)
                printf(" ");
            else
                printf("-");
    }

    printf("%x\n", tra->val);

    // vertical spacers below
    for (int i = 0; i < depth; i++)
    {
        if (path[i])
            printf("|");
        else
            printf(" ");

        for (int j = 1; j < space; j++)
            printf(" ");
    }

    // go to left Node
    draw_tree_hor2(tra->left, depth, path, 0);
}

void draw_tree_hor(Node* Node)
{
    // should check if we don't exceed this somehow..
    char path[255] = {};
    //initial depth is 0
    draw_tree_hor2(Node, 0, path, 0);
}