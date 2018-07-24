#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
	double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
		int num_n = nums1.size() + nums2.size();
		int mid_n = num_n / 2 + 1;
		int i = 0, j = 0,idx = 0;
		vector<int> num(mid_n, 0), remain;
		while (i < nums1.size() && j < nums2.size() && idx < mid_n) {
			nums1[i] < nums2[j] ? (num[idx++] = nums1[i++]) : (num[idx++] = nums2[j++]);
		}
		if (idx < mid_n) {
			i < nums1.size() ? remain = nums1 : remain = nums2;
			int tmp = i < nums1.size() ? i: j;
			while (idx < mid_n) {
				num[idx++] = remain[tmp++];
			}
		}

		if (num_n % 2) {
			return num[mid_n - 1];
		}
		else {
			return ((double)num[mid_n - 2] + num[mid_n - 1]) / 2;
		}

	}
};



/* test case example format,you need to create a file names data.txt and use it save test case data
k1 n1 n2 ... nk1
k2 m1 m2 ... mk2
*/

int main(int argc, char ** argv)
{
	freopen("data.txt", "r", stdin);
	vector<int> nums1, nums2;
	int k1, k2, tmp; Solution eg;

	cin >> k1;
	while (k1--) {
		cin >> tmp;
		nums1.push_back(tmp);
	}

	cin >> k2;
	while (k2--) {
		cin >> tmp;
		nums2.push_back(tmp);
	}

	cout << eg.findMedianSortedArrays(nums1, nums2);
	return 0;
}