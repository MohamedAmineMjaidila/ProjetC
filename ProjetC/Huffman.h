#pragma once

#include <stdint.h>

#define space 5

struct Code {
    char* code;
    int length;
};

typedef uint8_t Hex;
typedef uint16_t Hex2;

struct Node {
    Hex2 val;
    int depth;
    struct Node* parent;
    struct Node* left;
    struct Node* right;
    bool is_full;
};

typedef struct Node Node;

void add_node_right(Node* node_src, int val);
void add_node_left(Node* node_src, int val);
void add_next(Node* node);
void find_next(Node* node);
bool add_node_at_hight(Node* root, int depth, int val);
Node* build_huffman_tree(Hex* huffman_lengths, Hex2* huffman_symbols,int* count);
void draw_tree_hor(Node* Node);
void draw_tree_hor2(Node* tra, int depth, char* path, int right);
Hex2 get_symbole_from_code(Node* root, Code* code);