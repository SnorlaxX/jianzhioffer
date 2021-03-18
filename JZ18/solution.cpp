#include <iostream>
using namespace std;


struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) : val(x), left(nullptr), right(nullptr){
    } 
};

class Solution {
public:
    TreeNode* Mirror(TreeNode* pRoot) {
        if(pRoot == nullptr){
            return nullptr;
        }
        TreeNode *tmp = Mirror(pRoot->right);
        pRoot->right = Mirror(pRoot->left);
        pRoot->left = tmp;
        return pRoot;
    }

    //测试用
    /* void print(TreeNode* pRoot){
        if(pRoot == nullptr){
            return;
        }
        
        cout << pRoot->val << " " << endl;
        print(pRoot->left);
        print(pRoot->right);
    } */
};

int main()
{
    //测试用
    /* TreeNode *p1 = new TreeNode(8);
    TreeNode *p2 = new TreeNode(6);
    TreeNode *p3 = new TreeNode(10);
    TreeNode *p4 = new TreeNode(5);
    TreeNode *p5 = new TreeNode(7);
    TreeNode *p6 = new TreeNode(9);
    TreeNode *p7 = new TreeNode(11);

    p1->left = p2;
    p1->right = p3;
    p2->left = p4;
    p2->right = p5;
    p3->left = p6;
    p3->right = p7;

    Solution s;

    s.print(p1); */

    system("pause");
    return 0;
}