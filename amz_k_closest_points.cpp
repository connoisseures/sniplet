class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
        priority_queue<vector<int>, vector<vector<int>>, myCompare> pq;
        for (int i = 0; i < points.size(); ++i) {
            pq.push(points[i]);
            if (pq.size() > K) {
                pq.pop();
            }
        }
        vector<vector<int>> res;
        while (!pq.empty()) {
            res.push_back(pq.top());
            pq.pop();
        }
        return res;
    }
    struct myCompare{
      bool operator()(const vector<int> &a, const vector<int> &b){
          return a[0] * a[0] + a[1] * a[1] < b[0] * b[0] + b[1] * b[1];
      }  
    };
};
