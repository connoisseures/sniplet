#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
	/*
	T(klogk + n) 
	*/
	vector<int> findKLargest(vector<int>& nums, int k) {
		int kth = findKthLargest(nums, k);
		sort(nums.begin(), nums.begin() + k, greater<int>());
		vector<int> res;
		res.insert(res.end(), nums.begin(), nums.begin()+k);
		return res;		
	}
	int findKthLargest(vector<int>& nums, int k) {
		/*
		partitiion of quick sort
		case1:
		xxxxxxxP***
		|-k-|     
		case2:
		|---K----|    
		xxxxp******
			 |-k-| 
			 xxxxp**
		*/
		int n = nums.size();
		int left = 0, right = n - 1;
		while (true) {
			int idx = kpartition(left, right, nums);
			if (idx == k - 1) return nums[idx];
			else if (idx > k - 1) right = idx - 1;
			else left = idx + 1;
		}
		return 0;
	}
	
	int kpartition(int left, int right, vector<int>& nums) {
		int pi = rand() % (right - left + 1) + left;
		swap(nums[pi], nums[right]);
		int pivot = nums[right];
		int large = left;
		for (int i = left; i < right; ++i) {
			if (nums[i] >= pivot) {
				swap(nums[large], nums[i]);
				large++;
			}
		}
		swap(nums[right], nums[large]);
		return large;
	}
};

int main(int argc, char *argv[]) {
	int arr[] = {3,2,1,5,6,4};
	vector<int> nums(arr, arr + sizeof(arr)/sizeof(int));
	Solution s;
	cout << "kth:" << endl;
	cout << s.findKthLargest(nums, 4) << endl; 
	vector<int> nums1(arr, arr + sizeof(arr)/sizeof(int));
	nums = nums1;
	cout << "k largest:" << endl;
	vector<int> res = s.findKLargest(nums, 4);
	for (int i = 0; i < res.size(); ++i) {
		cout << nums[i] << endl;
	}
}