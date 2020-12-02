#include "BST.h"

BST::BST() : root(nullptr) {}


void BST::insert(Account& account)
{
	Node* newNode = new Node; // creates a new Node object

	// assigns members
	newNode->acc = &account;
	newNode->left = newNode->right = nullptr;

	insertNode(root, newNode); // passes root and newNode for insertion
}

// insertNode takes two pointers to Nodes. It uses the first parameter as a starting point and traverses
// the tree, inserting the Node where its value is less than its parent Node.
void BST::insertNode(Node*& nodePtr, Node*& newNode)
{
	// Finds an empty spot for a Node. If tree is empty, root becomes new node
	if (nodePtr == nullptr)
	{
		nodePtr = newNode;

	}
	else if (newNode->acc->getaccountNumber() < nodePtr->acc->getaccountNumber()) 
	// if new account number is less than the current account number
	{
		insertNode(nodePtr->left, newNode); // traverse left
	}
	else // account number is greater than current account number
	{
		insertNode(nodePtr->right, newNode); // traverse right
	}
}

// print traverses the tree inorder and displays the members to the user
void BST::print(const Node* nodePtr) const
{
    if (nodePtr)
    {

        print(nodePtr->left);
		cout << "Account number: "<< nodePtr->acc->getaccountNumber() << 
			" Name: "<< nodePtr->acc->getfirstName() << " " << nodePtr->acc->getlastName() << 
			" Balance: "<< nodePtr->acc->getbalance()<< " Address: "<<nodePtr->acc->getaddress()<<endl;
        print(nodePtr->right);
    }
}

// this print declaration allows a tree object to call the function and passes the private root member
void BST::print() const
{
    print(root);
}
