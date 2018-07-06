#include <iostream>

using namespace std;

struct node {
    int data;
    struct node *left, *right;
};

struct node * getNode(int idata)
{
    struct node * tmp = new node;
    tmp->data = idata;
    tmp->left = NULL;
    tmp->right = NULL;
    
    return tmp;
}

bool isIsomorfic(struct node * root1, struct node * root2)
{
    if(root1 == NULL && root2 == NULL)
       return true;
       
    if((root1 != NULL && root2 == NULL) || (root1 == NULL && root2 != NULL))
       return false;
       
    if(root1->data == root2->data)
       return true;
    
    bool isT1LandT2RisIso = isIsomorfic(root1->left, root2->right);
    bool isT1LandT2LisIso = isIsomorfic(root1->left, root2->left);
    
    if(isT1LandT2LisIso || isT1LandT2LisIso)
       return true;
    
    isT1LandT2RisIso = isIsomorfic(root2->left, root1->right);
    isT1LandT2LisIso = isIsomorfic(root2->left, root1->left);
    
    if(isT1LandT2LisIso || isT1LandT2LisIso)
       return true;
       
    return false;
}

void traverse(struct node * root)
{
    // Inorder
    if(root)
    {
       traverse(root->left);
       cout << root->data << endl;
       traverse(root->right);
    }
}
int main()
{
   cout << "Check if two trees are isomorphic." << endl; 
   
   cout << "Traverse tree1." << endl;
   // Tree 1 started with root1
   struct node * root1 = getNode(100);
   root1->left          = getNode(50);
   root1->right         = getNode(120);
   (root1->right)->left  = getNode(70);
   (root1->right)->right = getNode(105);
   
   //traverse(root1);
   
   cout << "Traverse tree2." << endl;
   // Tree 2 started with root2
   struct node * root2 = getNode(100);
   root2->right        = getNode(50);
   root2->left         = getNode(120);
   (root2->left)->right= getNode(105);
   (root2->left)->left = getNode(70);
   
   //traverse(root2);
   
   cout << isIsomorfic(root1, root2) << endl;
   
   return 0;
}