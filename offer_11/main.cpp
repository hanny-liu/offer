/*
 tips:
 如果面试题是要求在排序的数组(或者部分排序的数组)中查找一个数字或者统计某个数字出现的次数,那么我们都可以尝试用二分查找算法

 旋转数组的最小数字
 把一个数组最开始的若干个元素搬到数组末尾,称为数组的旋转.输入一个递增排序的数组的一个旋转,输出旋转数组的最小元素.
 例:数组{3,4,5,1,2}为{1,2,3,4,5}的一个旋转,该数组的最小值为1
 思路:分别在数组收尾定义两个指针,一般的首指针的值比尾指针的值大,然后再计算中间指针的值,若大于首指针,则属于左边范围,将首指针指向中间位置.
 若小于尾指针属于右边范围,尾指针指向中间位置.然后不断循环,直到首尾指针的差值为1时,尾指针指向的对象就是最小值
 */


#include <iostream>
#include <vector>
using namespace std;

int min_sort(vector<int>& s)
{
    int min=s[0];
    for(int i=1;i<s.size();i++)
    {
        if(min>s[i])
            min=s[i];
    }
    return min;
}

int mini(vector<int> &s)
{
    int begin=0;
    int end=s.size()-1;
    int middle=begin;
    if(s.empty())
    {
        cout<<"无效数组!"<<endl;
        return 0;
    }
    while(s[begin]>=s[end])
    {
        middle=(end-begin)/2+begin;
        if(end-begin==1)
        {
            middle=end;
            break;
        }
        if(s[middle]>=s[begin])
        {
            begin=middle;
        }
        if(s[middle]<=s[end])
        {
            end=middle;
        }
        if(s[begin]==s[middle]&&s[middle]==s[end])
        {
            return min_sort(s);
        }
    }
    return s[middle];
}

int main() {
//    vector<int> v{3,4,5,1,2};
//    vector<int> v{3,4,5,2,2,2};
//      vector<int> v{1,1,1,0,1,1,1};
    vector<int> v{};
    cout<<mini(v);
    return 0;
}