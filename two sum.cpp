#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

class Solution {
public:
	vector<int>twoSum(vector<int>&nums, int target) {
		vector<int>result;
		unordered_map<int, int>Hash;
		for (size_t i = 0; i < nums.size(); ++i) {
			int findNum = target - nums[i];
			unordered_map<int, int>::iterator it = Hash.find(findNum);
			if (it != Hash.end()) {
				result.push_back(it->second);//it->second is small than i,so insert it in result vector frist
				result.push_back(i);//current number index
				return result;
			}
			Hash[nums[i]] = i;
		}
		return result;
	}
};

/* test case example format
	4  7  0  1  2  9
	k n1 n2 ... nk target
 	frist number k means the nums vector element's number,then k integers follows,and the last number is the target
*/

//int main() {
//	freopen("data.txt", "r", stdin);
//	Solution eg;
//	vector<int>data; int numN, tmp, target;
//	cin >> numN;
//	for (int i = 0; i < numN; ++i) {
//		cin >> tmp;
//		data.push_back(tmp);
//	}
//	cin >> target;
//
//	vector<int>res = eg.twoSum(data, target);
//	if (res.size()) {
//		cout << res[0] << "	" << res[1];
//	}
//}