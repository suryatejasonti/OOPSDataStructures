#include <iostream>
#include "AvlTree.h"

using namespace std;

AvlTree::AvlTree() : BinarySearchTree() {}

AvlTree::~AvlTree() {}

int AvlTree::height(const BinaryNode *ptr) const
{
	return ptr == nullptr ? -1 : ptr->height;
}

void AvlTree::insert(const int data, BinaryNode* &ptr)
{
    BinarySearchTree::insert(data, ptr);
    rebalance(ptr);
}

void AvlTree::remove(const int data, BinaryNode* &ptr)
{
    BinarySearchTree::remove(data, ptr);
    rebalance(ptr);
}

BinaryNode *AvlTree::rebalance(BinaryNode* &ptr)
{
	if (ptr == nullptr) return ptr;

	// Left side too high.
	if (height(ptr->left) - height(ptr->right) > 1)
	{
		if (height(ptr->left->left) >= height(ptr->left->right))
		{
			ptr = single_left_rotation(ptr);
		}
		else
		{
			ptr = double_right_left_rotation(ptr);
		}
	}

	// Right side too high.
	else if (height(ptr->right) - height(ptr->left) > 1)
	{
		if (height(ptr->right->right) >= height(ptr->right->left))
		{
			ptr = single_left_rotation(ptr);
		}
		else
		{
			ptr = double_right_left_rotation(ptr);
		}
	}

	// Recompute the node's height.
	ptr->height = (max(height(ptr->left),
					   height(ptr->right)) + 1);

    if (check_balance(ptr) < 0)
    {
        cout << endl << "***** Tree unbalanced!" << endl;
    }

    return ptr;
}

BinaryNode *AvlTree::single_right_rotation(BinaryNode *k2)
{
	//Node k2 is unbalanced.

	//k2's left child becomes the new root of the subtree.
	BinaryNode *new_root = k2->left;

	//k2 adopts the new root's right child as its new left child.
	k2->left = new_root->right;

	//k2 becomes the right child of the new root
	new_root->right = k2;

	//Recompute the old root node k2's height.
	k2->height = (max(height(k2->left), height(k2->right)) + 1);

	return new_root;
}

BinaryNode *AvlTree::double_left_right_rotation(BinaryNode *k3)
{
	//Node k3 is unbalanced.
	//The new root of the subtree is got after two rotations.
	//Step 1 is a single left rotation of k3's left child
	k3->left = single_left_rotation(k3->left);

	//Step 2 is a single right rotation of k3
	return single_right_rotation(k3);
}

BinaryNode *AvlTree::double_right_left_rotation(BinaryNode *k1)
{
	//Node k1 is unbalanced.
	//The new root of the subtree is got after two rotations.

	//Step 1 is a single right rotation of k1's right child
	k1->right = single_right_rotation(k1->right);

	//Step 2 is a single left rotation of k1
	return single_left_rotation(k1);
}

BinaryNode *AvlTree::single_left_rotation(BinaryNode *k1)
{
	//Node k1 is unbalanced.

	//k1's right child becomes the new root of the subtree.
	BinaryNode *new_root = k1->right;

	//k1 adopts C's left child as its new right child
	k1->right = new_root->left;

	//Node k1 becomes the left child of the new root
	new_root->left = k1;

	//Recompute the old root node k1's height.
	k1->height = (max(height(k1->left), height(k1->right)) + 1);

	return new_root;
}

int AvlTree::check_balance(BinaryNode *ptr)
{
    if (ptr == nullptr) return -1;

    int leftHeight  = check_balance(ptr->left);
    int rightHeight = check_balance(ptr->right);

    if ((abs(height(ptr->left) - height(ptr->right)) > 1)
        || (height(ptr->left)  != leftHeight)
        || (height(ptr->right) != rightHeight))
    {
        return -2;       // unbalanced
    }

    return height(ptr);  // balanced
}
