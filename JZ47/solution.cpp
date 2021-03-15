#include <iostream>
using namespace std;

class Solution {
public:
    int Sum_Solution(int n) {
        bool n_neq_1 =  n > 1 && (n += Sum_Solution(n - 1));    //n>1时进入递归
        return n;
    }
};

int main()
{
    system("pause");
    return 0;
}