#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;


class Solution {
public:
	int reverse(int x) {
		long long res = 0;
		while (x) {
			res = res * 10 + x % 10;
			if (res > (signed int)INT_MAX || res < (signed int)INT_MIN) {
				return 0;
			}
			x /= 10;
		}
		return (int)res;
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
	int case_n,tmp; cin >> case_n;
	while (case_n--) {
		cin >> tmp;
		cout << eg.reverse(tmp) << endl;
	}	
}