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
    bool isSymmetrical(TreeNode* pRoot) {
        if(pRoot == NULL){
            return true;
        }
        return isMirror(pRoot->left, pRoot->right);
    }

private:
    bool isMirror(TreeNode* left, TreeNode* right){
        if(left == NULL && right == NULL){
            return true;
        }else if(left == NULL || right == NULL){
            return false;
        }
        if(left->val != right->val){
            return false;
        }else{
            return isMirror(left->left, right->right) && isMirror(left->right, right->left);
        }
    }
};

int main()
{
    system("pause");
    return 0;
}