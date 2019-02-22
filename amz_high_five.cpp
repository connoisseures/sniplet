#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
using namespace std;

struct record{
    int id;
    double val;
    record(int i, double t) : id(i), val(t) {}
};

vector<record> high_five(int k, int count, vector<record> lst) {
    unordered_map<int, priority_queue<double, vector<double>, greater<double>>> dict;
    for (int i = 0; i < count; ++i) {
        dict[lst[i].id].push(lst[i].val);
        if (dict[lst[i].id].size() > k) {
            dict[lst[i].id].pop();
        }
    }
    vector<record> res;
    for (auto it = dict.begin(); it != dict.end(); ++it) {
        int id = it->first;
        int sum = 0;
        double avg = 0;
        while(!dict[id].empty()){
            sum += dict[id].top();
            dict[id].pop();
        }
        //cout << id << ";" << sum << endl;
        avg = sum / k;
        res.push_back(record(id, avg));
    }
    return res;
}

int main(int argc, char *argv[]) {
    vector<record> lst;
    /*
    1: 10,20,30,40,50,60,70
    2: 1,2,3,4,5,6,7,8
    3: 100,200,300,400,500,600
    ans=
    1: avg = 50
    2: avg = 6
    3: avg = 400
    */
    lst.push_back(record(2, 2.0));
    lst.push_back(record(1, 20.0));
    lst.push_back(record(3, 200.0));
    lst.push_back(record(1, 30.0));
    lst.push_back(record(2, 1.0));
    lst.push_back(record(1, 10.0));
    lst.push_back(record(3, 100.0));
    lst.push_back(record(1, 40.0));
    lst.push_back(record(3, 300.0));
    lst.push_back(record(3, 400.0));
    lst.push_back(record(1, 50.0));
    lst.push_back(record(2, 3.0));
    lst.push_back(record(1, 60.0));
    lst.push_back(record(3, 500.0));
    lst.push_back(record(1, 70.0));
    lst.push_back(record(3, 600.0));
    lst.push_back(record(2, 4.0));
    lst.push_back(record(2, 6.0));
    lst.push_back(record(2, 5.0));
    lst.push_back(record(2, 7.0));
    lst.push_back(record(2, 8.0));
    vector<record> res = high_five(5, 21, lst);
    for (int i = 0; i < res.size(); ++i) {
        cout << res[i].id << "; " << res[i].val << endl;
    }
}
