#include <iostream>
#include <vector>
using namespace std;
/*
898. Leftmost One
Given a 2D array, and each line has only 0 and 1, the front part is 0, and the latter part is 1. Find the number of columns in the leftmost 1 of all the rows in the array.

Example
Given arr = [[0,0,0,1],[1,1,1,1]], return 0.

Explanation:
Arr[1][0] is the leftmost 1 in all rows and its column is 0.
Given arr = [[0,0,0,1],[0,1,1,1]], return 1.

Explanation:
Arr[1][1] is the leftmost 1 in all rows and its column is 1.
Notice
The number of rows in the array and the number of columns do not exceed 1000
In order to limit the time complexity, your program will run 50000 times

*/
class Solution {
public:
	/**
	 * @param arr: The 2-dimension array
	 * @return: Return the column the leftmost one is located
	 */
	int getColumn(vector<vector<int>> &arr) {
		/*
		T(n) = O(m+n)
		S(n) = 1
 		*/
		int m = arr.size();
		int n = arr[0].size();
		/*
		0000000111
		0000011111
		0011111111
		0000011111
		0001111111
		*/
		int x = n - 1, y = 0;
		while (x > -1 && y < m) {
			while (x - 1 > -1 && arr[y][x-1] == 1) {//x at most = 0;
				x--;
			}
			while (y +1 < m && arr[y+1][x] == 0) {
				y++;
			}
			y++;//1st one for y
		}
		return x;
	}
};

int main(int argc, char *argv[]) {
	vector<vector<int>> arr;
	arr.push_back(vector<int> {0,0,0,0,0,0,0,1,1,1});
	arr.push_back(vector<int> {0,0,0,0,0,1,1,1,1,1});
	arr.push_back(vector<int> {0,0,1,1,1,1,1,1,1,1});
	arr.push_back(vector<int> {0,0,0,0,1,1,1,1,1,1});
	arr.push_back(vector<int> {0,0,0,1,1,1,1,1,1,1});
	Solution s;
	int c = s.getColumn(arr);
	cout << c << endl;
}