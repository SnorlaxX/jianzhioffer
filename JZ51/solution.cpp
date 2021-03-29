#include <iostream>
using namespace std;
#include <vector>

//分上三角和下三角进行计算
class Solution {
public:
    vector<int> multiply(const vector<int>& A) {
        vector<int> B(A.size(), 1);
        int tmp = 1;
        for(int i = 0; i<A.size()-1; i++){  //下三角部分
            tmp *= A[i];
            B[i + 1] *= tmp;
        }
        tmp = 1;
        for(int i = A.size()-1; i > 0; i--){    //上三角部分
            tmp *= A[i];
            B[i - 1] *= tmp;
        }
        return B;
    }
};

int main()
{
    system("pause");
    return 0;
}
