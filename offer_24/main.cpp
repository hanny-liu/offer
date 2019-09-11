/*
 输入一个链表，反转链表后，输出新链表的表头。
 */
#include <iostream>

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}

struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
			val(x), next(NULL) {
	}
};
class Solution {
public:
    ListNode* ReverseList(ListNode* pHead) {
        if(pHead == nullptr)
            return nullptr;
        if(pHead->next == nullptr)
            return pHead;
        ListNode* pre=nullptr;
        ListNode* post=pHead->next;
        ListNode* p=pHead;
        while(post !=nullptr)
        {
            p->next = pre;
            pre = p;
            p = post;
            post = post ->next;
        }
        p->next = pre;
        pHead = p;
        return pHead;
    }
};