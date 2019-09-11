//满意度最小
#include<iostream>
using namespace std;

bool g_bInputInvalid = false;

bool CheckIn(int* numbers, int length)
{
    g_bInputInvalid = false;
    if(numbers == nullptr && length <= 0)
        g_bInputInvalid = true;

    return g_bInputInvalid;
}

bool checkhalf(int* numbers, int length, int number)
{
    int times = 0;
    for(int i = 0; i < length; ++i)
    {
        if(numbers[i] == number)
            times++;
    }

    bool isMoreThanHalf = true;
    if(times * 2 <= length)
    {
        g_bInputInvalid = true;
        isMoreThanHalf = false;
    }

    return isMoreThanHalf;
}

int NumberAppearMoreThanHalf(int numbers[],int length)
{
    if(CheckIn(numbers, length))
        return 0;

    int result = numbers[0];
    int times = 1;
    for(int i = 1; i < length; ++i)
    {
        if(times == 0)
        {
            result = numbers[i];
            times = 1;
        }
        else if(numbers[i] == result)
            times++;
        else
            times--;
    }

    if(!checkhalf(numbers, length, result))
        result = 0;

    return result;
}
bool g_InvalidInput = false;
int FindGreatestSumOfSubArray(int *pData, int nLength)
{
    if((pData == nullptr) || (nLength <= 0))
    {
        g_InvalidInput = true;
        return 0;
    }

    g_InvalidInput = false;

    int nCurSum = 0;
    int nGreatestSum = 0x80000000;
    for(int i = 0; i < nLength; ++i)
    {
        if(nCurSum <= 0)
            nCurSum = pData[i];
        else
            nCurSum += pData[i];

        if(nCurSum > nGreatestSum)
            nGreatestSum = nCurSum;
    }

    return nGreatestSum;
}

//蚂蚁问题
#include <iostream>

using namespace std;


int position[100];

int main(){

    int T;
    scanf("%d",&T);

    while (T--) {

        int gan_length,ant_num,k;

        while(~scanf("%d%d",&gan_length,&ant_num)){

            for(int i = 0; i < ant_num; ++i){
                scanf("%d",&k);
                position[i] = k;
            }


            int speed = 1; //蚂蚁的速度
            int max_time = 0; //最长时间
            int min_time = 0; //最短时间

            int temp_max = 0;
            int temp_min = 0;

            for(int i=0; i<ant_num; i++){
                temp_max = 0;
                temp_min = 0;

                if (position[i] < gan_length / 2) //中点左边
                {
                    temp_max = (gan_length - position[i]) / speed;
                    temp_min = position[i] / speed;
                }
                else //中点右边
                {
                    temp_max = position[i] / speed;
                    temp_min = (gan_length - position[i]) / speed;
                }

                if (max_time < temp_max)
                    max_time = temp_max;
                if (min_time < temp_min)
                    min_time = temp_min;
            }

            cout<<min_time<<" "<<max_time<<endl;
        }
    }

    return 0;
}
void getMinMaxTime(int length,int ant_cnt,int positions[],int* min,int*max)
{
    int speed = 1; //蚂蚁的速度
    int max_time = 0; //最长时间
    int min_time = 0; //最短时间

    int temp_max = 0;
    int temp_min = 0;

    for(int i=0; i<ant_cnt; i++){
        temp_max = 0;
        temp_min = 0;

        if (position[i] < length / 2) //中点左边
        {
            temp_max = (length - position[i]) / speed;
            temp_min = position[i] / speed;
        }
        else //中点右边
        {
            temp_max = position[i] / speed;
            temp_min = (length - position[i]) / speed;
        }

        if (max_time < temp_max)
            max_time = temp_max;
        if (min_time < temp_min)
            min_time = temp_min;
    }
    *min = min_time;
    *max = max_time;

}
//---------------
void Test(char* testName, int* pData, int nLength, int expected, bool expectedFlag)
{
    if(testName != nullptr)
        printf("%s begins: \n", testName);

    int result = FindGreatestSumOfSubArray(pData, nLength);
    if(result == expected && expectedFlag == g_InvalidInput)
        printf("Passed.\n");
    else
        printf("Failed.\n");
}

// 1, -2, 3, 10, -4, 7, 2, -5
void Test1()
{
    int data[] = {1, -2, 3, 10, -4, 7, 2, -5};
    Test("Test1", data, sizeof(data) / sizeof(int), 18, false);
}

// 所有数字都是负数
// -2, -8, -1, -5, -9
void Test2()
{
    int data[] = {-2, -8, -1, -5, -9};
    Test("Test2", data, sizeof(data) / sizeof(int), -1, false);
}

// 所有数字都是正数
// 2, 8, 1, 5, 9
void Test3()
{
    int data[] = {2, 8, 1, 5, 9};
    Test("Test3", data, sizeof(data) / sizeof(int), 25, false);
}

// 无效输入
void Test4()
{
    Test("Test4", nullptr, 0, 0, true);
}

int main(int argc, char* argv[])
{
    Test1();
    Test2();
    Test3();
    Test4();

    return 0;
}

//int main()
//{
//    //3
//    //1 2
//    //3 4
//    vector<int> que;//排队顾客数量
//    vector<vector<int>> w;//每个顾客的不满意度
//    int n;
//    int a,b;
//    cin>>n;
//    while(n>0)
//    {
//        cin>>a>>b;
//        que.push_back(a);
//        que.push_back(b);
//        w.push_back(que);
//        que.clear();
//        n--;
//    }
//    // vector<map<int,vector<int>>> cost;
//    map<int,int> costi;
//    int sum;
//    int number(0);
//    n=w.size();
//    for(int i=1;i<=w.size();++i)
//    {
//        for(int j=1;j<=w.size();++j)
//        {
//            sum=w[i-1][0]*(j-1)+w[i-1][1]*(n-j);
//            costi[sum]=i-1;
//        }
//        // cost.push_back(costi);
//        number+=(costi.begin())->first;
//        costi.clear();
//    }
//
//
//    // for(int i=0;i<n;++i)
//    // {
//    //     // if(v[cost[i].begin()->second[0]]==0)
//    //        number+=v[cost[i].begin()->first];
//    //     // else
//    //     //     {
//    //     //         int j=1,k=1;
//    //     //         while(v[cost[i].begin()->second[j]]!=0 && j<cost[i].begin()->second.size())
//    //     //         {
//    //     //             j++;
//    //     //         }
//    //     //         if(v[cost[i].begin()->second[j]]==0)
//    //     //         {
//    //     //             v[cost[i].begin()->second[j]]++;
//    //     //         }
//    //         else
//    //         {
//    //             j=0;
//    //             while(k<v.size()&&v[(cost[i].begin()+k)->second[j]]!=0 && j<(cost[i].begin()+k)->second.size())
//    //             {
//
//    //             }
//    //         }
//
//    //     }
//    // }
//    cout<< number<<endl;
//    return 0;
//}