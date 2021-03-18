#include <iostream>
using namespace std;


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
    bool HasSubtree(TreeNode* pRoot1, TreeNode* pRoot2) {
        if(pRoot1 == NULL || pRoot2 == NULL){
            return false;
        }
        
        if(pRoot1->val != pRoot2->val){
            return HasSubtree(pRoot1->left, pRoot2) || HasSubtree(pRoot1->right, pRoot2);
        }else{
            if(HasTrueSubtree(pRoot1, pRoot2)){
                return true;
            }else{
                return HasSubtree(pRoot1->left, pRoot2) || HasSubtree(pRoot1->right, pRoot2);
            }
        }

    }

    //判断以pRoot1为根的树是否恰好包含树root2
    //即包含root2的子树以pRoot1为真根
    bool HasTrueSubtree(TreeNode* pRoot1, TreeNode* pRoot2){    
        if(pRoot2 == NULL){
            return true;
        }

        if(pRoot1 == NULL){
            return false;
        }

        if(pRoot1->val == pRoot2->val){
            return HasTrueSubtree(pRoot1->left, pRoot2->left) && HasTrueSubtree(pRoot1->right, pRoot2->right);
        }else{
            return false;
        }
    }
};

int main()
{
    system("pause");
    return 0;
}