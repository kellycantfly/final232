#ifndef BST_H
#define BST_H

#include <string>
#include <iostream>
#include <fstream>
using namespace std;

class BST
{
	private:
		struct Node
		{
			string name, phone; // holds a first and last name and a phone number
			int aptNum; // holds an apartment number
			Node* left; // Node to left
			Node* right; // Node to right
		};

		Node* root; // Initial Node

		void insertNode(Node*&, Node*&);
		bool searchNode(Node*&, int);
		bool searchAptNum(Node*&, int);
		void print(Node*) const;
		bool checkValid(string num);
		bool printToFile(Node*& nodePtr,ofstream&);
		void deleteAll(Node* nodePtr);
		int treeHeight(Node* nodePtr);
		int numNodes(Node* nodePtr);


	public:
		BST();
		~BST();
		void insert(string num, string aptName, string aptPhone);
		void addTenant();
		bool search(int);
		void print() const;
		void readFile(string file);
		void remove(int);
		bool upload(ofstream&);


		// These functions are defined in header file in order to be in the same scope as struct Node

		// traverses to the left-most value of the tree, which will be the smallest value
		Node* min(Node* root)
		{
			while (root->left != nullptr) 
				root = root->left;
			return root; // returns location of smallest value
		}

		// remove Node removes a Node from a tree if that Node has a matching apartment number.
		struct Node* removeNode(struct Node* root, int num) {
			if (root == nullptr) 
				return root;
			else if (num < root->aptNum) // searches left if apartment number a smaller value than current
				root->left = removeNode(root->left, num);
			else if (num > root->aptNum) // searches right if apartment number a larger value than current
				root->right = removeNode(root->right, num); 	
			else {
				// Node is found with no children
				if (root->left == nullptr && root->right == nullptr) {
					delete root;
					root = nullptr;
				}
				//Node is found with one child to the right
				else if (root->left == nullptr) {
					struct Node* temp = root;
					root = root->right;
					delete temp;
				}
				//Node is found with one child to the left
				else if (root->right == nullptr) {
					struct Node* temp = root;
					root = root->left;
					delete temp;
				}
				// Node is found with left and right child
				else {
					struct Node* temp = min(root->right); // the node with least value is held in a temp node
					root->aptNum = temp->aptNum; // the current root value is reassigned with least node
					root->right = removeNode(root->right, temp->aptNum); // greater value is removed
				}
			}
			return root;
		}

};

#endif