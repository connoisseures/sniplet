#include <iostream>
#include <vector>
using namespace std;

int binarysearchWithEnd(vector<int> nums, int target) {
	int left = 0, right = nums.size();
	while (left < right) {
		int mid = left + (right - left) / 2;
		if (nums[mid] >= target) {
			right = mid;
		} else {
			left = mid + 1;
		}
	}
	cout << "l:" << left << endl;
	cout << "r:" << right << endl;
	//cout << arr[left] << endl;
	return left;
}

int binarysearchWithMid(vector<int> nums, int target) {
	int left = 0, right = nums.size() - 1;
	while (left <= right) {
		int mid = left + (right - left) / 2;
		if (nums[mid] == target) {
			return mid;
		} else if (nums[mid] > target) {
			right = mid - 1;
			cout << "small:r=" << right << endl;
		} else {
			left = mid + 1;
			cout << "lar:l=" << left << endl;
			cout << "mid=" << nums[mid] << endl;
		}
	}
	cout << "l:" << left << endl;
	cout << "r:" << right << endl;
	//cout << arr[left] << endl;
	return left;
}


int binarysearchWithoutEnd(vector<int> nums, int target) {
	int left = 0, right = nums.size();
	int res = -1;
	while (left < right) {
		int mid = left + (right - left) / 2;
		if (nums[mid] == target) {
			res = mid;
			break;
		}
		else if (nums[mid] > target) {
			right = mid - 1;
			cout << "small:r=" << right << endl;
		} else {
			left = mid + 1;
			cout << "lar:l=" << left << endl;
		}
	}
	cout << "l:" << left << endl;
	cout << "r:" << right << endl;
	cout << "res:" << res << endl;

	//cout << arr[left] << endl;
	return res;
}

int main(int argc, char *argv[]) {
	int arr[] = {-2,-1,5,6,8,11};
	vector<int> nums(arr, arr + sizeof(arr)/sizeof(int));
	int target = 0;
	binarysearchWithEnd(nums, target);
	binarysearchWithoutEnd(nums, target);
	binarysearchWithMid(nums, target);

	
}