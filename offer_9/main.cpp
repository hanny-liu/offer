/*
 用两个栈实现队列
 请实现队列的两个函数appendTail和deleteHead,分布完成在队列尾部插入节点,在队列头部删除节点的功能
 */

#include <iostream>
#include <stack>
using namespace std;
template <typename T>
class cqueue
{
    public:
        cqueue(void){}
        ~cqueue(void){}
        void appendTail(const T& node);
        T deleteHead();
    private:
        stack<T> stack1;
        stack<T> stack2;
};
template <typename T>
void cqueue<T>::appendTail(const T &node)
{
    stack1.push(node);
}
template <typename T>
T cqueue<T>::deleteHead()
{
    if(stack2.empty())
    {
        if(stack1.empty())
        {
            cout<<"队列为空"<<endl;
            return T();
        }
        while(!stack1.empty())
        {
            stack2.push(stack1.top());
            stack1.pop();
        }
    }
    auto i=stack2.top();
    stack2.pop();
    return i;
}
int main() {
    cqueue<int> que;
    for(int i=0;i<10;i++)
    {
        que.appendTail(i);
    }
    for(int i=0;i<10;i++)
    {
        cout<<que.deleteHead()<<ends;
    }
    return 0;
}