#include <iostream>

using namespace std;

struct node {
    int data;
    struct node *left, *right;
};

struct node * getNode(int idata)
{
    struct node * tmp = new node;
    if(tmp) { 
      tmp->data = idata;
      tmp->right = NULL;
      tmp->left = NULL;
    }
    
    return tmp; 
}

// post order traversal
void traverseTree(struct node * root)
{
    if(root==NULL)
       return;
    traverseTree(root->left);
    cout << root->data << endl;
    traverseTree(root->right);
    return;
}

void mirrorTree(struct node *root)
{

  if(root == NULL)
     return;
  else if (root->left == NULL && root->right == NULL)
     return;
  else
  {
      mirrorTree(root->left);
      mirrorTree(root->right);
      // swap laft and right node
      struct node * tmp = root->left;
      root->left = root->right;
      root->right = tmp;
  }
}

int main()
{
   cout << "Create a mirror tree." << endl; 
   
   struct node * root = getNode(30);
   root->left         = getNode(40);
   root->right        = getNode(20);
   (root->left)->right  = getNode(5);
   (root->left)->left  = getNode(-25);
   (root->right)->right= getNode(15);
   (root->right)->left = getNode(35);   
   
   traverseTree(root);
   mirrorTree(root);
   cout << "Mirror tree:" << endl;
   traverseTree(root);
   return 0;
}