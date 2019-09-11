#include<iostream>
#include <iomanip>
using namespace std;

double C(int i,int n)
{
   double result=1;
    for(int j=i;j>0;j--)
        {
            result*=n;
            n--;
        }
    for(;i>0;i--)
        {
            result/=i;
        }
    return result;
}

int main()
{
    int n,m;
    cin>>n>>m;
    double result = C(1,n)/C(1,(m+n));
    int num=(m+n)/3;
    if(num>1)
            result=(C(3,m)*C(1,n))/C(4,(m+n));
    cout<<setiosflags(ios::fixed)<<setprecision(5)<<result<<endl;
}