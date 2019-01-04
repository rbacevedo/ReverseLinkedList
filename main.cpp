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
		if (head == NULL) return NULL;
		else if (head->next == NULL) return head;
		ListNode * curr = NULL;
		ListNode * next;
		while (head) // While head is not a nullptr
		{
			next = head->next;  // Need to save the rest
			head->next = curr; //Making head->next point to current
			curr = head; // want to remember the previous one to assign it to the next one
			head = next; //For loop iteration
		}
		return curr;
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