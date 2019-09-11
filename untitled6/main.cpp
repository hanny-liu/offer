#include <iostream>
#include<vector>
#include <algorithm>
#include <string>
#include <stdio.h>
using namespace std;
int main() {
    string line;
    vector<int> v;
    while(getline(cin,line,','))
    {
        v.push_back(stoi(line));
    }
    int num(0);
    sort(v.begin(),v.end());
    int i=0,j=v.size()-1;
    while(i<j)
    {
        if(v[i]+v[j]==0)
        {
            num++;
            i++;
            j--;
        } else if(v[i]+v[j]>0)
        {
            j--;
        } else
        {
            i++;
        }
    }
    return 0;
}