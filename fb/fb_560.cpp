#include <iostream>
#include <vector>
using namespace std;

int subarrayWithNegElement(vector<int>& nums, int k) {
	
}

bool subarrayWithPosElement(vector<int>& nums, int k) {
	int left = 0, sum = 0;
	int n = nums.size();
	for (int i = 0; i < n; ++i) {
		sum += nums[i];
		while (sum > k) {
			sum -= nums[left];
			left++;
		}
		cout << "s:" << sum << endl;
		if (sum == k) return true;
	}
	return false;
}

int main(int argc, char *argv[]) {
	int arr[] = {2,1,3,4,1,2,1,5,4};
	vector<int> nums(arr, arr + sizeof(arr)/sizeof(int));
	cout << "1." << endl;
	cout << subarrayWithPosElement(nums, 20) << endl;
	cout << "2." << endl;
	cout << subarrayWithPosElement(nums, 20) << endl;
}