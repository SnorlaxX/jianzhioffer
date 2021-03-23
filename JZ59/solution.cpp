#include <iostream>
using namespace std;
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
            val(x), left(NULL), right(NULL) {
    }
};

class Solution {
public:
    vector<vector<int> > Print(TreeNode* pRoot) {
        vector<vector<int>> ret;
        if(pRoot == NULL){
            return ret;
        }
        
        /* 利用队列进行广度优先遍历，偶数层reverse反转
        queue<TreeNode* > tNode;
        tNode.push(pRoot);
        int order = 0;      //层数
        while(!tNode.empty()){
            int num = tNode.size();
            order++;
            vector<int> vec;
            while(num--){
                TreeNode* tmp = tNode.front();
                vec.push_back(tmp->val);
                tNode.pop();
                if(tmp->left){
                    tNode.push(tmp->left);
                    
                }
                if(tmp->right){
                    tNode.push(tmp->right);
                }
            }
            if(order % 2 == 0){
                reverse(vec.begin(), vec.end());
            }
            ret.push_back(vec);
        } 
        */

       //利用两个栈
        stack<TreeNode *> stack1;
        stack<TreeNode *> stack2;
        stack1.push(pRoot);
        while (!stack1.empty() || !stack2.empty()){
            if(!stack1.empty()){
                vector<int> tmpVal;
                while (!stack1.empty())
                {
                    TreeNode *tmp = stack1.top();
                    tmpVal.push_back(tmp->val);
                    stack1.pop();
                    if (tmp->left)
                    {
                        stack2.push(tmp->left);
                    }
                    if (tmp->right)
                    {
                        stack2.push(tmp->right);
                    }
                }
                ret.push_back(tmpVal);
            }
            if(!stack2.empty()){
                vector<int> tmpVal;
                while(!stack2.empty()){
                    TreeNode *tmp = stack2.top();
                    tmpVal.push_back(tmp->val);
                    stack2.pop();
                    if(tmp->right){
                        stack1.push(tmp->right);
                    }
                    if(tmp->left){
                        stack1.push(tmp->left);
                    }
                }
                ret.push_back(tmpVal);
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