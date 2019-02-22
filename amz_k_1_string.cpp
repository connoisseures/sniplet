#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

/**
 * Find substring with K-1 distinct characters (http://www.cnblogs.com/pegasus923/p/8444653.html)
 *
 * Given a string and number K, find the substrings of size K with K-1 distinct characters. If no, output empty list.
 * Remember to remove the duplicate substrings, i.e. if the substring repeated twice, only output once.
 */

vector<string> k_1_string(string s, int k) {    
    vector<string> res;
    if (s.empty() || k < 1) {
        return res;
    }
    int left = 0, right = 0;
    vector<int> dict(26, 0);
    int cnt_distinct = 0;
    unordered_set<string> str_set;
    while (left <= right && right < s.size()) {
        //sliding window 
        if (dict[s[right] - 'a'] == 0) {
            cnt_distinct++;
        }
        dict[s[right] - 'a']++;
        //narrow window 
        if (right - left + 1 == k) {
            if (cnt_distinct == k - 1) {
                string crt = s.substr(left, right - left + 1);
                if (str_set.count(crt) == 0) {
                    str_set.insert(crt);
                    res.push_back(crt);
                }
            }
            dict[s[left] - 'a']--;
            if (dict[s[left] - 'a'] == 0) {
                cnt_distinct--;
            }
            left++;
        }
        right++;
    }
    return res;
}

void show_vec(vector<string> res) {
    if (res.size() == 0) {
        cout << "- Empty -" << endl;
        return;
    }
    for (int i = 0; i < res.size(); ++i) {
        cout << res[i] << endl;
    }
}

int main(int argc, char *argv[]) {
    string s = "abcabc";
    vector<string> res = k_1_string(s, 4); show_vec(res);
    cout << "----" << endl; s = "awaglk";
    res = k_1_string(s, 4); show_vec(res);
    
    cout << "----" << endl; s = "baaacdef";
    res = k_1_string(s, 4); show_vec(res);
    
    cout << "----" << endl; s = "abccdef";
    res = k_1_string(s, 2); show_vec(res);
    
    cout << "----" << endl; s = "awaglknagawunagwkwagl";
    res = k_1_string(s, 4); show_vec(res);
    
    cout << "----" << endl; s = "";
    res = k_1_string(s, 1); show_vec(res);
    
    cout << "----" << endl; s = "aaaaaaa";
    res = k_1_string(s, 2); show_vec(res);
    
    cout << "----" << endl; s = "aaaaaaa";
    res = k_1_string(s, 1); show_vec(res);

    cout << "----" << endl; s = "aaaabbb";
    res = k_1_string(s, 3); show_vec(res);

}
