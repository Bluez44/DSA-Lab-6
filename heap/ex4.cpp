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
    for(int i = 0; i < this->count ; i++){
        if(this->elements[i] == item) return i;
    }
    return -1;
}

template<class T>
void Heap<T>::remove(T item) {
    // TODO: remove the element with value equal to item
    if(this->count != 0){
        int i = getItem(item);
        if(i != -1){
            T temp = this->elements[count-1];
            this->elements[count-1] = this->elements[i];
            this->elements[i] = temp;
            this->count--;
            reheapDown(i);
            reheapUp(i);
        }
    }
}
template<class T>
void Heap<T>::clear() {
    // TODO: delete all elements in heap
    T * newelement = new T[this->capacity];
    this->elements = newelement;
    this->count = 0;
}