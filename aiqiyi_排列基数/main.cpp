#include<cstdio>
#include<iostream>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<cmath>
#define max 1000005
#define mod 1000000007
using namespace std;
long long num,n,m,h[max],ny[max];
long long f[max];
long long fun(long long k,int num){
	long long a=k,result=1;
	while(num>0){
		if(num&1)
            result=result*a;
		a=a*a;
		a%=mod;
        result%=mod;
		num/=2;
	}
	return result;
}
long long Cal(int n,int m){
	return (((h[n]*ny[m])%mod)*ny[n-m])%mod;
}
int main(){
	h[0]=1;
	n=1000000;
	for(int i=1;i<=n;i++)
	{
	    h[i]=h[i-1]*i;h[i]%=mod;
	}
    ny[n]=fun(h[n],mod-2);
	ny[0]=1;
	for(int i=n-1;i>=1;i--)
	{
		ny[i]=ny[i+1]*(i+1);
		ny[i]%=mod;
	}
	int op=1;
	f[0]=1;
	f[1]=0;
	f[2]=1;
	for(int i=3;i<=1000000;i++)
	{
		f[i]=((i-1)*((f[i-1]+f[i-2])%mod))%mod;
	}
	cin>>num;
	while(num--)
	{
	    cin >> n >> m;
		//scanf("%lld%lld",&n,&m);
		long long tmp=Cal(n,m)*f[n-m];
		tmp%=mod;
		cout << tmp;
		//printf("%lld\n",tmp);
	}
	return 0;
}