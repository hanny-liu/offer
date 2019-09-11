/* // 剑指offer中的面试题3:数组中重复的数字
// 在一个长度为n的数组里的所有数字都在0~n-1的范围内.
// 数组中某些数字是重复的,但不知道几个数字重复了,
// 也不知道每个数字重复了几次.请找出数组中任意一个重复的数字.
// 例如,输入长度为7的数组{2,3,1,0,2,5,3},那么对应的输出是重复的2或者3 */

/* 
方法一:(笨方法)
    把输入的数组排序,然后再遍历数组找出重复的数字.
方法二:(一般方法)
    利用哈希表,将数组中每一个数利用哈希函数保存在哈希表中,如果通过哈希函数计算的位置上存在数字,则说明此数字有重复.
    虽然时间复杂度是O(n),但是空间复杂度也是O(n),可以改进,把空间复杂度改为O(1);
方法三:先比较该数字m与当前数字所处的数组位置i是否相等(相当于哈希函数key=x),
      若不相等,则将m与数组位置m的数字进行比较,若第m个数字不等于m,则两个交换,重新开始比较,若相等,则找出重复的数字.
 */

/*
 测试用例:1.无重复的数组
         2.空数组
         3.包含一个或多个重复数字
 */
#include<iostream>
#include<vector>
using namespace std;
bool duplicate(vector<int> &v)
{
//    vector<int> v{6,4,1,0,2,5,3};
//    vector<int> v{};
    if(v.empty())
    {
        cout<<"数组为空!"<<endl;
        return 0;
    }
    auto i=v.begin();
    while(i!=v.end()) {
        if (*i == (i - v.begin())) {
            i++;
        } else {
            if (*i == v[*i]) {
                cout << *i << endl;
                break;
            } else {
                int tmp = v[*i];
                v[*i] = *i;
                *i = tmp;
            }
        }
    }
    if(i==v.end())
        cout<<"无重复的数字"<<endl;
    return 1;
}

/*
 进阶:不修改数组找出重复的数字
    在一个长度为n+1的数组里的所有数字都在1~n的范围内,所以数组中至少有一个数字是重复的.
    请找出数组中任意重复的数字,但不能修改输入的数组.例如,如果输入长度为8的数组{2,3,5,4,3,2,6,7},
    那么对应的输出是重复的数字2或3.
 */
/*
 方法一:(牺牲空间,空间复杂度为O(n))
    创建一个数组大小的新数组,逐一把原数组的数组按其大小赋值到对应大小的位置上,如果对应位置已有值,则该数字为重复数字
 方法二:(牺牲时间复杂度o(nlgn))
    循环二分遍历数组中的数字,若左右两部分中的数字数目大于左右两部分的数字差+1,则说明某个区间有重复值,不断循环遍历,找出重复的数字
    此方法无法找到所有重复的数字,如果某个区间是[1,2],但在这区间的两个数字都是2的话,就无法找到重复的2
 */
//需要写两个函数,一个是判断数字次数与范围,一个是计算某个范围下的数字数目
int computeCount(vector<int> &v,int start,int middle)
{
    int count(0);
    //记得判断数组是否为空
    if(v.empty())
    {
        cout<<"数组为空"<<endl;
        return 0;
    }
    for(auto i:v)
    {
        if(i<=middle&&i>=start)
            count++;
    }
    return count;
}
int dplicate(vector<int> &v)
{
    if(v.empty())
    {
        cout<<"数组为空!"<<endl;
        return -1;
    }
    int start(1),end(v.size()-1);
    while(start<=end)
    {
        int middle=((end-start)>>1)+start;
        int count=computeCount(v,start,middle);
        if(start==end)
        {
            if(count>1)
                return start;
            else
                break;
        }
        if(count>(middle-start+1))
            end=middle;
        else
        {
            start=middle+1;
        }
    }
    return -1;
}
int main()
{
//    vector<int> v{1,8,3,4,5,2,6,7};
    vector<int> v{};
    int i(0);
    i=dplicate(v);
    cout<<i<<endl;
}
