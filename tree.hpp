#ifndef TREE_HPP
#define TREE_HPP

#include <algorithm>
#include <iostream>

struct Node{
    int datum;
    Node* left;
    Node* right;
    int height;

    Node(int n)
    :datum(n), left(nullptr), right(nullptr), height(1){};
};

//AVL tree
class Tree {
    private:
        Node* root;

        int height(Node * node){
            if(node){
                return node->height;
            }
            return 0;
        }

        int balanceFactor(Node * node){
            if(node){
                return height(node->left) - height(node->right);
            }
            return 0;
        }
};

#endif