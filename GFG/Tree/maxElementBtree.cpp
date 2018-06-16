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

int findMax(struct BinaryTreeNode* root){

    int root_val ,left , right ,max = INT_MIN;
    if(root!=NULL){
        root_val = root->data;
        left=findMax(root->left);
        right=findMax(root->right);
        if(left>right)
            max=left;
        else
            max=right;

        if(root_val>max)
            max = root_val;
    }
    return max;
}

int main(){

    struct BinaryTreeNode* root = NULL;
	root = Insert(root,1);
	root = Insert(root,5);
	root = Insert(root,6);
	root = Insert(root,3);
	root = Insert(root,4);
	root = Insert(root,2);


	cout<<findMax(root);
return 0;
}
