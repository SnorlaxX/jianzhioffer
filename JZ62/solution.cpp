#include <iostream>
using namespace std;
#include <vector>

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
    //二叉搜索树的中序遍历序列递增
    //利用中序遍历即可获得第k小的结点
    TreeNode* KthNode(TreeNode* pRoot, int k) {
        midOrder(pRoot);
        if(k > nodeVec.size() || k < 1){
            return NULL;
        }
        
        return nodeVec[k-1];
    }

private:
    vector<TreeNode *> nodeVec;
    void midOrder(TreeNode* pRoot){
        if(pRoot == NULL){
            return;
        }
        midOrder(pRoot->left);
        nodeVec.push_back(pRoot);
        midOrder(pRoot->right);
    }
};

int main()
{
    system("pause");
    return 0;
}