#include <iostream>
using namespace std;

class Solution
{
public:
    int NumberOf1Between1AndN_Solution(int n) 
    {
        /*暴力
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
        */

        int sum = 0;

        /*
        **高位，当前位，和低位
        **eg:对于数字3789024
        **当前位为0时，高位和低位分别为3789和24
        */

        int highValue, curValue, lowValue;
        int index = 1; //curValue在整数n中的位数 取1 10 100 依次类推
        while(highValue){
            lowValue = n % index;
            curValue = (n / index) % 10;
            highValue = n / (index*10);
            if(curValue > 1){
                //当前位大于1时，高位可取0~highValue，低位可取任意值
                sum += (highValue + 1) * index;
            }else if(curValue < 1){
                //当前位为0时，需向高位借1使此位可取1，高位可取0~highValue-1，低位可取任意值
                sum += highValue * index;
            }else{
                //当前位为1时，当高位取0~highValue-1时，低位可取任意值
                //当高位取highValue时，为保证数小于等于n，低位最大只能取到lowValue的值
                sum += highValue * index + lowValue + 1;
            }
            index *= 10;
        }
        return sum;
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