#include <iostream>
#include <vector>
using namespace std;

int maxSubarrayBypresum(vector<int>& nums, int k) {
	int max_val = INT_MIN;
	int idx;
	/*
	k=2
	1234
	^^
	  *
	  sum(1~2) = sum[2] - sum[2-2]
	*/
	for (int i = 1; i < nums.size(); ++i) {
		nums[i] = nums[i-1] + nums[i];
		if (i == k - 1) max_val = nums[i];
		if (i >= k) {
			if (nums[i] - nums[i-k] > max_val) {
				max_val = nums[i] - nums[i-k];
				idx = i - k + 1;
			}
		}
	}
	cout << idx << " has max = " << max_val << endl;
	return max_val;
}

vector<int> maxSubarray(vector<int>& nums, int k) {
	int n = nums.size();
	vector<int> res;
	int idx = -1;
	int left = 0, sum = 0, max_val = INT_MIN;
	for (int i = 0; i < n; ++i) {
		if (i < k) {
			sum += nums[i];
			max_val = sum;
			continue;
		}
		sum += nums[i];
		sum -= nums[i-k];
		if (sum > max_val) {
			max_val = sum;
			idx = i - k + 1;
		}	
	}
	res.push_back(idx);
	res.push_back(max_val);
	cout << idx << " has max = " << max_val << endl;
	return res;
}

int main(int argc, char *argv[]) {
	int arr[] = {-2,1,-3,4,-1,2,1,-5,4};
	vector<int> nums(arr, arr + sizeof(arr)/sizeof(int));
	maxSubarray(nums, 4);
	maxSubarrayBypresum(nums, 4);
		
}