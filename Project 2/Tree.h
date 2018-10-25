#ifndef _TREE_H
#define _TREE_H

#include <iostream>
using namespace std;

template <class T>
class Tree{
    private:
    	struct node{
        T data;
        node *left;
        node *right;
        };

    	int count;
    	int capacity;
    	node *root;

    	void insertPrivate(T item, node* n);

    	void inOrderPrivate(node* n);
    	
		//CreateLeaf is here because I didn't figured out how to implement this
		//outside the class. it has something to do with the struct type getting
		//called from outside the Tree class. 
    	node* CreateLeaf(T item){
    		node* n = new node;
			n->data = item;
			n->left = NULL;
			n->right = NULL;
			return n;
    	}
    
    public:
    	Tree(void);

    	void insert(T item);

    	~Tree();

    	void destroyer(node* tree);

    	void inOrder();

    	
};


//Tree constructor makes and empty tree. 
template <class T>
Tree<T>::Tree(void){
	root=NULL;
	count = 0;
	capacity = 0;
	//cout << "made the empty tree" << endl;
}

//public insert calls the private version using the root as a parameter
template <class T>
void Tree<T>::insert(T item){

	insertPrivate(item, root);

}


template <class T>
void Tree<T>::insertPrivate(T item, node* n){

	if(root==NULL){
		root = CreateLeaf(item);
		cout << "added: " << item << " to the root" << endl;
	}
	else if(item < n->data)
	{
		if(n->left != NULL)
		{
			insertPrivate(item, n->left);
		}
		else
		{
			n->left = CreateLeaf(item);
			cout << "added: " << item << " to the left" << endl;
		}
	}
	else if(item > n->data)
	{
		if(n->right != NULL)
		{
			insertPrivate(item, n->right);
		}
		else
		{
			n->right = CreateLeaf(item);
			cout << "added: " << item << " to the right" << endl;
		}
	}
	else
	{
		cout << "item " << item << " is already in the tree\n";
	}


}


//public inOrderfunction calls the private inOrder function by passing the root.
template <class T>
void Tree<T>::inOrder(){
	inOrderPrivate(root);
}

template <class T>
void Tree<T>::inOrderPrivate(node* n){
	if (root != NULL)
	{
		if(n->left !=NULL)
		{
			inOrderPrivate(n->left);
		}
		cout << n->data << " ";
		if(n->right !=NULL)
		{
			inOrderPrivate(n->right);
		}
	}
	else
	{
		cout << "empty tree" << endl;
	}
}

/*
 *destroyer is a helper function for the destructor. It takes in the root as a parameter
 *and it recursively deletes the tree nodes and leaves. it doesn't do anything if the tree is empty.
 */
template <class T>
void Tree<T>::destroyer(node *tree){
	T thing;
	if(tree != NULL){
		thing = tree->data;
		destroyer(tree->left);
		destroyer(tree->right);
		//cout << "deleted: " << thing << endl;
		delete tree;
	}
}
//the destructor calls destroyer which deletes the tree. 
template <class T>
Tree<T>::~Tree(){
	destroyer(root);
	cout << "destroyed the tree" << endl;
}


#endif