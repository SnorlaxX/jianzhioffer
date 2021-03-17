#include <iostream>
using namespace std;
#include <vector>


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode* reConstructBinaryTree(vector<int> pre,vector<int> vin) {
        if(pre.empty() || vin.empty()){
            return NULL;
        }
        if(pre.size() != vin.size()){
            return NULL;
        }

        TreeNode *root = new TreeNode(pre[0]);

        int pos = 0;    //根结点在中序数组中的位置
        for(auto i : vin){
            if(i == pre[0]){
                break;
            }
            pos++;
        }

        //将前序数组和中序数组元素按与根的相对位置分为左右两部分。递归
        vector<int> preLeft(pre.begin()+1, pre.begin()+pos+1);
        vector<int> preRight(pre.begin()+pos+1, pre.end());
        vector<int> vinLeft (vin.begin(), vin.begin()+pos);
        vector<int> vinRight(vin.begin()+pos+1, vin.end());

        root->left = reConstructBinaryTree(preLeft, vinLeft);
        root->right = reConstructBinaryTree(preRight, vinRight);

        return root;
    }
};

int main()
{
    system("pause");
    return 0;
}