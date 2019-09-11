/*
 重建二叉树:
 根据二叉树的前序遍历和中序遍历结果,重建二叉树.假设结果无重复的数字.
 例:前序遍历:{1,2,4,7,3,5,6,8}
    中序遍历:{4,7,2,1,5,3,8,6}
    二叉树:   1
           2  3
         4   5  6
           7   8
 */


#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class treenode {
public:
    int value;
    treenode *left;
    treenode *right;
};
treenode *ConstructCore(int *startpreorder,int *endpreorder,int *startinorder,int *endinorder)
{
    treenode *root=new treenode();
    root->value=startpreorder[0];
    root->left=root->right=nullptr;
    int rootvalue=startpreorder[0];
    if(startpreorder==endpreorder)
    {
        if(startinorder==endinorder && *startpreorder==*startinorder)
            return  root;
    }
    int *rootinorder=startinorder;
    while (rootinorder <= endinorder && *rootinorder!=rootvalue)
        rootinorder++;
    int leftlength=rootinorder-startinorder;
    int *leftpreorderend=startpreorder+leftlength;
    if(leftlength>0)
    {
        root->left=ConstructCore(startpreorder+1,leftpreorderend,startinorder,rootinorder-1);
    }
    if(leftlength<endpreorder-startpreorder)
    {
        root->right=ConstructCore(leftpreorderend+1,endpreorder,rootinorder+1,endinorder);
    }
    return root;
}

treenode *ConstructTree(int *preorder,int *inorder,int length)
{
    if(preorder== nullptr||inorder== nullptr||length<=0)
        return nullptr;
    return ConstructCore(preorder,preorder+length-1,inorder,inorder+length-1);
}

int main() {
    int pre[]={1,2,4,7,3,5,6,8};
    int in[]={4,7,2,1,5,3,8,6};
    int *preorder=pre;
    int *inorder=pre;
    treenode * root=ConstructTree(preorder,inorder,8);
    queue<treenode*> lq;
    lq.push(root);
    while(root->left!= nullptr||root->right!= nullptr)
    {
        if(root->left== nullptr)
        {
            lq.push(root->right);
            root=lq.front();
            lq.pop();
            cout<<root->value<<ends;
        }
        else if(root->right)
        {
            lq.push(root->left);
            root=lq.front();
            lq.pop();
            cout<<root->value<<ends;
        }
        else
        {
            lq.push(root->left);
            lq.push(root->right);
            root=lq.front();
            lq.pop();
            cout<<root->value<<ends;
        }
    }

    return 0;
}