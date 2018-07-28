#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;


// manual simulation
/*
class Solution {
public:
	string convert(string s, int numRows) {
		if (numRows == 1)return s;
		vector<string> record(numRows);
		int step = 1, curRow = 0;
		for (int i = 0; i < s.length(); ++i) {
			record[curRow].push_back(s[i]);

			if (curRow == 0) step = 1;
			else if (curRow == numRows - 1)step = -1;
			curRow += step;
		}

		string res;
		for (auto s : record) {
			res += s;
		}
		return res;
	}
};
*/

class Solution {
public:
	string convert(string s, int numRows) {
		if (1 == numRows)return s;
		int step1, step2, pos = 0;
		string res;
		for (int i = 0; i < numRows;++i) {
			step1 = 2 * (numRows - i - 1);
			step2 = 2 * i;
			pos = i;
			if (pos < s.length()) {
				res += s[pos];
			}

			while (true) {
				pos += step1;
				if (pos >= s.length()) {
					break;
				}
				if (step1) {
					res += s[pos];
				}

				pos += step2;
				if (pos >= s.length()) {
					break;
				}
				if (step2) {
					res += s[pos];
				}
				
			}
		}
		return res;
	}
};

/* test case example format,you need to create a file names data.txt and use it save test case data
	2
	PAYPALISHIRING 3
	PAYPALISHIRING 4
	
	k
	s1 rown1
	s2 rown2
	...
	sk rownk
*/ 


int main() {
	freopen("data.txt", "r", stdin);
	Solution eg;
	int case_n, numRows;
	string str;
	cin >> case_n;
	while (case_n--) {
		cin >> str >> numRows;
		cout << eg.convert(str,numRows) <<endl;
	}
}