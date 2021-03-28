#include <iostream>
#include <vector>
#include <set>

using namespace std;

/* 排序，比较0的数量和空缺的数字个数（相邻非0数求差）
class Solution {
public:
    bool IsContinuous( vector<int> numbers ) {
        int cnt = 0;
        int tmp = 0;
        if(numbers.empty()){
            return false;
        }
        sort(numbers.begin(), numbers.end());
        for(int i = 0; i<numbers.size() - 1; i++){
            if(numbers[i] == 0){
                cnt++;
                continue;
            }
            int div = numbers[i + 1] - numbers[i];
            if(div == 0){
                return false;
            }
            tmp += div-1;
        }
        
        return cnt >= tmp;
    }
};
*/

//利用set查重，有重复返回false
//因为只抽五张，除王外，最大值减最小值小于5即可组成顺子
class Solution {
public:
    bool IsContinuous( vector<int> numbers ){
        set<int> num;
        int minNum = 14;
        int maxNum = 0;

        for(auto n :numbers){
            if(n !=0 && num.find(n)!=num.end()){
                return false;
            }
            num.insert(n);

            minNum = min(n, minNum);
            maxNum = max(n, maxNum);
        }

        return  (maxNum - minNum) < 5;
    }
};

int main()
{
    system("pause");
    return 0;
}