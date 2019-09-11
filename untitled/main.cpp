#include <iostream>
#include<vector>
#include <algorithm>
using namespace std;
int main() {
    int l,n;
    vector<int> v;
    int t;
    cin>>l>>n;
    for(;n>0;n--)
    {
        cin>>t;
        v.push_back(t);
    }
    int sum(0);

    for(auto i:v)
        sum+=i;
    sum/=v.size();

    for(auto &i:v)
    {
        if(i>l/2) {
            i -=l;
        }
    }

    sort(v.begin(),v.end());
    vector<int> vl,vr;
    for(int i=0;i<v.size()/2;i++)
    {
        vl.push_back(v[i]);
    }
    for(int i=v.size()/2+1;i<v.size();i++)
    {
        vr.push_back(v[i]);
    }
    for(int i=0;i<vl.size()-1;i++)
    {
        vl[i]=abs(vl[i]-vl[i+1])-1;
    }
    vl[vl.size()-1]=abs(vl[vl.size()-1]-v[v.size()/2])-1;
    for(int i=1;i<vr.size();i++)
    {
        vr[i]=abs(vr[i]-vr[i-1])-1;
    }
    vr[0]=abs(vr[0]-v[v.size()/2])-1;
    int sl(0);
    for(int i=0;i<vl.size();i++)
    {
        int s(0);
        for(int j=i;j<vl.size();j++)
            s+=vl[j];
        sl+=s;
    }
    for(int i=vr.size()-1;i>=0;i--)
    {
        int s(0);
        for(int j=i;j>=0;j--)
            s+=vr[j];
        sl+=s;
    }
    cout<<sl<<endl;
    return 0;
}