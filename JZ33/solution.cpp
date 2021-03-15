#include <iostream>
#include <vector>
using namespace std;


class Solution {
public:
    int GetUglyNumber_Solution(int index) {
        if(index <= 0){
            return 0;
        }
        vector<int> uglynum = {1};
        int p_multi2 = 0;
        int p_multi3 = 0;
        int p_multi5 = 0;
        int cnt = 1;
        //丑数都是由前面的丑数与2，3，5相乘得到的
        while(cnt != index){
            int minValue = min(min(2*uglynum[p_multi2], 3*uglynum[p_multi3]), 5*uglynum[p_multi5]);
            uglynum.push_back(minValue);
            cnt++;
            if(minValue == 2*uglynum[p_multi2]){ //不能用if-else，防止重复加入同一个数
                p_multi2++;
            }
            if(minValue == 3*uglynum[p_multi3]){
                p_multi3++;
            }
            if(minValue == 5*uglynum[p_multi5]){
                p_multi5++;
            }
        }
        return uglynum[cnt-1];
    }
};

int main()
{
    Solution s;
    int res = s.GetUglyNumber_Solution(7);
    cout << res << endl;
    system("pause");
    return 0;
}