#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <sstream>
#include <iomanip>
using namespace std;
int main() {
    string line;
    vector<int> v;
    int k;
    getline(cin,line);
    istringstream is(line);
    string word;
    while(is>>word)
        v.push_back(stoi(word));
    cin>>k;
    double num(0);
    for(int i=0;i<v.size()-k;++i)
    {
        for(int j=0;j<k;++j)
        {
            num+=v[i+j];
        }
        cout<<setiosflags(ios::fixed)<<setprecision(2)<<k<<endl;
        num=0;
    }
    return 0;
}