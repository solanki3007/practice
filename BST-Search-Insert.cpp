#include <iostream>

using namespace std;

struct node {
    int data;
    struct node * left, *right;
};

struct node * getNode(int num)
{
    struct node * tmp = new node();
    tmp->right = NULL;
    tmp->left = NULL;
    tmp->data = num;
    return tmp;
}
// Serch the number node in BST
struct node * search(struct node * root, int num)
{
    if(root == NULL)
       return NULL;
       
    if(root->data == num)
       return root;
       
    if (num > root->data)
       return search(root->right,num);
    
    return search(root->left,num);
}

struct node * insert(struct node * root, int num)
{
    if(root == NULL)
        return getNode(num);
       
    if(root->data == num)
        cout << "Element is already present. Not added" << endl;
    else if (num > root->data)
       root->right = insert(root->right,num);
    else
       root->left = insert(root->left,num);

    return root;
}

void preorder(struct node * root)
{
    if(root)
    {
        cout << root->data << endl;
        preorder(root->left);
        preorder(root->right);
    }
}

int main()
{
   cout << "BST" << endl; 
   
   struct node * BST = getNode(50);
   BST->left         = getNode(25);
   BST->right        = getNode(75);
   BST->left->left   = getNode(5);
   BST->left->right  = getNode(35);
   BST->right->left  = getNode(60);
   BST->right->right = getNode(80);
   
   struct node * found = NULL;
   
   found = search(BST,6);
   if(found)
        cout << "Found Node : " << found->data << endl;
   else
        cout << "Node not present in BST." << endl;
   
   struct node * newnode = NULL;
   
   newnode = insert(BST,95);
   
   preorder(BST);
   
   newnode = insert(BST,10);
   
   preorder(BST);
   return 0;
}