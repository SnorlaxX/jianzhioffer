#include <iostream>
#include <vector>
#include <map>
using namespace std;

class Solution {
public:
    int MoreThanHalfNum_Solution(vector<int> numbers) {
        /* 时间复杂度O(n) 空间复杂度O(n) 
        map<int, int>cnt;
        for(auto i : numbers){
            if(cnt.find(i) != cnt.end()){
                cnt[i] += 1; 
            }else{
                cnt[i] = 1;
            }
            if(cnt[i] > (numbers.size()/2))
                return i;
        }
        return 0;  
        */
        //两个不同的数相互抵消，最后剩下的数才有可能超过半数
        int last = 0;
        int lastcnt = 0;
        for(auto i : numbers){
            if(lastcnt == 0){
                last = i;
                lastcnt = 1;
            }else{
                if(last == i){  //相同叠加
                    lastcnt++;
                }else{          //不同抵消
                    lastcnt--;
                }
            }
        }
        if(lastcnt == 0){       //所有数抵消完
            return 0;
        }else{                  //对剩下的数进行判断
            lastcnt = 0;
            for(auto i: numbers){
                if(i == last){
                    lastcnt++;
                }
            }
            if(lastcnt > (numbers.size()/2)){
                return last;
            }else{
                return 0;
            }
        }
        
    }
};

int main()
{
    system("pause");
    return 0;
}