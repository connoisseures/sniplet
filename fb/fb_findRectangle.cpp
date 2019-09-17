#include <iostream>
#include <vector>
#include <utility>
#include <unordered_set>
using namespace std;

bool findRectangleXY(vector<vector<int>>& nums) {
	unordered_set<vector<int>> hset;
	for (int i = 0; i < nums.size(); ++i) {
		hset.insert(nums[i]);
	}
	for (int i = 0; i < nums.size(); ++i) {
		for (int j = i + 1; j < nums.size(); ++j) {
			if (nums[i][0] == nums[j][0] || nums[i][1] == nums[j][1]) continue;
			if (hset.count({nums[i][0], nums[j][1]}) > 0 && hset.count({nums[j][0], nums[i][1]}))
				return true;
		}
	}
	return false;
}

vector<int> findPoint(vector<int>& a, vector<int>& b, vector<int>& c) {
	vector<int> point(2, 0);
	point[0] = a[0] + b[0] - c[0];
	point[1] = a[1] + b[1] - c[1];
	return point;
}

bool isRightTriangle(int i, int j, int k, vector<vector<int>>& nums, vector<int>& point) {
	int a2 = (nums[i][0] - nums[j][0]) * (nums[i][0] - nums[j][0]) + 
			 (nums[i][1] - nums[j][1]) * (nums[i][1] - nums[j][1]);
	int b2 = (nums[i][0] - nums[k][0]) * (nums[i][0] - nums[k][0]) + 
			 (nums[i][1] - nums[k][1]) * (nums[i][1] - nums[k][1]);
	int c2 = (nums[k][0] - nums[j][0]) * (nums[k][0] - nums[j][0]) + 
			 (nums[k][1] - nums[j][1]) * (nums[k][1] - nums[j][1]);
	int max_val = max(a2, max(b2, c2));
	if (max_val == a2 && a2 == b2 + c2) {
		point = findPoint(nums[i], nums[j], nums[k]);	
		return true;
	}		
	if (max_val == b2 && b2 == a2 + c2) {
		point = findPoint(nums[i], nums[k], nums[j]);	
		return true;
	}		
	if (max_val == c2 && c2 == b2 + a2) {
		point = findPoint(nums[k], nums[j], nums[i]);
		return true;	
	}		
	return false;
}

bool findRectangle(vector<vector<int>>& nums) {
	unordered_set<vector<int>> hset;
	for (int i = 0; i < nums.size(); ++i) {
		hset.insert(nums[i]);
	}
	for (int i = 0; i < nums.size(); ++i) {
		for (int j = i + 1; j < nums.size(); ++j) {
			for (int k = j + 1; k < nums.size(); ++k) {
				vector<int> point(2,0);
				if(isRightTriangle(i, j, k, nums, point) && hset.count(point) > 0)
					return true;
			}
		}
	}
	return false;
}


int main(int argc, char *argv[]) {
	
}