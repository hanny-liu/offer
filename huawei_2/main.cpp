#include <iostream>
#include <map>
#include <vector>
#include <sstream>
using namespace std;
int add(map<string,int> &tb,string tmp,string i)
{
    if((tmp[0]>='0'&&tmp[0]<='9')||tmp[0]=='-')
    {
        long m=stoi(tmp);
        tmp.clear();
        for(auto w=i.begin();w!=i.end();++w)
        {
            if(*w!='+')
            {
                tmp.push_back(*w);
            } else
            {
                ++w;
                string n=string(w,i.end());
                return m+add(tb,tmp,n);
            }
        }
        if((tmp[0]>='0'&&tmp[0]<='9')||tmp[0]=='-')
            return m+stol(tmp);
        else
        {
            if(tb.find(tmp)!=tb.end())
            {
                return m+tb[tmp];
            }
            else
            {
                return -1;
            }
        }
    } else
    {
        if(tb.find(tmp)!=tb.end())
        {
            string t;
            for(auto w=i.begin();w!=i.end();++w)
            {
                if(*w!='+')
                {
                    t.push_back(*w);
                } else
                {
                    ++w;
                    string n=string(w,i.end());
                    return tb[tmp]+add(tb,t,n);
                }
            }
            if((t[0]>='0'&&t[0]<='9')||t[0]=='-')
                return tb[tmp]+stoi(t);
            else
            {
                if(tb.find(t)!=tb.end())
                {
                    return tb[tmp]+tb[t];
                }
                else
                {
                    return -1;
                }
            }
        }
        else
        {
            return -1;
        }
    }
}
int equa(map<string,int> &tb,string tmp,string s)
{
    string word;
    bool flag= false;
    for(auto i=s.begin();i!=s.end();++i)
    {
        if(*i!='+')
            word.push_back(*i);
        else
        {
            ++i;
            string n=string(i,s.end());
            tb[tmp]=add(tb,word,n);
            flag= true;
        }
    }
    if(!flag)
    {
        if((word[0]>='0'&&word[0]<='9')||word[0]=='-')
            tb[tmp]=stoi(word);
        else
        {
            if(tb.find(word)!=tb.end())
                tb[tmp]=tb[word];
            else
                return -1;
        }
    } else
        return tb[tmp];
}
int main() {
    int n;
    cin>>n;
    string line;
    vector<string> vs;
    vector<vector<string>> str;

    string wi;
    for(int i=0;i<n;++i)
    {
        getline(cin,line);
        istringstream is(line);
        //while(is>>wi)
            vs.push_back(line);
        //str.push_back(vs);
    }
    //---------------

    string word;
    map<string,int> tb;
    vector<string> vw;
    for(auto i:vs)//遍历所有表达式
    {
        for(auto j=i.begin();j!=i.end();++j)//遍历每行表达式
        {
            if(*j!='=')
            {
                word.push_back(*j);
            } else
            {
                ++j;
                int r;
               r=equa(tb,word,string(j,i.end()));
                tb[word]=r;
                vw.push_back(word);
                word.clear();
                break;
            }
        }
        vw.push_back(word);
    }
    if(tb[vs.back()]==-1)
        cout<<"NA"<<endl;
    else
        cout<<tb[vw[vw.size()-2]]<<endl;
    return 0;
}