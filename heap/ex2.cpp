// Implement function push to push a new item to a maxHeap. You also have to implement ensureCapacity and reheapUp to help you achieve that.
#include<bits/stdc++.h>
using namespace std;

template<class T>
class Heap{
protected:
    T *elements;
    int capacity;
    int count;
    
public:
    Heap()
    {
        this->capacity = 10;
        this->count = 0;
        this->elements = new T[capacity];
    }
    ~Heap()
    {
        delete []elements;
    }
    void push(T item);
    void printHeap()
    {
        cout << "Max Heap [ ";
        for (int i = 0; i < count; i++)
            cout << elements[i] << " ";
        cout << "]";
    }
    
private:
    void ensureCapacity(int minCapacity); 
    void reheapUp(int position);
};


//code
template<class T>
void Heap<T>::push(T item){
    if(count == capacity) {
        ensureCapacity(capacity*2);
    }
    elements[count] = item;
    reheapUp(count);
    count++;
}

template<class T>
void Heap<T>::ensureCapacity(int minCapacity){
    if (minCapacity > capacity) {
        T *newElements = new T[minCapacity];
        for (int i = 0; i < count; i++) {
            newElements[i] = elements[i];
        }
        delete[] elements;
        elements = newElements;
        capacity = minCapacity;
    }
}

template<class T>
void Heap<T>::reheapUp(int position){
    if(position == 0) return;
    int parent = (position-1)/2;
    if(elements[position] > elements[parent]) swap(elements[position],elements[parent]);
    reheapUp(parent);
}