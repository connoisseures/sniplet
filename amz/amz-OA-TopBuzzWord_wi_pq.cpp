#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <sstream>    //istringsteam
//#include <utility>   //pair
#include <queue>      // std::priority_queue
#include <algorithm>  // std::reverse
using namespace std;

/*
Thought:
The quotes are read word by word. The frequency of each toy is recorded by a hash table. 
The format of the value in the hash value is as follows. 
A bank is used to record the occurrence of each toy in the quotes. 
The frequency of each toy in the quotes is recorded in the number system with the bank size as the base number. 
Ex: elmo occurs 4 times in the quotes and appeared in 3 different quotes. The elmo's value in the hash table is 4*10+3 = 43, where bank size = 10.

We can put each cell of the hash table into a priority queue (min-heap) with size = topToy. Then, we draw the top element of the priority queue one by one and put them into a list. The reverse of the list is the answer.

Time complexity analysis is as follows. 
L : the average lenght of each quote.
m : the number of the quotes.
n : the number of toys
k : the number of topToys
T(m*L + nlogk + k) = T(m*L)
*/

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
    if (topToys == 0 || numToys == 0 || numQuotes == 0) return res;
    unordered_map<string, int> hmap;
    //initialize hash table 
    for(int i = 0; i < numToys; ++i) {
        hmap[toys[i]] = 0; 
    }

    //calculate bank size
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
    
    auto myCmp = [](pair<string, int> a, pair<string, int> b) {
        if (a.second == b.second) return a.first < b.first;
        if (a.second > b.second) return true;
        return false;
    };
    priority_queue<pair<string, int>, vector<pair<string, int>>, decltype(myCmp)> pq(myCmp);
    for(auto it = hmap.begin(); it != hmap.end(); ++it) {
        string name = it->first;
        int cnt = it->second;
        //cout << name << ";" << cnt << endl;
        pair<string, int> cell = {name, cnt};
        pq.push(cell);
        if (pq.size() > topToys) pq.pop();
    }

    while(!pq.empty()) {
        //cout << pq.top().first << endl;
        //cout << pq.top().second << endl;
        if (pq.top().second > 0) { 
            res.push_back(pq.top().first);
        }
        pq.pop();
    }
    reverse(res.begin(), res.end());
    return res;
}

void show_vec(vector<string> v) {
    for (int i = 0; i < v.size(); ++i) {
        cout << v[i] << endl;
    }
    cout << endl;
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
    cout << "case1" << endl;
    vector<string> res = topNBuzzwords(numToys, topToys, toys, numQuotes, quotes);  
    show_vec(res);
    cout << "case2, topToys > numToys" << endl;
    topToys = 10;
    vector<string> res2 = topNBuzzwords(numToys, topToys, toys, numQuotes, quotes);  
    show_vec(res2);

    vector<string> quotes3 = {"Elmo is the hottest of the season! Elmo will be on every kid's wishlist!",
"The new Elmo dolls are super high quality",
"Expect the Elsa dolls to be very popular this year, Elsa!",
"Elsa and Elmo are the toys I'll be buying for my kids, it is good",
"For parents of older kids, Elsa look into buying them a drone",
"Warcraft is slowly rising in popularity ahead of the holiday season"
    };
    cout << "case3, elmo == elsa" << endl;
    topToys = 2;
    vector<string> res3 = topNBuzzwords(numToys, topToys, toys, numQuotes, quotes3);  
    show_vec(res3);
    
    cout << "case4, topToy = 1" << endl;
    topToys = 1;
    vector<string> res4 = topNBuzzwords(numToys, topToys, toys, numQuotes, quotes3);  
    show_vec(res4);

    cout << "case5, topToy = 0" << endl;
    topToys = 0;
    vector<string> res5 = topNBuzzwords(numToys, topToys, toys, numQuotes, quotes3);  
    show_vec(res5);
}
