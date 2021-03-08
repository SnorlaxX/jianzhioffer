#include <iostream>
using namespace std;
#include <cmath>

class Solution
{
public:
    int jumpFloorII(int number) {
    /*
    **参考JZ8思路
    **可得f(n) = 1 + f(1) + f(2) + ... + f(n-1) ①
    **则f(n-1) = 1 + f(1) + f(2) + ... + f(n-2) ②
    **②代入①中，可得f(n) = 2f(n-1)
    **即f(n) = 2^(n-1)
    */
        return pow(2, number - 1);
    }
};

int main()
{
    Solution s;
    int res = s.jumpFloorII(4);
    cout << res << endl;
    system("pause");
    return 0;
}