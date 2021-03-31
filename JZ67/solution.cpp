#include <iostream>
using namespace std;
#include <vector>

/*动态规划 dp[i]将长度为i的绳子分为至少两段后乘积的最大值
**分为长度为i-j和j的两段后，i-j可以继续切割或者保留
**乘积分别为j*dp[i-j]和j*(i-j)
*/
class Solution {
public:
    int cutRope(int number) {
        vector<int> dp(number + 1);
        dp[0] = dp[1] = 1;
        for(int i = 2; i<=number; i++){
            int curMax = 0;
            for(int j = 1; j<i; j++){
                curMax = max(curMax, max( j*(i-j), j*dp[i-j]) );
            }
            dp[i] = curMax;
        }
        return dp[number];
    }
};

int main()
{
    system("pause");
    return 0;
}
