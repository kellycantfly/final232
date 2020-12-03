#include <string>
#include <iostream>
#include "account.h"
using namespace std;

class BST {
    private:
        struct Node
        {
            Account* acc;
            Node* left;
            Node* right;
        };

        Node* root;

        void print(const Node* nodePtr) const;
        void insertNode(Node*& nodePtr, Node*& newNode);

    public:
        BST();
        void insert(Account& account);
        void insert(Node*& nodePtr, Node* newNode);
        void print() const;
};