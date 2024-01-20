#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>

using namespace std;

struct Node
{
	int data;
	Node* left, *right;
};

Node* newNode(int data)
{
	Node* node = new Node;
	node->data = data;
	node->left = node->right = NULL;
	return (node);
}

Node* insertLevelOrder(const vector<int>& tree_vec, int i, int n)
{
	Node* root = nullptr;
	if (i < n && tree_vec[i] != -1)
	{
		root = newNode(tree_vec[i]);
		root->left = insertLevelOrder(tree_vec, 2 * i + 1, n);
		root->right = insertLevelOrder(tree_vec, 2 * i + 2, n);
	}
	return root;
}

bool checkmax(Node* root)
{
    if (root == nullptr)
        return true;

    bool leftValid = (root->left == nullptr) || (root->data >= root->left->data);
    bool rightValid = (root->right == nullptr) || (root->data >= root->right->data);

    return leftValid && rightValid && checkmax(root->left) && checkmax(root->right);
}
int main()
{
	vector<int> tree_vec;
	string file_name;
	int temp_data;
	cout << "Please input the file name of a complete binary tree:";
	cin >> file_name;
	ifstream tree_file(file_name, ios::in);

	if (tree_file.fail())
	{
		cout << "Fail to open the tree file.";
		return 0;
	}

	while (!tree_file.fail() && !tree_file.eof())
	{
		tree_file >> temp_data;
		tree_vec.push_back(temp_data);
	}

	tree_file.close();

	Node* root = insertLevelOrder(tree_vec, 0, tree_vec.size());

	if (checkmax(root)) {
		cout << "The given array is a max heap." << endl;
	}
	else {
		cout << "The given array is not a max heap." << endl;
	}

	return 0;
}
