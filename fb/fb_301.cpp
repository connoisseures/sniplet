#include <iostream>
#include <vector>
#include <stack>
using namespace std;
/*
remove Invalid Parentheses
*/

string singleRemove(string s, char p1, char p2) {
	string sout;
	int cnt = 0;
	for (int i = 0; i < s.size(); ++i) {
		if (s[i] == p1) cnt++;
		else if (s[i] == p2) cnt--;
		if (cnt > -1) {
			sout += s[i];
		} else {
			cnt++;
		}
	}
	return sout;
}

string twoPass(string input) {
	/*
	remove one side parantheses one time. 
		()))()(()
	1st   xx
	    ()()(()
	2nd     x   

	T(n) = O(n)
	S(n) = O(1)
	*/
	char p1 = '(', p2 = ')';
	string sout = singleRemove(input, p1, p2);
	reverse(sout.begin(), sout.end());
	sout = singleRemove(sout, p2, p1);
	reverse(sout.begin(), sout.end());
	return sout;
}


string onePass(string input) {
	/*
	    ()))()(()
	stk () pop
	stk ))() pop
	stk ))(() pop
	stk ))( ->remove
	*/
	/*
	T(n) = O(n)
	S(n) = O(n)
 	*/
	stack<int> stk;
	for (int i = 0; i < input.size(); ++i) {
		if (input[i] == '(') {
			stk.push(i);
		} else if (input[i] == ')') {
			//edge case stk is empty!
			if (!stk.empty() && input[stk.top()] == '(') stk.pop();
			else stk.push(i);
		}
	}
	string res = input;
	int pos = 0;
	while (!stk.empty()) {
		/*
		  012345
		i   | |
		ps|   
		stk = 2,4 idx is recorded frome back
		*/
		res.erase(stk.top(), 1);
		stk.pop();
	}
	return res;
}

int main(int argc, char *argv[]) {
	string s1 = "()))()(()";
	string s2 = "(a)v())((())";
	string s3 = "()a())()";
	string s4 = "())c)()(()";
	string s5 = "()s()(v(()(";

	cout << onePass(s1) << endl;
	cout << onePass(s2) << endl;
	cout << onePass(s3) << endl;
	cout << onePass(s4) << endl;
	cout << onePass(s5) << endl;
	cout << "two pass" << endl;
	cout << twoPass(s1) << endl;
	cout << twoPass(s2) << endl;
	cout << twoPass(s3) << endl;
	cout << twoPass(s4) << endl;
	cout << twoPass(s5) << endl;

}