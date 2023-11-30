#include<bits/stdc++.h>
using namespace std;

int jumpSearch(int arr[], int x, int n) {
    // TODO: print the traversed indexes and return the index of value x in array if x is found, otherwise, return -1.
    int step = (int)sqrt(n);
    cout << 0 << " ";
    if(arr[0] == x) {
        return 0;
    }

    int i = step;
    for( ; i < n; i += step) {
        cout << i << " ";
        if(arr[i] == x) return i;
        else if(arr[i] > x) {
            for(int k = i - step + 1; k < i; k++) {
                cout << k << " ";
                if(arr[k] == x) return k;
            }
            break ;
        }
        else if(i + step > n) {
            i++;
            for( ; i <= n; i++) {
                cout << i << " ";
                if(arr[i] == x) return i;
            }
            break;
        }
    }

    
    return -1;
}

int main() {

int arr[] = { 0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144, 233, 377, 610, 611, 612, 613, 1000, 1002, 2000, 2003, 2004, 2005, 2006 };
int x = 36;
int n = sizeof(arr) / sizeof(arr[0]);
int index = jumpSearch(arr, x, n);

if (index != -1) {
    cout << "\nNumber " << x << " is at index " << index;
}
else {
    cout << "\n" << x << " is not in array!";
}
    return 0;
}