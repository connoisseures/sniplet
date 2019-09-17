#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

/*
https://blog.csdn.net/DieHorseSpecial/article/details/52835714
http://vitasuper.github.io/2017/11/13/LC621-Task-Scheduler/
https://www.1point3acres.com/bbs/forum.php?mod=viewthread&tid=447655&extra=&page=1
task的种类数量 >> cooldown的最大值 和 cooldown >> task的种类两种情况
task的种类数量很少 两种不同情况下的空间最优的做法，分别写了实现。
https://www.1point3acres.com/bbs/thread-313212-1-1.html

follow up: many types of tasks and short cool down time, optimize space complexitySpace: O(n), Time: O(n*task.length)

			* 为了达到O(1)的空间复杂度 需要牺牲一定的时间复杂度 因为已知需要K的cooldown 所以每次遇到一个index i . From 1point 3acres bbs
			* 就往回回溯i - k个index 看有没有重复的 有的话就把cooldown加上 这样时间复杂度相当于是n * k


*/

int lastInterval2(vector<string> tasks, int n) {
	if (n == 0) return tasks.size();
	unordered_map<string, int> tmap;
	int cnt = 0;
	for (int i = 0; i < tasks.size(); ++i) {
		if (tmap.count(tasks[i]) == 0) {
			cnt++;
		} else {
			cnt = max(cnt + 1, tmap[tasks[i]] + n + 1);
		}
		tmap[tasks[i]] = cnt;
	}
	return cnt;
}

int main(int argc, char *argv[]) {
	vector<string> tasks{"A","A","B","A"};
	int n = 2;
	cout << lastInterval2(tasks, n) << endl;
	vector<string> tasks2{"A","B","A","A","B","C"};
	cout << lastInterval2(tasks2, 3) << endl;

}