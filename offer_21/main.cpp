/*
 输入一个整数数组，实现一个函数来调整该数组中数字的顺序，使得所有的奇数位于数组的前半部分，
 所有的偶数位于数组的后半部分，并保证奇数和奇数，偶数和偶数之间的相对位置不变。
 */
#include <iostream>
#include <vector>
using namespace std;

//void reOrderArray(vector<int> &array) {
//    int i=0;
//    int j=array.size()-1;
//    if(array.empty())
//        return;
//    for(;i<j;++i)
//    {
//        if(array[i]%2==0)
//        {
//            if(array[j]%2==0)
//            {
//                j--;
//                i--;
//            }
//            else
//            {
//                swap(array[i],array[j]);
//                i++;
//                j--;
//            }
//        }
//    }
//}


void OrderArray(vector<int> & array,int begin,int end)
{
    if(begin == end)
        return;
    int mid=begin+(end-begin)/2;
    if(begin == mid)
    {
        if(array[begin]%2==0)
        {
            if(array[end]%2==0)
                return;
            else
            {
                swap(array[begin],array[end]);
            }
        }
        return;
    }
    //左边
    OrderArray(array,begin,mid);
    //右边
    OrderArray(array,mid+1,end);
    mid++;
    while((begin<=mid&&mid<=end))
    {
        if(array[begin]%2!=0)
        {
            begin++;
        } else
        {
            if(array[mid]%2!=0)//奇数
            {
                swap(array[begin],array[mid]);
                begin++;
                if(mid+1<=end)
                {
                    if(array[mid+1]%2!=0)
                        mid++;
                    else
                        return;
                }

            }
        }
        if(array[begin]%2==0&&array[mid]%2==0)
        {
            if(begin==mid)
                return;
            else
            {
                swap(array[begin],array[mid]);
                begin++;
            }
        }
    }

}
void rOrderArray(vector<int> &array) {
    if(array.empty())
        return;
    else
    {
        int begin=0;
        int end =array.size()-1;
        OrderArray(array,begin,end);
    }
}
int main() {
//    vector<int> array{1,2,3,4,5,6,7};
    vector<int> array{8,6,2,3,4,4,3,7};
    rOrderArray(array);
    for(auto i:array)
        cout<<i<<ends;
    return 0;
}