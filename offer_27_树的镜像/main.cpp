/*
 树的镜像:
 请完成一个函数,输入一颗二叉树,该函数输出它的镜像.
 镜像比较简单,直接递归,然后把二叉树的左子树节点赋值给右子树节点
 */
#include <iostream>
#include <random>
#include <deque>
#include <vector>
using namespace std;
template <typename T>
class node
{
public:
    T val;
    node *left;
    node *right;
};
vector<int> record_double;
template <typename T>
node<T> * rand_tree(int len,int max)//len表示高度
{
    //根据二叉树的深度来建立
    node<T> * head=new node<T>;
    static default_random_engine e;
    static uniform_int_distribution<T> dis(1,max);//均匀unsigned数值返回
    //normal_distribution<double> dis(10,1);//正态分布unsighed数值返回
    //uniform_real_distribution<double> dis(1,max);//均匀分布double数值返回
    head->val=dis(e);
    deque<node<T> *> qnode;
    qnode.push_back(head);

    record_double.push_back(head->val);
    for(int i=1;i<len;i+=2)
    {
        node<T> *tmp=qnode.front();
        qnode.pop_front();
        node<T> *left=new node<T>;
        node<T> *right=new node<T>;
        left->val=dis(e);
        right->val=dis(e);
        tmp->left=left;
        tmp->right=right;
        record_double.push_back(left->val);
        record_double.push_back(right->val);
        qnode.push_back(left);
        qnode.push_back(right);
    }
    return head;
}

node<int> * MirrorNode(node<int> * root)
{
    if(root == nullptr || (root->right == nullptr && root->left == nullptr))
        return root;
    node<int> * tmp;
    tmp = MirrorNode(root->left);
    root->left = MirrorNode(root->right);
    root->right = tmp;
    return root;
}

void Inorder(node<int> * root)
{
    if(root == nullptr)
        return ;
    Inorder(root->left);
    cout<<root->val<<" ";
    Inorder(root->right);
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    node<int> * root = rand_tree<int>(15,10);
    for(auto i:record_double)
        cout << i <<" ";
    cout<<endl;
    Inorder(root);
    cout<<endl;
    MirrorNode(root);
    Inorder(root);

    return 0;
}