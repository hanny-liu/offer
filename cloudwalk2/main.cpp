#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>
using namespace std;

int main() {
    int n,m;
    vector<int> si;
    string line;
    int num(0);
    while(num<2)
    {
        getline(cin,line);
        istringstream is(line);
        string word;
        if(num==0)
        {
            string t1,t2;
            is>>t1>>t2;
            n=stoi(t1);
            m=stoi(t2);
        } else
        {
            while(is>>word)
            {
                si.push_back(stoi(word));
            }
        }
        num++;
    }
    sort(si.begin(),si.end());
    vector<int> result;
    result.push_back(si[0]);
    for(int i=1;i<m;++i)
    {
        int max(0);
        int id;
        for(int j=i;j<n;++j)
        {
            if(result.size()==1)
            {
                if(max<abs(result[0]-si[j]))
                {
                    max=abs(result[0]-si[j]);
                    id=j;
                }
            } else
            {
                int t=1;
                for(int k=0;k<result.size();++k)
                {
                    t*=abs(result[k]-si[j]);
                }
                if(t>max)
                {
                    max=t;
                    id=j;
                }
            }

        }
        result.push_back(si[id]);
        swap(si[id],si[i]);

    }
    int min=abs(result[1]-result[0]);
    for(int i=0;i<result.size();++i)
    {
        for(int j=i+1;j<result.size();j++)
        {
            if(abs(result[i]-result[j])<min)
                min=abs(result[i]-result[j]);
        }
    }

    cout<<min<<endl;

    return 0;
}