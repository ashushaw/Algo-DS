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



struct Node* findMin(struct Node* root){

    if(root==NULL){
            return NULL;
    }

    if(root->left==NULL)
       return root;
    else
        findMin(root->left);
}

struct Node* deletion(struct Node* root , int data){

    if(root == NULL)
        return NULL;

    if(root->data<data){
        deletion(root->left,data);
    }

    else if(root->data>data){
        deletion(root->right,data);
    }

    else{
        //Node found
        //Case 1 : no child
        if(root->left&&root->right){
            delete root;
            root= NULL;
        }
        //Case 2 : one child
        else if(root->left){
            struct Node* temp = root;
            root=root->left;
            delete temp;
        }

        else if(root->right){
            struct Node* temp = root;
            root=root->right;
            delete temp;
        }

        else{

            struct Node* temp = findMin(root);
            root->data = temp->data;
            root->right = deletion(root->right, temp->data);
        }
    }

}

// driver program to test the above function
int main()
{
    struct Node *root = NULL;
    root = insert(root, 50);
    root = insert(root, 30);
    root = insert(root, 20);
    root = insert(root, 40);
    root = insert(root, 70);
    root = insert(root, 60);
    root = insert(root, 80);

    printf("Inorder traversal of the given tree \n");
    inorder(root);

    printf("\nDelete 20\n");
    root = deletion(root, 20);
    printf("Inorder traversal of the modified tree \n");
    inorder(root);

    printf("\nDelete 30\n");
    root = deletion(root, 30);
    printf("Inorder traversal of the modified tree \n");
    inorder(root);



    return 0;
}

