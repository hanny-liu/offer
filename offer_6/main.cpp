/*
 从尾到头打印链表
 思路:利用栈的先入后出的性质
 */

#include <iostream>
#include <forward_list>
#include <stack>
using namespace std;
void reverseList(forward_list<int> &l)
{
    if(l.empty())
        return;
    stack<int> z;
    auto i=l.begin();
    while(i!=l.end())
    {
        z.push(*i);
        i++;
    }
    while(!z.empty())
    {
        cout<<z.top()<<ends;
        z.pop();
    }
}

int main() {
//    forward_list<int> l{1,2,3,4,5,6,7};
    forward_list<int> l{1};
    reverseList(l);
    return 0;
}