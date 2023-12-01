// Given an array of non-negative integers. Each time, we can take the smallest integer out of the array, multiply it by 2, and push it back to the array.

// Request: Implement function:

// int leastAfter(vector<int>& nums, int k);
// Where nums is the given array (the length of the array is between 1 and 100000). 
// This function returns the smallest integer in the array after performing the operation k times (k is between 1 and 100000).

// Example:

// Given nums = [2, 3, 5, 7].

// In the 1st operation, we take 2 out and push back 4. The array is now nums = [3, 4, 5, 7].

// In the 2nd operation, we take 3 out and push back 6. The array is now nums = [4, 5, 6, 7].

// In the 3rd operation, we take 4 out and push back 8. The array is now nums = [5, 6, 7, 8].

// With k = 3, the result would be 5.

#include<bits/stdc++.h>
using namespace std;    

int leastAfter(vector<int>& nums, int k) {
    priority_queue<int, vector<int>, greater<int>> pq(nums.begin(), nums.end());
    for (int i = 0; i < k; i++) {
        int smallest = pq.top();
        pq.pop();
        pq.push(smallest * 2);
    }
    return pq.top();
}

int main() {
    vector<int> nums {2, 3, 5, 7};
    int k = 3;
    cout << leastAfter(nums, k);
    return 0;
}