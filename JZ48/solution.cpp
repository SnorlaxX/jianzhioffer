#include <iostream>
using namespace std;

class Solution {
public:
    int Add(int num1, int num2) {
        int c = 0;    //进位
        while(num2){
            c = (num1 & num2)<<1;
            num1 ^= num2; 
            num2 = c;
        }
        return num1;
    }
};

int main()
{
    Solution s;
    int res = s.Add(-1, 3);
    cout << res << endl;
    system("pause");
    return 0;
}