
/*
solution 1: use stable sort
notice:
    1. use static for compare function with the class
Approach: 
We use the stable sort function in STL to reorder the input strings by overwriting the compare function used in the stable sort. The the stable sort will maintain the relative order of inputs with the equal values.  
For the compare function used in the stable sort, if both of the inputs of compare function are letter, we will compare their meta and if their meta are also the same, we will compare their identifier. If both are digit logs, their relative order are kept. For one is letter log and the other is digital log. The letter one comes before digital one. 

For the compare function, the time complexity is O(m), where m is the maximul length size of the input strings.

Time complexity:
For a comparing sorting, the time complexity is O(nlogn), where n is the number of inputs. If we consider the length of the input string. The total time complexity is O(m*nlogn), where m is the maximul length of the input string. 
Space complexity: We use a substr function in the compare function, so the space complexity is O(m).

ref:
sort strings: T = O(m*nlogn), where m is the length of the input string
https://stackoverflow.com/questions/9449447/string-sorting-using-merge-sort
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
solution 2: use sort
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


/*
solution 3: not use compare function 
*/
class Solution {
public:
    /*
    1. separate log_dig and log_letter
    2. modify log_letter by moving identifer into the end of the log. 
    3. sort modified log_letter
    4. merge log_letter and log_dig
    */
    vector<string> reorderLogFiles(vector<string>& logs) {
        vector<string> log_dig;
        vector<string> log_letter;
        for (int i = 0; i < logs.size(); ++i) {
            int idx = logs[i].find(' ');
            if (isdigit(logs[i][idx+1])) {
                log_dig.push_back(logs[i]);
            } else {
                string s;
                s = logs[i].substr(idx + 1) + '#' + logs[i].substr(0, idx); 
                log_letter.push_back(s);
            }
        }
        sort(log_letter.begin(), log_letter.end());
        vector<string> res;
        for (int i = 0; i < log_letter.size(); ++i) {
            int idx = log_letter[i].find('#');
            string s = log_letter[i].substr(idx + 1) + ' ' + log_letter[i].substr(0, idx);
            res.push_back(s);
        }
        for (int i = 0; i < log_dig.size(); ++i) {
            res.push_back(log_dig[i]);
        }
        return res;
    }
};

