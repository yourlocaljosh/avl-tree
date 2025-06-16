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

        Node* insert(Node* node, int key) {
            if (!node) return new Node(key);
        
            if (key < node->datum){
                node->left = insert(node->left, key);
            }
            else if (key > node->datum){
                node->right = insert(node->right, key);
            }
            else{
                return node;
            }//Dupes banned
            //updates height
            node->height = 1 + std::max(height(node->left), height(node->right));
            int balance = balanceFactor(node);
            // Left Left Rebalance
            if (balance > 1 && key < node->left->datum){
                return rotateRight(node);
            }
            // Right Right Rebalance
            if (balance < -1 && key > node->right->datum){
                return rotateLeft(node);
            }
            // Left Right Rebalance
            if (balance > 1 && key > node->left->datum){
                node->left = rotateLeft(node->left);
                return rotateRight(node);
            }
            // Right Left Rebalance
            if (balance < -1 && key < node->right->datum){
                node->right = rotateRight(node->right);
                return rotateLeft(node);
            }
            return node;
        }

        //Helper function for public function
        bool find(Node* node, int key) const {
            if(!node){
                return false;
            }
            if(key == node->datum){
                return true;
            }
            if(key < node->datum){
                return find(node->left, key);
            }
            else{
                return find(node->right, key);
            }
        }

    public:

        Tree():
            root(nullptr){}
            
        void insert(int key){
            root = insert(root, key);
        }

        Node* getRoot() const{
            return root;
        }

        bool find(int key) const {
            return find(root, key);
        }

        void printInOrder(Node* node){
            if(!node){
                return;
            }
            printInOrder(node->left);
            std::cout << node->datum << " ";
            printInOrder(node->right);
        }

        void printBalance(Node* node){
            if(!node){
                return;
            }
            printBalance(node->left);//recursive leap of FAITH
            int leftHeight = 0;
            int rightHeight = 0;
        
            if (node->left){
                leftHeight = node->left->height;
            }
        
            if (node->right){
                rightHeight = node->right->height;
            }
            int factor = leftHeight - rightHeight;
        
            std::cout << "Node " << node->datum 
            << " | Height: " << node->height 
            << " | Balance Factor: " << factor << std::endl;
            printBalance(node->right);
        }
};

#endif
