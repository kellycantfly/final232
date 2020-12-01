#include "BST.h"

static int count = 1; // A counter for number of nodes

// Default Constructor
BST::BST()
{
	root = nullptr;
}

// Assist function for Destructor. Traverses tree and deletes every node
void BST::deleteAll(Node* nodePtr)
{
	if (nodePtr) // Iterates until nodePtr is nullptr
	{
		deleteAll(nodePtr->left);
		deleteAll(nodePtr->right);
		delete nodePtr;
	}
}

// Destructor
BST::~BST()
{
	deleteAll(root);
}

// insert takes 3 string parameters that were read from a text file and assigns them to a new Node's members,
// then the new Node is passed to insertNode for proper insertion starting at the tree's root.
// insert can be called by an object in main and allows access to the private root member.
void BST::insert(string num, string aptName, string aptPhone)
{
	Node* newNode = new Node; // creates a new Node object

	// assigns members
	newNode->aptNum = stoi(num); // casts num as an int for the int type variable
	newNode->name = aptName;
	newNode->phone = aptPhone;
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
	else if (newNode->aptNum < nodePtr->aptNum) // if new apartment number is less than the current apartment number
	{
		insertNode(nodePtr->left, newNode); // traverse left
	}
	else // apartment number is greater than current apartment number
	{
		insertNode(nodePtr->right, newNode); // traverse right
	}
}

// addTenant prompts a user for input. The input should be read in as an integer and two strings with all seperated by a space.
// The apartment number is read first and then checked to see if it's a valid 3+ digit integer and if it's not already in use,
// then the rest of the input is read into the name and phone members and all are passed for insertion.
void BST::addTenant()
{
	string text, num, aptName, aptPhone; // temporary string variables for input

	// prompts and reads user input into text variable
	cout << "Enter tenant information seperated by a space" << endl;

	// clears buffer to prepare for input
	cin.clear();
	cin.ignore();

	getline(cin, text);

	num = text.substr(0, text.find(" ")); // first entry of user input should be apartment number
	try
	{
		if ((checkValid(num)) && searchAptNum(root,stoi(num))) // runs if a unique, 3+ digit apartment number is entered
		{
			text = text.substr(text.find(" ") + 1, text.length());

			aptName = text.substr(0, text.find(" "));
			text = text.substr(text.find(" ") + 1, text.length());
			aptName.append(" ");
			aptName.append(text.substr(0, text.find(" ")));
			text = text.substr(text.find(" ") + 1, text.length());

			aptPhone = text.substr(0, text.length());
			insert(num, aptName, aptPhone); // passes variables and new nodes are added with information
		}
		else
		{
			throw num; // goes to exception handling
		}
	}
	catch (string num) // exception handling
	{
		cout << num << " invalid apartment number" << endl;
	}
	


}

// checkValid takes a string and reads every character, checking if they are all digits.
// The length of the apartment number must be at least 3 but I've allowed for them to have 10,000 apartments if they're successful.
bool BST::checkValid(string num)
{
	if (num.length() >= 3)
	{
		for (int i = 0; i < num.length(); i++)
		{
			if (isdigit(num[i]))
				i++;
			else
				return 0;
		}
		return 1;
	}
	
	return 0;
}

// print traverses the tree inorder and displays the members to the user
void BST::print(Node* nodePtr) const
{
	if (nodePtr)
	{
		
		print(nodePtr->left);
		cout << nodePtr->aptNum << " " << nodePtr->name << " " << nodePtr->phone << endl;
		print(nodePtr->right);
	}
}

// this print declaration allows a tree object to call the function and passes the private root member
void BST::print() const
{
	print(root);
}

// readFile takes a file parameter, opens that file, and reads the contents into a text variable.
// It reads every line until new line and until the end of file.
// All members are assigned from file and are passed for insertion. 
void BST::readFile(string file)
{
	string text, num, aptName, aptPhone; // temporary string variables
	fstream inFile; // fstream object to read from
	inFile.open(file);

	if (inFile)
	{
		while (getline(inFile,text))
		{
			num = text.substr(0, text.find(" "));
			text = text.substr(text.find(" ") + 1, text.length());

			aptName = text.substr(0, text.find(" "));
			text = text.substr(text.find(" ") + 1, text.length());
			aptName.append(" ");
			aptName.append(text.substr(0, text.find(" ")));
			text = text.substr(text.find(" ") + 1, text.length());

			aptPhone = text.substr(0, text.length());
			insert(num,aptName,aptPhone); // passes variables and new nodes are added with information 
		}
	}
	else
	{
		cout << "File not found" << endl;
	}

	inFile.close();
}

// printToFile takes a Node pointer for traversal and an ofstream object to write to.
// It traverses the tree inorder and prints each node's information to a text file in a new line.
bool BST::printToFile(Node*& nodePtr, ofstream& outFile)
{
	
	if (nodePtr)
	{		
		printToFile(nodePtr->left,outFile);
		outFile << nodePtr->aptNum << " " << nodePtr->name << " " << nodePtr->phone << endl;
		printToFile(nodePtr->right,outFile);
	}
	
}

// upload takes a ofstream object to write to and allows a tree object to call the function, as it passes
// the private root member.
bool BST::upload(ofstream& outFile)
{
	if (printToFile(root, outFile))
		return 1;
	return 0;
	
}

// searchNode takes a Node pointer for traversal and a num to identify.
// It will traverse the tree and if a Node is found with the same apartment number was passed,
// it will print the information of that Node.
bool BST::searchNode(Node*& nodePtr, int num)
{
	if (nodePtr == nullptr)
		return 0; // returns false if tree is empty or if end is reached
	else if (num == nodePtr->aptNum)
	{
		cout << nodePtr->aptNum << " " << nodePtr->name << " " << nodePtr->phone << endl;
		return 1; // returns true if a match is found
	}

	else if (num < nodePtr->aptNum) // search left
		searchNode(nodePtr->left, num);
	else // search right
		searchNode(nodePtr->right, num);
}

// search allows a tree object to call searchNode, as it passes the private root member.
// It will inform the user whether a matching apartment number was found or not.
bool BST::search(int num)
{
	if (searchNode(root, num))
	{
		return 1; // true if a match was found
	}
		
	else
	{
		cout << "Not found" << endl;
		return 0; // otherwise false
	}
		
}

// searchAptNum takes a Node pointer for traversal and a num to identify.
// It will traverse the tree and if no matching apartment number is found, the apartment number is a
// unique number and a valid input
bool BST::searchAptNum(Node*& nodePtr, int num)
{
	if (nodePtr == nullptr)
		return 1; // if tree is empty or end is reached, no matching number and input is allowed
	else if (num == nodePtr->aptNum) // if a match is found, input not allowed
	{
		cout << "Apartment number in use" << endl;
		return 0;
	}

	else if (num < nodePtr->aptNum) // search left
		searchAptNum(nodePtr->left, num);
	else // search right
		searchAptNum(nodePtr->right, num);
}

// remove takes an apartment number and calls removeNode from header file.
// It allows a tree object to call removeNode, as it passes the private root member.
void BST::remove(int num)
{
	if (checkValid(to_string(num))) // checks if a valid apartment number is passed
	{
		removeNode(root, num);
	}
	else
	{
		cout << "Not found" << endl;
	}

}
