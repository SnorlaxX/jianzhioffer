#include <iostream>
using namespace std;

class Solution {
public:
    double Power(double base, int exponent) {
        /*暴力 
        double res = 1.0;
        if(base == 0.0){
            return 0.0;
        }else if(exponent == 0.0){
            return 1.0;
        }else{
            if(exponent > 0){
                for(int i = 0; i<exponent;i++){
                    res *= base;
                }
            }else{
                base = 1.0 / base;
                exponent = -exponent;
                for(int i = 0; i<exponent;i++){
                    res *= base;
                }
            }
            return res;
        }
        */
       /*
       **对于x^10, 10 = (1010)b = 0*2^0 + 1*2^1 + 0*2^2 + 1*2^3
       **x^10 = x^0 * x^(1*2^1) * x^0 * x^(1*2^3) = x^(1*2^1) * x^(1*2^3)
       **因此将指数划成二进制进行移位取值，当值为1时进行乘法即可
       */
      if(base == 0){
          return 0;
      }
      if(exponent < 0){ //指数为负数
          base = 1 / base;
          exponent = -exponent;
      }
      double res = 1.0;
      while(exponent){
          if(exponent&1){ //取二进制当前位，为1进行乘法
              res *= base;
          }
          base *= base; //x^1 , x^2, x^4 ...
          exponent >>= 1;
      }
      return res;
    }
};

int main()
{
    Solution s;
    double res = s.Power(3, -1);
    cout << res << endl;
    system("pause");
    return 0;
}