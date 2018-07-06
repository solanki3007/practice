#include <iostream>

using namespace std;

void swap(int A[], int a, int b)
{
    int tmp = A[a];
    A[a] = A[b];
    A[b] = tmp;
}

int partition(int A[], int start, int end)
{
    int ipivot = A[end];
    int pIndex = start;
    for (int i = start; i < end; i++)
    {
        if(A[i] <= ipivot)
        {
            swap(A, pIndex,i);
            pIndex++;
        }
    }
    // Now swap pindex and ipovet
    swap(A, pIndex, end);
    return pIndex;
}

void quickSort(int A[], int start, int end)
{
    cout << "Sub Arry: " << A[start] << endl;
    if(start < end){
        int pivot = partition(A, start, end);
        quickSort(A,start, pivot-1);
        quickSort(A,pivot+1, end);
    }
}

int main()
{
   cout << "Quick Sort:" << endl;

   int Array[10] = {10,7,21,3,23,6,15,73,90,7};

   quickSort(Array,0,9);
   int i = 0;
   while(i<10)
      cout << Array[i++] << "," ;
   return 0;
}