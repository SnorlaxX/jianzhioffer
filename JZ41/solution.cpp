#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int> > FindContinuousSequence(int sum) {
        vector<vector<int> >ret;
        int l = 1, r = 1;   //左开右毕的窗口
        int tmp = 0;
        while(l <= sum / 2){    //左边到和一半的地方终止
            if(tmp < sum){
                tmp += r;
                r++;
            }else if(tmp == sum){
                vector<int> vTmp;
                for(int i = l; i < r; i++){
                    vTmp.push_back(i);
                }
                ret.push_back(vTmp);
                tmp -= l;
                l++;
            }else{
                tmp -= l;
                l++;
            }
        }
        return ret;
    }
};

int main()
{
    system("pause");
    return 0;
}