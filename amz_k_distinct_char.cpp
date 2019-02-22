#include <iostream>
#include <vector>
using namespace std;

void clean_vec(vector<int> &arr) {
    for (int i = 0; i < arr.size(); ++ i) {
        arr[i] = 0;
    }
}

int k_distinct_chars(string s, int k){
    vector<int> dict(26, 0);
    int cnt_distinct = 0;
    int total = 0;
    for (int i = 0; i < s.size(); ++i) {
        cnt_distinct = 0;
        for (int j = i; j < s.size(); ++j) {
            if (dict[s[j] - 'a'] == 0) {
                cnt_distinct++;
            }
            dict[s[j] - 'a']++;
            if (cnt_distinct == k) {
                total++;
            }
            if (cnt_distinct > k) {
                break;
            }
        }
        clean_vec(dict);
    }
    return total;
}


int main(int argc, char *argv[]) {
    string s = "pqpqs";
    cout << k_distinct_chars(s, 2) << endl;
    s = "abcabc";
    cout << k_distinct_chars(s, 3) << endl;
}
