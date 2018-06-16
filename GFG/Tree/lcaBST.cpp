#include<bits/stdc++.h>

using namespace std;

struct Node{

    int data;
    struct Node* left;
    struct Node* right;
};

void inorder(struct Node *root)
{
    if (root != NULL)
    {
        inorder(root->left);
        cout<<root->data<<" ";
        inorder(root->right);
    }
}

struct Node *newNode(int item)
{
    struct Node *temp =  (struct Node *)malloc(sizeof(struct Node));
    temp->data = item;
    temp->left = temp->right = NULL;
    return temp;
}
struct Node* insert(struct Node* root, int data)
{
    /* If the tree is empty, return a new Node */
    if (root == NULL) return newNode(data);

    /* Otherwise, recur down the tree */
    if (data < root->data)
        root->left  = insert(root->left, data);
    else
        root->right = insert(root->right, data);

    /* return the (unchanged) Node pointer */
    return root;
}



struct Node* LCA(struct Node* root,int n1 , int n2){

        if (root == NULL)
            return NULL;

        if(root->data>max(n1,n2))
         return LCA(root->left,n1,n2);

        if(root->data<min(n1,n2))
           return LCA(root->right,n1,n2);
        else
            return root;
}

int main()
{
    struct Node *root = NULL;
    root = insert(root, 20);
    root = insert(root, 8);
    root = insert(root, 22);
    root = insert(root, 4);
    root = insert(root, 12);
    root = insert(root, 10);
    root = insert(root, 14);

    int n1,n2;

    struct Node* ans = LCA(root,10,22);
    cout<<ans->data;
    return 0;
}
