#include <iostream>

using namespace std;

struct node {
    int data;
    struct node *next;
};

struct node * getNode(int idata)
{
    struct node * tmp = new node;
    tmp->data = idata;
    tmp->next = NULL;
    
    return tmp;
}

void splitList(struct node *head, struct node **list1, struct node **list2)
{
    // take the concept of slow and fast pointer
    struct node * slow = head;
    struct node * fast = head->next;
    
    while(fast != NULL)
    {
        fast = fast->next;
        if(fast!=NULL)
        {
            fast = fast->next;
            slow = slow->next;
        }
    }
    
    *list1 = head;
    *list2 = slow->next;
    slow->next = NULL;
}

struct node * mergelist(struct node * list1, struct node * list2)
{
    struct node * result = NULL;
    
    if(list1 == NULL)
        return list2;
    else if(list2 == NULL)
        return list1;
    
    if(list1->data < list2->data)
    {
        result = list1;
        result->next = mergelist(list1->next, list2);
    }
    else {
        result = list2;
        result->next = mergelist(list1, list2->next);
    }
    return result;
}

void mergesort(struct node ** listHead)
{
    struct node * head = *listHead;
    struct node * subList1, *subList2;
    
    if((head == NULL) || (head->next == NULL))
      return;
    
    splitList(head, &subList1, &subList2);
    
    mergesort(&subList1);
    mergesort(&subList2);
    
    *listHead = mergelist(subList1,subList2);
}

int main()
{
   cout << "implement merge sort." << endl; 
   
   struct node * list                        = getNode(20);
   list->next                                = getNode(5);
   (list->next)->next                         = getNode(15);
   ((list->next)->next)->next                  = getNode(35);
   (((list->next)->next)->next)->next           = getNode(25);
   ((((list->next)->next)->next)->next)->next    = getNode(13);
   (((((list->next)->next)->next)->next)->next)->next = getNode(23);
   
   mergesort(&list);
   
   struct node * tmp = list;
   while(tmp)
   {
       cout << tmp->data << endl;
       tmp = tmp->next;
   }
   return 0;
}