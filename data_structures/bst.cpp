#include <iostream>
#include <stack>

struct node{
	int data;
	bool flag;
	struct node* right_child;
	struct node* left_child;
};

class BST{
	public:
		struct node* root;
 
		BST(){
			root = NULL;
		}
		
		struct node* search(int data);
		void insert(int data);
		int height(node* root);
		void balance();

		//left-root-right
		void inorder_traversal(struct node* root);
		//root-left-right
		void preorder_traversal(struct node* root);
		//left-right-root
		void postorder_traversal(struct node* root);
		//depth first traversal
		void dft();
		//breadth first traversal
		void bft();
};

int main(){
	std::cout << "huy" << std::endl;
	BST* bst = new BST();
	bst->insert(11);
	bst->insert(9);
	bst->insert(8);
	bst->insert(10);
	bst->insert(12);
	bst->insert(13);
	bst->insert(14);
	//std::cout << bst->root->right_child->right_child->data << std::endl;
	bst->preorder_traversal(bst->root);
	//bst->dft();
}

struct node* BST::search(int data){
	struct node* ptr;
	std::cout << "huy" << std::endl;
	
}

void BST::insert(int data){
	if (root == NULL){
		root = new node;
		root->data = data;
		root->left_child = NULL;
		root->right_child = NULL;
		root->flag = false;
		return;
	}
	else{
		node* previous;
		node* current = root;
		while(true){
			if (data <= current->data){
				previous = current;
				current = current->left_child;
				if (current == NULL){
					current = new node;
					current->data = data;
					current->left_child = NULL;
					current->right_child = NULL;
					current->flag = false;
					previous->left_child = current;
					return;
				}
			}
			else if (data > current->data){
				previous = current;
				current = current->right_child;
				if (current == NULL){
					current = new node;
					current->data = data;
					current->left_child = NULL;
					current->right_child = NULL;
					current->flag = false;
					previous->right_child = current;
					return;
				}
			}
		}
	}
}

void BST::inorder_traversal(node* root){
	node* current = root;
	if (current == NULL){
		return;
	}
	else{
		inorder_traversal(current->left_child);
		std::cout << current->data << std::endl;
		inorder_traversal(current->right_child);
	}
}

void BST::preorder_traversal(node* root){
	node* current = root;
	if (current == NULL){
		return;
	}
	else{
		std::cout << current->data << std::endl;
		inorder_traversal(current->left_child);
		inorder_traversal(current->right_child);
	}
}

void BST::postorder_traversal(node* root){
	node* current = root;
	if (current == NULL){
		return;
	}
	else{
		inorder_traversal(current->left_child);
		inorder_traversal(current->right_child);
		std::cout << current->data << std::endl;
	}
}

void BST::dft(){
	std::stack<node*> stek;
	node* current = root;
	current->flag = true;
	std::cout << current->data << std::endl;
	stek.push(current);
	do {
		if (current->left_child != NULL){
			if (current->left_child->flag == false){
				current = current->left_child;
				current->flag = true;
				std::cout << current->data << std::endl;
				stek.push(current);
				continue;
			}
		}
		if (current->right_child != NULL){
			if (current->right_child->flag == false){
				current = current->right_child;
				current->flag = true;
				std::cout << current->data << std::endl;
				stek.push(current);
				continue;
			}
		}
		stek.pop();
		current = stek.top();
	} while (!stek.empty());
}

int height(node* root){

}

void balance(){
	
}



