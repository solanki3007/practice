#include <iostream>

using namespace std;

struct node {
    struct node * left;
    struct node * right;
    
    int data;
};

struct node * getNode(int val)
{
    struct node * tmpNode = new node;
    tmpNode->left = NULL;
    tmpNode->right = NULL;
    tmpNode->data = val;
    
    return tmpNode;
}

void postorder(struct node * root)
{
    if (root)
    {
        postorder(root->left);
        postorder(root->right);
        cout << root->data << endl;
    }
}

int sumTree (struct node * root)
{
    if(root)
    {
        int left = sumTree(root->left);
        int right = sumTree(root->right);
        
        cout << root->data << ", " << left << ", " << right << endl;
        if(left && right)
        {
            int olddata = root->data;
            root->data = left + right;
            return root->data + olddata;
        }
        else
        {
            int rootdata = root->data;
            root->data = 0;
            return rootdata;
        }
    }
    return 0;
}

int main()
{
   cout << "Sum Tree:" << endl; 
   
   struct node * root = getNode(10);
   
   root->left = getNode(5);
   root->right = getNode(20);
   
   root->left->left = getNode(3);
   root->left->right = getNode(7);
   
   root->right->left = getNode(15);
   root->right->right = getNode(25);
   
   sumTree(root);
   postorder(root);
   return 0;
}