#include <iostream>
#include <vector>
using namespace std;

int maxSumSubarrayK(vector<int>& nums, int k) {
	if (nums.size() < k || k < 1) return 0;
	int sum = 0;
	for (int i = 0; i < k; ++i) {
		sum += nums[i];
	}
	int max_val = sum;
	for (int i = k; i < nums.size(); ++i) {
		/*
		0123 k =3
		   |
		|
		*/
		sum += nums[i] - nums[i-k];
		max_val = max(max_val, sum);
	}
	return max_val;
}

int main(int argc, char *argv[]) {
	vector<int> nums{1, 4, 2, 10, 23, 3, 1, 0, 20};
	int k = 4;
	cout << maxSumSubarrayK(nums, k) << endl;
}