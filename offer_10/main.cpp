/*
 斐波那契数列
 求斐波那契数列的第n项
            0           n=0
 f(n)=      1           n=1
      f(n-1)+f(n-1)     n>1
 方法一:递归
 但递归的效率太低,会多次计算重复的值
 方法二:迭代(时间O(n))

 题目二:
 青蛙跳台阶问题
 一只青蛙一次可以跳上1级台阶,也可以跳上二级台阶,求该青蛙跳上一个n级台阶总共有多少种跳法.
 */
long long fibonacci(int n)
{
    long long n0(0),n1(1);
    long long num(0);
    if(n==0)
        return 0;
    if(n==1)
        return 1;
    for(int i=2;i<=n;i++)
    {
        num=n0+n1;
        n0=n1;
        n1=num;
    }
    return num;
}



#include <iostream>

int main() {

        std::cout << fibonacci(150) << std::ends;
    return 0;
}