/*
 回溯法
 矩阵中的路径:请设计一个函数,用来判断在一个矩阵中是否存在一条包含某字符串所有字符的路径.路径可以从矩阵中的任意一格开始,
 每一步可以在矩阵中向左\向右\向上\向下移动一格.如果一条路径经过了矩阵的某个格,那么该路径不能再次进入该格子.
 例:在下面3x4的矩阵中包含一条字符串"bfce"的路径.但矩阵中不包含字符串"abfb",因为字符串的第一个字符b占据了矩阵中的第一行第二个
 格子之后,路径不能再次进入这个格子.
 扩展:和迷宫找出口类似
 方法一:(消耗空间复杂度)
 递归
 方法二:用栈实现递归,为了不重复访问同一个字符,还需要额外申请一个大小相同的矩阵,来判断该位置是否之前被访问过.
 */

#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

bool haspathcore(char *matrix,int rows,int cols,int row,int col,const char *str,int &pathlength,bool *visited)
{
    if(str[pathlength]=='\0')
    {
        return true;
    }
    bool haspath= false;
    if(row>=0&&row<rows&&col>=0&&col<cols&&matrix[row*cols+col]==str[pathlength]&&!visited[row*cols+col])
    {
        ++pathlength;
        visited[row*cols+col]= true;
        haspath=haspathcore(matrix,rows,cols,row,col-1,str,pathlength,visited)
                ||haspathcore(matrix,rows,cols,row-1,col,str,pathlength,visited)
                ||haspathcore(matrix,rows,cols,row,col+1,str,pathlength,visited)
                ||haspathcore(matrix,rows,cols,row+1,col,str,pathlength,visited);
        if(!haspath)
        {
            --pathlength;
            visited[row*cols+col]= false;
        }
    }
    return haspath;
}

bool haspath(char *matrix,int rows,int cols,char *str)
{
    if(matrix== nullptr||cols<1||rows<1||str== nullptr)
    {
        return false;
    }
    bool visit[rows*cols];
    bool *visited=visit;
    int pathlength(0);
    for(int i=0;i<rows*cols;i++)
    {
        visit[i]=0;
    }
    for(int row=0;row<rows;row++)
    {
        for(int col=0;col<cols;col++)
        {
            if(haspathcore(matrix,rows,cols,row,col,str,pathlength,visited))
            {
                return true;
            }
        }
    }
    return false;
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}