/*
1099. Two Sum Less Than K
https://leetcode.com/problems/two-sum-less-than-k/
*/
class Solution {
public:
    int twoSumLessThanK(vector<int>& A, int K) {
        /*
        1. sort array
        2. use two pointer, left and right, to find the closet sum. 
        */
        sort(A.begin(), A.end());
        int left = 0, right = A.size() - 1;
        vector<int> res(2, 0);
        int diff = INT_MAX;
        int ans = -1;
        while (left < right) {
            if (A[left] + A[right] < K && K - A[left] - A[right] < diff) {
                diff = K - A[left] - A[right];
                res[0] = left;
                res[1] = right;
                ans = A[left] + A[right];
            }
            if (A[left] + A[right] > K) right--;
            else left++;
        }
        return ans;
    }
};

