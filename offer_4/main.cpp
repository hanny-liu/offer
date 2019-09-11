/*
 二维数组的查找
 在一个二维数组里,每一行都按照从左到右递增的顺序排序,每一列都按照从上到下递增的顺序排序
 请完成一个函数,输入这样的一个二维数组和一个整数,判断数组中是否含有该整数
 */
/*
 1 2 8 9
 2 4 9 12
 4 7 10 13
 6 8 11 15
 解题思路:
 从右上角的数字或左上角的数字进行比较
 */
#include <iostream>
#include <vector>
using namespace std;
//我的
//int main() {
//    int d(7);
//    vector<vector<int>> v{{1,2,8,9},{2,4,9,12},{4,7,10,13},{6,8,11,15}};
//    for(int i=0;i<v.size();i++)
//    {
//        for(int j=v.size()-1;j>=0;j--)
//        {
//            if(d==v[i][j])
//                return 1;
//            else if(d<v[i][j])
//            {
//                continue;
//            } else
//            {
//                while(i<v.size())
//                {
//
//                    if(d!=v[i][j])
//                        i++;
//                    else
//                    {
//                        cout<<d<<endl;
//                        return 1;
//                    }
//                }
//                return -1;
//            }
//        }
//    }
//    return 0;
//}
bool find(vector<vector<int>> & v,int rows,int cols,int number)
{
    bool found=false;
    if(!v.empty()&&rows>0&&cols>0)
    {
        int row(0);
        int col(cols-1);
        while(row<rows&&col>=0)
        {
            if(v[row][col]==number)
            {
                found= true;
                break;
            } else if(v[row][col]>number)
                col--;
            else
                row++;
        }
    }
    return found;
}
int main()
{
//    vector<vector<int>> v;
    vector<vector<int>> v{{1,2,8,9},{2,4,9,12},{4,7,10,13},{6,8,11,15}};
    auto i=find(v,4,4,4);
    cout<<i<<endl;
}