// Cho template của class PrinterQueue có 2 phương thức bắt buộc:

// 1. addNewRequest(int priority, string fileName)
// Phương thức đầu tiên sẽ thêm 1 file vào danh sách hàng đợi của máy in (bao gồm độ ưu tiên và tên file). 
// Test case sẽ có tối đa 100 file cùng lúc trong hàng đợi

// 2. print()
// Phương thức thứ hai sẽ in tên file kèm xuống dòng và xóa nó ra khỏi hàng đợi. 
// Nếu không có file nào trong hàng đợi, phương thức sẽ in ra "No file to print" kèm xuống dòng.

// PrinterQueue tuân theo các quy tắc sau:

// fileName có độ ưu tiên cao nhất sẽ được in trước.
// Các fileName có cùng độ ưu tiên sẽ in theo thứ tự FIFO (First In First Out) order.

#include<bits/stdc++.h>
using namespace std;

class PrinterQueue
{
    // your attributes
    queue<string> q;
    pair<int , string> arr[100];
    int n = 0;
    int order_counter = 1000;
public:
    // your methods
    void reHeapDown(int index) {
        if(index > n/2) return;

        int left_child = 2*index + 1;
        int right_child = 2*index + 2;
        int larger_child;

        if(left_child >= n) return;
        if(right_child >= n) larger_child = left_child;
        else larger_child = (arr[left_child].first >= arr[right_child].first)? left_child : right_child;

        if(arr[larger_child].first >= arr[index].first) {
            swap(arr[larger_child], arr[index]);
            reHeapDown(larger_child);
        }
    }

    void remove() {
        if (this->n == 0) throw "Empty heap"; 
        swap(arr[0],arr[--n]);
        reHeapDown(0);
    }

    void buildHeap() {
        for(int i = n/2 ; i >= 0; i--) {
            reHeapDown(i);
        }
    }



    void addNewRequest(int priority, string fileName)
    {
        arr[n].first = priority*1000 + order_counter;
        arr[n].second = fileName;
        n++; order_counter--;
        buildHeap();
        // your code here
    }

    void print()
    {
        if(n > 0) {
            cout << arr[0].second << endl;
            remove();
        }
        else cout << "No file to print\n";
        // for(int i = 0; i < n; i++) 
        //     cout << arr[i].second << " - " << arr[i].first << endl;

        // your code here
        // After some logic code, you have to print fileName with endline 
    }
};

int main() {
    PrinterQueue* myPrinterQueue = new PrinterQueue();
    myPrinterQueue->addNewRequest(1, "hello.pdf");
    myPrinterQueue->addNewRequest(2, "goodbye.pdf");
    myPrinterQueue->addNewRequest(2, "goodnight.pdf");
    myPrinterQueue->print();
    myPrinterQueue->print();
    myPrinterQueue->print();
    myPrinterQueue->print();
    return 0;
}