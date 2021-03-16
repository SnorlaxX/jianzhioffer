#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<int> FindNumsAppearOnce(vector<int>& array) {
        /* 时间O(n) 空间O(n)
        map<int, int>cnt;
        vector<int> ret;
        for(auto i: array){
            if(cnt.find(i)!=cnt.end()){
                cnt[i]++;
            }else{
                cnt[i]=1;
            }
        }
        for(auto i: cnt){
            if(i.second==1){
                ret.push_back(i.first);
            }
        }
        sort(ret.begin(),ret.end());
        return ret; 
        */
        vector<int> ret;
        int twoNumXor = 0;  //两个所求数的异或值
        for(auto i: array){
            twoNumXor ^= i;
        }
        int cnt = 0;
        while(twoNumXor % 2 == 0){  //寻找两个数的第一差异位
            cnt++;
            twoNumXor /= 2;
        }
        int mask = 1 << cnt;
        int firstNum = 0;
        int secondNum = 0;
        for(auto i: array){ //根据该位的值将数组分为两部分
            if(mask & i){
                firstNum ^= i;
            }else{
                secondNum ^= i;
            }
        }
        if(firstNum < secondNum){
            ret.push_back(firstNum);
            ret.push_back(secondNum);
        }else{
            ret.push_back(secondNum);
            ret.push_back(firstNum);
        }
        return ret;
    }
};

int main()
{
    Solution s;
    vector<int> array = {2,4,3,6,3,2,5,5};
    vector<int> res = s.FindNumsAppearOnce(array);
    for(auto i: res){
        cout << i << " ";
    }
    cout << endl;
    system("pause");
    return 0;
}