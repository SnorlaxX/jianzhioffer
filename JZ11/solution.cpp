#include <iostream>
using namespace std;

class Solution {
public:
     int  NumberOf1(int n) {
         /* 
         int cnt = 0;
         while(n){
             if(n & 1){
                 cnt++;
            }
            n = (unsigned)n >> 1;   //逻辑右移
         }
         return cnt; 
         */

        // n&(n-1)时，会将n二进制右侧的第一个1变为0
         int cnt = 0;
         while(n){
             cnt++;
             n &= (n - 1);
         }
         return cnt;
     }
};
int main()
{
    Solution s;
    int res = s.NumberOf1(-1);
    cout << res << endl;
    system("pause");
    return 0;
}