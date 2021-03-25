#include <iostream>
using namespace std;

class Solution {
public:
    int rectCover(int number) {
        //f(n) = f(n-1) + f(n-2)
        if(number <= 2)
            return number;
        int a = 1, b = 2, c;
        for(int i = 3; i <= number; i++){
            c = a + b;
            a = b;
            b = c;
        }
        return c;
    }
};

int main()
{
    system("pause");
    return 0;
}