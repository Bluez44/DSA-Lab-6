#include<bits/stdc++.h>
using namespace std;

template <class T>
class Sorting {
public:
    /* Function to print an array */
    static void printArray(T *start, T *end)
    {
        long size = end - start;
        for (int i = 0; i < size - 1; i++)
            cout << start[i] << ", ";
        cout << start[size - 1];
        cout << endl;
    }
    
    //Helping functions go here
    static void heapify(T* arr, int n, int i);
    static void heapSort(T* start, T* end){
        //TODO
        Sorting<T>::printArray(start,end);
    }
    
};

// //Helping functions go here
// static void reheapDown(T* &start, int index, int n) {
//     int left_child = index*2 + 1;
//     int right_child = index*2 + 2;
//     if(left_child >= n) return;
//     int smaller_child; 
//     if(right_child >= n) smaller_child = left_child;
//     else smaller_child = (start[left_child] < start[right_child])? left_child : right_child;
//     if(start[index] > start[smaller_child]) swap(start[index], start[smaller_child]);
// }

// static void removeHeap(T* start, T* end, int n) {
//     swap(start[0], start[n]);
//     reheapDown(start, 0, n);
//     long size = end - start;
//     for(int i = n; i < size-1; i++) {
//         swap(start[i], start[i+1]);
//     }
// }

// static void buildHeap(T* &start, int n) {
//     for(int i = (n-1)/2; i >= 0; i--) {
//         reheapDown(start, i, n);
//     }
// }

// static void heapSort(T* start, T* end){
//     //TODO
//     long n = end - start;
//     Sorting<T>::buildHeap(start, n);
//     while(n) {
//         n--;
//         removeHeap(start, end, n);
//     }
//     Sorting<T>::printArray(start,end);
// }

template<class T> void Sorting<T>::heapify(T *arr, int n, int i) {
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;

    if (l < n && arr[l] > arr[largest])
        largest = l;

    if (r < n && arr[r] > arr[largest])
        largest = r;

    if (largest != i) {
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}

template<class T> inline void Sorting<T>::heapSort(T *start, T *end) {
    int n = end - start;

    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(start, n, i);

    for (int i = n - 1; i > 0; i--) {
        swap(start[0], start[i]);
        heapify(start, i, 0);
    }

    Sorting<T>::printArray(start, end);
}
