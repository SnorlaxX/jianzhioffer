#include <iostream>
using namespace std;
#include <vector>
#include <queue>


struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL){
    } 
};

class Solution {
public:
    //二叉搜索树的中序遍历序列为递增序列
    TreeNode* pre = NULL, *head = NULL;
    TreeNode* Convert(TreeNode* pRootOfTree) {
        if(pRootOfTree==NULL){
            return NULL;
        }

        //也可以以 右 根 左 的顺序 逆序遍历
        //这样无需head指针，最后的pre指针即指向开头
        Convert(pRootOfTree->left);
        if(pre!=NULL){
            pRootOfTree->left=pre;
            pre->right=pRootOfTree;
        }else{
            head = pRootOfTree;
        }
        pre=pRootOfTree;
        Convert(pRootOfTree->right);

        return head;
    }
};

int main()
{
    system("pause");
    return 0;
}