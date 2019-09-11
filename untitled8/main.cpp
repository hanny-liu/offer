#include<iostream>
#include<vector>
#include <math.h>
using namespace std;
int n=0;
int a[1000];
int index=1;
int b[1000];

void Inorder(int root)
{
//    int mid=left+(right-left)/2;
//    if(left==mid)
//        cout<<arr[left]<<endl;
//    Inorder(arr,left,mid);
//    cout<<arr[mid]<<endl;
//    Inorder(arr,mid+1,right);
    if(root>n)
        return;
    Inorder(root*2+1);
    b[root]=a[index++];
    Inorder(root*2+2);
}
int main()
{
    int n,t;
    vector<int> arr;
    cin>>n;
    int num=pow(2,n)-1;
    while(num<n)
    {
        cin>>t;
        a[num]=t;
        num++;
    }
    Inorder(0);
    for(int j=0;j<=n;++j)
    {
        cout<<b[j]<<endl;
    }
}