#include <iostream>
using namespace std;

class Solution
{
public:
    int jumpFloor(int number) {
        if(number == 1 || number == 2){
            return number;
        }else{
            /*
            **令青蛙站在第n个台阶往回跳(n>2)
            **共有两种情况，分别落在第n-1个台阶和第n-2个台阶
            **两种情况下跳回第一级台阶分别有f(n-1)和f(n-2)种情况
            **即f(n) = f(n-1) + f(n-2)
            */
            return jumpFloor(number - 1) + jumpFloor(number - 2);
        }
    }
};

int main()
{
    Solution s;
    int res = s.jumpFloor(4);
    cout << res << endl;
    system("pause");
    return 0;
}