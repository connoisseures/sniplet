#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;
/*
https://leetcode.com/discuss/interview-question/372434
*/

int num_of_two_sum_unique_pair(vector<int> &nums, int target) {
    unordered_set<int> hset;
    unordered_set<int> ans;
    for (auto n : nums) {
        if (hset.count(target - n) > 0) {
            ans.insert(n);
        } else {
            hset.insert(n);
        }
    }
    return ans.size();
} 

int main() {
    vector<int> nums = {1, 1, 2, 45, 46, 46};
    int target = 47;
    cout << num_of_two_sum_unique_pair(nums, target) << endl;
    
    vector<int> nums1 = {1, 1};
    int target1 = 2;
    cout << num_of_two_sum_unique_pair(nums1, target1) << endl;
}
