#include <iostream>
#include <string>
#include <map>
#include <sstream>
#include <algorithm>
#include <bits/stl_vector.h>

using namespace std;
int main() {
    //不管输入输出
    //定义图结构;
    string line;
    int t1,t2;
    int n,m,k;
    string word1,word2,word3;
    int o(1);
    vector<pair<int,int>> v;


        cin>>word1>>word2>>word3;
            istringstream it(line);
            it>>word1>>word2>>word3;
            n=stoi(word1);
            m=stoi(word2);
            k=stoi(word3);
    int s[n+1][n+1];

    while(getline(cin,line))
    {

        if(o>m)
        {
            istringstream it(line);
            it>>word1>>word2;
            int tmp1(stoi(word1)),tmp2(stoi(word2));
            v.emplace_back(pair<int,int>(tmp1,tmp2));
        }
        if(o==(m+k))
            break;
        if(word1.empty())
            break;

        istringstream it(line);
        it>>word1>>word2>>word3;
        s[stoi(word1)][stoi(word2)]=stoi(word3);
        o++;

    }

    for(int i=0;i<n+1;i++)
    {
        for(int j=0;j<n+1;j++)
        {
            s[i][j]=-1;
        }
    }
    int p,q;
    vector<int> s1,s2,s3;
    for(int i=0;i<k;i++)
    {
        if(s[v[i].first][v[i].second]!=-1)
        {
            cout<<s[v[i].first][v[i].second]<<endl;
        }
        if(s[v[i].first][v[i].second]==-1)
        {
            for(int j=1;j<n;j++)
            {
                if(s[v[i].first][j]!=-1)
                {
                    s1.push_back(j);
                }
                if(s[j][v[i].second]!=-1)
                {
                    s2.push_back(j);
                }
            }
            if(s1.empty()||s2.empty())
            {
                cout<<3<<endl;
                continue;
            }
            sort(s1.begin(),s1.end());
            sort(s2.begin(),s2.end());
            for(int r=0;r<s1.size();r++)
            {
                int j=0;
                for(;j<s2.size();j++)
                {
                    if(s1[r]==s2[j])
                    {
                        s3.push_back(s1[r]);
                    }
                    if(s1[r]<s2[j])
                    {
                        break;
                    }
                    if (s1[r]>s2[j])
                    {
                        continue;
                    }
                }
                if(j==s2.size())
                    break;
            }
            if(s3.size()==0)
                cout<<3<<endl;
            else
            {
                int j=0;
                for(;j<s3.size();j++)
                {
                    if(s3[j]==0)
                    {
                        cout<<1<<endl;
                        break;
                    }
                }
                if(j==s3.size()-1)
                {
                    cout<<0<<endl;
                }
            }

        }
    }

    return 0;
}