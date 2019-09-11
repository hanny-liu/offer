#include <iostream>
#include <vector>
#include <sstream>
using namespace std;
int main() {

    string line;
    vector<int> nums;
    while(getline(cin,line))
    {   if(line.empty())
            break;
        istringstream is(line);
        string word;
        while(is>>word)
        {
            if(ispunct(word[word.size()-1]))
            {
                word.erase(word.end()-1);
            }
            int num=stoi(word);
            nums.push_back(num);
        }
    }
    int n=nums.size();
    int steps=0;
    int start=0;
    int end=0;
    while(end<n-1)
    {
        int max_pos=0;
        for(int i=start;i<=end;++i)
        {
            max_pos=max(max_pos,i+nums[i]);
        }
        start=end+1;
        end=max_pos;
        ++steps;
    }
    cout<<steps<<endl;
    return 0;
}