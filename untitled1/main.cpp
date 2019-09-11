#include <iostream>
#include <vector>
#include <sstream>
using namespace std;

int main() {
    int n(0),m(0);
    vector<vector<int>> c;
    cin>>n>>m;
    int n1(0),t(0);
    string m1;
    vector<int> tmp;
    tmp.resize(m);
    c.resize(n);
    int max(0);
    while(getline(cin,m1))
    {
        if(n1==n-1)
            break;
        istringstream is(m1);
        string m2;
        while(is>>m2)
        {
            c[n1][t]=stoi(m2);
            if(max<c[n1][t])
                max=c[n1][t];
            t++;
        }
        n1++;
    }
    vector<vector<vector<int>>> s1,s2;
    for(int i=0;i<max;i++)//高
    {
        for(int j=0;j<n;j++)//行
        {
            for(int k=0;k<m;k++)//列
            {
                if(c[n][m]<=i)
                {
                    s1[i][j][k]=1;
                } else
                    s1[i][j][k]=0;
                s2[i][j][k]=0;//0表示kong
            }
        }
    }
    int area(0);
    for(int i=0;i<max;i++)//高
    {
        for(int j=0;j<n;j++)//行
        {
            for(int k=0;k<m;k++)//列
            {
                {

                    for(int p=-1;p<=1;p++)
                        for(int q=-1;q<=1;q++)
                            for(int r=-1;r<=1;r++)
                            {
                                  if(p==0&&q==0&&r==0)
                                        continue;
                                   if(i>0&&i<max-1&&j>0&&j<n-1&&k>0&&k<m-1)
                                    {
                                        if(s1[i+p][j+q][k+r]==0)
                                            area++;
                                    }else if(i==0||i==max-1||j==0||j==n-1||k==0||k==m-1)
                                    {
                                       if(i==0)
                                       {
                                           if(q==-1)
                                               continue;
                                       }
                                       if(i==max-1)
                                       {
                                           if(q==1)
                                               continue;
                                       }
                                        if(j==0)
                                        {
                                            if(p==-1)
                                                continue;
                                        }
                                        if(j==max-1)
                                        {
                                            if(p==1)
                                                continue;
                                        }
                                    if(k==0)
                                    {
                                        if(r==-1)
                                            continue;
                                    }
                                    if(i==max-1)
                                    {
                                        if(r==1)
                                            continue;
                                    }
                                }
                            }
                }
                s1[i][j][k]=-1;//0表示kong
            }
        }
    }
}