/*
 正则表达式：是一种字符串匹配的模式。
// 题目：请实现一个函数用来匹配包含'.'和'*'的正则表达式。模式中的字符'.'
// 表示任意一个字符，而'*'表示它前面的字符可以出现任意次（含0次）。在本题
// 中，匹配是指字符串的所有字符匹配整个模式。例如，字符串"aaa"与模式"a.a"
// 和"ab*ac*a"匹配，但与"aa.a"及"ab*a"均不匹配。
 解题思路：
1.如果是'.'的话直接和字符串当前指针指向的内容是否为空比较，若不为空，则两个指针往下走，如果为空，返回false
2.如果是'*'的话，就有几种比较形式：
如果字符相等：
（1）当正则表达式指针的后一位是*时，指针直接往后挪两位，再与字符串比较；
（2）当正则表达式指针的后一位是*时，保持目前指向的位置不变，将字符串指针往后挪一位；
（3）当正则表达式指针的后一位是*时，字符串指针后移一位，然后正则表达式也后移两位，这样相当与出现一次匹配。
若不等：则正则表达式往后挪两位；
所以在比较*的时候可以在return 中返回两个函数调用的或运算。来表示是否能匹配。
此题用递归解题，较为容易

 */
#include <iostream>
using namespace std;
bool matchCore(char* str, char* pattern)
{
    //首先写出它们递归的结束标志
    //由于在*情况下有两种选择，必须把两种选择的结束条件都写上
    //if(*str!='\0'&&(*pattern)=='\0')//最后结果只看字符串是否结束
    //  return false;
    if(*str=='\0'&&*pattern=='\0')
        return true;
    if(*(pattern+1)=='*')//表示后一位是*，字符串还没走完
    {
        //需要比较正则表达式当前位的字符是否和字符串当前位的字符是否相等
        if(*pattern == *str || (*pattern == '.' && *str != '\0'))
        {
            return matchCore(str,pattern+2) || matchCore(str+1,pattern) || matchCore(str+1,pattern+2);//两种模式
        }
        else
        {
            return matchCore(str,pattern+2);
        }
    }
    if(*pattern == *str || (*pattern =='.' && *str != '\0'))
    {
        return matchCore(str+1,pattern+1);
    }
    return false;
}

bool match(char* str, char* pattern)
{
    if(str == nullptr && pattern ==nullptr)
        return false;
    else
        return matchCore(str,pattern);
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}