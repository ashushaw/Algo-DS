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

void printZigZag(struct Node* root ){

    if(root==NULL)
        return;
    stack<struct Node*> currentLevel;
    stack<struct Node*> nextLevel;

    bool lefttoright = true;
    currentLevel.push(root);

    while(!currentLevel.empty()){
        struct Node* temp = currentLevel.top();
        currentLevel.pop();

        //if not null
        if(temp){
        cout<<temp->data<<" ";

        if(lefttoright==true){
            if(temp->left)
                nextLevel.push(temp->left);

            if(temp->right)
                nextLevel.push(temp->right);
        }
        /*if lefttoright is false then we add first right child and then left*/
        else{
                if(temp->right)
                nextLevel.push(temp->right);

            if(temp->right)
                nextLevel.push(temp->left);
        }
    }
    if(currentLevel.empty()){
        lefttoright = !lefttoright;
        swap(nextLevel,currentLevel);
    }
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
    cout << "ZigZag Order traversal of binary tree is \n";

    printZigZag(root);

    return 0;
}


