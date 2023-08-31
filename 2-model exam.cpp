#include <iostream>
using namespace std;
struct node 
{
	int key;
	struct node *left, *right;
};
struct node* newNode(int item)
{
	struct node* temp
		= new struct node;
	temp->key = item;
	temp->left = temp->right = NULL;
	return temp;
}
struct node* insert(struct node* node, int key)
{
	if (node == NULL)
    return newNode(key);
	if (key < node->key)
	node->left = insert(node->left, key);
	else if (key > node->key)
	node->right = insert(node->right, key);

	// Return the (unchanged) node pointer
	return node;
}
struct node* search(struct node* root, int key)
{
	if (root == NULL || root->key == key)
    return root;
	if (root->key < key)
	return search(root->right, key);
	return search(root->left, key);
}
