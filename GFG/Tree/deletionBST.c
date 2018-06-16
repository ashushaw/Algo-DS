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

void printTopView(struct Node* root){

    if(root==NULL)
        return ;

    unordered_map <int , int > m;
    queue<pair<struct Node* , int >> q;

    q.push(make_pair(root,0));

    while(!q.empty()){

        pair<Node *, int>temp = q.front();
        q.pop();
        struct Node* node = temp.first;
        int hd = temp.second;

        if(m.find(hd)==m.end()){
            m[hd]=node->data;
            cout<<node->data<<" ";
        }

        if(node->left){
            q.push(make_pair(node->left,hd-1));
        }

        if(node->right)
            q.push(make_pair(node->right,hd+1));

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
   printTopView(root);

    return 0;
}

