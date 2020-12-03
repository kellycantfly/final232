<<<<<<< HEAD
#include <string>
#include <iostream>
#include "account.h"
#include "USER.h"
using namespace std;

class BST {
    private:
        struct Node
        {
            Account* acc;
            USER* user;
            Node* left;
            Node* right;
        };

        Node* root;

        void print(const Node* nodePtr) const;
        void insertNode(Node*& nodePtr, Node*& newNode);

    public:
        BST();
        void insert(Account& account);
        void insert(USER& use);
        void insert(Node*& nodePtr, Node* newNode);
        void print() const;

=======
#include <string>
#include <iostream>
#include "account.h"
#include "USER.h"
using namespace std;

class BST {
    private:
        struct Node
        {
            Account* acc;
            USER* user;
            Node* left;
            Node* right;
        };

        Node* root;

        void print(const Node* nodePtr) const;
        void insertNode(Node*& nodePtr, Node*& newNode);

    public:
        BST();
        void insert(Account& account);
        void insert(USER& use);
        void insert(Node*& nodePtr, Node* newNode);
        void print() const;

>>>>>>> 3766df0a8d8b69452f4201877bfaeec3ee7d16c6
};