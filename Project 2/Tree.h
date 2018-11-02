#ifndef _TREE_H
#define _TREE_H

#include <iostream>
#include <queue>
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
    	
    	void levelOrderPrivate(node* n);
    	
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

    	int getCount();

    	void destroyer(node* tree);

    	void inOrder();
    	
    	void levelOrder();

    	int maxDepth();

    	int maxDepthPrivate(node* n);

    	
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

//insert private actually adds the element 
template <class T>
void Tree<T>::insertPrivate(T item, node* n){//start Tree constructor

	if(root==NULL){
		root = CreateLeaf(item);
		//cout << "added: " << item << " to the root" << endl;
		count++;
	}
	else if(item <= n->data)
	{
		if(n->left != NULL)
		{
			insertPrivate(item, n->left);
		}
		else
		{
			n->left = CreateLeaf(item);
			count++;
			//cout << "added: " << item << " to the left" << endl;
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
			count++;
			//cout << "added: " << item << " to the right" << endl;
		}
	}
	else
	{
		//cout << "item " << item << " is already in the tree\n";
	}


}//end tree constructor


//public inOrderfunction calls the private inOrder function by passing the root.
template <class T>
void Tree<T>::inOrder(){
	inOrderPrivate(root);
}

//inOrderPrivate actually goes through the tree recursively to print the data.
//Assuming the BST was properly implemented, this function should output the data in 
//ascending order. 
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

template <class T>
void Tree<T>::levelOrder(){
	levelOrderPrivate(root);
}

template <class T>
void Tree<T>::levelOrderPrivate(node* n){
	
	//return if the tree is empty
    if (n == NULL) return;  
  
    // Create an empty queue for level order tarversal  
    queue<node *> q;  
  
    // Enqueue Root and initialize height  
    q.push(n);  
  
    while (q.empty() == false)  
    {  
        // nodeCount (queue size) indicates number 
        // of nodes at current lelvel.  
        int nodeCount = q.size();  
  
        // Dequeue all nodes of current level and  
        // Enqueue all nodes of next level  
        while (nodeCount > 0) 
        {  
            node *node = q.front();  
            cout << node->data << " ";  
            q.pop();  
            if (node->left != NULL)  
                q.push(node->left);  
            if (node->right != NULL)  
                q.push(node->right);  
            nodeCount--;  
        }  
        cout << endl;  
    }  
}

template <class T>
int Tree<T>::maxDepth(){
	return maxDepthPrivate(root);
}

template <class T>
int Tree<T>::maxDepthPrivate(node *n){

	if (n==NULL){
		return 0;
	}
	else 
    { 
       /* compute the depth of each subtree */
       int lDepth = maxDepthPrivate(n->left); 
       int rDepth = maxDepthPrivate(n->right); 
  
       /* use the larger one */
       if (lDepth > rDepth)  
           return(lDepth+1); 
       else return(rDepth+1); 
    } 
}
//returns number of nodes in the tree
template <class T>
int Tree<T>::getCount(){
	return count;
}

/*
 *destroyer is a helper function for the destructor. It takes in the root as a parameter
 *and it recursively deletes the tree nodes and leaves. it doesn't do anything if the tree is empty.
 */
template <class T>
void Tree<T>::destroyer(node *tree){
	T thing;
	if(tree != NULL)
	{
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