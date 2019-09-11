/**
 二进制中1的个数
 请实现一个函数,输入一个整数,输出该数二进制表示中1的个数.例如,把9表示成二进制是1001,有2位是1.
 因此,如果输入0,则该函数输出2.
 考点:考察对二进制及位运算的理解
 方法一(会引起死循环)
 将输入的数与1进行位与运算,判断运算结果是否为true判断是否为1,然后对此数右移一位操作.
 如果输入的数是负数的话,此循环将一直循环下去,因为如果符号位为1,则右移位操作的最左端的位会添加为1.因此会一直为true
 方法二(常规解法)
 在方法一的基础上改进,进行与运算后,不对该数进行右移运算,而对1进行左移位运算,再加入循环就不会陷入死循环.
 但是也有缺点.此循环的次数是整数的位数,如果是32位的整数就需要循环32位,为了简化只循环位数为1的次数,进行了方法3的改进
 方法三
 在方法二的基础上,进行改进,不再用与1的位于运算,而是用减一操作与该数进行位于运算,这样当运算结果为0时,循环停止.
 例,1001-1=1000,然后1000&1001=1000,可以看出-1再进行位与运算是将最右边的1变为0
 1100-1=1001,1100&1001=1000.
 */
/***
 涉及进制的题目:
 在微软产品Excel中,用A表示第一列,B表示第二列,...Z表示第26列,AA表第27列,AB表示第28列,..以此类推.
 请写出一个函数,输入用字母表示的列号编码,输出它是第几列.
 可以看出上述是一个26进制的表示方法
 涉及位运算的相关题目:
 1.用一条语句判断一个整数是不是2的整数次方.一个整数如果是2的整数次方,那么它的二进制表示中有且只有一位是1,
 而其他所有位是0.根据前面的分析,把这个整数减去1后再和它自己做与运算,这个整数中唯一的1就变成0
 2.输入两个整数m和n,计算需要改变m的二进制表示中的多少位才能得到n.比如10的二进制表示为1010,13的二进制表示为1101,
 需要改变1010的3位才能得到1101.可以分为2步解决:第一步求这两个数的异或(相同为0,不同为1),第二步统计异或结果1的位数((n-1)&n可统计)
 */


#include <iostream>
using namespace std;

int NumberOf1(int num)
{
    int count(0);
    while(num)
    {
        if(num&1)
        {
            count++;
        }
       num=num>>1;
    }
    return count;
}

int NumberOf2(int num)
{
    int count(0);
    int flag=1;
    while(flag)
    {
        if(num & flag)
        {
            count++;
        }
        flag=flag<<1;
    }
    return count;
}

int NumberOf3(int num)
{
    int count(0);
    while(num)
    {
        num=(num-1) & num;
        count++;
    }
    return count;
}

int main() {

    int num=-16;
    //cout<<NumberOf1(num)<<endl;
    cout<<NumberOf2(num)<<endl;
    cout<<NumberOf3(num)<<endl;
    return 0;
}