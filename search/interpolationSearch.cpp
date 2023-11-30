#include<bits/stdc++.h>
using namespace std;

int interpolationSearch(int arr[], int left, int right, int x)
{
    int pos = left + (  ((x - arr[left])*(right - left)) / (arr[right] - arr[left]) );

    if(arr[pos] == x) {
            cout << "We traverse on index: " << pos << endl;
        return pos;
    }
    else if(pos < left || pos >= right) return -1;
    else if(arr[pos] < x) {
        cout << "We traverse on index: " << pos << endl;
        return interpolationSearch(arr, pos+1, right, x);
    }
    else {
            cout << "We traverse on index: " << pos << endl;
        return interpolationSearch(arr, left, pos-1, x);
    }
}