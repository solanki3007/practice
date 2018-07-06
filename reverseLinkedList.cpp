#include <iostream>

using namespace std;

struct node {
    int data;
    struct node * next;
};


struct node * getNode(int idata)
{
    struct node * tmp = new node;
    tmp->data = idata;
    tmp->next = NULL;
    return tmp;
}

struct node * reverse(struct node * head)
{
    struct node * t1, *t2;
    t1 = NULL;
    t2 = head;
    head = head->next;
    
    while(head->next != NULL)
    {
        t2->next = t1;
        t1 = t2;
        t2 = head;
        head = head->next;
    }
    
    t2->next = t1;
    head->next = t2;
    t1 = t2 = NULL;
    
    return head;
}

int main()
{
   cout << "Reverse Linked list." << endl; 
   
   struct node * head = getNode(1);
   head->next         = getNode(2);
   (head->next)->next  = getNode(3);
   ((head->next)->next)->next  = getNode(4);
   (((head->next)->next)->next)->next  = getNode(5);
   ((((head->next)->next)->next)->next)->next = NULL;
 
   struct node * tmp = head;
   while(tmp!=NULL)
   {
       cout << tmp->data << endl;
       tmp = tmp->next;
   }
   
   struct node * headNew = reverse(head);
 
   cout << "Reverse List:" << endl;
   tmp = headNew;
   while(tmp!=NULL)
   {
       cout << tmp->data << endl;
       tmp = tmp->next;
   }
   
   return 0;
}