#include <iostream>
#include <cmath>
using namespace std;

class Solution
{
public:
    int Fibonacci(int n) 
    {
        /*递归
        if(n == 0 || n == 1)
        {
            return n;
        }else
        {
            return Fibonacci(n - 1) + Fibonacci(n - 2);
        }
        */
        /*公式法
        if(n == 0 || n == 1)
        {
            return n;
        }
        double sqrt5 = sqrt(5.0);
        return (pow((1+sqrt5),n)-pow((1-sqrt5),n))/(pow((double)2,n)*sqrt5);
        */
        if (n == 0 || n == 1)
        {
            return n;
        }else
        {
            int a = 0, b = 1, c;
            for (int i = 2; i <= n; i++){
                c = a + b;
                a = b;
                b = c;
            }
            return c;
        }
    }
};

int main()
{
    Solution s;
    int res = s.Fibonacci(3);
    cout << res << endl;
    system("pause");
    return 0;
}