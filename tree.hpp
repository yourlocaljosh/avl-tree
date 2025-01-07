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

        Node* rotateRight(Node* y) {
            Node* x = y->left;
            Node* T2 = x->right;

            x->right = y;
            y->left = T2;

            y->height = std::max(height(y->left), height(y->right)) + 1;
            x->height = std::max(height(x->left), height(x->right)) + 1;

            return x;
        }

         Node* rotateLeft(Node* x) {
            Node* y = x->right;
            Node* T2 = y->left;

            y->left = x;
            x->right = T2;

            x->height = std::max(height(x->left), height(x->right)) + 1;
            y->height = std::max(height(y->left), height(y->right)) + 1;
            return y;
        }
};

#endif
