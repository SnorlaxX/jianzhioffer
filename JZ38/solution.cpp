#include <iostream>
using namespace std;
#include <queue>


struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) : 
		val(x), left(NULL), right(NULL){
    } 
};

class Solution {
public:
    int TreeDepth(TreeNode* pRoot) {
        /* //递归 
        if(pRoot == NULL){
            return 0;
        }
        return 1 + max(TreeDepth(pRoot->left), TreeDepth(pRoot->right)); 
        */

        if(pRoot == NULL){
            return 0;
        }

        queue<TreeNode *> tNodeTmp;
        tNodeTmp.push(pRoot);
        int height = 0;
        while(!tNodeTmp.empty()){
            int num = tNodeTmp.size();  //当前层的结点数
            while(num--){
                TreeNode *tmp = tNodeTmp.front();
                if(tmp->left){
                    tNodeTmp.push(tmp->left);
                }
                if(tmp->right){
                    tNodeTmp.push(tmp->right);
                }
                tNodeTmp.pop();
            }
            height++;                   //当前层遍历完，高度加1
        }

        return height;
    }
};

int main()
{
    system("pause");
    return 0;
}