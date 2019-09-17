/*
Approach:
We use a hash map to record the index of each element in the array by using the value of the element as the key in the hash map and the index in the array as the value of the hash map. We check the element one by one to find if there is another element existing in the hash map and their sume is exactly the target. We also use a variable to record the maximal value in candidate pairs to help us find the pair with the maximal value. 
Time complexity: We scan the elements in the array one by one, so the time complexity is O(N)
Space complexity: We use a hash map to record the index of each element, so the space complexity is O(N) 
*/

#include <iostream>
#include <vector>
#include <unordered_map>
#include <climits>
using namespace std;

vector<int> find_pair_with_given_sum(vector<int> &nums, int target) {
    unordered_map<int, int> hmap;
    vector<int> res(2, 0);
    int max_val = INT_MIN;
    if (target - 30 < 0) return res;
    for (int i = 0; i < nums.size(); ++i) {
        if (hmap.count(target - 30 - nums[i]) > 0) {
            if (nums[i] > max_val || target - 30 - nums[i] > max_val) {
                res[0] = hmap[target-30-nums[i]];
                res[1] = i;
                max_val = max(nums[i], target - 30 - nums[i]);
            }
        }
        hmap[nums[i]] = i;
    }
    return res;
}

int main() {
    vector<int> nums = {1, 10, 25, 35, 60}; 
    int target = 90;
    vector<int> ans = find_pair_with_given_sum(nums, target);
    cout << ans[0] << "," << ans[1] << endl;

    vector<int> nums1 = {20, 50, 40, 25, 30, 10};
    int target1 = 90;
    vector<int> ans1 = find_pair_with_given_sum(nums1, target1);
    cout << ans1[0] << "," << ans1[1] << endl;

    vector<int> nums2 = {10, 30, 40, 25, 30, 10};
    int target2 = 90;
    vector<int> ans2 = find_pair_with_given_sum(nums2, target2);
    cout << ans2[0] << "," << ans2[1] << endl;
}
