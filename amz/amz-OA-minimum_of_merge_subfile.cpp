/*
Approach:
We can choose the two minimal values to get merged and put the merged value back to the array. We continue the process until there is only one element in the array. We use a min-heap to store the elements. The top element of the min-heap is the smallest value in the heap. We can get the two minimal value from the top elements of the min-heap and insert the merged value back to the min-heap. The min-heap is implemented by a priority queue.     
Time complexity: 
We insert all the element in to the min-heap, and the time cost is O(log2 + log3 + ... logn) = O(log(n!)) < O(nlogn).
We get the top two element from the min-heap and insert the merged value back to the min-heap. The time cost is O(log(n-2) + log(n-3) + ... 1) < O(nlogn).
Hence, the total time complexity is O(nlogn)
Space complexity: O(n), that is the size of the priority queue. 
*/

class Solution {
public:
    int connectSticks(vector<int>& sticks) {
        priority_queue<int, vector<int>, greater<int>> pq;
        for (auto s : sticks) {
            pq.push(s);
        }
        int cnt = 0;
        while (pq.size() > 1) {
            int mrg = pq.top(); pq.pop();
            mrg += pq.top(); pq.pop();
            pq.push(mrg);
            cnt += mrg;
        }
        return cnt;
    }
};


//---------------------------------
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

/*
https://leetcode.com/discuss/interview-question/344677/Amazon-or-Online-Assessment-2019-or-Min-Cost-to-Connect-Ropes
Input: ropes = [8, 4, 6, 12]
Output: 58
Explanation: The optimal way to connect ropes is as follows
1. Connect the ropes of length 4 and 6 (cost is 10). Ropes after connecting: [8, 10, 12]
2. Connect the ropes of length 8 and 10 (cost is 18). Ropes after connecting: [18, 12]
3. Connect the ropes of length 18 and 12 (cost is 30).
Total cost to connect the ropes is 10 + 18 + 30 = 58
*/


struct comp {
    bool operator()(const int &a, const int &b) {
        return a > b;
    }
};

int minimunOfMerge(vector<int> &nums) {
    int res = 0;
    priority_queue<int, vector<int>, comp> pq;
    for (int i = 0; i < nums.size(); ++i) {
        pq.push(nums[i]);
    }
    while (pq.size() > 1) {
        int min1, min2, sum;
        min1 = pq.top();
        pq.pop();
        min2 = pq.top();
        pq.pop();
        sum = min1 + min2;
        res += sum;
        pq.push(sum);   
        cout << min1 << ";" << min2 << endl;
    }
    pq.pop();
    return res;
}

int main() {
    vector<int> nums = {4,12,6,8};
    int res = minimunOfMerge(nums);
    cout << "min: " << res << endl;
    
    vector<int> nums1 = {1, 2, 5, 10, 35, 89};
    int res1 = minimunOfMerge(nums1);
    cout << "min: " << res1 << endl;
    
    vector<int> nums2 = {2, 2, 3, 3};
    int res2 = minimunOfMerge(nums2);
    cout << "min: " << res2 << endl;
}

