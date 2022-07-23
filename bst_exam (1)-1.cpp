// For the BST class provided, implement the findSum() method that returns the sum of the key values of all the nodes in the BST 
// by Luis Umana
#include <iostream>
#include<bits/stdc++.h>


using namespace std;

/********** BST Class declaration **************/
class Node
{
private:
   int key;
   Node* left;
   Node* right;
   friend class BinarySearchTree;   
};   

class BinarySearchTree
{
public:  
		BinarySearchTree();
		void insert(int key); // Recursive
		int findSum() const; // Returns the sum of keys of all nodes
private:
        Node* root;
        void insertHelper(Node* parent, Node* new_node);
		
};

/*********** BST Class implemenation *********/
BinarySearchTree::BinarySearchTree()
{  
   root = nullptr;
}
   
void BinarySearchTree::insert(int key) 
{  
   Node* new_node = new Node;
   new_node->key = key;
   new_node->left = nullptr;
   new_node->right = nullptr;
   if (root == nullptr) { 
      root = new_node; 
   } else { 
      insertHelper(root, new_node); 
   }
}

void BinarySearchTree::insertHelper(Node* parent, Node* new_node) 
{  
   if (new_node->key < parent->key) {  
      if (parent->left == nullptr) { 
         parent->left = new_node; 
      }
      else { 
         insertHelper(parent->left, new_node); }
   }
   else if (new_node->key > parent->key) {  
      if (parent->right == nullptr) {
         parent->right = new_node; 
      }
      else { 
         insertHelper(parent->right, new_node);
      }
   }
}


int BinarySearchTree::findSum() const {
// Your code here. Feel free to add additional private methods to the BinarySearchTree class
	int sum = 0;	
	stack<Node *> stackofnode; 
    Node *answer_node = BinarySearchTree::root; 
  
    while (answer_node != NULL || stackofnode.empty() == false) 
    { 
        while (answer_node !=  NULL) 
        { 
            stackofnode.push(answer_node); 
            answer_node = answer_node->left; 
            
        } 
        
        answer_node = stackofnode.top(); 
        stackofnode.pop(); 
        sum+=answer_node->key;
        answer_node = answer_node->right; 
  
    }
	return sum;
}



/******************** Test **************/
int main()
{  
	BinarySearchTree t;
	t.insert(5);
	t.insert(3);
	t.insert(7);
	t.insert(2);
	t.insert(4);
	t.insert(6);
	t.insert(8);
   	t.insert(9);

	cout << "The sum of key values is " << t.findSum() << endl;	// Should print 44
	
    return 0;
}

  
