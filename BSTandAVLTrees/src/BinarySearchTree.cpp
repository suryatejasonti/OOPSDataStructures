#include <string>
#include "BinarySearchTree.h"

using namespace std;

BinarySearchTree::BinarySearchTree() : root(nullptr) {}

BinarySearchTree::~BinarySearchTree() { clear(); }

BinaryNode *BinarySearchTree::get_root() const { return root; }

int BinarySearchTree::height() const { return height(root); }

int BinarySearchTree::height(const BinaryNode *ptr) const
{
	if (ptr==NULL)
	   return 0;
   else
   {
	   /* compute the depth of each subtree */
	   int lDepth = height(ptr->left);
	   int rDepth = height(ptr->right);

	   /* use the larger one */
	   if (lDepth > rDepth)
		   return(lDepth+1);
	   else return(rDepth+1);
   }
}

int BinarySearchTree::find_min() const throw(string)
{
    if (is_empty()) throw(string("Empty tree"));
    return find_min(root)->data;
}

BinaryNode *BinarySearchTree::find_min(BinaryNode *ptr) const
{
	if (ptr == nullptr)       return nullptr;
	if (ptr->left == nullptr) return ptr;

	return find_min(ptr->left);
}

int BinarySearchTree::find_max() const throw(string)
{
    if (is_empty()) throw(string("Empty tree"));
    return find_max(root)->data;
}

BinaryNode *BinarySearchTree::find_max(BinaryNode *ptr) const
{
	if (ptr != nullptr)
	{
		while(ptr->right != nullptr) ptr = ptr->right;
	}

	return ptr;
}

void BinarySearchTree::clear()
{
    clear(root);
}

void BinarySearchTree::clear(BinaryNode* &ptr)
{
	if(root!=NULL)
	{
		clear(ptr->left);
		clear(ptr->right);
		delete(ptr);
		if(ptr->left!=NULL)
			ptr->left=NULL;
		if(ptr->right!=NULL)
			ptr->right=NULL;
		ptr=NULL;
	}
}

bool BinarySearchTree::is_empty() const
{
    return root == nullptr;
}

bool BinarySearchTree::contains(const int data) const
{
    return contains(data, root);
}

bool BinarySearchTree::contains(const int data, BinaryNode *ptr) const
{
	while (ptr != nullptr)
	{
		if (data < ptr->data)
		{
			ptr = ptr->left;
		}
		else if (data > ptr->data)
		{
			ptr = ptr->right;
		}
		else
		{
			return true;  // found
		}
	}
	return false;
}

void BinarySearchTree::insert(const int data)
{
    insert(data, root);
}

void BinarySearchTree::insert(const int data, BinaryNode* &ptr)
{
	if (ptr == nullptr)
	{
		ptr = new BinaryNode(data);
	}
	else if (data < ptr->data)
	{
		insert(data, ptr->left);
	}
	else if (data > ptr->data)
	{
		insert(data, ptr->right);
	}
}

void BinarySearchTree::remove(const int data)
{
    remove(data, root);
}

void BinarySearchTree::remove(const int data, BinaryNode* &ptr)
{
	if (ptr == nullptr) return;

	if (data < ptr->data)
	{
		remove(data, ptr->left);
	}
	else if (data > ptr->data)
	{
		remove(data, ptr->right);
	}
	else if (   (ptr->left  != nullptr)
			 && (ptr->right != nullptr))
	{
		ptr->data = find_min(ptr->right)->data;
		remove(ptr->data, ptr->right);
	}
	else
	{
		BinaryNode *oldNode = ptr;
		ptr = (ptr->left != nullptr) ? ptr->left
									 : ptr->right;
		delete oldNode;
	}
}
