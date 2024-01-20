#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

/* A binary tree node has data,
pointer to left child and a
pointer to right child */
struct Node {
	int data;
	Node* left, * right;
};

/*Function for creating a new Node structure */
Node* newNode(int data) {
	Node* node = new Node;
	// Node* node = (Node*)malloc(sizeof(Node)); //will also work.
	node->data = data;
	node->left = node->right = NULL;
	return (node);
}

// Function to insert nodes in level order. This function takes an array-based
// tree representation as input and convert it into a linked list-based tree
// representation
Node* insertLevelOrder(vector<int> tree_vec, // tree_vec: array implementation,
											 // create node for position i.
	int i, int n) {
	Node* root = nullptr;
	// Base case for recursion
	if (i < n) {
		// Check if the current node is a missing node (-1)
		if (tree_vec[i] == -1)
			return nullptr;

		root = newNode(tree_vec[i]);

		// insert left child
		root->left = insertLevelOrder(tree_vec, 2 * i + 1, n);

		// insert right child
		root->right = insertLevelOrder(tree_vec, 2 * i + 2, n);
	}
	return root;
}

// Example code for InOrder traversal
void inOrder(Node* root) {
	if (root != NULL) {
		inOrder(root->left);
		cout << root->data << " ";
		inOrder(root->right);
	}
}

// Task 1: Recursive function to count the total number of leaves in the tree
int countLeaves(Node* root) {
	if (root == nullptr)
		return 0;

	if (root->left == nullptr && root->right == nullptr)
		return 1;

	return countLeaves(root->left) + countLeaves(root->right);
}

// Task 2: Postorder traversal
void postOrder(Node* root) {
	if (root != nullptr) {
		postOrder(root->left);
		postOrder(root->right);
		cout << root->data << " ";
	}
}

int main() {
	vector<int> tree_vec;
	string file_name;
	int temp_data;
	cout << "Please input the file name of a complete binary tree:";
	cin >> file_name;
	ifstream tree_file(file_name, ios::in);

	if (tree_file.fail()) {
		cout << "Fail to open the tree file.";
		return 0;
	}

	while (!tree_file.fail() && !tree_file.eof()) {
		tree_file >> temp_data;
		tree_vec.push_back(temp_data);
	}

	/*Transform the array-based tree into linked-list in level-order.*/
	Node* root = insertLevelOrder(tree_vec, 0, tree_vec.size());

	/*Task 1: Count the number of leaves in the tree*/
	int leafCount = countLeaves(root);
	cout << "The inorder traversal is: ";
	inOrder(root);
	cout << endl;
	cout << "The total number of leaves is: " << leafCount << endl;

	/*Task 2: Postorder Traversal*/
	cout << "The postorder traversal is: ";
	postOrder(root);
	cout << endl;

	return 0;
}
