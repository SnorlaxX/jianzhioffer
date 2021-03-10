#include <iostream>
using namespace std;
#include <vector>

class Solution {
public:
    //这里用了vector表示栈，实际可以直接用stack
    void push(int value) { 
       if(s.size() == 0){
           minNum.push_back(value);
       }else if(value < minNum[minNum.size()-1]){
           minNum.push_back(value);
       }else{
           minNum.push_back(minNum[minNum.size()-1]);
       }
       return s.push_back(value); 
    }
    void pop() {
        minNum.pop_back();
        return s.pop_back();
    }
    int top() {
        return s[s.size()-1];
    }
    int min() {
        return minNum[minNum.size()-1];
    }
private:
    vector<int> s;          //用于实现栈
    vector<int> minNum;     //用于实时存放栈的最小值
};

int main()
{
    //测试略
    system("pause");
    return 0;
}