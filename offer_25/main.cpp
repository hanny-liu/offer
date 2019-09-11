/*
输入两个单调递增的链表，输出两个链表合成后的链表，当然我们需要合成后的链表满足单调不减规则。
利用分治递归的思想。需要判断不满足条件的情况。
*/
#include <iostream>
using namespace std;
struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
			val(x), next(NULL) {
	}
};
class Solution {
public:
    ListNode* Merge(ListNode* pHead1, ListNode* pHead2)
    {
        if(pHead1 == nullptr )
            return pHead2 ;
        if(pHead2 ==nullptr)
            return pHead1 ;
        ListNode* p = nullptr;
        if(pHead2 -> val > pHead1 ->val)
        {
            p=pHead1;
            p->next =Merge(pHead1->next , pHead2);
        }
        else
        {
            p=pHead2;
            p->next =Merge(pHead1 , pHead2->next);
        }
        return p;
    }
};