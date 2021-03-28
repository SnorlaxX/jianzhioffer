#include <iostream>
using namespace std;
#include <vector>
#include <set>

/* //集合
class Solution {
public:
    int duplicate(vector<int>& numbers) {
        set<int> num;
        for(auto n: numbers){
            if(num.find(n) != num.end()){
                return n;
            }else{
                num.insert(n);
            }
        }
        return -1;
    }
}; 
*/

/*如果数组中没有重复数字，那么正常排序后，数字i应该在下标为i的位置
**如果下标为i的数字不是i的话，（假设为m),那么我们就拿与下标m的数字交换。
**在交换过程中，如果遇到重复的数字，那么返回该数字
*/
class Solution {
public:
    int duplicate(vector<int>& numbers) {
        for (int i = 0; i < numbers.size(); i++){
            while(numbers[i] != i){
                if(numbers[i] == numbers[numbers[i]]){
                    return numbers[i];
                }
                swap(numbers[i], numbers[numbers[i]]);
            }
        }

        return -1;
    }
};

int main()
{
    system("pause");
    return 0;
}
