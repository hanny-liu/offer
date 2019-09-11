/*
 机器人的运动范围
 地上有一个m行n列的方格.一个机器人从坐标(0,0)的格子开始移动,
 它每次可以向左\右\上\下移动一格,但不能进入行坐标和列坐标的数位之和大于k的格子.
 例,当k为18时,机器人能够进入方格(35,37),因为3+5+3+7=18,但不能进入(35,38),因为
 3+5+3+8=19>18.
 请问该机器人能够到达多少个格子.
 */
int getDigitSum(int d)
{
    int sum(0);
    while(d>0)
    {
        sum+=d%10;
        d/=10;
    }
    return sum;
}

bool check(int threshold,int rows,int cols,int row,int col,bool *visited)
{
    if(row>=0 && row<rows && col>=0 && col<cols && getDigitSum(row)+getDigitSum(col)<=threshold && !visited[row*cols+col])
        return true;
}
int movingCountCore(int threshold,int rows,int cols,int row,int col,bool *visited)
{
    int count(0);
    if(check(threshold,rows,cols,row,col,visited))
    {
        visited[row*cols+col]= true;
        count=1+movingCountCore(threshold,rows,cols,row,col+1,visited)
               +movingCountCore(threshold,rows,cols,row+1,col,visited)
               +movingCountCore(threshold,rows,cols,row-1,col,visited)
               +movingCountCore(threshold,rows,cols,row,col-1,visited);
    }
    return count;
}
int movingCount(int threshold,int rows,int cols)
{
    if(threshold<0||rows<=0||cols<=0)
        return 0;
    bool *visited=new bool[rows*cols];
    for(int i=0;i<rows*cols;i++)
    {
        visited[i]= false;
    }
    int count=movingCountCore(threshold,rows,cols,0,0,visited);
    delete[] visited;
    return count;
}

#include <iostream>

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}