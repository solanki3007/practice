// Count Number of SubTrees having given Sum

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

void traverseTree(struct node * root)
{
    if(root==NULL)
       return;
    traverseTree(root->left);
    traverseTree(root->right);
    cout << root->data << endl;
    return;
}

int countSubtreesWithSumX(struct node *root, int k)
{
    static int count = 0;
    int sum = 0, sum1=0;
    if(root == NULL)
      return 0;
    else
    {   if(root->left == NULL && root->right == NULL)
        {
            cout << "Node1 :" << root->data << endl;
            sum = root->data;
            return sum;
        }
        else if(root->left == NULL and root->right != NULL)
        {
            cout << "Node2 :" << root->data << endl;

            // Check the current node value
            sum = countSubtreesWithSumX(root->right, k);
            if(sum==k) cout << "Count2 : " << ++count << endl;
            else cout << "sum: " << sum << endl;
            return root->data + sum;
        }
        else if(root->right == NULL && root->left != NULL)
        {
            cout << "Node3 :" << root->data << endl;
            sum = countSubtreesWithSumX(root->left, k);
            if(sum==k) cout << "Count3 : " << ++count << endl;
            else cout << "sum: " << sum << endl;
            return root->data + sum;
        }
        else if (root->right && root->left)
        {
            cout << "Node4 :" << root->data << endl;
            sum = countSubtreesWithSumX(root->left, k);
            if(sum==k) cout << "Count4 : " << ++count << endl;
            else cout << "sum4: " << sum << endl;

            sum1 = countSubtreesWithSumX(root->right, k);
            if(sum1==k) cout << "Count4 : " << ++count << endl;
            else cout << "sum4: " << sum1 << endl;

            return root->data + sum +sum1;
        }
    }
}

int main()
{
   cout << "Subtree sum." << endl;

   struct node * root = getNode(30);
   root->left         = getNode(40);
   root->right        = getNode(20);
   (root->left)->right  = getNode(5);
   (root->left)->left  = getNode(25);
   (root->right)->right= getNode(15);
   (root->right)->left = getNode(35);

   traverseTree(root);

   cout<< "Total Sum: " << countSubtreesWithSumX(root,70) << endl;

   return 0;
}