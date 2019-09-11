#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <map>
using namespace std;
int main() {
    int n,k,ms,me;
    vector<int> si,ei;
    string line;
    int num(0);
    while(num<3)
    {
        getline(cin,line);
        istringstream is(line);
        string word;
        if(num==0)
        {
            string t1,t2,t3,t4;
            is>>t1>>t2>>t3>>t4;
            n=stoi(t1);
            k=stoi(t2);
            ms=stoi(t3);
            me=stoi(t4);
        } else if(num==1)
        {
            while(is>>word)
            {
                si.push_back(stoi(word));
            }
        } else
        {
            while(is>>word)
            {
                ei.push_back(stoi(word));
            }
        }
        num++;
    }
//    for(auto i:si)
//    {
//        cout<< i<<ends;
//    }
//---------------------------
    int ns(0),ne(0);
    string result;
    int value(0);
    for(int i=0;i<n;++i)
    {
        if(si[i]<=ei[i])
        {
            ns++;
            value+=si[i];
            result.push_back('S');
        } else
        {
            ne++;
            value+=ei[i];
            result.push_back('E');
        }
    }
    if(ns>=ms&&ne>=me)
    {
        cout<<value<<endl;
        cout<<result<<endl;
    }
    map<int,int> s;
    if(ns>ms&&ne<me)
    {
        for(int i=0;i<n;++i)
        {
            if(s.find(abs(si[i]-ei[i]))==s.end())
            {
                s[abs(si[i]-ei[i])]=i;
            }
        }
        for(auto i:s)
        {
            if(result[i.second]=='S')
            {
                value/=si[i.second];
                ns--;
                ne++;
                result[i.second]='E';
                value*=ei[i.second];
            }
            if(ns>=ms&&ne>=me)
                break;
        }
    }
    if(ns<ms&&ne>=me)
    {
        for(int i=0;i<n;++i)
        {
            if(s.find(abs(si[i]-ei[i]))==s.end())
            {
                s[abs(si[i]-ei[i])]=i;
            }
        }
        for(auto i:s)
        {
            if(result[i.second]=='E')
            {
                value/=si[i.second];
                ns++;
                ne--;
                result[i.second]='S';
                value*=ei[i.second];
            }
            if(ns>=ms&&ne>=me)
                break;
        }
    }
    cout<<value<<endl;
    cout<<result<<endl;
    return 0;
}