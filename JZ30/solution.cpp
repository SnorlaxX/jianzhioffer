#include <iostream>
using namespace std;
#include <vector>

class Solution {
public:
    int FindGreatestSumOfSubArray(vector<int> array) {
        /* 
        int tmp = 0;
        int ret = array[0];
        for(auto i : array){
            tmp += i;
            if(tmp > ret){
                ret = tmp;
            }
            if(tmp < 0){
                tmp = 0;
            }
        }
        return ret; 
        */

        //动态规划
        int pre = 0;
        int ret = array[0];
        for(auto i : array){
            pre = max(pre + i, i);
            ret = max(pre, ret);
        }
        return ret;
    }
};

int main()
{
    //测试略
    system("pause");
    return 0;
}