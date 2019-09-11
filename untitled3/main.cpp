#include<iostream>
#include<vector>
#include<sstream>
#include<string>
using namespace std;
int main()
{
    string line;
    vector<int> nums;
    int num(0);
    while(getline(cin,line))
    {
        if(line.empty())
            break;
        for(auto &i:line)
        {
            if(i==',')
                i=' ';
        }
        istringstream is(line);
        string word;
        while(getline(is,word,' '))
        {
            num=stoi(word);
            nums.push_back(num);
        }
    }
    int n=nums.size();
    if(n==0)
    {
        cout<<0<<endl;
        return 0;
    }
    if(n==1)
    {
        cout<<0<<endl;
        return 0;
    }
    int *l=&nums[0];
    int *r=&nums[n-1];
    int maxarea(0);
    while(l<r)
    {
        int area=min(*l,*r)*(r-l);
        maxarea=max(maxarea,area);
        if(*l<*r)
        {
            l++;
        }else
        {
            r--;
        }
    }
    cout<<maxarea<<endl;
    return 0;
}