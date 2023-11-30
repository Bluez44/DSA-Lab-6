#include<bits/stdc++.h>
using namespace std;

bool findPairs(int arr[], int n, pair<int,int>& pair1, pair<int, int>& pair2) {
    map<int, pair<int, int>> sumMap;

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            int sum = arr[i] + arr[j];
            if (sumMap.find(sum) != sumMap.end()) {
                pair<int, int> pair1 = sumMap[sum];
                pair<int, int> pair2 = make_pair(arr[i], arr[j]);
                if (pair1.first != pair2.first && pair1.first != pair2.second
                    && pair1.second != pair2.first && pair1.second != pair2.second) {
                    cout << "Pairs with equal sum found: (" << pair1.first << ", " << pair1.second << ") and ("
                              << pair2.first << ", " << pair2.second << ")" << endl;
                    return true;
                }
            } else {
                sumMap[sum] = make_pair(arr[i], arr[j]);
            }
        }
    }

    cout << "No pairs with equal sum found" << endl;
    return false;
}


int main() {
    int arr[] = { 3, 4, 7, 1, 2, 9, 8 };
    int n = sizeof arr / sizeof arr[0];
    pair<int, int> pair1, pair2;
    
    return 0;
}