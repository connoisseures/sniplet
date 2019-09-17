#include <iostream>
#include <vector>
#include <utility>
using namespace std;

struct Point {
	int x;
	int y;
	Point(): x(0), y(0) {}
	Point(int a, int b): x(a), y(b) {}
};

bool pointComp(Point a, Point b) {
	return a.x * a.x + a.y * a.y < b.x * b.x + b.y * b.y; 
}

class Solution {
public:
	/**
	 * @param points: a list of points
	 * @param origin: a point
	 * @param k: An integer
	 * @return: the k closest points
	 */
	 /*
	 T(n) = O(n+kn+klogk) if the sorted k largest elements are returned.
	 T(n) = O(n+kn) if the returned k element is not sorted.
	 S(n) = O(n)
	 we can improve S(n) as O(1) if we don't use an arry to store the distance.
	 */
	vector<Point> kClosest(vector<Point> &points, Point &origin, int k) {
		//1. convert distance for each point 
		int n = points.size();
		vector<pair<double, int>> dist;
		for (int i = 0; i < n; ++i) {
			double d = getDistance(points[i]);
			dist.push_back(make_pair(d, i));
		}
		//2. k quick selection 
		int left = 0, right = n - 1;
		while (true) {
			int idx = kpartition(left, right, dist);
			if (idx == k - 1) break;
			else if (idx > k - 1) right = idx - 1;
			else left = idx + 1;
		}
		//2.1 sort first k elements
		sort(dist.begin(), dist.begin()+k);
		showDist(dist); 

		//3. return first k element 
		vector<Point> res;
		for (int i = 0; i < k; ++i) {
			int idx = dist[i].second;
			res.push_back(points[idx]);
		}
		return res;
	}
	/*
	worst case: the array is sorted!
	54321
	->
	12345
	pivot = 1(idx = 0)
	partition sequence: n-1, n-2, n-3 ... n-k
	We use random pivot to improve the worst case!
	*/
	int kpartition(int left, int right, vector<pair<double, int>>& dist) {
		/*
		12453
		G   p
		42153
		 G  p
		*/
		int rnd = rand() % (right - left + 1) + left;
		swap(dist[right], dist[rnd]);
		int pivot = right;
		int large = left;
		for (int i = left; i < right; ++i) {
			if (dist[i].first <= dist[pivot].first) {
				swap(dist[i], dist[large]);
				large++;
			}
		} 
		swap(dist[large], dist[pivot]);
		return large;
	}

	double getDistance(Point p) {
		return p.x * p.x + p.y * p.y;
	}
	
	void showDist(vector<pair<double, int>>& dist) {
		for (int i = 0; i < dist.size(); ++i) {
			cout << dist[i].first << endl;
		}
	}

	void show(vector<Point>&  arr) {
		for (int i = 0; i < arr.size(); ++i) {
			cout << arr[i].x << ";" << arr[i].y << endl;
		}
	}
};

class ConstSpaceSolution {
public:
	vector<Point> kClosest(vector<Point> &points, Point &origin, int k) {
		int n = points.size();
		int left = 0, right = n - 1;
		//1. k selection 
		while (true) {
			int idx = kpartition(left, right, points);
			if (idx == k - 1) break;
			else if (idx > k - 1) right = idx - 1;
			else left = idx + 1;
		}
		//1.1 sort first k element
		sort(points.begin(), points.begin() + k, pointComp);
		Solution s;
		cout << "points in class:" << endl;
		s.show(points);
		cout << "----------------" << endl;
		//2. report first k elements 
		vector<Point> res;
		for (int i = 0; i < k; ++i) {
			res.push_back(points[i]);
		}
		return res;
	}

	int kpartition(int left, int right, vector<Point>& points) {
		int rnd = rand() % (right - left + 1) + left;
		swap(points[rnd], points[right]);
		int pivot = right;
		int large = left;
		/*
		12453
		G   P
		52413
		 G  p
		*/
		for (int i = left; i < right; ++i) {
			if (pointComp(points[i], points[pivot])) {
				swap(points[i], points[large]);
				large++;
			}
		}
		swap(points[large], points[pivot]);
		return large;
	}
};


int main(int argc, char *argv[]) {
	vector<Point> points0;
	points0.push_back(Point (4,6));
	points0.push_back(Point (4,4));
	points0.push_back(Point (4,7));
	points0.push_back(Point (2,5));
	points0.push_back(Point (1,1));
	vector<Point> points;
	points = points0;
	/*
	1,1
	2,5
	4,4
	4,6
	4,7
	*/
	Point ori(0, 0);
	Solution s;
	int k = 3;
	vector<Point> res;
	cout << "sol1: with O(n) space" << endl;
	res = s.kClosest(points, ori, k);
	s.show(res);

	ConstSpaceSolution csts;
	vector<Point> points1;
	points1 = points0;
	vector<Point> res1;
	cout << "sol2: with O(1) space" << endl;
	res1 = csts.kClosest(points1, ori, 4);
	s.show(res1);
}