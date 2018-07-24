#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
	int lengthOfLongestSubstring(string s) {
		int start = -1, chLoc[256],Max_len = 0;
		memset(chLoc, -1, sizeof(int) * 256);
		for (int i = 0; i < s.length(); ++i) {
			if (chLoc[s[i]] > start) {
				start = chLoc[s[i]];
			}
			chLoc[s[i]] = i;
			Max_len = max(Max_len, i - start);
		}

		return Max_len;
	}
};


/* test case example format,you need to create a file names data.txt and use it save test case data
k
str1
str2
...
strk

eg.
4
abcabcbb
bbbbb
pwwkew
a
*/

int main(int argc, char ** argv)
{
	freopen("data.txt", "r", stdin);
	int case_n; cin >> case_n;
	string str; Solution eg;
	while (case_n--) {
		cin >> str;
		cout << eg.lengthOfLongestSubstring(str);
	}
	return 0;
}