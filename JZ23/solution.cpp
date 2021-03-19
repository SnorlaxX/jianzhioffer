#include <iostream>
using namespace std;
#include <vector>

class Solution {
public:
    bool VerifySquenceOfBST(vector<int> sequence) {
        if(sequence.empty()){
            return false;
        }

        int root = sequence.back();
        sequence.pop_back();
        int index = -1;
        for (int i = 0; i < sequence.size(); i++){
            if(index == -1 && sequence[i] > root){  //寻找右子树起始位置
                index = i;
            }
            if(index != -1 && sequence[i] < root){  //右子树有小于根结点的值
                return false;
            }
        }

        vector<int> seqLeft;
        vector<int> seqRight;
        if(index == -1){            //右子树为空
            seqLeft = vector<int>(sequence);
        }else if(index != 0)        //左子树不为空
            seqLeft = vector<int>(sequence.begin(), sequence.begin()+index);

        if(index != -1)             //右子树不为空
            seqRight =vector<int>(sequence.begin() + index, sequence.end());

        bool leftRet;
        bool rightRet;

        if(seqLeft.empty()){
            leftRet = true;
        }else{
            leftRet = VerifySquenceOfBST(seqLeft);
        }

        if(seqRight.empty()){
            rightRet = true;
        }else{
            rightRet =  VerifySquenceOfBST(seqRight);
        }

        return leftRet && rightRet;
    }
};

int main()
{
    vector<int> vec = {4, 8, 6, 12, 16, 14, 10};
    Solution s;
    bool ret = s.VerifySquenceOfBST(vec);
    cout << ret << endl;
    system("pause");
    return 0;
}