#include <iostream>
#include <vector>
#include <unordered_map>
#include <utility>
using namespace std;

/*
第一题 sparse vector dot product 设计sparse vector的存储方式，以及如何计算dot product。地里高频题，存储为非零分量对应的(index, value)对的数组。
dot product计算，当两个vector长度差不多且都不太长时two pointers， 否则枚举短的对长的二分。我先写了two pointers， 她follow-up让我写了二分，并且进行一些细节的优化。

http://yuanhsh.iteye.com/blog/2186422
有两个很大的稀疏向量，问怎么存储和算他们的dot product. 只存储非零元素和他的index
，如果压缩后的向量大小为m,n, O(m+n)和O(mlogn)方法都不难想到。他问有没有更好
，提示divide and conquer，我就说先取一个向量的中间元素，然后搜索他在另一个向
量中对应元素的位置，这样就把两个矩阵都分别分为两半。他问复杂度，我说我要算一
下才知道，然后他说他也不知道，不过平均情况应该比前面的好。
*/

int DotProductByDict(vector<int>& v1, vector<int>& v2) {
	/*
	dict: {indx, value}
	T(n) = O(n+m)
	S(n) = O(n+m)
	*/
	unordered_map<int, int> dict1;
	unordered_map<int, int>	dict2;
	for (int i = 0; i < v1.size(); ++i) {
		if (v1[i] != 0) dict1[i] = v1[i];
	}
	for (int i = 0; i < v2.size(); ++i) {
		if (v2[i] != 0) dict2[i] = v2[i];
	}
	int res = 0;
	for (auto it = dict1.begin(); it != dict1.end(); ++it) {
		if (dict2.count(it->first) > 0) res += dict2[it->first] * it->second;
	}
	return res;
}

int DotProductByVec(vector<int>& v1, vector<int>& v2) {
	/*
	assume v1.size() ~ v2.size()
	T(n) = O(n+m)
	S(n) = O(n+m)
	*/
	vector<pair<int, int>> p1;
	for (int i = 0; i < v1.size(); ++i) {
		if (v1[i] != 0) p1.push_back(make_pair(i, v1[i]));
	}
	vector<pair<int, int>> p2;
	for (int i = 0; i < v2.size(); ++i) {
		if (v2[i] != 0) p2.push_back(make_pair(i, v2[i]));
	}
	int res = 0;
	int idx1 = 0, idx2 = 0;
	while (idx1 < p1.size() && idx2 < p2.size()) {
		if (p1[idx1].first == p2[idx2].first) {
			res += p1[idx1].second * p2[idx2].second;
			idx1++;
			idx2++;
		} else if (p1[idx1].first > p2[idx2].first) {
			idx2++;
		} else {
			idx1++;
		}
	}
	return res;
}

int binarySearch(int target, vector<pair<int, int>>& p) {
	int left = 0, right = p.size() - 1;
	while (left <= right) {
		int mid = left + (right - left) / 2;
		if (target == p[mid].first) return mid;
		if (target > p[mid].first) left = mid + 1;
		else right = mid - 1;
	}
	return -1;
}

int DotProductByBS(vector<int>& v1, vector<int>& v2) {
	/*
	assume v1.size() (n) << v2.size() (m)
	T(n) = O(nlogm)
	S(n) = O(n+m)
	*/
	vector<pair<int, int>> p1;
	for (int i = 0; i < v1.size(); ++i) {
		if (v1[i] != 0) p1.push_back(make_pair(i, v1[i]));
	}
	vector<pair<int, int>> p2;
	for (int i = 0; i < v2.size(); ++i) {
		if (v2[i] != 0) p2.push_back(make_pair(i, v2[i]));
	}
	int res = 0;
	for (int i = 0; i < p1.size(); ++i) {
		int idx = binarySearch(p1[i].first, p2);
		if (idx > -1) res += p1[i].second * p2[idx].second; 
	}
	return res;
}

int main(int argc, char *argv[]) {
	cout << "with hash" << endl;
	vector<int> v1{0,2,0,2,0,0,3,0,0,4};
	vector<int> v2{0,0,0,0,5,0,2,0,0,8};
	cout << DotProductByDict(v1, v2) << endl;
	 
	cout << "with array and v1 ~ v2" << endl;
	vector<int> v3{0,2,0,2,0,0,3,0,0,4,1,3,2};
	vector<int> v4{0,0,0,0,5,0,2,0,0,8,0,1,1,1,1,1};
	cout << DotProductByVec(v3, v4) << endl; 
	
	cout << "with array + Binary Search and v1 << v2" << endl;
	vector<int> v5{0,2,2,0,1,1,1,1,1,1};
	vector<int> v6{0,0,0,0,5,0,2,0,0,8,0,1,1,1,1,1};
	cout << DotProductByBS(v5, v6) << endl; 


}