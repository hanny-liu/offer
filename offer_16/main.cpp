/**
 第三章 高质量的代码
 1.代码规范性:书写,布局,命名
 命名用完整的英文单词组合命名变量和函数,这样让别人不容易混淆,容易理解
 2.代码完整性
 主要考虑代码是否完成了基本功能,输入边界值是否能得到正确的输出,是否对各种不规范的非法输入做出了合理的错误处理
 单元测试:功能测试,边界测试,负面测试
 3.错误处理方法3种
 (1)利用函数返回值告诉调用者是否出错
 (2)当错误发生时,设置一个全局变量.
 (3)异常处理.当函数运行出错的时候,抛出异常,还可以根据不同的出错原因定义不同的异常类型.例,try,catch
 */
/**
 16.数值的整数次方
 实现函数double power(double base,int exponent),求base的exponent次方.不得使用库函数,同时不需要考虑大数问题.
 问题思考方式:
 (1)基本功能实现:就是循环
 (2)边界值:
 //TODO:  如果exponent为0,任何值的0次方都为1,因此需要考虑0次方,然后0的0次方既可以是0也可以是1.
          还需要考虑如果exponent足够大,数值会不会溢出,由于题目说了不考虑大数所以不会溢出.
 //TODO:  如果exponent<0的话,那就不是直接循环这么简单,循环完需要求倒,那如果是0的-1次方就没有意义,需要考虑
 (3)负面测试:如果输入的base或者exponent是非数字的时候,就需要返回输入错误的信息
 */
 /**
  改进方法:记住乘除2可以用移位操作来表示,移位操作比乘除效率快得多
  可以观察得到,当计算a^n时,可以计算a^(n/2)^2,不比循环很多次,可以使用递归操作
  */

#include <iostream>
using namespace std;

double power(double base,int exponent)
{
    double muti(base);
    if(base==0)
        return 0;
    if(exponent==0)
        return 1;
    if(exponent>0)
    {
        for(int i=1;i<exponent;i++)
        {
            base*=muti;
        }
    } else
    {
        for(int i=1;i<-exponent;i++)
        {
            base*=muti;
        }
        base=1.0/base;
    }
    return base;
    }


double power2(double base,int exponent)
{
    if(exponent==0)
        return 1;
    if(exponent==1)
        return base;
    if(exponent==-1)
        return 1.0/base;
    if(exponent<0)
    {
        exponent=-exponent;
        double result=power2(base,exponent>>1);
        result*=result;
        if(exponent & 1==1)
            result*=base;
        result=1.0/result;
        return result;
    }
    double result=power2(base,exponent>>1);
    result*=result;
    if(exponent & 1==1)
        result*=base;
    return result;
}
int main() {
    cout<<power(0,0)<<endl;
    cout<<power(1,0)<<endl;
    cout<<power(5,-2)<<endl;
    cout<<power(3,-2)<<endl;
    cout<<power(3,5)<<endl;
    cout<<power2(0,0)<<endl;
    cout<<power2(1,0)<<endl;
    cout<<power2(5,-2)<<endl;
    cout<<power2(3,-2)<<endl;
    cout<<power2(3,5)<<endl;
    return 0;
}