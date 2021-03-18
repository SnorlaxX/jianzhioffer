#include <iostream>
using namespace std;
#include <vector>
#include <queue>


struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) : val(x), left(nullptr), right(nullptr){
    } 
};

class Solution {
public:
    vector<int> PrintFromTopToBottom(TreeNode* root) {
        vector<int> ret;
        if(root == NULL){
            return ret;
        }

        queue<TreeNode *> treeNodeTmp;
        treeNodeTmp.push(root);
        
        while(!treeNodeTmp.empty()){
            TreeNode *tmp = treeNodeTmp.front();
            ret.push_back(tmp->val);
            if(tmp->left){
                treeNodeTmp.push(tmp->left);
            }
            if(tmp->right){
                treeNodeTmp.push(tmp->right);
            }
            treeNodeTmp.pop();
        }
        return ret;
    }
};

int main()
{
    system("pause");
    return 0;
}