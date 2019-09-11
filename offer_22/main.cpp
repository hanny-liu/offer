

/*
 * 输入一个链表，输出该链表中倒数第k个结点。
1.考虑边界：如果传入一个空链表，或只含一个节点的链表
2.考虑链表长度没有k的时候，需要返回nullptr;
3.考虑k=0的情况
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
    ListNode* FindKthToTail(ListNode* pListHead, unsigned int k) 
    {
        if(pListHead==nullptr)
            return nullptr;
        if(pListHead->next==nullptr)
            return pListHead;
        if(k==0)
            return nullptr;
        //先遍历一遍
        ListNode* p=pListHead;
        int i=0;
        while(p != nullptr)
        {
            i++;
            p=p->next;
        }
        if(i<k)
            return nullptr;
        ListNode* post=pListHead;
        i=0;
        while(i<k-1)
        {
            post=post->next;
            i++;
        }
        ListNode* pre=pListHead;
        while(post->next !=nullptr)
        {
            post=post->next;
            pre=pre->next;
        }
        return pre;
    }
};