#include<bits/stdc++.h>
using namespace std;

int binarySearch(int arr[], int left, int right, int x)
{
    int index = (right+left) / 2;
    cout << "We traverse on index: " << index << endl;
    if(arr[index] == x) return index;
    else if(left == right) return -1;
    else if(arr[index] < x) {
        return binarySearch(arr, index+1, right, x);
    }
    else return binarySearch(arr, left, index-1, x);
}