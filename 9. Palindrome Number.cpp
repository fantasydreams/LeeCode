#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;


/*
class Solution {
public:
	bool isPalindrome(int x) {
		string str = to_string(x);
		string Reverse = str;
		reverse(Reverse.begin(), Reverse.end());
		return str == Reverse;
	}
};
*/


/*
class Solution {
public:
	bool isPalindrome(int x) {
		if (x < 0) return false;

		int tmp = x, Reverse = 0;
		while (tmp >= 10) {
			Reverse = 10 * Reverse + tmp % 10;
			tmp /= 10;
		}

		return (x / 10 == Reverse && x % 10 == tmp);
	}
};
*/

/*
class Solution {
public:
	bool isPalindrome(int x) {
		if (x < 0 || (x && x%10 == 0)) return false;

		int Rev = 0, tmp = x;
		while (tmp > Rev) {
			Rev = 10 * Rev + tmp % 10;
			tmp /= 10;
		}
		return (Rev == tmp || Rev / 10 == tmp);
	}
};
*/

class Solution {
public:
	bool isPalindrome(int x) {
		string str = to_string(x);
		int len = str.size();
		int half = len / 2;
		for (int i = 0; i <= half; ++i) {
			if (str[i] != str[len - i - 1]) {
				return false;
			}
		}

		return true;
	}
};

/* test case example format,you need to create a file names data.txt and use it save test case data
	k
	n1
	n2
	...
	nk
*/ 


int main() {
	freopen("data.txt", "r", stdin);
	Solution eg;
	int case_n,num; cin >> case_n;

	while (case_n--) {
		cin >> num;
		cout << eg.isPalindrome(num);
	}
	//cout << eg.myAtoi("0-1");
}