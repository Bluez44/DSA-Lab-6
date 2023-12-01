// Given an array which the elements in it are random. Now we want to build a Max heap from this array. 
// Implement functions Reheap up and Reheap down to heapify element at index position. We will use it to build a heap in next question.
#include<bits/stdc++.h>
using namespace std;

void reheapDown(int maxHeap[], int numberOfElements, int index)
{
    if(index > numberOfElements || index < 0) return;
    
    int left_child = 2*index +1;
    int right_child = 2*index +2;
    int i = (maxHeap[left_child] > maxHeap[right_child])? left_child : right_child;
    if(i > numberOfElements) return;
    if(maxHeap[index] < maxHeap[i]) swap(maxHeap[index], maxHeap[i]);
    reheapDown(maxHeap, numberOfElements, i);
}

void reheapUp(int maxHeap[], int numberOfElements, int index)
{
    if(index > numberOfElements || index < 1) return;
    
    int parent = (index-1)/2;
    if(maxHeap[index] > maxHeap[parent]) swap(maxHeap[index],maxHeap[parent]);
    reheapUp(maxHeap, numberOfElements, parent);
}

int main() {

    int arr[] = {1,2,3,4,5,6,7,8};
    int size = sizeof(arr)/sizeof(arr[0]);
    reheapDown(arr,size,0);
    cout << "[ ";
    for(int i=0;i<size;i++)
        cout << arr[i] << " ";
    cout << "]";
    return 0;
}