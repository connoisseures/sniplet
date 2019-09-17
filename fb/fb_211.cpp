#include <iostream>
#include <vector>
using namespace std;

class WordDictionary {
	struct TrieNode {
		bool isEnd;
		vector<TrieNode*> children;
		TrieNode():isEnd(false), children(vector<TrieNode*> (26, NULL)) {}
		~TrieNode() {
			for (int i = 0; i < 26; ++i)
				delete children[i];
		}
	};
	TrieNode* root;
public:
	/** Initialize your data structure here. */
	WordDictionary() {
		root = new TrieNode();
	}
	
	/** Adds a word into the data structure. */
	void addWord(string word) {
		TrieNode* crt = root;
		for (int i = 0; i < word.size(); ++i) {
			if (!crt->children[word[i] - 'a']) 
				crt->children[word[i] - 'a'] = new TrieNode();
			crt = crt->children[word[i] - 'a'];
		}
		crt->isEnd = true;
	}
	
	/** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
	bool search(string word) {
		vector<string> res;
		string matched;
		helper(root, word, 0, res, matched);
		return res;
	}
	
	void helper(TrieNode* root, string& word, int idx, vector<string>& res, string matched) {
		if (!root) return;
		if (idx == word.size() && root->isEnd) {
			res.push_back(matched);
			return;
		}
		if (word[idx] == '*') {
			for (int i = 0; i < 26; ++i) {
				matched += 'a' + j;
				helper(root->children[j], word, idx + 1, res, matched);
				helper(root->children[j], word, idx, res, matched);
				matched.pop_back();
			}
		} else {
			matched += word[idx];
			helper(root->children[word[idx]-'a'], word, idx + 1, res, matched);
			matched.pop_back();
		}
	}
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary obj = new WordDictionary();
 * obj.addWord(word);
 * bool param_2 = obj.search(word);
 */



int main(int argc, char *argv[]) {
	
}