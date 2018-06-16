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

void printSumPathUtil(Node* root , int k , int sum_so_far , vector<int>&path){

    if(root==NULL)
        return ;
    sum_so_far+=root->data;

    //we add the root element to our path i.e we push back the root element in the vector
    path.push_back(root->data);

    if(sum_so_far==k){
        for(int i=0;i<path.size();i++){
            cout<<path[i];
        }
    }

    //if path not found with the sum we go to the left and right tree

    //left recursive call
    if(root->left!=NULL)
        printSumPathUtil(root->left,k,sum_so_far,path);

    //right recursive call
    if(root->right!=NULL)
        printSumPathUtil(root->right,k,sum_so_far,path);
    //if we are not able to find path with the sum we remove the last element and return to its parent
    path.pop_back();
}

//here we have to print that path which has required sum
void printSumPath(Node* root , int k){

    vector<int> path;
    printSumPathUtil(root,k,0,path);
}

int main(){

    struct Node* root = NULL;
	root = Insert(root,10);
	root = Insert(root,28);
	root = Insert(root,13);
	root = Insert(root,14);
	root = Insert(root,15);
	root = Insert(root,21);
	root = Insert(root,22);
	root = Insert(root,23);
	root = Insert(root,24);

	//levelorderTravversal(root);

	int k = 38;

	printSumPath(root,k);
return 0;
}
