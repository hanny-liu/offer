/*
 18:删除链表节点
 给定单向链表的头指针和一个节点指针,定义一个函数在O(1)时间内删除该节点.
 解题思路:
 不用循环遍历到该节点的前一个节点然后再改变它的next指针,可以直接把目前指针指向需要删除的节点,
 用它后面的节点覆盖掉,同时后面节点的指针也赋值给当前节点,然后完成交换后再删掉next节点就ok.
 1.基本功能:删除链表中间节点,与思路一直
 2.边界条件:(1)如果删除尾置节点,只能通过遍历,到尾置前一个节点进行节点删除
           (2)如果链表中只有一个头节点,只需将头节点删除,并赋值为nullptr就行
           (3)如果链表中无节点,直接返回
 题目二:删除链表中重复的节点
 在一个排序的链表中,如何删除重复的节点.
 */
#include <iostream>
using namespace std;
struct ListNode
{
    int value;
    ListNode *next;
};
void DeleteNode(ListNode **pListNode,ListNode* pToBeDeleted)
{
    if(!pListNode&&!pToBeDeleted)
        return;
    if(pToBeDeleted->next!= nullptr)//不等于尾节点
    {
        ListNode *tmp=pToBeDeleted->next;
        pToBeDeleted->value=tmp->value;
        pToBeDeleted->next=tmp->next;
        delete tmp;
        tmp= nullptr;
        return;
    }
    if(*pListNode == pToBeDeleted)
    {
        *pListNode = nullptr;
        delete pToBeDeleted;
        pToBeDeleted = nullptr;
        return;
    }
    if(pToBeDeleted->next == nullptr)
    {
        ListNode *tmp = *pListNode;
        while(tmp->next != pToBeDeleted)
        {
            tmp = tmp->next;
        }
        tmp->next = nullptr;
        delete pToBeDeleted;
        return;
    }

}
int main() {
    ListNode *m = new ListNode;
    ListNode **pListNode = &m;
//    ListNode *p = new ListNode;
//    p->value = 9;
//    (*pListNode)->next=p;
//    ListNode *t = nullptr;
//    for(int i = 1; i < 11 ; ++i)
//    {
//        ListNode *tmp = new ListNode;
//        tmp->value = i;
//        p->next = tmp;
//        p = p->next;
//    }
//    p->next = nullptr;
//    ListNode *node = (*pListNode);
//    for(int i = 0 ;i < 11; i++)
//    {
//        node = node->next ;
//    }
    ListNode *tmp = *pListNode;
////    DeleteNode(pListNode,node);
    DeleteNode(pListNode, tmp);
    while(tmp != nullptr)
    {
        cout << tmp->value << ends;
        tmp = tmp->next ;
    }
    std::cout << "Hello, World!" << std::endl;
    return 0;
}