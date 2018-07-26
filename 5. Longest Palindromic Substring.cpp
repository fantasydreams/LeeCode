#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

// frist solution : violence aesthetics , unfortunately, this algorithm can't pass the juedger.
/*
class Solution {
public:
	inline bool isPalindrome(string s) {
		string str = s;
		reverse(str.begin(), str.end());
		return s == str ? 1 : 0;
	}
	string longestPalindrome(string s) {
		string max_record = "";
		for (int i = 0; i < s.size(); ++i) {
			for (int j = i; j < s.size(); ++j) {
				if (j - i + 1 > max_record.size()) {
					string tmp = s.substr(i, j - i + 1);
					if (isPalindrome(tmp)) {
						max_record = tmp;
					}
				}

			}
		}
		return max_record;
	}
};
*/


/* the second solution, use dynamical programming
1. if the length of string equal 1,it must be Longest Palindromic Substring d[i][i] = 1
2. if two element is adjacent together, and they insame, it may be the Longest Palindromic Substring d[j][j+1] = 1
3. if the element is not neighbor ,we need to discuss there gerneral situations , suppose the index of this two elements is j and i seperately, and j < i
	1). if d[j+1][i-1] not equal 1,then the new substring index from j to i is not Palindromic
	2). if d[j+1][i-1] equal 1, and s[j] == s[i],the new substring index from j to i may be Longest Palindromic Substring d[j][i] = 1
	3). if d[j+1][i-1] equal 1, but s[i] != s[i],then the new substring index from j to i is not Palindromic
*/

/*
const int Size = 1001;
bool dp[Size][Size] = { 0 };
class Solution {
public:
	string longestPalindrome(string s) {
		memset(dp, 0, Size * Size);
		int maxLen = 0, left = 0, right = 0;
		for (int i = 0; i < s.size(); ++i) {
			dp[i][i] = 1;
			for (int j = 0; j < i; ++j) {
				dp[j][i] = (s[i] == s[j] && (i - j < 2 || dp[j + 1][i - 1]));
				if (dp[j][i] && i - j + 1 > maxLen) {
					maxLen = i - j + 1;
					left = j;
					right = i;
				}
			}
		}

		return s.substr(left, right - left + 1);
	}
};
*/


/* the third solution: for each element in string ,take it as center ,and scan center to both sides.
*/

/*
class Solution {
public:
	string longestPalindrome(string s) {
		int start = 0, len = 1;
		int left, right;
		for (int i = 0; i < s.size() - 1; ++i) {
			if (s[i] == s[i + 1]) {
				left = i; right = i + 1;
				searchForPalindrome(s, left, right, start, len);
			}
			left = right = i;
			searchForPalindrome(s, left, right, start, len);
		}

		return s.substr(start, len);
	}



	void searchForPalindrome(const string & s, int left, int right, int &start, int& len) {
		while (left >= 0 && right <= s.size() && s[left] == s[right]) {
			if ((left == 0 || right == s.size())) {
				if (right - left + 1 > len) {
					start = 0;
					len = right - left + 1;
				}
				return;
			}
			left--;
			right++;
		}

		if (right - left - 1 > len) {
			start = left + 1;
			len = right - left - 1;
		}
	}
};
*/


/* the fourth solution,use the famous algrithm:Manacher's algrithm
*/
class Solution {
public:
	string longestPalindrome(string s) {
		return Manacher(s);
	}

	string Manacher(const string &s) {
		string res = "&#";
		for (int i = 0; i < s.size(); ++i) {
			res += s[i];
			res += "#";
		}

		vector<int>P(res.size(), 0);
		int mid = 0, R = 0, max_idx = 0, max_len = 0;
		for (int i = 1; i < res.size() - 1; ++i) {
			P[i] = R - i > 0 ? (min(P[2 * mid - i], R - i)) : 1;

			while (res[i + P[i]] == res[i - P[i]]) {
				++P[i];
			}

			if (mid + P[i] > R) {
				R = mid + P[i];
				mid = i;
			}

			if (max_len < P[i]) {
				max_len = P[i];
				max_idx = i;
			}
		}

		return s.substr((max_idx - max_len) / 2, max_len - 1);
	}
};



/* test case example format,you need to create a file names data.txt and use it save test case data
	3
	abcabcbb
	bbbbb
	pwwkew


	k
	s1
	s2
	s3
*/ 


int main() {
	freopen("data.txt", "r", stdin);
	Solution eg;
	int k; cin >> k;
	while (k--) {
		string str; cin >> str;
		cout << eg.longestPalindrome(str) << endl;
	}
}