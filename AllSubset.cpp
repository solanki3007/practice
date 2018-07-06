#include <iostream>

using namespace std;

void subsets(int data[], int index, int array[], int i, int setsize)
{
    // print only leaf nodes of the subset tree
    if ((i >= setsize) || (index >= setsize)){
      for(int j = 0; j < i; j++)
        cout << data[j] <<"," ;
      cout << endl;
    }

    if ((i >= setsize) || (index >= setsize))
    return;

    // Added one next element in data
    data[i] = array[index];

    // Call the same function including this item
    subsets(data, index+1, array, i+1, setsize);

    // Call the same function excluding next item
    subsets(data, index+1, array, i, setsize);
}

int main()
{
   cout << "All possible subsets." << endl;

   int set[10] = {4,10,3,45};
   int data[10] = {0,0,0,0};

   subsets(data, 0, set, 0, 4);

   return 0;
}