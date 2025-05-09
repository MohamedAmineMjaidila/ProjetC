#pragma once

#include <stdint.h>

const uint8_t HUFFMAN_LENGTHS[] = {
    0x00, 0x02, 0x03
};

const uint16_t HUFFMAN_SYMBOLS[] = {
    0xA0, 0xB0, 0xC0
};

struct node {
    uint16_t val;
    int depth;
    struct node* parent;
    struct node* left;
    struct node* right;
    bool is_full;
};

typedef struct node tree;

tree* add_node_right(tree* node_src, int val);
void add_node_left(tree* node_src, int val);
tree* add_next(tree* node);
tree* find_next(tree* node);
bool add_node_at_hight(tree* root, int depth, int val);