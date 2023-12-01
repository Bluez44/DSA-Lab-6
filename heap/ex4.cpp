#include<bits/stdc++.h>
using namespace std;
template<class T>
class Heap {
protected:
    T* elements;
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
        delete[]elements;
    }
    void push(T item);
    int getItem(T item);
    void remove(T item);
    void clear();
    void printHeap()
    {
        cout << "Max Heap [ ";
        for (int i = 0; i < count; i++)
            cout << elements[i] << " ";
        cout << "]\n";
    }
private:
    void ensureCapacity(int minCapacity);
    void reheapUp(int position);
    void reheapDown(int position);
};


template<class T>
int Heap<T>::getItem(T item) {
    // TODO: return the index of item in heap
    if(count == 0) return -1;
    for(int i = 0; i < count; i++) {
        if(elements[i] == item) return i;
    }
    return -1;
}

template<class T>
void Heap<T>::remove(T item) {
    // TODO: remove the element with value equal to item
    
    int index = getItem(item);
    
    if(index == -1) return; 
    
    swap(elements[index],elements[--count]);

    reheapDown(index);
    
}

template<class T>
void Heap<T>::clear() {
    // TODO: delete all elements in heap
    //    then reallocate memory as initial state
    delete[] elements;
    count = 0;
    elements = new T[capacity];

}