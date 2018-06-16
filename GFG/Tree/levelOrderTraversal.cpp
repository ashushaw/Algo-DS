#include<bits/stdc++.h>

using namespace std;

struct BinaryTreeNode{

    int data;
    struct BinaryTreeNode* left;
    struct BinaryTreeNode* right;
};

BinaryTreeNode* GetNewNode(int data) {
	BinaryTreeNode* newNode = new BinaryTreeNode();
	newNode->data = data;
	newNode->left = newNode->right = NULL;
	return newNode;
}

// To insert data in BST, returns address of root node
BinaryTreeNode* Insert(BinaryTreeNode* root,int data) {
	if(root == NULL) { // empty tree
		root = GetNewNode(data);
	}
	// if data to be inserted is lesser, insert in left subtree.
	else if(data <= root->data) {
		root->left = Insert(root->left,data);
	}
	// else, insert in right subtree.
	else {
		root->right = Insert(root->right,data);
	}
	return root;
}

void levelorderTravversal(struct BinaryTreeNode* root){

    if(root==NULL)
        return ;

    queue<BinaryTreeNode* > q;
    q.push(root);
    while(!q.empty()){
        struct BinaryTreeNode* current = q.front();
        cout<<current->data<<" ";
        if(root->left!=NULL)
            q.push(root->left);
        if(root->right!=NULL)
            q.push(root->right);
        q.pop();
    }

}

int main(){

    struct BinaryTreeNode* root = NULL;
	root = Insert(root,'M'); root = Insert(root,'B');
	root = Insert(root,'Q'); root = Insert(root,'Z');
	root = Insert(root,'A'); root = Insert(root,'C');

	levelorderTravversal(root);
return 0;
}
