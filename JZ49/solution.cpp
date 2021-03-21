#include <iostream>
using namespace std;
#include <string>

class Solution {
public:
    int strToInt(string str) {
        int ret = 0;
        int flag = 1;
        int op = 0;
        int i;
        
        if(str[0] == '+' || str[0] == '-'){
            op = 1;
            if(str[0] == '-'){
                flag = 0;
            }
        }
        
        for(i=op==1?1:0;i<str.length();i++){
            ret*=10;
            if(str[i] < '0' || str[i] > '9'){
                return 0;
            }else{
                ret += str[i] - '0';
            }
        }
        if(flag == 0){
            ret = -ret;
        }
        return ret;
    }
};

int main()
{
    string str= "+2147483647";
    Solution s;
    int res = s.strToInt(str);
    cout << res << endl;
    system("pause");
    return 0;
}
