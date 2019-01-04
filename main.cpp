#include <iostream>

using namespace std;

 struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(nullptr) {}
 };

class Solution {
public:
	ListNode* reverseList(ListNode* head)
	{
		if (head == nullptr) return head;
		ListNode * prev;
		ListNode * curr;
		ListNode * next;
		next = head->next;
		head->next = nullptr;
		prev = head;
		curr = next;
		for (; curr != nullptr; curr = next)
		{
			//curr = next;
			next = curr->next;
			curr->next = prev;
			prev = curr;
		}
		return prev;
	}
};

int main()
{
	//Solution solution;
	ListNode * node = new ListNode(1);
	ListNode * temp = node;
	for (int i = 1; i < 5; ++i)
	{
		temp->next = new ListNode(i+1);
		temp = temp->next;
	}
	temp->next = nullptr;
	Solution solution;
	node = solution.reverseList(node);

	for (int i = 1; i < 6; ++i)
	{
		cout << node->val << "->";
		node = node->next;
	}
	cout << "NULL";
	cin.ignore();
	return 0;
}