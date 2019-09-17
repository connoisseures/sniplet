#include <iostream>
#include <vector>
using namespace std;
/*
https://1o24bbs.com/t/topic/262
一个数组[1,5,2,-2,3,4], k = 3 它让求两个interval的和的最大值，问题是，不是这两个interval分别长k，
而是加起来为k……比如k=3就是分成（1，2）长度的interval（0，3这种不算）也就是说这道题答案是（5）+（3+4）= 12.
*/


class Solution {
public:
	vector<int> ksum(vector<int>& nums, int k) {
		/*
		use slidding window to have k-sum
		*/
		int n = nums.size();
		vector<int> sum(n, nums[0]);
		for (int i = 1; i < n; ++i) {
			if (i < k) sum[i] = sum[i-1] + nums[i];
			else {
			   sum[i] = sum[i-1] - nums[i-k] + nums[i]; 
			}
		}
		return sum;
	}
	vector<int> maxSumLeftIdx(vector<int>& ksum, int k) {
		int n = ksum.size();
		int max_val = ksum[k-1];
		vector<int> idxL(n, k - 1);
		for (int i = k; i < n; ++i) {
			if (max_val < ksum[i]) {
				idxL[i] = i;
				max_val = ksum[i];
			} else {
				idxL[i] = idxL[i-1];
			}
		}
		return idxL;
	}
	vector<int> maxSumRightIdx(vector<int>& ksum, int k) {
		int n = ksum.size();
		int max_val = ksum[n-1];
		vector<int> idxR(n, n - 1);
		for (int i = n - 2; i > k - 2; --i) {
			if (max_val < ksum[i]) {
				idxR[i] = i;
				max_val = ksum[i];
			} else {
				idxR[i] = idxR[i+1];
			}
		}
		return idxR;
	}
	int maxSumOfSubarraysK(vector<int>& nums, int m) {
		vector<vector<int>> ksum2d;
		vector<vector<int>> leftIdx;
		vector<vector<int>> rightIdx;
		for (int i = 0; i < m - 1; ++i) {
			vector<int> sum = ksum(nums, i + 1);
			ksum2d.push_back(sum);
			vector<int> idx_L = maxSumLeftIdx(sum, i + 1);
			vector<int> idx_R = maxSumRightIdx(sum, i + 1);
			leftIdx.push_back(idx_L);
			rightIdx.push_back(idx_R);
			show(sum);
			show(idx_L);
			show(idx_R);
		}
		//cout << leftIdx.size() << endl;
		//cout << leftIdx[0].size() << endl;

		int n = nums.size();
		int max_val = 0;
		vector<int> interval(2,0);
		vector<int> ansIdx(2, 0);
		for (int i = 0; i < m - 1; ++i) {
			for (int j = i; j < (n - (i + 1)); ++j) {
				if (max_val < ksum2d[i][j] + ksum2d[m-i-2][j+m-1-i]) {
					max_val = ksum2d[i][j] + ksum2d[m-i-2][j+m-1-i];
					interval = {i + 1, m - (i + 1)};
					ansIdx = {leftIdx[i][j], rightIdx[m-i-2][j+m-1-i]};
				}
			}
		}
		cout << "interval: ";
		show(interval);
		cout << "idx: ";
		show(ansIdx);
		return max_val;
	}
	void show(vector<int>& arr) {
		for (auto i : arr) cout << i << " ";
		cout << endl;
	}
};

int main(int argc, char *argv[]) {
	Solution s;
	vector<int> nums{1,5,2,-2,3,4};
	int k = 3;
	s.show(nums);
	cout << s.maxSumOfSubarraysK(nums, k) << endl;
	vector<int> nums1{1,5,3,2,-2,3,4};
	int k1 = 3;
	s.show(nums1);
	cout << s.maxSumOfSubarraysK(nums1, k1) << endl;
}