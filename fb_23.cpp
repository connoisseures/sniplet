#include <iostream>
#include <vector>
#include <queue>
using namespace std;
/*
https://blog.csdn.net/github_34333284/article/details/51345092
https://www.cnblogs.com/EdwardLiu/p/6563060.html
http://www.dongcoder.com/detail-746009.html
*/

struct myPair {
	int idx;
	int id;
	int val;
	myPair(int idx, int id, int val):idx(idx), id(id), val(val) {}	
};

struct CustCompare{
	bool operator()(const myPair a, const myPair b) {
		return a.val > b.val;
	}
};

vector<int> mergeSortedArray(vector<vector<int>>& nums) {
	/*
	T(n) = O(nlogk) 
	S(n) = O(logk)
	where k is the number of input array.
	*/
	vector<int> res;
	priority_queue<myPair, vector<myPair>, CustCompare> pq;
	for (int i = 0; i < nums.size(); ++i) {
		myPair cell(i, 0, nums[i][0]);
		pq.push(cell);
	}
	if (pq.empty()) return res;
	while (!pq.empty()) {
		myPair cell = pq.top();
		pq.pop();
		res.push_back(cell.val);
		if (cell.id + 1 < nums[cell.idx].size()) 
			pq.push(myPair (cell.idx, cell.id + 1, nums[cell.idx][cell.id+1]));
	}
	return res;
}

int main(int argc, char *argv[]) {
	vector<vector<int>> nums{{1, 5, 7},{2, 4, 6, 8, 11},{0, 3, 9, 10}};
	vector<int> sortArr = mergeSortedArray(nums);
	for (auto cell : sortArr) {
		cout << cell << " ";
	}
	
}