#include <iostream>
using namespace std;


struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) : 
		val(x), left(NULL), right(NULL){
    } 
};

/*自顶向下递归，结点的高度重复计算
**时间复杂度O(n^2)
*/
/* 
class Solution {
public:
    bool IsBalanced_Solution(TreeNode* pRoot) {
        if(pRoot == NULL){
            return true;
        }
        if(abs(depth(pRoot->left) - depth(pRoot->right)) > 1){
            return false;
        }else{
            return IsBalanced_Solution(pRoot->right) && IsBalanced_Solution(pRoot->left);
        }

    }
    
    int depth(TreeNode* pRoot){
        if(pRoot == NULL){
            return 0;
        }
        
        return 1 + max(depth(pRoot->left), depth(pRoot->right));
    }
}; 
*/

/*自底向上的递归
**时间复杂度O(n)
*/
class Solution {
public:
    bool IsBalanced_Solution(TreeNode* pRoot) {
        if(depth(pRoot) == -1){
            return false;
        }else{
            return true;
        }
    }
    
    int depth(TreeNode* pRoot){
        if(pRoot == NULL){
            return 0;
        }

        int leftDepth = depth(pRoot->left);
        int rightDepth = depth(pRoot->right);
        if(leftDepth == -1 || rightDepth == -1 || abs(leftDepth-rightDepth)>1){
            return -1;
        }

        return max(leftDepth, rightDepth) + 1;
    }
};

int main()
{
    system("pause");
    return 0;
}