/*
 字符串:替换空格
 请实现一个函数,把字符串中的每个空格替换成"%20".例如
 输入"we are happy.",则输出"we%20are%20happy."
 */
#include <iostream>
#include <string>
using namespace std;
void ReplaceBlank(string &s)
{
    if(s.empty())
    {
        cout<<"字符串为空"<<endl;
        return;
    }
    int num(0);
    for(int i=0;i<s.size();i++)
    {
        if(isblank(s[i]))
            num++;
    }
    if(num==0)
        return;
    int size=s.size();
    s.resize(size+2*num);
    auto p2=s.end()-1;
    auto p1=s.begin()+size-1;
    while(p1!=p2)
    {
        if(!isblank(*p1))
        {
            *p2=*p1;
            p1--;
            p2--;
        } else
        {
            *p2--='0';
            *p2--='2';
            *p2--='%';
            p1--;
        }
    }
}

int main() {
    string s;
    ReplaceBlank(s);
    cout<<s<<endl;
    return 0;
}
/*
 相关的题目:
 有两个排序的数组A1和A2.内存在A1的末尾有足够多的空间容纳A2.请实现一个函数,把A2的所有数字插入A1中,
 并且所有的数字是排序的.
 可以直接用上面的思路,从后往前遍历!
 */