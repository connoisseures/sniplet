class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        int start = 0;
        int max_len = 1;
        for (int i = 0; i < n; ++i) {
            expending(s, i, i, start, max_len);
            expending(s, i, i + 1, start, max_len);
        }
        return s.substr(start, max_len);
    }
    void expending(string s, int i, int j, int &start, int &max_len) {
        while (i > -1 && j < s.size() && s[i] == s[j]) {
            i--;
            j++;
        }
        if (j - i - 1 > max_len) {
            max_len = j - i - 1;
            start = i + 1;
        }
    }
};
