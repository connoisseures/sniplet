#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

/*
Thought:
If a word is the prefix of aother word, they must be the neighbors in the sorted order. 
First, we sort the products. 
We can use binary search to find the first word which has the prefix matching the part of the searchWord. 
Then, we check if the next two words have the same prefiex or not.

Time complexity is bounded by O(C*logN)
T : O(C*logN), where C = total length of list of string = L*N
T : O(M*logN), where N = the size of the product strings, M = length of searchWord
*/
class Solution_binary_search {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        sort(products.begin(), products.end());
        vector<vector<string>> res;
        int idx = 0;
        string crt = "";
        for (auto c : searchWord) {
            crt += c;
            vector<string> suggestion;
            idx = binary_search(idx, products, crt);
            for (int i = idx; i < products.size() && i < idx + 3; ++i) {
                if (crt != products[i].substr(0, crt.size())) break;
                suggestion.push_back(products[i]);
            }
            res.push_back(suggestion);
        }
        return res;
    }
    int binary_search(int left, vector<string> &arr, string &target) {
        int right = arr.size();
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (arr[mid] < target) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        return left;
    }
};

/*
Time complexity is bounded by O(C*logN)
T : O(C*logN), where C = total length of list of string = L*N
T : O(M*N), where N = the size of the product strings, M = length of searchWord
*/

class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        // L*NlogN
        sort(products.begin(), products.end());
        vector<vector<string>> res;
        string crt = "";
        int idx = 0;
        // O(nm)
        for(auto c : searchWord) {
            crt += c;
            vector<string> suggestion;
            while(idx < products.size() && products[idx].substr(0, crt.size()) != crt) {
                idx++;
            }
            for(int i = idx; i < idx + 3 && i < products.size(); ++i) {
                if (crt != products[i].substr(0, crt.size())) break; 
                suggestion.push_back(products[i]);
            }
            res.push_back(suggestion);
        }
        return res;
    }
};

void show_vecs(vector<vector<string>>& v) {
    for (int i = 0; i < v.size(); ++i) {
        for (int j = 0; j < v[i].size(); ++j) {
            cout << v[i][j] << ",";
        }
        cout << endl;
    }
}

int main() {
    Solution sol;
    vector<string> products = {"mobile","mouse","moneypot","monitor","mousepad"};
    string searchWord = "mouse";
    vector<vector<string>> res = sol.suggestedProducts(products, searchWord);
    cout << "method1" << endl;
    show_vecs(res);

    cout << "method2" << endl;
    Solution_binary_search sol2;
    vector<vector<string>> res2 = sol2.suggestedProducts(products, searchWord);
    show_vecs(res);
}
