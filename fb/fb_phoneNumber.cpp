#include <iostream>
#include <vector>
#include <unordered_set>
#include <queue>
#include <string>
#include <utility>
using namespace std;
/*

给一个电话棋盘 0-9，形状类似汉字 '甲' ，最下面的是0。有一个走日的骑士，起始在'1'上，也就是左上角，走 n 步，
求能走出的电话号码的个数。
followup：输入加一个List<String>， 里面是一些长度为 n + 1的电话号码，表示这些电话号码是被禁止的，
所以不应该被包括在上一问的结果里，还是求能走出的号码的个数。
*/

class Solution {
public:
	int knightDialer(int N, int idx) {
		static const int MOD = 1000000007;
		vector<vector<int>> graph = {{4, 6}, {6, 8}, {7, 9}, {4, 8}, {0, 3, 9}, {}, 
									 {0, 1, 7}, {2, 6}, {1, 3}, {2, 4}};
		vector<int> cnt(graph.size(), 0);
		cnt[idx] = 1;
		int total = 10;
		for (int k = 1; k <= N; ++k) {
			vector<int> nxtCnt(graph.size(), 0);
			int nxtTotal = 0;
			for (int i = 0; i < graph.size(); ++i) {
				for (int j = 0; j < graph[i].size(); ++j) {
					int nd = graph[i][j];
					nxtCnt[i] = (nxtCnt[i] + cnt[nd]) % MOD;
				}
				nxtTotal = (nxtTotal + nxtCnt[i]) % MOD; 
			}
			cnt = nxtCnt;
			total = nxtTotal;
		}
		return total;
	}
	int knightDialerWiProhibition(int N, int idx, vector<string>& nums) {
		vector<vector<int>> graph = {{4, 6}, {6, 8}, {7, 9}, {4, 8}, {0, 3, 9}, {}, 
									 {0, 1, 7}, {2, 6}, {1, 3}, {2, 4}};
		unordered_set<string> hset(nums.begin(), nums.end());
		queue<pair<int, string>> que;
		que.push(make_pair(idx, to_string(idx)));
		while (N > 0) {
			int sz = que.size();
			for (int i = 0; i < sz; ++i) {
				int nd = que.front().first;
				string s = que.front().second;
				que.pop();
				for (int j = 0; j < graph[nd].size(); ++j) {
					int neighbor = graph[nd][j];
					que.push(make_pair(neighbor, s + to_string(neighbor)));
				}
			}
			N--;
		}
		vector<string> res;
		//cout << que.size() << endl;
		while (que.size()) {
			string s = que.front().second;
			//cout << s << endl;
			if (hset.count(s) == 0) res.push_back(s);
			que.pop();
		}
		return res.size();
	}
};

int main(int argc, char *argv[]) {
	Solution s;
	cout << s.knightDialer(3, 1) << endl;
	vector<string>	nums{"1816", "1834"};
	cout << s.knightDialerWiProhibition(3, 1, nums) << endl;	
}