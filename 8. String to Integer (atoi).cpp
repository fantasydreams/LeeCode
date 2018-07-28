#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

/*
class Solution {
public:
	int myAtoi(string str) {
		long long res = 0;
		bool negFlag = false, posFlag = false;
		bool isValid = false;

		for (int i = 0; i < str.size(); ++i) {
			if (' ' == str[i]) {
				if (isValid || negFlag || posFlag) break;;
				continue;
			}
			if ('-' == str[i] || '+' == str[i]) {
				if (isValid || negFlag || posFlag) break;
				if ('-' == str[i]) negFlag = true;
				else posFlag = true;
				continue;
			}

			if (!(str[i] >= '0' && str[i] <= '9')) break;

			isValid = true;
			res = res * 10 + str[i] - '0';
			if (res > INT_MAX) {
				if (!negFlag)return INT_MAX;
				return INT_MIN;
			}
		}
		
		negFlag ? res = -res : 0;
		return res;
	}
};
*/ 


class Solution {
public:
	int myAtoi(string str) {
		int factor = 1;
		long long res = 0;
		int idx = str.find_first_not_of(' ');

		if ('-' == str[idx] || '+' == str[idx]) {
			factor = ('-' == str[idx++]) ? -1 : 1;
		}

		while ('0' <= str[idx] && str[idx] <= '9') {
			res = res * 10 + str[idx++] - '0';
			if (res > INT_MAX) {
				if (-1 == factor) return INT_MIN;
				return INT_MAX;
			}
		}

		return res * factor;
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
	int case_n; cin >> case_n;
	string str;

	cin.get();
	while (case_n--) {
		getline(cin,str);
		cout << eg.myAtoi(str) << endl;
	}
	//cout << eg.myAtoi("0-1");
}