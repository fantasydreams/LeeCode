#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;


struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
	ListNode * addTwoNumbers(ListNode* l1, ListNode* l2) {
		ListNode head(0);
		ListNode * calc = &head;
		int carry = 0;
		while (l1 || l2 || carry) {
			calc->next = new ListNode(0);
			calc = calc->next;
			calc->val = (l1 ? l1->val : 0) + (l2 ? l2->val : 0) + carry;
			carry = calc->val / 10;
			calc->val = calc->val % 10;
			l1 ? l1 = l1->next : nullptr;
			l2 ? l2 = l2->next : nullptr;
		}
		return head.next;
	}
};

/* test case example format,you need to create a file names data.txt and use it save test case data
	5 1 2 3 4 5
	6 1 2 3 4 5 6
	k n1 n2 ... nk
*/




ListNode * CreateList(vector<int> & vec) {
	ListNode Head(0);
	ListNode * workptr = &Head;
	for (int i = 0; i < vec.size(); ++i) {
		workptr->next = new ListNode(0);
		workptr = workptr->next;
		workptr->val = vec[i];
	}

	return Head.next;
}

void PrintList(ListNode * P) {
	while (P) {
		cout << P->val << "	";
		P = P->next;
	}
}


int main() {
	freopen("data.txt", "r", stdin);
	Solution eg;
	vector<int> num1, num2;
	int n1, n2, record;
	cin >> n1;
	while (n1--) {
		cin >> record;
		num1.push_back(record);
	}

	cin >> n2;
	while (n2--) {
		cin >> record;
		num2.push_back(record);
	}

	ListNode *P1, *P2;
	P1 = CreateList(num1);
	P2 = CreateList(num2);
	ListNode *res = eg.addTwoNumbers(P1, P2);
	PrintList(res);

}