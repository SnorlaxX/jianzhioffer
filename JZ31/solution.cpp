#include <iostream>
using namespace std;

class Solution
{
public:
    int NumberOf1Between1AndN_Solution(int n) 
    {
        int count = 0;
        int tmp;
        for(int i = 1; i<=n; i++){
            int tmp2 = i;
            while(tmp2){
                tmp = tmp2 % 10;
                if(tmp == 1)
                    count++;
                tmp2 /= 10;
            }
        }
    }
};

int main()
{
    Solution s;
    int res = s.NumberOf1Between1AndN_Solution(13);
    cout << res << endl;
    system("pause");
    return 0;
}