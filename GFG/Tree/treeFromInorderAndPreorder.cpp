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

int search(char arr[], int strt, int end, char value)
{
  int i;
  for(i = strt; i <= end; i++)
  {
    if(arr[i] == value)
      return i;
  }
}
struct Node* buildTree(char inorder[] , char preOrder[] ,int inOrderStart , int inOrderEnd){

    static int preOrderIndx = 0;
    struct Node* newNode ;

    if(inOrderStart>inOrderEnd)
        return NULL;

    newNode->data = preOrder[preOrderIndx];
    preOrderIndx++;

    int inOrderIdx = search(inorder,inOrderStart,inOrderEnd,newNode->data);
    newNode->left = buildTree(inorder,preOrder,inOrderStart,inOrderIdx-1);
    newNode->right = buildTree(inorder,preOrder,inOrderIdx+1,inOrderEnd);

    return newNode;
}



void printInorder(struct Node* node)
{
  if (node == NULL)
     return;

  /* first recur on left child */
  printInorder(node->left);

  /* then print the data of node */
  printf("%c ", node->data);

  /* now recur on right child */
  printInorder(node->right);
}

/* Driver program to test above functions */
int main()
{
  char in[] = {'D', 'B', 'E', 'A', 'F', 'C'};
  char pre[] = {'A', 'B', 'D', 'E', 'C', 'F'};
  int len = sizeof(in)/sizeof(in[0]);
  struct Node *root = buildTree(in, pre, 0, len - 1);

  /* Let us test the built tree by printing Insorder traversal */
  printf("Inorder traversal of the constructed tree is \n");
  printInorder(root);
  getchar();
}
