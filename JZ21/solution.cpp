#include <iostream>
using namespace std;
#include <vector>
#include <stack>

class Solution
{
public:
    bool IsPopOrder(vector<int> pushV,vector<int> popV) {
        int j = 0; //弹出序列popV下标
        for (int i = 0; i < pushV.size();i++){
            s.push(pushV[i]);
            while(s.size() && (s.top() == popV[j])){
                s.pop();
                j++;
            }
        }
        if(s.size()){
            return false;
        }else{
            return true;
        }
    }

private:
    stack<int> s;
};

int main()
{
    system("pause");
    return 0;
}