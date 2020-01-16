#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <sstream>    //istringsteam
//#include <utility>   //pair
#include <algorithm>    // std::sort
using namespace std;

string alpha_to_lowercase(const string &s) {
    string sout;
    for (int i = 0; i < s.size(); ++i) {
        if (!isalpha(s[i])) continue;
        sout += tolower(s[i]);
    }
    return sout;
}

vector<string> topNBuzzwords(int numToys, int topToys, vector<string> toys, int numQuotes, vector<string> quotes) {
    vector<string> res;
    unordered_map<string, int> hmap;
    for(int i = 0; i < numToys; ++i) {
        hmap[toys[i]] = 0; 
    }

    int bank = 10;
    while (bank < numQuotes) bank = bank * 10;

    for (auto words : quotes) {
        istringstream iss(words);
        unordered_set<string> hset;
        string word;
        while (iss >> word) {
            word = alpha_to_lowercase(word);
            if (hmap.find(word) != hmap.end()) {
                hmap[word] += 1 * bank;
                hset.insert(word);
            }
        } 
        for (auto it = hset.begin(); it != hset.end(); ++it) {
            string word = *it;
            hmap[word]++;
        }
    }
    vector<pair<string, int>> sorted_ans;
    for(auto it = hmap.begin(); it != hmap.end(); ++it) {
        string name = it->first;
        int cnt = it->second;
        pair<string, int> cell = {name, cnt};
        sorted_ans.push_back(cell);
    }
    auto myCmp = [](pair<string, int> a, pair<string, int> b) {
        if (a.second == b.second) return a.first < b.first;
        if (a.second > b.second) return true;
        return false;
    };
    sort(sorted_ans.begin(), sorted_ans.end(), myCmp);
    for (int i = 0; i < sorted_ans.size() && i < topToys; ++i) {
        res.push_back(sorted_ans[i].first);
        cout << sorted_ans[i].first << endl;
        cout << sorted_ans[i].second << endl;
    }
    return res;
}

void show_vec(vector<string> v) {
    for (int i = 0; i < v.size(); ++i) {
        cout << v[i] << endl;
    }
}

int main() {
    int numToys = 6;
    int topToys = 2;
    vector<string> toys = {"elmo", "elsa", "legos", "drone", "tablet", "warcraft"};
    int numQuotes = 6;
    vector<string> quotes = {"Elmo is the hottest of the season! Elmo will be on every kid's wishlist!",
"The new Elmo dolls are super high quality",
"Expect the Elsa dolls to be very popular this year, Elsa!",
"Elsa and Elmo are the toys I'll be buying for my kids, Elsa is good",
"For parents of older kids, look into buying them a drone",
"Warcraft is slowly rising in popularity ahead of the holiday season"
    };
    vector<string> res = topNBuzzwords(numToys, topToys, toys, numQuotes, quotes);  
    show_vec(res);
}
