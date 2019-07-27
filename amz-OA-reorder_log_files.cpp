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

