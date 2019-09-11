/**
 17:打印从1到最大的n位数
 输入数字n,按顺序打印出1到最大的n位十进制数.
 比如输入3,则打印1,2,3一直到达最大的3位数999.

 思考:
 (1)功能实现:打印从1到10^n-1的数
 (2)边界测试:
  a.n=0时,不打印
  //TODO:b.考虑溢出10^10次方已经>2^32已经溢出,需要考虑溢出问题,
  //TODO:因此,不可能打印数字,只能打印字符串!!!所以功能实现需要打印字符串而不是数字了
 (3)负面测试:
 若输入错误数字,则返回输入错误信息

 解题思路:
 用递归判断是否到达最大值
 还需考虑用户阅读习惯,把最左边为0的去掉然后打印
 */


#include <iostream>
#include <cstring>
using namespace std;

void printnumber(char *number)
{
    bool isbegin=true;
    int nlength=strlen(number);
    for(int i=0;i<nlength;++i)
    {
        if(isbegin && number[i] !='\0')
        {
            isbegin= false;
        }
        if(!isbegin)
        {
            cout<<number[i];
        }
    }
}

void printtomaxofdigitsrecursively(char *number,int length,int index)
{
    if(index==length-1)
    {
        printnumber(number);
        return;
    }
    for(int i=0;i<10;i++)
    {
        number[index+1]=i+'0';
        printtomaxofdigitsrecursively(number,length,index+1);
    }
}

void printNdigitnumber(int n)
{
    if(n<=0)
        return;
    char * number=new char[n+1];
    number[n]='\0';
    for(int i=0;i<10;i++)
    {
        number[0]=i+'\0';
        printtomaxofdigitsrecursively(number,n,0);
    }
    delete[] number;
}


int main() {
    printNdigitnumber(2);
    return 0;
}