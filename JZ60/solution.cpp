#include <iostream>
using namespace std;
#include <vector>
#include <queue>

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
        
        //利用队列进行广度优先遍历
        queue<TreeNode* > tNode;
        tNode.push(pRoot);
        while(!tNode.empty()){
            int num = tNode.size();
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
                ret.push_back(vec);
        } 
        return ret;
    }
};

int main()
{
    system("pause");
    return 0;
}