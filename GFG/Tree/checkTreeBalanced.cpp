#include<bits/stdc++.h>

using namespace std;

struct Node{

    int data;
    struct Node* left;
    struct Node* right;
};

Node* GetNewNode(int data) {
	Node* newNode = new Node();
	newNode->data = data;
	newNode->left = newNode->right = NULL;
	return newNode;
}

// To insert data in BST, returns address of root node
Node* Insert(Node* root,int data) {
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

void levelorderTravversal(struct Node* root){

    if(root==NULL)
        return ;

    queue<Node* > q;
    q.push(root);
    while(!q.empty()){
        struct Node* current = q.front();
        cout<<current->data<<" ";
        if(root->left!=NULL)
            q.push(root->left);
        if(root->right!=NULL)
            q.push(root->right);
        q.pop();
    }

}




int isBalanced(struct Node* root){
		if(root==NULL){
			return 0;
		}
		int leftH = isBalanced(root->left);
		if(leftH==-1){
			return -1;
		}
		int rightH = isBalanced(root->right);
		if(rightH==-1){
			return -1;
		}
		int diff = leftH-rightH;
		if(abs(diff)>1){
			return -1;
		}
		return 1 + max(leftH, rightH);
	}

bool checkBalance(struct Node* root){
		int result = isBalanced(root);
		if(result>0){
			return true;
		}else{
			return false;
		}
	}

struct Node* newNode(int data)
{
    struct Node* node = new struct Node;
    node->data = data;
    node->left = node->right = NULL;
    return (node);
}

// driver program to test the above function
int main()
{
    // create tree
    struct Node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(7);
    root->left->right = newNode(6);
    root->right->left = newNode(5);
    root->right->right = newNode(4);
    //cout << "ZigZag Order traversal of binary tree is \n";
   cout<<checkBalance(root);

    return 0;
}
