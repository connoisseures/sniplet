class Solution {
public:
    string mostCommonWord(string paragraph, vector<string>& banned) {
        unordered_map<string, int> hdict; 
        for (int i = 0; i < banned.size(); ++i) {
            hdict[banned[i]] = -1;
        }
        int i = 0;
        int max_val = 0;
        string res;
        while (i < paragraph.size()) {
            string word = getLowercaseWord(paragraph, i); //i will be udated here!
            if (hdict[word] != -1) {
                hdict[word]++;
                if (hdict[word] > max_val) {
                    max_val = hdict[word];
                    res = word;
                }
            }
        }
        return res;
    }
    
    string getLowercaseWord(string s, int &i) {
        /*
        return word seperated by delimiter and index i at the start of next word if i < s.size.  
        */
        string word = "";
        while (i < s.size() && isalpha(s[i])) {
            word.push_back(tolower(s[i]));
            i++;
        }
        while (i < s.size() && !isalpha(s[i])) {
            i++;
        }
        return word;
    }
};

