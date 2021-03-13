#include <iostream>
using namespace std;

class Solution {
public:
    int LastRemaining_Solution(int n, int m) {
        //可用链表存储，每次删除一个数，直至剩下最后一个数

        //递归
        //对于长度为n的序列，最后剩下的数为f(n,m),第一次删去的数为m%n；
        //此时对于剩下的长度为n-1的序列，最后剩下的数为f(n-1，m)，
        //由于之前已经删除了第m%n个数，此时应为m%n后的第f(n-1，m)，
        //即 f(n,m) = (f(n-1, m) + m%n)%n  = (f(n-1, m) + m)%n
        /* 
        if(n == 0){
            return -1;
        }
        if(n == 1){
            return 0;
        }
        return (m + LastRemaining_Solution(n-1, m)) % n; 
        */

       //由上面式子即 f(n,m) = (f(n-1, m) + m)%n
       if(n == 0){
           return -1;
       }
       int res = 0; //res为f(n, m) 初值f(1, m) = 1
       for (int i = 2; i <= n; i++){
           res = (res + m) % i; //左为f(i, m)，右为上一次的结果即f(i-1, m);
       }
    }
};

int main()
{
    system("pause");
    return 0;
}