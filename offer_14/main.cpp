/*
 剪绳子
 给一根长度为n的绳子,请把绳子剪成m段(m\n都是整数,n>1且m>1),每段绳子的长度记为k[0],k[1],...k[m].
 请问k[0]*k[1]*...*k[m]可能的最大乘积是多少?
 例,当绳子长度是8时,我们把它剪成长度分别为2,3,3的三段,此时得到的最大乘积是18.
 方法一:动态规划
 从下到上,分别求出每个长度最大的乘积,f(n)=max(f(i)*f(n-i))
*/
/**
     * 动态规划法：
     * 动态规划求解问题的四个特征： 
            ①求一个问题的最优解； 
            ②整体的问题的最优解是依赖于各个子问题的最优解； 
            ③小问题之间还有相互重叠的更小的子问题； 
            ④从上往下分析问题，从下往上求解问题；
     * 动态规划：
            有一段长度为n的绳子，我们现在要剪第一刀，我可以选择下第一刀的地方有1~n-1这些地方；比如长度为10的绳子，我第一刀可以在1~9这些地方下刀，共9种方式。
            第一刀下去后，绳子分成两部分，假设在i处下刀，绳子两部分就分别为：[0~i]与[i~n]，长度分为表示为i与n-i；那么找出第一刀最合适的位置，其实就是找i在哪下刀，可以使得[0~i]与[i~n]的乘积最大，函数表示为：f(n)=max(f(i)×f(n−i))f(n)=max(f(i)×f(n−i))。
                                    那么如何判断i处切最大呢？这个时候，我们就要知道，[0~i]这个长度的绳子，任意方式切，最大的乘积是多少；假如说，当我们要切一个长度为10的绳子：切成1和9与4和6，两种方式，哪个乘积更大？ 
            回答：不光要考虑第一刀后两个绳子的大小，还要考虑到9、4、6这三种情况，因为第一刀切出的绳子长度是否可以再切第二刀，使它有更大的乘积，比如将9再切成 3×3×33×3×3，6切成 4×24×2，哪个更大？
                                   这种情况下，我们可以发现，无论再怎么切，一定是越切越短，那么我们是否可以将小于给定长度的绳子的每一个长度的最大乘积都求出来？ 
            即：长度为10的绳子，我们就计算出：长度1~9这9种长度的绳子，每种长度的最大乘积是多少。 
              要求长度9的绳子的最大乘积，我们要知道1~8各个长度的最大乘积，要知道长度8的最大乘积，就要知道1~7长度的各个最大乘积，以此类推。
     * 
     * 动态规划版本
     * f(n)定义为将长度为n的绳子分成若干段后的各段长度的最大乘积（最优解），在剪第一刀时有n-1种剪法，可选择在0 < i < n处下刀
     * 在i处下刀，分成长度为i的左半绳子和长度为n-i的右半绳子，对于这两根绳子，定义最优解为f(i)和f(n-i)，于是f(n) = max(f(i) * f(n-i))，即求出各种相乘可能中的最大值就是f(n)的最优解
     * 就这样从上到下的分下去，但是问题的解决从下到上。即先求出f(2)、f(3)的最优解，然后根据这两个值求出f(4)、f(5)...直到f(n)
     * f(2) = 1，因为只能分成两半
     * f(3) = 2，因为分成两段2*1 大于分成三段的1*1*1
     * ...
     */

#include <iostream>
#include <math.h>
using namespace std;
///动态规划
int maxProduct(int length)
{
    if (length < 2) return 0;
    if (length == 2) return 1;
    if (length == 3) return 2;
    int* products = new int[length + 1];
    products[0] = 0;
    products[1] = 1;
    products[2] = 2;
    products[3] = 3;
    int max = 0;
    for (int i = 4; i <= length; ++i) {
        max = 0;
        for (int j = 1; j <= i / 2; ++j) {
            int product = products[j] * products[i - j];
            if (max < product)
                max = product;

            products[i] = max;
        }
    }
    max = products[length];
    delete[] products;
    return max;
}
///贪心算法
/**
 贪心算法在对问题求解时，不从整体最优上加以考虑，他所做出的是在某种意义上的局部最优解；
选择的贪心策略必须具备无后效性，即某个状态以前的过程不会影响以后的状态，只与当前状态有关；
题目贪婪策略：当n>=5时，尽可能多地剪长度为3的绳子；当剩下的绳子长度为4时，把绳子剪成两段长度为2的绳子。
 * @return
 */
int maxProduct1(int length)
{
    if (length < 2) return 0;
    if (length == 2) return 1;
    if (length == 3) return 2;
    int timesOf3 = length / 3;
    if (length - timesOf3 * 3 == 1)
        timesOf3--;
    int timesOf2 = (length - timesOf3 * 3) / 2;
    int result = pow(3, timesOf3) * pow(2, timesOf2);
    return result;
}


int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}