#include <iostream>
#include <queue>
using namespace std;
class bitreenode
{
public:
    bitreenode *left;
    bitreenode *right;
    int data;
};

int main() {
    //构造二叉树
    vector<int> vi{13,10,25,2,12,20,31,29};
    vector<bitreenode *> bv;
    for(int i=0;i<8;i++)
    {
        bv.push_back(new bitreenode());
        bv[i]->data=vi[i];
    }
    bv[0]->left=bv[1];
    bv[0]->right=bv[2];
    for(int i=1;i<8;i++)
    {
        if(2*i+2>7) {
            bv[i]->left = nullptr;
            bv[i]->right= nullptr;
            continue;
        }
        if(bv[2*i+1]!= nullptr)
        {
            bv[i]->left=bv[2*i+1];
        } else
        {
            bv[i]->left= nullptr;
        }
        if(bv[2*i+2]!= nullptr)
        {
            bv[i]->right=bv[2*i+2];
        }else
        {
            bv[i]->right= nullptr;
        }
    }

    queue<bitreenode *> visit;
    auto t=bv[0];
    while(t!=nullptr)
    {
        visit.push(t->left);
        visit.push(t->right);
        t=visit.front();
        if(t== nullptr)
            break;
        cout<<visit.front()->data<<ends;
        visit.pop();
    }

    //std::cout << "Hello, World!" << std::endl;
    return 0;
}