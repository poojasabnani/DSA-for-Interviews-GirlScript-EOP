#include<iostream>
using namespace std;

struct BstNode{
	int data;
	BstNode* left;
	BstNode* right;	
};

BstNode* GetNewNode(int data){
	BstNode* newNode = new BstNode();
	newNode->data = data;
	newNode->left = newNode->right = NULL;
	return newNode;
}

BstNode* Insert(BstNode* root, int data){
	if (root == NULL){
		root = GetNewNode(data);
	}
	else if(data < root->data) root->left = Insert(root->left, data);
	else root->right = Insert(root->right, data);
	return root;
}

bool Search(BstNode* root, int data){
	if (root == NULL) return false;
	else if (data == root->data) return true;
	else if (data < root->data) Search(root->left, data);
	else Search(root->right, data);
}

void inorder(BstNode* root){
	if (root!=NULL){
		inorder(root->left);
		cout<<root->data<<" ";
		inorder(root->right);
	}
	else{
		cout<<"\n";
	}
}

BstNode* FindMin(BstNode* root){
	if (root != NULL){
		root = FindMin(root->left);
	}
	return root;
}

BstNode* Delete(BstNode* root, int data){
	if (root == NULL) return root;
	else if(data < root->data) root->left = Delete(root->left, data);
	else if(data > root->data) root->right = Delete(root->right, data);
	else{// when we have found the node
		if (root->left == NULL && root->right == NULL){
			//case 1: no child
			delete root;
			root = NULL;
		}
		else if(root->left == NULL){ //when only one child i.e. right child
			BstNode* temp = root;
			root = temp->right;
			delete temp;
		}
		else if(root->right == NULL){ //when only one child i.e. left child
			BstNode* temp = root;
			root = temp->left;
			delete temp;
		}
		else{//two children
			BstNode* temp = FindMin(root->right);
			root->data = temp->data;
			root->right = Delete(root->right, temp->data);
		}
	}
	return root;
}

int main(){
	
	BstNode* root = NULL; //creates an empty tree
	
	root = Insert(root, 10);
	root = Insert(root, 9);
	root = Insert(root, 15);
	root = Insert(root, 100);
	
	int number;
	cout<<"Enter the number to be searched: ";
	cin>>number;
	if (Search(root, number) == true) cout<<"Found\n";
	else cout<<"Not Found\n";
	
	inorder(root);
	
	root = Delete(root, 15);
	
	inorder(root);
	
	return 0;
}
