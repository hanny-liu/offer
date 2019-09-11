//给出一个仅包含加减乘除四种运算符的算式(不含括号)，如1+2*3/4，
// 在保持运算符顺序不变的情况下，现在你可以进行若干次如下操作：
// 如果交换相邻的两个数，表达式值不变，那么你就可以交换这两个数。
//
//现在你可以进行任意次操作，
// 使得算式的数字序列字典序最小，然后输出结果，
//数字之间的字典序定义为若a<b则a的字典序小于b。
//第一行包含一个整数n，表示算式的长度，即包含n个数字和n-1个运算符。(1≤n≤100000)。
//
//第二行包含一个含有n个非0整数和n-1个运算符的算式，整数与运算符用空格隔开，
// 运算符包括“+，-，*，/”，整数的绝对值不超过1000。
//按要求输出字典序最小的表达式，数字与符号之间用空格隔开。
#include <iostream>
#include <string>
#include <vector>
using namespace std;
int main() {
    string str;
    int n;
    string line;
    getline(cin,line);
    n=stoi(line);
    getline(cin,line);
    str=line;
    string t1;
    vector<int> t2;
    for(int i= 0; i< str.size()-1 ; i++)
    {
        if(str[i] == '+' ||str[i] == '-' ||str[i] == '*' ||str[i] == '/' )
        {
            t1.push_back(str[i]);
            if(str[i+1] == '+' ||str[i+1] == '-' ||str[i+1] == '*' ||str[i+1] == '/')
            {
                string tmp;
                tmp.push_back(str[i+1]);
                tmp.push_back(str[i+2]);
                t2.push_back(stoi(tmp));
                i+=2;
            }

        }
        else
        {
            string tmp;
            tmp.push_back(str[i]);
            t2.push_back(stoi(tmp));
        }
    }
    for(int i=0;i<t1.size()-1;i++)
    {
        if(t1.size()==1)
        {
            if(t2[0]<=t2[1])
                cout << str <<endl;
            else
            {
                cout << t2[1] <<t1[0]<<t2[0] <<endl;
            }

        } else
        {
            if(t1[i]==t1[i+1])
            {
                if(t2[i]>t2[i+1])
                {
                    swap(t2[i],t2[i+1]);
                }
            } else
            {
                if(t2[i+1]>t2[i+2])
                {
                    swap(t2[i],t2[i+1]);
                }
            }
        }

    }
    for(int i=0;i<n;i++)
    {
        if(i<n-1)
        {
            cout<< t2[i] <<t1[i];
        }
        else
            cout <<t2[i];
    }
    return 0;
}