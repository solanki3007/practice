#include <iostream>

using namespace std;

// Program is to get the min hight of the tree

struct node {
    int data;
    struct node *left, *right;
};

int minDepth(struct node * root)
{
    // If root itself null
    if(!root)
      return 0;
      
    // If left and right of root is null. means it is leaf node
    if(root->left == NULL && root->right==NULL)
       return 1;
       
    // If only left tree is null then traverse right sub tree;
    return minDepth(root->right) + 1;
    
    // If only right tree is null then traverse left three
    return minDepth(root->left) + 1;
    
    // If both right and left trees are not null. Then take the min of the length
    return min(minDepth(root->left), minDepth(root->right));
}

struct node * newNode(int idata)
{
    struct node * tmp = new node;
    
    tmp->data = idata;
    tmp->left = NULL;
    tmp->right = NULL;
    
    return tmp;
}


int main()
{

   struct node * root = newNode(10);
   root->left         = newNode(5);
   root->right        = newNode(15);
   (root->left)->left  = newNode(2);
   (root->left)->right = newNode(8);
   (root->right)->right = newNode(17);
   ((root->right)->right)->left = newNode(16);
   
   cout << "Minimum depth of a binary tree: " << minDepth(root) << endl;
   
   return 0;
}