#include <iostream>
using namespace std;
#include <stack>

class Solution
{
public:
    /*
    **此处未考虑异常情况，如对空队列执行pop操作
    */
    void push(int node) {
        stack1.push(node);
    }

    int pop() {
        if(stack2.empty()){
            //出栈为空时，将入栈元素倒入出栈
            //入栈的栈顶元素（后进）变成了出栈的栈底元素（后出）
            //而入栈的栈底元素（先进）变成了出栈的栈顶元素（先出）
            //由先进后出变为了先进先出
            while(!stack1.empty()){
                stack2.push(stack1.top());
                stack1.pop();
            }
        }
        int res = stack2.top();
        stack2.pop();
        return res;
    }

private:
    stack<int> stack1;  //入栈
    stack<int> stack2;  //出栈
};

int main()
{
    //测试略
    system("pause");
    return 0;
}
