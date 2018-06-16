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

void printVerticalorder(struct Node* root ){

    if(root==NULL)
        return;

    /*Map for storing the hd and node*/

    map<int , vector<int>> m;
    int hd=0;

    queue<pair<Node* , int >> q;

    q.push(make_pair(root,hd));

    while(!q.empty()){

        pair<Node * ,int> temp = q.front();
        q.pop();
        hd= temp.second;
        struct Node* node = temp.first;

        m[hd].push_back(node->data);
        if (node->left != NULL)
            q.push(make_pair(node->left, hd-1));
        if (node->right != NULL)
            q.push(make_pair(node->right, hd+1));

    }

    map< int,vector<int> > :: iterator it;
    for (it=m.begin(); it!=m.end(); it++)
    {
        for (int i=0; i<it->second.size(); ++i)
            cout << it->second[i] << " ";
        cout << endl;
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
    Node *root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->left = newNode(6);
    root->right->right = newNode(7);
    root->right->left->right = newNode(8);
    root->right->right->right = newNode(9);
    root->right->right->left= newNode(10);
    root->right->right->left->right= newNode(11);
    root->right->right->left->right->right= newNode(12);
    cout << "Vertical order traversal is \n";
    printVerticalorder(root);
    return 0;
}



