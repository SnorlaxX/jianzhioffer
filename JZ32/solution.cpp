#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>

bool myCompare(int num1, int num2){
    string str1 = to_string(num1);
    string str2 = to_string(num2);
    string tmp1 = str1+str2;
    string tmp2 = str2+str1;
    return tmp1 < tmp2;
}

class Solution {
public:
    string PrintMinNumber(vector<int>& nums) {
        string res;
        if(nums.empty()){
            return res;
        }
        sort(nums.begin(), nums.end(), myCompare);
        for(auto i : nums){
            res+=to_string(i);
        }

        return res;
    }
};

int main()
{
    system("pause");
    return 0;
}