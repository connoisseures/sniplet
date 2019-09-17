
/*
solution 1: use stable sort
notice:
    1. use static for compare function with the class
*/
class Solution {
public:
    static bool myCompare (const string &a, const string &b) {
        int i = a.find(' ');
        int j = b.find(' ');
        if (!isdigit(a[i+1]) && !isdigit(b[j+1])) {
            if (a.substr(i+1) == b.substr(j+1)) {
                return a.substr(0, i) < b.substr(0, j);
            } else {
                return a.substr(i+1) < b.substr(j+1);
            }
        }
        if (!isdigit(a[i+1])) return true;
        return false;
    }
    vector<string> reorderLogFiles(vector<string>& logs) {
        stable_sort(logs.begin(), logs.end(), myCompare);
        return logs;
    }
};


/*
solution 1: use sort
notice:
    1. use static for compare function with the class
*/
class Solution {
public:
    static bool myCompare(const string &a, const string &b) {
        int i = a.find(' ');
        int j = b.find(' ');
        if (a.substr(i+1) == b.substr(j+1)) {
            return a.substr(0, i) < b.substr(0, j);
        }
        return a.substr(i+1) < b.substr(j+1);
    }
    vector<string> reorderLogFiles(vector<string>& logs) {
        vector<string> dig_log;
        vector<string> letter_log;
        for (auto log : logs) {
            int idx = log.find(' ');
            if (isdigit(log[idx+1])) dig_log.push_back(log);
            else letter_log.push_back(log);
        }
        sort(letter_log.begin(), letter_log.end(), myCompare);
        letter_log.insert(letter_log.end(), dig_log.begin(), dig_log.end());
        return letter_log;
    }
};

